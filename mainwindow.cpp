#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"
#include "QDebug"
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
uint number=ui->lineEdit->text().toInt();
numberToText(number);
ui->lineEdit_2->setText(numberToText(number));
}
QString MainWindow::numberToText(uint number)
{
     static QMap<uint, QString> numbers;
    if (numbers.isEmpty())
     {
      numbers[0] = "zero";
      numbers[1] = "one";
      numbers[2] = "two";
      numbers[3] = "three";
      numbers[4] = "four";
      numbers[5] = "five";
      numbers[6] = "six";
      numbers[7] = "seven";
      numbers[8] = "eight";
      numbers[9] = "nine";
      numbers[10] = "ten";
      numbers[11] = "eleven";
      numbers[12] = "twelve";
      numbers[13] = "thirteen";
      numbers[14] = "fourteen";
      numbers[15] = "fifteen";
      numbers[16] = "sixteen";
      numbers[17] = "seventeen";
      numbers[18] = "eighteen";
      numbers[19] = "nineteen";
      numbers[20] = "twenty";
      numbers[30] = "thirty";
      numbers[40] = "forty";
      numbers[50] = "fifty";
      numbers[60] = "sixty";
      numbers[70] = "seventy";
      numbers[80] = "eighty";
      numbers[90] = "ninety";
     }

     static QMap<uint, QString> powers;

     //Only initialize once
     if (powers.isEmpty())
     {
      powers[2] = "hundred";
      powers[3] = "thousand";
      powers[6] = "million";
      powers[9] = "billion";
     }

     QString output;

     if (number < 21)
     {
      output = numbers[number];
     }
     else if (number < 100)
     {
      output = numbers[10 * qFloor(number / 10)];
      uint remainder = number % 10;

      if (remainder > 0)
       output += "-" + numberToText(remainder);
     }
     else
     {
      uint power = 2;
      uint place = 0;
      QString powerString;

      //QMap::keys is ordered
      foreach (uint pow, powers.keys())
      {
       uint place_value = qPow(10, pow);
       uint tmp_place = qFloor(number / place_value);
       if (tmp_place < 1)
        break;

       place = tmp_place;
       power = pow;
       powerString = powers[pow];
      }

      if (power > 0)
      {
       output = numberToText(place) + " " + powerString;
       uint remainder = number % uint(qPow(10, power));

       if (remainder > 0)
        output += " " + numberToText(remainder);
      }
     }
     return output;
}
