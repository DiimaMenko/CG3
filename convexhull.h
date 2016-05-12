#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include "segment.h"
#include <QVector>

class ConvexHull
{
    QVector<Point* > _array;
    QVector<Point* > _hull;
    QVector<int> _hullIndexes;
public:
    ConvexHull();
    ConvexHull(QVector<Point* > array);
    void setArray(QVector<Point* > array);
    QVector<Point* > hull();
    QVector<int> hullIndexes();
    QVector<Point* > array();
    bool findConvexHull();
    bool isInHullIndexes(int k);
};

#endif // CONVEXHULL_H
