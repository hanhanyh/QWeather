#include "apinet.h"
#include<QUrl>
APINet::APINet()
{
    this->mAppCode=new QString();
    this->mToken=new QString();
    this->mManager=new QNetworkAccessManager(nullptr);
    QString url="http://aliv8.data.moji.com/whapi/json/aliweather/shortforecast";
    this->mrequest=new  QNetworkRequest(QUrl(url));
}
APINet::~APINet()
{
    this->mManager->deleteLater();
    delete this->mAppCode;
    delete this->mToken;

}
void APINet::getWeather(QString lat, QString lon)
{

    // QString data="lat=30.63432&lon=103.775294&token=bbc0fdc738a3877f3f72f69b1a4d30fe";//四川崇州用于调试
    QString data="lat="+lat+"&lon="+lon+"&token=bbc0fdc738a3877f3f72f69b1a4d30fe";
    this->mrequest->setRawHeader("content-type","application/x-www-form-urlencoded");
    this->mrequest->setRawHeader("Authorization","APPCODE bc3a59ee22d847b880bec52d64726ae5");
    this->mManager->post(*(this->mrequest),QByteArray(data.toUtf8()));
    //
    connect(this->mManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(dataReceived(QNetworkReply*)));
}

void APINet::dataReceived(QNetworkReply *reply)
{
    QString data=reply->readAll();
    emit this->receiveData(data);
}
