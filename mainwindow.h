#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QListView>
#include <QComboBox>
#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QDialog>
#include <QString>
#include <QStringList>
#include <QPropertyAnimation>
#include <QTimer>
#include <QIcon>
#include <QGraphicsOpacityEffect>
#include <QMovie>
#include<QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QMediaPlayer>
#include<QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMovie *movie;
    QLabel *label;


private slots:
    void on_orel_clicked();
    void on_res_clicked();
    void ontimout();
    void Loading();
    void updateBalanceDisplay();
    void on_setButton_clicked();
    bool isAbleToPlay();
    void on_pushButton_clicked();
    void on_progressBar_valueChanged(int value);
    void onloadout();
    void on_exitButton_clicked();
    void on_collectWinningsButton_clicked();



private:
    Ui::MainWindow *ui;
    int choose;
    int fin;
    double balance;
    double bet;
    int value;
    QTimer *tim;
    QFont f1;
    QFont f2;
    QIcon ic1;
    QIcon ic2;
    QIcon ic3;
    QIcon ic4;
    QPixmap pix;
    QLineEdit *balanceInput;
    QLineEdit *betInput;
    QTimer *timer;
    QMediaPlayer *player;
    QAudioOutput *audio;


};
#endif // MAINWINDOW_H
