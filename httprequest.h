#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QObject>
#include <QUrl>
#include <QByteArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class HttpRequest : public QObject
{
    Q_OBJECT
    Q_ENUMS(Status)
public:

    explicit HttpRequest(QNetworkAccessManager *_manager, QObject *parent = 0);
    HttpRequest(QNetworkAccessManager *_manager, QUrl url, QObject *parent = 0);
    void setUrl(QUrl);
    QUrl url() const;
    void fetch();
    bool isSuccess() const;
    int status() const;

signals:
    void finished( const QByteArray &data);

private slots:
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64,qint64);

private:
    QUrlQuery _query;
    QNetworkReply *_reply;
    QByteArray _bytes;
    QUrl _url;
    int _status;
    QNetworkAccessManager *_manager;
};

#endif // HTTPREQUEST_H
