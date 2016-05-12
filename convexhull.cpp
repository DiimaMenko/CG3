#include "convexhull.h"
#include <QDebug>

ConvexHull::ConvexHull()
{

}

ConvexHull::ConvexHull(QVector<Point *> array){
    this->_array = array;
    for(int i = 0; i < this->_array.size(); i++){
        QString tmp;
        tmp += QString::number(this->_array[i]->x()) + "; " + QString::number(this->_array[i]->y());
        qDebug(tmp.toUtf8());
    }
}

QVector<Point* > ConvexHull::array(){
    return this->_array;
}

QVector<Point* > ConvexHull::hull(){
    return this->_hull;
}

void ConvexHull::setArray(QVector<Point *> array){
    this->_array = array;
}

bool ConvexHull::isInHullIndexes(int k){
    for(int i = 0; i < this->_hullIndexes.size(); i++){
        if(k == this->_hullIndexes[i]){
            return true;
        }
    }
    return false;
}

bool ConvexHull::findConvexHull(){
    int minIndex = 0;
    int minAngleIndex = 0;
    for(int i = 0; i < this->_array.size(); i++){
        if(this->_array[i]->y() < this->_array[minIndex]->y()){
            minIndex = i;
        }
    }
    this->_hullIndexes.push_back(minIndex);
    Point *tempStartPoint = new Point(this->_array[minIndex]->x() - 1, this->_array[minIndex]->y());
    Segment *first = new Segment(tempStartPoint, this->_array[minIndex]);
    Segment *second;
    double minAngle = 3.14159265;
    if(minIndex){
        second = new Segment(this->_array[minIndex], this->_array[0]);
    }
    else{
        second = new Segment(this->_array[minIndex], this->_array[1]);
        minAngleIndex = 1;
    }

    for(int j = 0; j < this->_hullIndexes.size(); j++){
        for(int i = 0; i < this->_array.size(); i++){
            if(!isInHullIndexes(i)){
                second->setEnd(this->_array[i]);
                if(first->Angle(second) < minAngle)
                {
                    minAngle = first->Angle(second);
                    minAngleIndex = i;
                    qDebug() << minAngleIndex;
                }
            }
        }
        if(this->_hullIndexes.last() != minAngleIndex){
            this->_hullIndexes.push_back(minAngleIndex);
        }

        first = second;
        second->setEnd(this->_array[minAngleIndex]);
        second->setStart(first->getEnd());
    }

    return 1;
}

//bool ConvexHull::findConvexHull(){
//    this->_hullIndexes.push_back(0);
//    for(int i = 0; i < this->_array.size(); i++){
//        if(_array[i]->y() < _array[this->_hullIndexes[0]]->y()){
//            this->_hullIndexes[0] = i;
//        }
//    }
//    qDebug() << "start min:";
//    qDebug() << this->_hullIndexes[0];
//    qDebug() << "Array size:";
//    qDebug() << this->_array.size();
//    Point *tempPoint = new Point(this->_array[_hullIndexes[0]]->x() + 10, this->_array[_hullIndexes[0]]->y());
//    Segment *first = new Segment(this->_array[_hullIndexes[0]], tempPoint);
//    bool finished = false;
//    int k = 0;
//    Segment *newFirst = new Segment(0,0,0,0);
//    while(!finished){
//        int minimalIndex = 0;
//        double minimalAngel = 3.14159;
//        for(int i = 0; i < this->_array.size() - 1; i++){
//            if(i != this->_hullIndexes.last()){
//                Segment *second = new Segment(first->getStart(), this->_array[i]);
//                if(first->Angle(second) < minimalAngel){
//                    minimalAngel = first->Angle(second);
//                    minimalIndex = i;
//                    newFirst->setSegment(first->getEnd(), second->getEnd());
//                }
//                qDebug() << i;
//                qDebug() << first->Angle(second);
//                qDebug() << minimalAngel;
//                qDebug() << "------------------------------";
//            }
//        }
//        if(minimalIndex == _hullIndexes[0]){
//            finished = true;
//        }
//        else{
//            this->_hullIndexes.push_back(minimalIndex);
//            if(this->_hullIndexes.size() > 2){
//                first->setSegment(newFirst->getStart(), newFirst->getEnd());
//            }
//            else{
//                first->setSegment(first->getStart(), newFirst->getEnd());
//            }
//        }
//    }
//    return 1;
//}

QVector<int> ConvexHull::hullIndexes(){
    return this->_hullIndexes;
}
