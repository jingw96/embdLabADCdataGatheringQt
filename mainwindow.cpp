#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "adc.h"
#include <sys/ioctl.h>

#define APP_VERSION "1.0.1"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "ADC data gathering: " << APP_VERSION;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//酒精传感器采集
void MainWindow::on_pushButton_alcohol_clicked()
{
    int fd;
    int data;
    char buf[32];
    fd = open("/dev/adc", O_RDWR);
    if (fd < 0) {
        perror("open");
    }
    ioctl(fd, SET_CHANNEL, ALCOHOL_CHANNEL);

    read(fd, &data, sizeof(data));
    sprintf(buf,"Vol: %0.2fV\n", 1.8 * data / 4096);
    QString alcohol_str(buf);
    ui->label_alcohol->setText(alcohol_str);
    ::close(fd);

}
//光敏传感器采集
void MainWindow::on_pushButton_light_clicked()
{
    int fd;
    int data;
    char buf[32];
    fd = open("/dev/adc", O_RDWR);
    if (fd < 0) {
        perror("open");
    }
    ioctl(fd, SET_CHANNEL, LIGHT_CHANNEL);

    read(fd, &data, sizeof(data));
    sprintf(buf,"Vol: %0.2fV\n", 1.8 * data / 4096);
    QString light_str(buf);
    ui->label_light->setText(light_str);
    ::close(fd);
}
//可燃气传感器采集
void MainWindow::on_pushButton_smoke_clicked()
{
    int fd;
    int data;
    char buf[32];
    fd = open("/dev/adc", O_RDWR);
    if (fd < 0) {
        perror("open");
    }
    ioctl(fd, SET_CHANNEL, SMOKE_CHANNEL);

    read(fd, &data, sizeof(data));
    sprintf(buf,"Vol: %0.2fV\n", 1.8 * data / 4096);
    QString smoke_str(buf);
    ui->label_smoke->setText(smoke_str);
    ::close(fd);
}
//火焰传感器采集
void MainWindow::on_pushButton_flame_clicked()
{
    int fd;
    int data;
    char buf[32];
    fd = open("/dev/adc", O_RDWR);
    if (fd < 0) {
        perror("open");
    }
    ioctl(fd, SET_CHANNEL, FLAME_CHANNEL);

    read(fd, &data, sizeof(data));
    sprintf(buf,"Vol: %0.2fV\n", 1.8 * data / 4096);
    QString flame_str(buf);
    ui->label_flame->setText(flame_str);
    ::close(fd);
}
