#include "httprequest.h"

HttpRequest::HttpRequest(QNetworkAccessManager *manager, QObject *parent) : QObject(parent)
{
    _manager = manager;
    _status = -1;
}

HttpRequest::HttpRequest(QNetworkAccessManager *manager, QUrl url, QObject *parent)
{
    _status = -1;
    _manager = manager;
    _url = url;
}

void HttpRequest::setUrl(QUrl url){ _url = url;}

QUrl HttpRequest::url() const {return _url;}

void HttpRequest::fetch()
{
    _bytes.clear();
    _reply = _manager->get(QNetworkRequest(_url));
    connect(_reply, SIGNAL(finished()),
            this, SLOT(httpFinished()));
    connect(_reply, SIGNAL(readyRead()),
            this, SLOT(httpReadyRead()));
    connect(_reply, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(updateDataReadProgress(qint64,qint64)));
}

int HttpRequest::status() const {return _status;}

bool HttpRequest::isSuccess() const {return (_status == 200);}

void HttpRequest::httpFinished()
{
    _bytes += _reply->readAll();
    _status = _reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    int redirection = _reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toInt();
    qDebug() << "status code:" << _status;
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
    emit finished(_bytes);
}

void HttpRequest::httpReadyRead()
{
    _bytes += _reply->readAll();
}

void HttpRequest::updateDataReadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    qDebug() << "HttpRequest progress bytesReceived:" << bytesReceived << " bytesTotal:" << bytesTotal;
}

