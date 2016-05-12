#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "convexhull.h"
#include <QLabel>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ConvexHull *someHull;
    QVector<QLabel* > pointsInView;
    QLabel *resultLabel;
};

#endif // MAINWINDOW_H
