#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f1.setPointSize(16);
    f2.setPointSize(24);

    QPixmap pix(":/images/c1.png");
    ui->label_Coin->setPixmap(pix.scaled(ui->label_Coin->width(), ui->label_Coin->height(), Qt::KeepAspectRatio));
    label = new QLabel(this);
    movie = new QMovie(":/images/с4.gif");
    label->move(250, 100);
    label->setFixedSize(250, 250);
    movie->setScaledSize(QSize(250, 250));
    label->setMovie(movie);

    ui->noth->hide();
    label->hide();
    movie->start();

    this->setStyleSheet("QWidget#centralwidget { background-color: rgb(0, 0, 0); }");

    tim = new QTimer(this);
    tim->setInterval(2000);
    tim->setSingleShot(true);

    connect(tim, &QTimer::timeout, this, &MainWindow::ontimout);

    ic1.addFile(":/images/c1.png", QSize(250, 250));
    ic2.addFile(":/images/c2.png", QSize(250, 250));
    ic3.addFile(":/images/c3.png", QSize(250, 250));
    ic4.addFile(":/images/c4.gif", QSize(400, 400));

    ui->noth->setIcon(ic1);
    ui->noth->setIconSize(QSize(250, 250));
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
    choose = 0;
    ui->resul->hide();
    label->show();
    ui->label_Coin->hide();
    tim->start();
}

void MainWindow::Loading() {
    ui->label_Coin->hide();

    choose = 1;
    ui->resul->hide();
    label->show();
    tim->start();
}

void MainWindow::on_res_clicked()
{
    Loading();
}

void MainWindow::ontimout()
{
    fin = rand() % 2;
    ui->resul->show();
    ui->resul->setFont(f2);
    label->hide();

    if (fin == 0) {
        ui->label_Coin->setPixmap(QPixmap(":/images/c2.png").scaled(ui->label_Coin->width(), ui->label_Coin->height(), Qt::KeepAspectRatio));
    } else {
        ui->label_Coin->setPixmap(QPixmap(":/images/c3.png").scaled(ui->label_Coin->width(), ui->label_Coin->height(), Qt::KeepAspectRatio));
    }
    ui->label_Coin->show();  // Показываем изображение монетки после таймера

    if (fin == 0 && choose == 0) {
        ui->resul->setText("You WIN!");
    }
    if (fin == 0 && choose == 1) {
        ui->resul->setText("You LOSE!");
    }
    if (fin == 1 && choose == 1) {
        ui->resul->setText("You WIN!");
    }
    if (fin == 1 && choose == 0) {
        ui->resul->setText("You LOSE!");
    }
}
