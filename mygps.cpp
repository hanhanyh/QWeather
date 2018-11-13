#include "mygps.h"

MyGPS::MyGPS()
{
    this->gps= QGeoPositionInfoSource::createDefaultSource(0);
    connect(this->gps,SIGNAL(positionUpdated(QGeoPositionInfo)),this,SLOT(GeoUpdate(QGeoPositionInfo)));
}
 MyGPS::~MyGPS()
{
    this->gps->deleteLater();
}
void MyGPS::StartGPS()
{
    this->gps->setUpdateInterval(600000);//更新间隔不能设置高了 否则API 会被不断刷（根据自己的情况）
    this->gps->startUpdates();
}
void MyGPS::GeoUpdate(QGeoPositionInfo gpi)
{
    emit this->update(gpi.coordinate().latitude(),gpi.coordinate().longitude());
}
