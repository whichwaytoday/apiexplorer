#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QDebug>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->_time->setDateTime(QDateTime::currentDateTime());
    _manager = new QNetworkAccessManager(this);
    connect(ui->_fetch,SIGNAL(clicked(bool)),this,SLOT(fetch()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fetch()
{
    //QString time = ui->_time->time().
    uint departureTimeInt = ui->_time->dateTime().toTime_t();
    QString departureTime(QString("%1").arg(departureTimeInt));
    QUrl url(QString(ui->_url->text()).arg(ui->_key->text()).arg(ui->_origin->text()).arg(ui->_destination->text()).arg(departureTime));
    qDebug() << "isValid:" << url.isValid() << " " << url.toEncoded();
    ui->_encodedUrl->setText(url.toEncoded());
    _bytes.clear();
    ui->_result->clear();
    //return;
    _reply = _manager->get(QNetworkRequest(url));
    connect(_reply, SIGNAL(finished()),
              this, SLOT(httpFinished()));
      connect(_reply, SIGNAL(readyRead()),
              this, SLOT(httpReadyRead()));
      connect(_reply, SIGNAL(downloadProgress(qint64,qint64)),
              this, SLOT(updateDataReadProgress(qint64,qint64)));


}


void MainWindow::httpFinished()
{
    qDebug() << "httpFinished";
    QByteArray bytes = _reply->readAll();
    _bytes += bytes;
    ui->_result->setText(QString::fromUtf8(_bytes.data(), _bytes.size()));
    QJsonDocument jsonDoc = QJsonDocument::fromBinaryData(_bytes);
    QJsonObject obj = jsonDoc.object();
    qDebug() << obj["routes"].toString();
    int statusCode = _reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    int redirection = _reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toInt();
    qDebug() << "status code:" << statusCode;
    qDebug() << "redirection code:" << redirection;
    /*if(statusCode == 302)
    {
        QUrl newUrl = reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
        qDebug() << "redirected from " + replyUrl + " to " + newUrl.toString();
        QNetworkRequest newRequest(newUrl);
        _manager->get(newRequest);
        return;
    }*/
    _reply->deleteLater();
}

void MainWindow::httpReadyRead()
{
    qDebug() << "httpReadyRead";
    QByteArray bytes = _reply->readAll();
    _bytes += bytes;
    //qDebug() << str;
}

void MainWindow::updateDataReadProgress(qint64,qint64)
{
    qDebug() << "upodateDataReadProgress";
}

