#include <QGuiApplication>
#include <qqmlcomponent.h>
#include <QQuickStyle>
#include <QQmlApplicationEngine>
#include <QIcon>

#include "t_finder.h"
#include "files_model.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc,argv);
    app.setOrganizationName("Ghalamchi company");
    app.setOrganizationDomain("gmtii.ir/");
    app.setApplicationName("Everything Finder Application"); // Find all files in Windows.

    //Set Material style
    QQuickStyle::setStyle("Material");

    app.setWindowIcon(QIcon(":/Icons/AppIcon.png"));

    //Registers the FilesModel type in the QML system
    qmlRegisterType<FilesModel>("Backend", 1, 0, "FilesModel");

    TFinder *finder = new TFinder();


    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/qml");

    qDebug()<<"Main thread"<<QThread::currentThreadId()<<"**IdealThreadCount"<<QThread::idealThreadCount();

    QQmlComponent component(&engine, QUrl(QStringLiteral("MainView.qml")));
    if( component.status() != QQmlComponent::Ready )
    {
        if( component.status() == QQmlComponent::Error )
            qDebug()<<("Error:"+ component.errorString());
    }
    QObject *object = component.create();
    //Connect signal and slots of QML and Cpp and vice versa
    {
        QObject::connect(object, SIGNAL(searchFiles()),
                         finder, SLOT(find()));
        QObject::connect(object, SIGNAL(setSearchText(QVariant, QVariant)),
                         finder, SLOT(getSearchParams(QVariant, QVariant)));
        QObject::connect(object, SIGNAL(openSelectedFileirectory(QVariant, QVariant, QVariant)),
                         finder, SLOT(openFileOfItem(QVariant, QVariant, QVariant)));
        QObject::connect(object, SIGNAL(setStoptoFinder(QVariant)),
                         finder, SLOT(setStop(QVariant)), Qt::DirectConnection);

        QObject::connect(finder, SIGNAL(appendToModel(QVariant)),
                         object, SLOT(updateListView(QVariant)));
        QObject::connect(finder, SIGNAL(setFinderTime(QVariant)),
                         object, SLOT(getFinderTime(QVariant)));
    }

    return app.exec();
}
