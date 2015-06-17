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
    enum class Status {
        SUCCESS = 0,
        ERROR = 1,
        PROCESSING = 2,
        NEW = 3
    };

    Q_OBJECT
public:
    explicit HttpRequest(QNetworkAccessManager *_manager, QObject *parent = 0);
    HttpRequest(QNetworkAccessManager *_manager, QUrl url, QObject *parent = 0);
    void setUrl(QUrl);
    QUrl url() const;
    void exec();
    Status status() const;
    int htmlStatus();
    void addParam(const QString &key, const QString &value);

signals:
    void finished(const QString &name, const QByteArray &data);

private slots:
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64,qint64);

private:
    QUrlQuery _query;
    QNetworkReply *_reply;
    QUrl _url;
    Status _status;
    QNetworkAccessManager *_manager;
};

#endif // HTTPREQUEST_H
