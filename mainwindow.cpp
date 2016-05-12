#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(640, 480);
    this->setStyleSheet("QMainWindow {background-color: white;}");

    QVector<Point* > temp;

    Point *tempP0 = new Point(6,  1);
    temp.push_back(tempP0);
    Point *tempP1 = new Point(12,  4);
    temp.push_back(tempP1);
    Point *tempP2 = new Point(9,  5);
    temp.push_back(tempP2);
    Point *tempP3 = new Point(9,  9);
    temp.push_back(tempP3);
    Point *tempP4 = new Point(4,  8);
    temp.push_back(tempP4);
    Point *tempP5 = new Point(7,  5);
    temp.push_back(tempP5);
    Point *tempP6 = new Point(10,  6);
    temp.push_back(tempP6);
    Point *tempP7 = new Point(11,  1);
    temp.push_back(tempP7);

    for(int i = 0; i < temp.size(); i++){
        QLabel *tempLabel = new QLabel(this);
        tempLabel->setText(" " + QString::number(i));
        tempLabel->move(temp[i]->x() * 20 + 20, temp[i]->y() * 20 + 20);
        tempLabel->resize(15, 15);
        tempLabel->setStyleSheet("QLabel{background-color: black; color: white; border-radius: 7px}");
        tempLabel->show();
        this->pointsInView.push_back(tempLabel);
    }

    this->someHull = new ConvexHull(temp);

    QString resultOutput;
    if(this->someHull->findConvexHull()){
        for(int i = 0; i < this->someHull->hullIndexes().size(); i++){
            resultOutput += QString::number(this->someHull->hullIndexes()[i]) + ", ";
        }
    }

    qDebug(resultOutput.toUtf8());
    this->resultLabel = new QLabel(resultOutput, this);
    this->resultLabel->resize(200, 20);
    this->resultLabel->move(20, this->height() - 30);
    this->resultLabel->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
