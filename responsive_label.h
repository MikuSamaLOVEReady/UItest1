//
// Created by twak on 14/10/2019.
//

#ifndef RESPONSIVELABEL_H
#define RESPONSIVELABEL_H


#include <QLabel>
#include <QString>
#include <map>

using namespace std;


// Please add to, but DO NOT modify the constants in this file.

// label names that are displayed
const QString
        kHomeLink       = "home",    //
        kBackButton     = "back",
        kShoppingBasket = "basket",   //
        kSignIn         = "sign-in",   //
        kNavTabs        = "navigation tabs",  //
        kFooter         = "fat footer",   //
        kAdvert         = "advert",  //
        kSearchButton   = "search",  //
        kSearchResult   = "result",     //
        kSearchText     = "search query", //
        kSearchForward  = ">",           //
        kSearchBackward = "<",           //
        KQRcode         = "QR code",
        KScroll         = "",
        kSearchOptions  = "search options"; //


// every label name has a colour
const map<QString, QString> kColours = {
        make_pair(kHomeLink,       "#ffaaff"),
        make_pair(kBackButton,     "#ffffaa"),
        make_pair(kShoppingBasket, "#ffaaaa"),
        make_pair(kSignIn,         "#aaffaa"),
        make_pair(kNavTabs,        "#ffa9d3"),
        make_pair(kFooter,         "#66ffaa"),
        make_pair(kAdvert,         "#ffaa66"),
        make_pair(kSearchButton,   "#aaffff"),
        make_pair(kSearchResult,   "#99ddff"),
        make_pair(kSearchText,     "#aaaaff"),
        make_pair(kSearchForward,  "#5caeff"),
        make_pair(kSearchBackward, "#5caeff"),
        make_pair(KQRcode,         "#4169E1"),
        make_pair(KScroll,         "#90EE90"),
        make_pair(kSearchOptions,  "#9dceff")
    };

class ResponsiveLabel : public QLabel {
public:
    ResponsiveLabel(QString name) ;   //一种只带名字的 label
    ResponsiveLabel(QString name, QString colour) ; //一种名字和颜色一起的label
};


#endif // RESPONSIVELABEL_H
