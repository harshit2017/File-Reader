#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>

// this file contains all the useful fun to compute angle
#include <laser_angle.h>

using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // add radio btns to group
    fileButtonGrp.addButton(ui->radioButton);
    fileButtonGrp.addButton(ui->radioButton_2);
    fileButtonGrp.addButton(ui->radioButton_3);
    fileButtonGrp.addButton(ui->radioButton_4);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// kind of event handler for push btn
void MainWindow::on_pushButton_clicked()
{
//    returns ptr to btn which is selected
    QAbstractButton *btn=fileButtonGrp.checkedButton();

    //returns label of btn in plain text
    QString fileName=btn->text();
    qDebug()<<fileName;

    // this method opens the file which is specified by the btn
    this->openFile(fileName);
}


void  MainWindow::openFile(QString fileName){
    if(fileName == "File 1")
       {
        QFile file("../data_file/file1.txt");
        angleVal(file);
    }


    else if (fileName== "File 2")
    {
        QFile file("../data_file/file2.txt");
        angleVal(file);
    }

    else if(fileName== "File 3")
     {
        QFile file("../data_file/file3.txt");
        angleVal(file);
    }

    else
    {
        QFile file("../data_file/file4.txt");
        angleVal(file);
    }

}



