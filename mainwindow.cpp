#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p_myTimer=new QTimer(this);
    connect(p_myTimer, SIGNAL(timeout()), this, SLOT(tick()));
    p_myTimer->start(1000);
    qDebug()<<"Timer start";
    ui->lcdNumber_2->display(qsTemp);
    tick();


    /*QDateTime dt;
    dt = QDateTime::currentDateTime();
    qDebug() << dt.toString();

    QString qsTemp0 = dt.toString("yyyy / MM / dd");
    qDebug() << "qsTemp is "<< qsTemp0;
    ui->lcdNumber_3->display(qsTemp0);


    QString qsTemp = dt.toString(" hh");
    qDebug() << "qsTemp is "<< qsTemp;
    ui->lcdNumber->display(qsTemp);

    QString qsTemp1 = dt.toString(" mm");
    qDebug() << "qsTemp is "<< qsTemp1;
    ui->lcdNumber_1->display(qsTemp1);

    QString qsTemp2 = dt.toString(" ss");
    qDebug() << "qsTemp is "<< qsTemp2;
    ui->lcdNumber_2->display(qsTemp2);
    ui->label->setText(tick);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tick()
{


    qsTemp = QTime::currentTime().toString();
    QStringList qslTmpList = qsTemp.split(":");
     ui->lcdNumber->display(QDate::currentDate().toString());


    if (qslTmpList[2].toInt()% 2 == 0){
           qsTemp = qsTemp.replace(":"," ");
           ui->lcdNumber_2->display(qsTemp);
       } else {
        ui->lcdNumber_2->display(qsTemp);
    }



}

