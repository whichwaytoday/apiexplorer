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
    ui->_bingTime->setDateTime(QDateTime::currentDateTime());
    _manager = new QNetworkAccessManager(this);
    _request = NULL;

    connect(ui->_googleFetch,SIGNAL(clicked(bool)),this,SLOT(fetchGoogle()));
    connect(ui->_bingFetch,SIGNAL(clicked(bool)),this,SLOT(fetchBing()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fetchGoogle()
{
    //QString time = ui->_time->time().
    uint departureTimeInt = ui->_time->dateTime().toTime_t();
    QString departureTime(QString("%1").arg(departureTimeInt));
    QUrl url(QString(ui->_url->text()).arg(ui->_key->text()).arg(ui->_origin->text()).arg(ui->_destination->text()).arg(departureTime));
    qDebug() << "isValid:" << url.isValid() << " " << url.toEncoded();

    fetchUrl(url);
}

void MainWindow::fetchBing()
{
    QString departureTime = ui->_bingTime->dateTime().toString("MM/dd/yyyy HH:mm:ss AP");
    //qDebug() << departureTime;
    //return;
    QUrl url(QString(ui->_bingUrl->text()).arg(ui->_bingKey->text()).arg(ui->_bingOrigin->text()).arg(ui->_bingDestination->text()).arg(departureTime));
    qDebug() << "isValid:" << url.isValid() << " " << url.toEncoded();
    fetchUrl(url);
    //ui->_encodedUrl->setText(url.toEncoded());

}

void MainWindow::fetchUrl(QUrl url)
{
    ui->_encodedUrl->setText(url.toEncoded());
    ui->_result->clear();
    if (_request)
        delete _request;
    _request = new HttpRequest(_manager,url);
    connect(_request,SIGNAL(finished(QByteArray)),this,SLOT(httpFinished(QByteArray)));
    _request->fetch();
}

void MainWindow::httpFinished(QByteArray bytes)
{
    qDebug() << "httpFinished";

    ui->_result->setText(QString::fromUtf8(bytes.data(), bytes.size()));
    //QJsonDocument jsonDoc = QJsonDocument::fromBinaryData(bytes);
    //QJsonObject obj = jsonDoc.object();
    //qDebug() << obj["routes"].toString();

}

