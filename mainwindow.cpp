#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f1.setPointSize(16);
    f2.setPointSize(24);




    this->setStyleSheet("QWidget#centralwidget { background-color: rgb(0, 0, 0); }");

    tim=new QTimer(this);
    tim->setInterval(2000);
    tim->setSingleShot(true);

    connect(tim,&QTimer::timeout,this,&MainWindow::ontimout);

    ic1.addFile(":/images/c1.png",QSize(250,250));
    ic2.addFile(":/images/c2.png",QSize(250,250));
    ic3.addFile(":/images/c3.png",QSize(250,250));

    ui->noth->setIcon(ic1);
    ui->noth->setIconSize(QSize(250,250));
    ui->noth->setFlat(true);
    ui->noth->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->resul->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_orel_clicked()
{
    choose=0;
    ui->resul->hide();
    tim->start();

}


void MainWindow::on_res_clicked()
{
    choose=1;
    ui->resul->hide();
    tim->start();
}

void MainWindow::ontimout()
{
    fin=rand()%2;
    ui->resul->show();
    ui->resul->setFont(f2);
    if(fin==0){
        ui->noth->setIcon(ic2);
        ui->noth->setIconSize(QSize(250,250));

    }else{
        ui->noth->setIcon(ic3);
        ui->noth->setIconSize(QSize(250,250));
    }
    if(fin==0 && choose==0){
        ui->resul->setText("You WIN!");
    }
    if(fin==0 && choose==1){
        ui->resul->setText("You LOSE!");
    }
    if(fin==1 && choose==1){
        ui->resul->setText("You WIN!");
    }
    if(fin==1 && choose==0){
        ui->resul->setText("You LOSE!");
    }
}
