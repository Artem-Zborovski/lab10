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

private slots:
    void on_orel_clicked();

    void on_res_clicked();
    void ontimout();

private:
    Ui::MainWindow *ui;
    int choose;
    int fin;
    QTimer *tim;
    QFont f1; //16
    QFont f2; //24
    QIcon ic1;
    QIcon ic2;
    QIcon ic3;

};
#endif // MAINWINDOW_H
