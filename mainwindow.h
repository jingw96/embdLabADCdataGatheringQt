#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:


    void on_pushButton_alcohol_clicked();

    void on_pushButton_light_clicked();

    void on_pushButton_smoke_clicked();

    void on_pushButton_flame_clicked();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
