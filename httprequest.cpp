#include "httprequest.h"

HttpRequest::HttpRequest(QNetworkAccessManager *_manager, QObject *parent) : QObject(parent)
{
_manager = manager;
_status = HttpRequest::Status::NEW;
}

HttpRequest::HttpRequest(QNetworkAccessManager *_manager, QUrl url, QObject *parent = 0)
{
    _status = HttpRequest::Status::NEW;
_manager = manager;
_url = url;
}

void HttpRequest::setUrl(QUrl url){ _url = url;}

QUrl HttpRequest::url() const {return _url;}

void HttpRequest::exec()
{

}

Status HttpRequest::status() const {return _status;}

int HttpRequest::htmlStatus() {}

void HttpRequest::addParam(const QString &key, const QString &value)
{

}

void HttpRequest::httpFinished()
{

}

void HttpRequest::httpReadyRead()
{

}

void HttpRequest::updateDataReadProgress(qint64,qint64)
{

}

