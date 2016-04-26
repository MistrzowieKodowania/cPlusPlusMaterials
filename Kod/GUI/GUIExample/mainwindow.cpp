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
    about = new AboutDialog(this);
    about->exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString mytext = ui->mainText->toPlainText();
    about = new AboutDialog(this);
    about->aboutText->setText(mytext);
    about->exec();
}
