#include "mainwindow.h"
#include <QApplication>
#include "TSelectUnion.h"
#include <iostream>
#include <cassert>

using namespace std;

void testList(QList<QString> list1, QList<QString> list2)
{
    auto iter1 = list2.begin();
    for (auto iter = list1.begin(); iter != list1.end(); iter++)
    {
        assert(*iter == *iter1);
        iter1++;
    }
}

void printListForTest(QList<QString> list1)
{
    for (auto iter = list1.begin(); iter != list1.end(); iter++)
    {
        qDebug() << *iter;
        //cout << *iter << '\n';
    }
}


int main(int argc, char *argv[])
{
    QList<selection<QString>> listAll;

    selection <QString> s1; 
        s1.arr.push_back("aaa");
        s1.arr.push_back("union1");
        s1.arr.push_back("ccc");
        s1.arr.push_back("union2");
        s1.len = 4;
        listAll.push_back(s1);

        selection <QString> s2; 
        s2.arr.push_back("a1");
        s2.arr.push_back("union1");
        s2.arr.push_back("union2");
        s2.arr.push_back("c1");
        s2.len = 4;

        selection <QString> s3;
        s3.arr.push_back("a2");
        s3.arr.push_back("union1");
        s3.arr.push_back("union2");
        s3.arr.push_back("c2");
        s3.len = 4;
        listAll.push_back(s3);

        //создаем объект класса для получения общего списка
        ListUnion<QString>* unionCreator = new ListUnion<QString>(listAll);

        const QList<selection<QString>> listAll1 = unionCreator->getArr();
        auto iter1 = listAll.begin();

        //тестируем конструктор
        for (auto iter = listAll1.begin(); iter != listAll1.end(); iter++)
        {
            testList(iter->arr, iter1->arr);
            iter1++;
        }

        ListUnion<QString>* unionCreator1 = new ListUnion<QString>();
        unionCreator1->setArr(listAll);
        const QList<selection<QString>> listAll2 = unionCreator->getArr();
     iter1 = listAll.begin();

     for (auto iter = listAll2.begin(); iter != listAll2.end(); iter++)
     {
        testList(iter->arr, iter1->arr);
        iter1++;
     }
    unionCreator1->addList(s3);
    listAll.push_back(s3);
    const QList<selection<QString>> listAll3 = unionCreator1->getArr();
    iter1 = listAll.begin();

    for (auto iter = listAll3.begin(); iter != listAll3.end(); iter++)
    {
        testList(iter->arr, iter1->arr);
        iter1++;
    }
    unionCreator->createUnion(); 
    QList<QString> forTest;
    forTest.push_back("union1");
    forTest.push_back("union2");

    testList(unionCreator->getResArr(), forTest); 

    QList<QString> res = unionCreator->getResArr();

    testList(res, forTest); 

    printListForTest(res); 


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
