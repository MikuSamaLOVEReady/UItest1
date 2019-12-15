//
// Created by twak on 07/10/2019.
//

#ifndef RESPONSIVELAYOUT_H
#define RESPONSIVELAYOUT_H

#include <QtGui>
#include <QList>
#include <QLayout>

class ResponsiveLayout : public QLayout
{
public:
    ResponsiveLayout(): QLayout() {} //这个表示  ResponsiveLayout的构造函数 是空的， 但是在实体化自己的时候 调用的父类的构造函数。
    ~ResponsiveLayout();

    // standard functions for a QLayout           //virtual void	setGeometry(const QRect &r) override
    void setGeometry(const QRect &rect);
    void setPosition();
    void setScroll();

    void addItem(QLayoutItem *item);           // 同样也是重写 父类

    QSize sizeHint() const;
    QSize minimumSize() const;
   // QSize maximumSize() cosnt;
    int count() const;                          //
    QLayoutItem *itemAt(int) const;
    QLayoutItem *takeAt(int);

    int Window_Width_,Window_Height_;
    QRect R_pass;

   // QScrollArea *scrollArea = new QScrollArea();

private:
    QList<QLayoutItem*> list_;
};
#endif // RESPONSIVELAYOUT_H
