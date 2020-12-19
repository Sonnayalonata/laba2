#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TSelectUnion.h"

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QString>

ListUnion<QString> *list1 = new ListUnion<QString>();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    QFile inputFile(QFileDialog::getOpenFileName());
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           while (!in.atEnd())
           {
               QString text = in.readLine();
              if (!text.isEmpty())
              {
                  qDebug() << text;

                  QList<QString> line = text.split(':');
                  selection<QString> sel;
                  sel.arr = line;
                  sel.len = line.size();

                  list1->addList(sel);
              }
           }

           inputFile.close();
        }
}

void MainWindow::on_pushButton_4_clicked()
{
    list1->createUnion();

    QFile file("output.txt");

    if (file.open(QIODevice::WriteOnly))
    {
        QList<QString> resArr = list1->getResArr();

        foreach( QString value, resArr)
        {
            file.write(value.toStdString().c_str());
            file.write("\n");
        }

        file.close();
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    QString res = "Исходный массив:\n";

    QList<selection<QString>> resArr = list1->getArr();

    foreach( selection<QString> val, resArr)
    {
        res += "Выбор сотрудника:\n";

        foreach( QString val, val.arr)
        {
            res += '\t' + val + '\n';
        }

        res += '\n';
    }

     ui->label->setText(res);
}

void MainWindow::on_pushButton_5_clicked()
{
    list1->createUnion();

    QString res = "Результат:\n";

    QList<QString> resArr = list1->getResArr();

    foreach( QString value, resArr)
    {
      res += value + '\n';
    }

     ui->label_2->setText(res);
}
