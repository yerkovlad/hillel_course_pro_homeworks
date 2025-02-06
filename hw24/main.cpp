#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "CustomFileSystemModel.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<CustomFileSystemModel>("CustomFileViewer", 1, 0, "CustomFileSystemModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
