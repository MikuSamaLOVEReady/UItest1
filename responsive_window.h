//
// Created by twak on 14/10/2019.
//

#ifndef RESPONSIVEWINDOW_H
#define RESPONSIVEWINDOW_H

#include <QWidget>
#include <QLayoutItem>
#include "responsive_layout.h"

using namespace std;

class ResponsiveWindow: public QWidget {

public:
    ResponsiveWindow();

protected:
    void createWidgets();
    void CreateScroll(ResponsiveLayout *lay);
    void SetScroll(QLayout *item,ResponsiveLayout *lay);
};


#endif //RESPONSIVEWINDOW_H
