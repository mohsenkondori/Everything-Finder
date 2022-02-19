/*******************************************
**       Mohsen Abdollahzadeh Kondori     **
**       Email: MohsenKondori@yahoo.com   **
********************************************/

#include <QElapsedTimer>
#include <QtWidgets>

#include "t_finder.h"

static inline void openFile(const QString &fileName)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

TFinder::TFinder(QObject *parent) : QObject(parent)
{
    _isStop = false;
    _timer = 0.0;

    // Move finder to second thread
    this->moveToThread(&_finderThread);
    _finderThread.start();
}

TFinder::~TFinder()
{
    //Destroy finder thread
    _finderThread.destroyed(this);
}

void TFinder::getSearchParams(QVariant directory, QVariant text)
{
    _currentDir.setPath(QDir::toNativeSeparators(directory.toString()));
    _text = text.toString();
}

void TFinder::find()
{
    QElapsedTimer timer;
    timer.start();
    qDebug()<<"Finder Thread:"<<QThread::currentThreadId();

    QString fileName = "*";
    QString path  = QDir::cleanPath(_currentDir.path());

    QStringList filter;
    if (!fileName.isEmpty())
        filter << fileName;
    QDirIterator it(path, filter, QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    QStringList files;
    int i = 0;
    while (it.hasNext() && !_isStop)
        files << it.next();

    if (_isStop) { //return if isStop == true and show files that find
        showFiles(files);
        emit setFinderTime(timer.elapsed()); // fill timer
        return;
    }

    if (!_text.isEmpty())
        files = findFiles(files, _text);

    files.sort();
    showFiles(files);

    emit setFinderTime(timer.elapsed());
}

//! [5]
QStringList TFinder::findFiles(const QStringList &files, const QString &text)
{
    QStringList foundFiles;

    for (int i = 0; i < files.size(); ++i) {
        QCoreApplication::processEvents();
        const QString fileName = files.at(i);
        QString fileNameStr = files.at(i);
        int pos = fileNameStr.lastIndexOf(QChar('/'));
        if (fileNameStr.mid(pos + 1, fileNameStr.length()).contains(text))
            foundFiles << files[i];
        if (_isStop)
            return foundFiles;
    }
    return foundFiles;
}

void TFinder::showFiles(const QStringList &paths)
{
     QList<QVariant> fileList;
    for (const QString &filePath : paths) {
        const QString relativePath = QDir::toNativeSeparators(_currentDir.relativeFilePath(filePath));
        const qint64 size = QFileInfo(filePath).size();

        QVariantMap fileMap_Obj;
        QString fileNameStr = filePath;
        QString pathStr = filePath;
        int pos = fileNameStr.lastIndexOf(QChar('/'));

        fileMap_Obj.insert("FileName", fileNameStr.mid(pos + 1, fileNameStr.length()));
        fileMap_Obj.insert("Path", pathStr.left(pos));
        fileMap_Obj.insert("Size", size);
        fileList.append(fileMap_Obj);
    }
    QVariant fileListVar;
    fileListVar.setValue(fileList);
    emit appendToModel(fileListVar);
}

void TFinder::openFileOfItem(QVariant fileName, QVariant pathSr, QVariant isOpenFile)
{
    if (isOpenFile.toBool())
        openFile(pathSr.toString() + "/" + fileName.toString());
    else
        openFile(pathSr.toString());
}

void TFinder::setStop(QVariant isStop)
{
    _isStop = isStop.toBool();
    if (_isStop) {
        _finderThread.requestInterruption();
        _finderThread.quit();
    } else if (!_finderThread.isRunning())
        _finderThread.start();
}
