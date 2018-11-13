import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material 2.0
import qiuyuhan.org.MyGps 1.0
import qiuyuhan.org.ApiNet 1.0
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

/*
    注册模块的操作
*/
    /*Component.onCompleted:
    {
         apinet.getWeather("","");//获取天气数据等待数据 接受
    }*/
    MyGps{
        id:gps
        onUpdate:{
         //   lab.text=latitude.toString()+","+longtitude.toString();
            apinet.getWeather(latitude.toString(),longtitude.toString());//获取天气数据等待数据 接受
        }//暴露信号的时候需要注意大小写
    }
    ApiNet{
        id:apinet
        onReceiveData: {
          //   lab.text=data
           // lab.text="收到数据了"
           /*
                开始解析JSON数据
            */
          var ojson=JSON.parse(data);
          var provname=ojson.data.city.pname;//省
          var posname=ojson.data.city.name;//城
          var weatherBanner=ojson.data.sfc.banner;//天气简介
          console.log("您所在的省："+provname+",城："+posname);
          console.log(weatherBanner);
          lab.text=weatherBanner;
          //设置定位Label
          labpos.text="位置："+provname+","+posname;
        }
    }
/*
*/
    header:Pane{
        id:header
        Label{
            text:"天气预报v1.0"
            anchors.centerIn: parent
        }
        Material.elevation:1
    }
    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page{
            Label
            {
                id:labpos
                text:"正在加载"
                anchors.top: parent.top
                anchors.left:parent.left
                anchors.margins:20
                anchors.leftMargin: 20
            }
            Label{
                id:lab
                text:"..."
                anchors.top: labpos.bottom
                anchors.topMargin: 40
                anchors.left:parent.left
                anchors.leftMargin: 20

            }
            Component.onCompleted: {
                gps.StartGPS();
            }
        }
        Page {
            Label {
                text: qsTr("请开启GPS，否则无法获取定位")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("首页")
        }
        TabButton {
            text: qsTr("关于")
        }
    }
}
