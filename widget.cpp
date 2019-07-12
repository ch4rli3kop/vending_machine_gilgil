#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <stdio.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    check();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::check(){
    if (money < 100) {
        ui->pbCoffee->setEnabled(false);
        ui->pbCocoa->setEnabled(false);
        ui->pbTea->setEnabled(false);
    } else if (100 <= money && money < 150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbCocoa->setEnabled(false);
    } else if (150 <= money && money < 200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCocoa->setEnabled(false);
    } else {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCocoa->setEnabled(true);
    }
}
void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number(money));
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    check();
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
    check();
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
    check();
}

void Widget::on_pb500_clicked(){
    changeMoney(500);
    check();
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    check();
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    check();
}

void Widget::on_pbCocoa_clicked()
{
    changeMoney(-200);
    check();
}

void Widget::on_pbReturn_clicked()
{
    QMessageBox msg;
    int a = money/500;
    money %= 500;
    int b = money/100;
    money %= 100;
    int c = money/50;
    money %= 50;
    int d = money/10;

    char str[100];
    std::sprintf(str, "Return result :\n500 : %d\n100 : %d\n50 : %d\n10 : %d", a, b, c, d);
    msg.information(nullptr, "Return", str);
}
