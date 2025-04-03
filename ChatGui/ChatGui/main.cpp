#include "ChatGui.h"
#include <QtWidgets/QApplication>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    qDebug() << "HellloPeople";
    QApplication a(argc, argv);
    ChatGui w;
    w.show();
    return a.exec();



//    qApp->setStyleSheet(R"(
//QScrollBar:vertical {
//    background: transparent;
//    width: 8px;
//    margin: 0px;
//}
//
//QScrollBar::handle:vertical {
//    background: #0c6ee9;
//    border-radius: 4px;
//    min-height: 20px;
//}
//
//QScrollBar::add-line:vertical,
//QScrollBar::sub-line:vertical {
//    height: 0px;
//}
//
//QScrollBar::add-page:vertical,
//QScrollBar::sub-page:vertical {
//    background: none;
//}
//
//)");


}
