#pragma once
#include <qwidget.h>
#include <qframe.h>
#include <qlabel.h>
#include <qboxlayout.h>
#include <qdebug.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qfont.h>
#include <qscrollbar.h>
#include <qtimer.h>
#include <qtextedit.h>
#include <qfontmetrics.h>
#include <qinputdialog.h>
#include <qscrollarea.h>


//
class ChatFrame :public QWidget {
    Q_OBJECT
    

public:
	explicit ChatFrame(QWidget* parent = nullptr) {

        page = new QWidget();
        pagelayout = new QVBoxLayout(page);
        pagelayout->setSpacing(6);
        pagelayout->setContentsMargins(11, 11, 11, 11);
        scrollarea = new QScrollArea(page);
        scrollarea->setWidgetResizable(true);
        content = new QWidget();
        messagelayout = new QVBoxLayout(content);
        messagelayout->setContentsMargins(11, 11, 11, 11);
		messagelayout->setAlignment(Qt::AlignTop);
        scrollarea->setWidget(content);
        pagelayout->addWidget(scrollarea);
        QMessageBox::information(nullptr, "H", "Created Frame");


	}

	void AddFMessage(QString message,bool sender) {
        ////Bot=0 User=1 :D
        
        QFrame* TextFrame = new QFrame(content);
        TextFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        TextFrame->setStyleSheet(QString::fromUtf8("background-color:#1f2023;"));
        TextFrame->setFrameShape(QFrame::StyledPanel);

        QHBoxLayout* TextLayout = new QHBoxLayout(TextFrame);
        TextLayout->setSpacing(6);
        TextLayout->setContentsMargins(10, 10, 10, 10);

        QFont font;
        font.setPointSize(14);

        QLabel* text = new QLabel(message);
        text->setMaximumWidth(scrollarea->width() * 0.8);
        text->setFont(font);
        text->setTextInteractionFlags(Qt::TextBrowserInteraction);
        text->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        text->setStyleSheet(QString::fromUtf8("color:#ffffff;"));

        QTimer::singleShot(10, this, [=]() {
            if (text->width() > scrollarea->width() * 0.7) 
            {
                text->setMinimumWidth(scrollarea->width() * 0.5);
                text->setWordWrap(true);
            }
            else 
            {
                text->setWordWrap(false);
            }
            });

        if (sender) {
            TextLayout->addWidget(text,0,Qt::AlignCenter);
            messagelayout->addWidget(TextFrame, 0, Qt::AlignRight);
        }
        else {
            TextLayout->addWidget(text, 0, Qt::AlignCenter);
            messagelayout->addWidget(TextFrame, 0, Qt::AlignLeft);
        }

        QTimer::singleShot(10, this, [=]() {
            QScrollBar* scrollbar = scrollarea->verticalScrollBar();
            scrollbar->setValue(scrollarea->verticalScrollBar()->maximum() - 1);
        });

	}
private:
    QWidget* content;
    QVBoxLayout* pagelayout;
    QVBoxLayout* messagelayout;
    QScrollArea* scrollarea;
    int id;

public:
    QWidget* page;
};


