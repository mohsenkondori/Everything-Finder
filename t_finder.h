#ifndef T_FINDER_H
#define T_FINDER_H

#include <QWidget>
#include <QDir>
#include <QQuickItemGrabResult>
#include <QThread>

class TFinder : public QObject
{
    Q_OBJECT
public:
    explicit TFinder(QObject *parent = 0);
    ~TFinder();

signals:
    void appendToModel(QVariant fileModel);
    void setFinderTime(QVariant timer);

public slots:
    void getSearchParams(QVariant directory, QVariant text);
    void find();
    void openFileOfItem(QVariant fileName, QVariant row, QVariant isOpenFile);
    void setStop(QVariant isStop);

private:
    QStringList findFiles(const QStringList &files, const QString &text);
    void showFiles(const QStringList &paths);

    bool _isStop; // for stopping search process without closing App.
    QDir _currentDir;
    QString _text;
    QThread _finderThread; // move to another thered.

    double _timer; // elapsed time of finder

};
//! [0]

#endif
