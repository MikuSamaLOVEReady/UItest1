//
// Created by twak on 07/10/2019.
//

#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>
#include <QScrollArea>
#include <QTextEdit>
#include <QPushButton>

using namespace std;

// you should probably make extensive changes to this function
void ResponsiveLayout::setGeometry(const QRect &r /* our layout should always fit inside r */ ) {

    QLayout::setGeometry(r);


    //QPushButton *button =new QPushButton("kSearchButton");
    //this->addWidget(button);

    //this->Window_Width_ =r.width();
    //this->Window_Height_=r.height();
    this->R_pass = r;
    int posi1 = r.y()+195-45;
    // for all the Widgets added in ResponsiveWindow.cpp
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) // null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;
            //搜索结果 手机
            else if (label -> text() == kSearchResult &&r.width()<600){
                posi1 =posi1+45;
                if (posi1<r.height()*0.725)
                {
                    label -> setGeometry(r.x()+5,posi1,r.width()-10, 40);
                }
                else{
                    label -> setGeometry (-1,-1,0,0);
                }
            }
            //前一页
            else if (label -> text() == kSearchBackward ) {
                if(r.height()>380)
                label->setGeometry( r.width() * 0.35, r.y() + r.height() - 65, r.width() * 0.1, 15);
                else{
                    label->setGeometry(r.x() + r.width() * 0.35, r.y() + r.height()*0.9, r.width() * 0.1, r.height()*0.1);
                }
            }
            //后一页
            else if (label -> text() ==  kSearchForward)
                if(r.height()>380)
                label -> setGeometry(r.x()+r.width()*0.55,r.y()+r.height()-65,r.width()*0.1, 15);
                else{
                    label->setGeometry(r.x() + r.width() * 0.55, r.y() + r.height()*0.9, r.width() * 0.1, r.height()*0.1);
                }
            //页脚
            else if (label -> text() == kFooter &&r.height()>380)
                label -> setGeometry(r.x()+r.width()*0.2,r.y()+r.height()-50,r.width()*0.6, 40);
            //额外 label二维码
            else if (label -> text() == KQRcode )
                label -> setGeometry(r.x()+r.width()*0.15+10,r.y(),r.width()*0.15, 35);
            //滚动区
            else if (label -> text() == KScroll &&r.width()>=600)
                label -> setGeometry(r.x()+r.width()*0.15,r.y()+165,r.width()*0.7, r.height()*0.5);
            // fixme: focus-group did not like this behaviour for the search result element.
           // else if (label -> text() == kSearchResult )
               // label -> setGeometry(rand() %(r.width()-60)+r.x(),rand() %(r.height()-100)+40+r.y(), 60, 60);
            else // otherwise: disappear label by moving out of bounds
                label -> setGeometry (-1,-1,0,0);
        }
        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }
        setPosition();
    }
}

void ResponsiveLayout::setPosition(){
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) // null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;
                //主页链接
           // kShoppingBasket  KQRcode  kSignIn  kHomeLink

            else if (label -> text() == kHomeLink ) // headers go at the top
                label -> setGeometry(R_pass.x()+5,R_pass.y(),R_pass.width()*0.15, 35);
                //导航栏
            else if (label -> text() == kNavTabs ) // headers go at the top
                label -> setGeometry(5+R_pass.x(),R_pass.y(),R_pass.width()-10, 25);  //这个位置指的 80
                //购物车标志
            else if(label -> text() == kShoppingBasket )
                label -> setGeometry(R_pass.width()*0.85+R_pass.x()-5,0+R_pass.y(),R_pass.width()*0.15, 35);
                //登陆标志
            else if(label -> text() == kSignIn )
                label -> setGeometry(R_pass.width()*0.70+R_pass.x()-10,+R_pass.y(),R_pass.width()*0.15, 35);
                //搜索按钮 only show a search button on small resolution, at the right of the window
            else if (label -> text() == kSearchButton )
                label -> setGeometry(R_pass.width()*0.85+R_pass.x()-5,R_pass.y()+40,R_pass.width()*0.15, 35);
                //搜索栏
            else if (label -> text() == kSearchText ) {
                //QHBoxLayout *serch_layout = new  QHBoxLayout();
                //QTextEdit* widget =new QTextEdit();
                //serch_layout->addWidget(widget);
                //serch_layout->set
                //label->findChild()
                //widget->setGeometry(0,0,100,10);
                //label->setLayout(serch_layout);
                label->setGeometry(R_pass.x() + 5, R_pass.y() + 40, R_pass.width() * 0.85 - 5 - 10, 35);
            }
                //广告区
            else if (label -> text() == kAdvert &&R_pass.width()<600)
                label -> setGeometry(R_pass.x()+5,R_pass.y()+110,R_pass.width()-10, 50);
                //搜索设置
            else if (label -> text() == kSearchOptions )
                label -> setGeometry(R_pass.x()+R_pass.width()*0.65-5,R_pass.y()+165,R_pass.width()*0.35, 25);
            else // otherwise: disappear label by moving out of bounds
                //label -> setGeometry (-1,-1,0,0);
                continue;
        }
        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }
    }
}

void ResponsiveLayout::setScroll(){
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) // null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;
                //搜索设置
            else if (label -> text() == kSearchOptions )
                label -> setGeometry(R_pass.x()+R_pass.width()*0.65-5,R_pass.y()+165,R_pass.width()*0.35, 25);

            else // otherwise: disappear label by moving out of bounds
                //label -> setGeometry (-1,-1,0,0);
                continue;
        }
        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }
    }
}


// following methods provide a trivial list-based implementation of the QLayout class
int ResponsiveLayout::count() const {
    return list_.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const {
    return list_.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx) {
    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item) {
    list_.append(item);
}

QSize ResponsiveLayout::sizeHint() const {
    return minimumSize();
}

QSize ResponsiveLayout::minimumSize() const {
    return QSize(320,520);
}



ResponsiveLayout::~ResponsiveLayout() {
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}


/*
           //主页链接
           else if (label -> text() == kHomeLink ) // headers go at the top
               label -> setGeometry(r.x()+5,r.y(),r.width()*0.15, 35);
           //导航栏
           else if (label -> text() == kNavTabs ) // headers go at the top
               label -> setGeometry(5+r.x(),5+75+r.y(),r.width()-10, 25);  //这个位置指的
           //购物车标志
           else if(label -> text() == kShoppingBasket )
               label -> setGeometry(r.width()*0.85+r.x()-5,0+r.y(),r.width()*0.15, 35);
           //登陆标志
           else if(label -> text() == kSignIn )
               label -> setGeometry(r.width()*0.70+r.x()-10,+r.y(),r.width()*0.15, 35);
           //搜索按钮 only show a search button on small resolution, at the right of the window
           else if (label -> text() == kSearchButton )
               label -> setGeometry(r.width()*0.85+r.x()-5,r.y()+40,r.width()*0.15, 35);
           //搜索栏
           else if (label -> text() == kSearchText )
               label -> setGeometry(r.x()+5,r.y()+40,r.width()*0.85-5-10, 35);
           //广告区
           else if (label -> text() == kAdvert )
               label -> setGeometry(r.x()+5,r.y()+110,r.width()-10, 50);
           //搜索设置
           else if (label -> text() == kSearchOptions )
               label -> setGeometry(r.x()+r.width()*0.65-5,r.y()+165,r.width()*0.35, 25);
           */