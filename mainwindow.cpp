#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include<QUrl>
#include <QSettings>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , balance(0)
    , bet(0)
    ,timer(new QTimer(this))
    ,player(new QMediaPlayer(this))
    ,audio(new QAudioOutput(this))
{
    setFixedSize(800,600);
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    ui->widget->setStyleSheet("QLabel { color : yellow; }");
    ui->widget->setStyleSheet("QWidget#widget { border-image: url(:/images/загрузка.png) 0 0 0 0 stretch stretch; }");
    ui->widget->show();
    timer = new QTimer(ui->widget);
    timer->start(20);

    connect(timer, &QTimer::timeout, this, &MainWindow::onloadout);

    f1.setPointSize(16);
    f2.setPointSize(24);

    player->setAudioOutput(audio);
    player->setSource(QUrl("qrc:/images/мелодия.mp3"));
    player->play();
    player->setLoops(QMediaPlayer::Infinite);

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
    this->setStyleSheet("QWidget#centralwidget { border-image: url(:/images/фон.jpeg) 0 0 0 0 stretch stretch; }");

    tim = new QTimer(this);
    tim->setInterval(2000);
    tim->setSingleShot(true);
    QSettings settings("MyCompany", "MyApp");
    balance = settings.value("balance", 0).toDouble();

    connect(tim, &QTimer::timeout, this, &MainWindow::ontimout);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::on_exitButton_clicked);
    connect(ui->collectWinningsButton, &QPushButton::clicked, this, &MainWindow::on_collectWinningsButton_clicked);


    ic1.addFile(":/images/c1.png", QSize(250, 250));
    ic2.addFile(":/images/c2.png", QSize(250, 250));
    ic3.addFile(":/images/c3.png", QSize(250, 250));
    ic4.addFile(":/images/c4.gif", QSize(400, 400));

    ui->noth->setIcon(ic1);
    ui->noth->setIconSize(QSize(250, 250));
    ui->noth->setFlat(true);
    ui->noth->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->resul->hide();
    updateBalanceDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isAbleToPlay()
{
    return balance >= bet && bet > 0;
}

void MainWindow::Loading()
{
    if (isAbleToPlay()) {
        balance -= bet;
        updateBalanceDisplay();
        ui->resul->hide();
        label->show();
        ui->label_Coin->hide();
        tim->start();
    } else {
        ui->resul->setText("DEPOSIT!!!");
        ui->resul->show();
    }
    ui->orel->setEnabled(false);
    ui->res->setEnabled(false);
}

void MainWindow::on_orel_clicked()
{
    choose = 0;
    Loading();
}

void MainWindow::on_res_clicked()
{
    choose = 1;
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
    ui->label_Coin->show();

    if (fin == 0 && choose == 0) {
        ui->resul->setText("You WIN!");
        balance += bet * 1.8;
    } else if (fin == 1 && choose == 1) {
        ui->resul->setText("You WIN!");
        balance += bet * 1.8;
    } else {
        ui->resul->setText("You LOSE!");

    }
    updateBalanceDisplay();
    ui->orel->setEnabled(true);
    ui->res->setEnabled(true);
}

void MainWindow::updateBalanceDisplay()
{
    ui->label->setText("BALANCE: " + QString::number(balance));
}

void MainWindow::on_setButton_clicked()
{
    bool ok;
    double newBalance = ui->BalanceInput->text().toDouble(&ok);
    if (ok) {
        balance += newBalance;
        updateBalanceDisplay();
    } else {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid number for the balance.");
    }
}

void MainWindow::on_pushButton_clicked()
{
    bool ok;
    double newBet = ui->betInput->text().toDouble(&ok);
    if (ok && newBet > 0 && newBet <= balance) {
        bet = newBet;
        ui->orel->setEnabled(true);
        ui->res->setEnabled(true);
        updateBalanceDisplay();
    } else {
        QMessageBox::warning(this, "Invalid Bet", "Please enter a valid bet amount that is less than or equal to your current balance.");
    }
}

void MainWindow::on_progressBar_valueChanged(int value)
{

}
void MainWindow::onloadout(){
    if(ui->progressBar->value()==100){
        ui->progressBar->hide();
        ui->widget->hide();
    }
    ui->progressBar->setValue(ui->progressBar->value()+1);

}
void MainWindow::on_exitButton_clicked()
{
    QSettings settings("MyCompany", "MyApp");
    settings.setValue("balance", balance);
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit Game", "Do you want to take your winnings and exit?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

void MainWindow::on_collectWinningsButton_clicked()
{
    if (balance > 11) {
        QMessageBox::information(this, "Winnings Collected", "Your winnings have been collected successfully!");
        balance = 0;
        updateBalanceDisplay();
    }
}
