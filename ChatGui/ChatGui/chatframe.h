#pragma once
#include <vector>
#include "ChatGui.h"
#include <iostream>
#include <qdebug.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qfont.h>

//
class ChatFrame :public QWidget {
	Q_OBJECT;
	QWidget* content;
	QVBoxLayout* messagelayout;
	QScrollArea* scrollarea;
	int id;

public:
	explicit ChatFrame(QWidget* parent = nullptr) {
		QVBoxLayout* mainlayout = new QVBoxLayout(this);

		scrollarea = new QScrollArea(this);
		scrollarea->setWidgetResizable(true);

		content = new QWidget(scrollarea);
		messagelayout = new QVBoxLayout(content);
		content->setLayout(messagelayout);
		scrollarea->setWidget(content);
		
	}

	void ScrollToButtom() {

	}

};


