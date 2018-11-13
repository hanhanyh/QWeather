#ifndef APINET_H
#define APINET_H
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QObject>
#include<QString>

class APINet:public QObject
{
    Q_OBJECT
private:
    QString * mToken;
    QString * mAppCode;
    QNetworkAccessManager * mManager;
    QNetworkRequest * mrequest;
signals:
    void receiveData(QString data);

public:
    APINet();
    ~APINet();
public slots:
   Q_INVOKABLE void getWeather(QString lat,QString lon);
private slots:
    void dataReceived(QNetworkReply*  reply);
};

#endif // APINET_H
