#include "mainwindow.h"
#include <QApplication>
#include <QQuickWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qmlRegisterType<HttpRequest>("com.whichwaytoday.httprequest", 1, 0, "HttpRequest");
    MainWindow w;
    w.show();

    return a.exec();
}
