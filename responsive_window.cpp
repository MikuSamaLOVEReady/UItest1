//
// Created by twak on 14/10/2019.
//

#include "responsive_window.h"
#include "responsive_layout.h"
#include "screenshot.h"
#include <iostream>
#include <QApplication>
#include <QScrollArea>
#include <QPushButton>
#include <QTextEdit>


ResponsiveWindow::ResponsiveWindow() {

    setWindowTitle("2811: Coursework 1");
    setMinimumSize(320, 50);  //最小最大尺寸

    createWidgets();
}

void ResponsiveWindow::createWidgets() {

    ResponsiveLayout * rl = new ResponsiveLayout();


    // add all the widgets we need to demonstrate all layouts

   // rl->addWidget(new ResponsiveLabel(kSearchButton));  button 换掉
   //we might have more than one search results
    rl->addWidget(new ResponsiveLabel(kShoppingBasket));
    rl->addWidget(new ResponsiveLabel(KQRcode));
    rl->addWidget(new ResponsiveLabel(kSignIn));
    rl->addWidget(new ResponsiveLabel(kHomeLink));
    // note that later widgets are drawn on top of earlier widgets
    ResponsiveLayout * rl1 = new ResponsiveLayout();


    //rl1->addWidget(new ResponsiveLabel(kSearchText));  Qtext 换掉
    rl1->addWidget(new ResponsiveLabel(kAdvert));
    rl1->addWidget(new ResponsiveLabel(kSearchOptions));
    rl1->addWidget(new ResponsiveLabel(kFooter));
    rl1->addWidget(new ResponsiveLabel(kNavTabs));

    rl1->addWidget(new ResponsiveLabel(kSearchResult));
    rl1->addWidget(new ResponsiveLabel(kSearchResult));
    rl1->addWidget(new ResponsiveLabel(kSearchResult));
    rl1->addWidget(new ResponsiveLabel(kSearchResult));
    rl1->addWidget(new ResponsiveLabel(kSearchResult));
    rl1->addWidget(new ResponsiveLabel(kSearchResult));
    rl1->addWidget(new ResponsiveLabel(kSearchResult));
    rl1->addWidget(new ResponsiveLabel(kSearchResult));
    rl1->addWidget(new ResponsiveLabel(kSearchResult));
    rl1->addWidget(new ResponsiveLabel(kSearchResult));
    rl1->addWidget(new ResponsiveLabel(kSearchResult));

    rl1->addWidget(new ResponsiveLabel(kSearchForward));
    rl1->addWidget(new ResponsiveLabel(kSearchBackward));


    CreateScroll(rl1);
    QVBoxLayout* layF = new QVBoxLayout();



    QHBoxLayout* lay2 = new QHBoxLayout();
    QPushButton *button2 =new QPushButton("push me");
   // button2->setStyle(QStyle())
    QTextEdit* Text2 =new QTextEdit();
    Text2->setMaximumHeight(25);
    lay2->addWidget(button2);
    lay2->addWidget(Text2);
     //  测试


     //这些特殊BOX 是被其中的 元素大小所限制了

    QGridLayout* lay1 = new QGridLayout();
    QPushButton *button =new QPushButton("push me");
    QTextEdit* Text1 =new QTextEdit();
    Text1->setMaximumHeight(25);
    //lay1->addStretch();
    lay1->addWidget(Text1,0,0);
    lay1->addWidget(button,0,1);
   // lay1->setRowMinimumHeight(0,25);

   // QVBoxLayout* layCombine = new QVBoxLayout();
   // layCombine->addLayout(lay1);
   // layCombine->addLayout(rl);





    //layF->addStretch(1);
   //layF->addLayout(lay2);
    //layF->addStretch(1);
    rl->setContentsMargins(0,0,0,0);

    //rl->maximumSize()
    //rl->maximumSize(QSize(320,120));
    //rl-> setMaximumHeight ()
    rl->setSizeConstraint(QLayout::SetMinimumSize);

    layF->addLayout(rl);     //最顶上一层
    layF->addLayout(lay1);  //搜索栏层


    layF->addLayout(rl1);  //最底层
  //  layF->addLayout(lay2);


    //lay2->setGeometry(QRect(0,0,200,200));

  //  layF->addLayout(rl1);
  // layF->insertLayout(1,lay2);



    //layF->addLayout(layCombine);


    setLayout(layF);

    // 只要我们设置了 setlayout  如果不加修改的话，就默认使用sizeHint()函数 来设置最合适的layout 大小来适应窗口
    // sizeHint() 返回 layout 的首选尺寸（97，45）供 widget（谁的layout） 参考
}

void ResponsiveWindow::CreateScroll(ResponsiveLayout *lay){
    ResponsiveLabel *label1 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label2 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label3 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label4 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *labelex1 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *labelex2 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label5 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label6 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label7 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label8 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *labelex3 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *labelex4 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label9  =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label10 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label11 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label12 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *labelex5 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *labelex6 =new ResponsiveLabel(kSearchResult);
    QHBoxLayout* layoutH3 = new QHBoxLayout();
    layoutH3->addWidget(label9);
    layoutH3->addWidget(label10);
    layoutH3->addWidget(label11);
    layoutH3->addWidget(label12);
    layoutH3->addWidget(labelex5);
    layoutH3->addWidget(labelex6);
    QHBoxLayout* layoutH2 = new QHBoxLayout();
    layoutH2->addWidget(label1);
    layoutH2->addWidget(label2);
    layoutH2->addWidget(label3);
    layoutH2->addWidget(label4);
    layoutH2->addWidget(labelex3);
    layoutH2->addWidget(labelex4);
    QHBoxLayout* layoutH1 = new QHBoxLayout();
    layoutH1->addWidget(label5);
    layoutH1->addWidget(label6);
    layoutH1->addWidget(label7);
    layoutH1->addWidget(label8);
    layoutH1->addWidget(labelex1);
    layoutH1->addWidget(labelex2);
    QVBoxLayout* layoutV  = new QVBoxLayout();
    layoutV->addLayout(layoutH2);
    layoutV->addLayout(layoutH1);
    layoutV->addLayout(layoutH3);
    SetScroll(layoutV,lay);
   // layoutV->setGeometry(QRect(0,0,50,60));
}

void ResponsiveWindow::SetScroll(QLayout *item,ResponsiveLayout *lay){
    ResponsiveLabel *Scroll_label = new ResponsiveLabel(KScroll);
    QScrollArea *scrollArea = new QScrollArea();
    QWidget* scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setLayout(item);
    scrollAreaWidgetContents->setGeometry(0,0,this->width()*2,this->height());   //(this->height())*0.15
    scrollArea->setWidget(scrollAreaWidgetContents);

    QHBoxLayout* ScrollLayout = new QHBoxLayout();
    ScrollLayout->addWidget(scrollArea);


    Scroll_label->setLayout(ScrollLayout);

    //Scroll_label->setGeometry(50,50,200,50);

    lay->addWidget(Scroll_label);


}

// please DO NOT edit this file beyond this line
int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    cout << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc, argv);

    // create a window. See respsonsive_window.cpp!  argc=2
    if (argc-1)  {
        // grading-mode - run the screenshot subclass
        Screenshot screenshot;
        screenshot.show();
        // wait for the app to terminate
        return app.exec();
    }
    //argc=1
    else {
        // interactive mode - run the regular superclass

        ResponsiveWindow window;
        //window.setLayout(lay1);
        window.show();
        // wait for the app to terminate
        return app.exec();
    }

}




/*
    ResponsiveLabel *Scroll_label = new ResponsiveLabel(KScroll);


    ResponsiveLabel *label1 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label2 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label3 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label4 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *labelex1 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *labelex2 =new ResponsiveLabel(kSearchResult);

    ResponsiveLabel *label5 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label6 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label7 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label8 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *labelex3 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *labelex4 =new ResponsiveLabel(kSearchResult);

    ResponsiveLabel *label9  =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label10 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label11 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *label12 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *labelex5 =new ResponsiveLabel(kSearchResult);
    ResponsiveLabel *labelex6 =new ResponsiveLabel(kSearchResult);



    QHBoxLayout* layoutH3 = new QHBoxLayout();
    layoutH3->addWidget(label9);
    layoutH3->addWidget(label10);
    layoutH3->addWidget(label11);
    layoutH3->addWidget(label12);
    layoutH3->addWidget(labelex5);
    layoutH3->addWidget(labelex6);


    QHBoxLayout* layoutH2 = new QHBoxLayout();
    layoutH2->addWidget(label1);
    layoutH2->addWidget(label2);
    layoutH2->addWidget(label3);
    layoutH2->addWidget(label4);
    layoutH2->addWidget(labelex3);
    layoutH2->addWidget(labelex4);

    QHBoxLayout* layoutH1 = new QHBoxLayout();
    layoutH1->addWidget(label5);
    layoutH1->addWidget(label6);
    layoutH1->addWidget(label7);
    layoutH1->addWidget(label8);
    layoutH1->addWidget(labelex1);
    layoutH1->addWidget(labelex2);


    //layoutH2->setGeometry(QRect(0,0,100,20));
    QVBoxLayout* layoutV  = new QVBoxLayout();
    layoutV->addLayout(layoutH2);
    layoutV->addLayout(layoutH1);
    layoutV->addLayout(layoutH3);
    //layoutV->setGeometry(QRect(0,0,50,60)); 无效果



    QScrollArea *scrollArea = new QScrollArea();
    QWidget* scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setLayout(layoutV);
    scrollAreaWidgetContents->setGeometry(0,0,this->width()*2,this->height());   //(this->height())*0.15
    scrollArea->setWidget(scrollAreaWidgetContents);

    QHBoxLayout* ScrollLayout = new QHBoxLayout();
    ScrollLayout->addWidget(scrollArea);


    Scroll_label->setLayout(ScrollLayout);

    Scroll_label->setGeometry(50,50,200,50);

    rl->addWidget(Scroll_label);
*/

//kHomeLink
//rl->addWidget(scrollArea);


