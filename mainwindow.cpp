#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    w.show();
}
void MainWindow::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap("../xqxbjt"));
}
