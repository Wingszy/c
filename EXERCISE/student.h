#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class student : public QObject
{
    Q_OBJECT
public:
    explicit student(QObject *parent = nullptr);
    //返回值void，需要声明也需要实现
    //可以有参数，可以发生重载
    void treat();

    void treat(QString foodName);

signals:

};

#endif // STUDENT_H
