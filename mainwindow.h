#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>

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
     void httpFinished();
     void httpReadyRead();
     void updateDataReadProgress(qint64,qint64);


private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *_manager;
    QNetworkReply *_reply;
    QByteArray _bytes;
};

#endif // MAINWINDOW_H
