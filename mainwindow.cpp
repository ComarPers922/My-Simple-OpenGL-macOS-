#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    ui->glWidget->Rotate();
}

void MainWindow::on_btn_Right_clicked()
{
    ui->glWidget->Translate(false);
}

void MainWindow::on_btn_Left_clicked()
{
    ui->glWidget->Translate(true);
}
