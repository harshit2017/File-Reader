#ifndef LASER_ANGLE_H
#define LASER_ANGLE_H

#include <QDebug>
#include <QVector>
#include <QFile>
#include <algorithm>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"

typedef pair<int,int> pii;


// function for sorting vector on basis of values
bool comp(const pii &i, const pii &j){
    return i.second > j.second;
}



// this function reads hex val converts it to decimal and finds maximum
void MainWindow::angleVal(QFile &file){
     QString fileData;
     QList <QString>lData;

//   we store the data in a list
     if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
         fileData = file.readAll();
         lData=fileData.split('\n');
     }

 //    make vector of pairs ->1)key->idx 2)val->dec val
     QVector <pii>v;
     for (int i=0;i<lData.size();i++){
         int temp=lData[i].toInt(NULL,16);
         v.push_back(make_pair(i,temp));
     }

     //sort the vector in decreasing order
     sort(v.begin(),v.end(),comp);

     //find 45% of maxm val and sub from maxm
     double max45=v[0].second-0.45*v[0].second;

     int idx45=-1;

//     find the idx of first val < max45
     for (int i=0;i<v.size();i++) {
         if(v[i].second < max45){
             idx45=i;
             break;
         }
     }


//     discard all  the values less than < max45
     if(idx45!=-1)
         v.erase(v.begin()+idx45,v.end());

//     it prints the rem values in the vector
     for (int i=0;i<v.size();i++) {
         qDebug()<<v[i].second;
     }

     //calc laser angle
     double ans=calcAng(v);
     qDebug()<<"Laser Angle : "<< ans;

     // set the text label
     QString str="Laser Angle : " + QString::number(ans);
     ui->label->setText(str);




}


// this function actually computes value
double MainWindow::calcAng(QVector<pii> &v){
//    weight arr stores the corresponding wts
    int wt[]={-45,-30,-18,-6,6,18,30,45};

    int WiVi=0;
    int Vi=0;

    //computes ΣWi*Vi and ΣVi
    for (int i=0;i<v.size();i++) {
        WiVi+=wt[(v[i].first)%8]*v[i].second;
        Vi+=v[i].second;
    }

//    return the angle value
    return (double)WiVi/Vi;

}


#endif // LASER_ANGLE_H
