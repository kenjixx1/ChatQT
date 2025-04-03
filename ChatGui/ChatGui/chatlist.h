#pragma once
#include <vector>
#include "ChatGui.h"
#include <iostream>
#include <qdebug.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qfont.h>

using namespace std;

class ChatList {
	vector<QPushButton*> list;
	int m_ID = 0;
	QString ActiveSS = "QPushButton{\n""background-color:#0c6ee9;\n""color: rgb(255, 255, 255);\n""border-radius:0px;\n""}\n""QPushButton::hover{\n""background-color:#0865c5;\n""}";


	QString DeactiveSS = "QPushButton{\n""background-color:#2aa5ff;\n""color: rgb(255, 255, 255);\n""border-radius:0px;\n""}\n""QPushButton::hover{\n""background-color:#0865c5;\n"
		"}";
 
	
public:
	void AddList(QPushButton* button) {
		list.push_back(button);
		m_ID++;
	}
	int GetMyID() {
		return m_ID;
	}

	int Size() {
		return list.size();
	}

	QPushButton* GetButtonByID(int id) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->property("ChatId").toInt() == id) {
				return list[i];
			}
		}
		return nullptr;
	}

	QPushButton* GetButton(int index) {
		if (0 <= index < list.size()) {
			return list[index];
		}
	}

	

	void Remove(int index) {
		vector<QPushButton*> templist;
		if (index <= m_ID and index >= 0) {
			for (int i = 0; i < list.size(); i++) {
				if (list[i]->property("ChatId").toInt()!= index) {
					templist.push_back(list[i]);
				}
			}
		}
		list = templist;
	}

	void SetActive(int id) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->property("ChatId").toInt() != id) {
				list[i]->setStyleSheet(DeactiveSS);
			}
			else {
				list[i]->setStyleSheet(ActiveSS);
			}
		}
	}
};
