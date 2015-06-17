#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "httprequest.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    public slots:
     void fetchGoogle();
     void fetchBing();
     void fetchUrl(QUrl);
     void httpFinished(QByteArray);


private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *_manager;
    HttpRequest *_request;
};

#endif // MAINWINDOW_H
