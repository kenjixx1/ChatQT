#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <qwidget.h>
#include <qpushbutton.h>
#include "qboxlayout.h"
#include <qmessagebox.h>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using nlohmann::json;

const int MAX_TOKEN = 8192;
const int SAFE_MARGIN = 1024;

class Session: public QWidget {
	Q_OBJECT

private:
    int id;
    string name;
    int load_size;
    int page_index;
    vector<json> history;
	
    QString ActiveSS = "QPushButton{\n""background-color:#0c6ee9;\n""color: rgb(255, 255, 255);\n""border-radius:0px;\n""}\n""QPushButton::hover{\n""background-color:#0865c5;\n""}";
    QString DeactiveSS = "QPushButton{\n""background-color:#2aa5ff;\n""color: rgb(255, 255, 255);\n""border-radius:0px;\n""}\n""QPushButton::hover{\n""background-color:#0865c5;\n""}";

public:
    QPushButton* button;
    explicit Session(int id, const string& n, string& response, int l = 0, const string& input = "", QWidget* parent = nullptr);
	Session() = default;

    void addHistory(const string& msg, bool system);
    string getResponse(const string& input);
    string getAIResponse(const vector<json>& history);
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
    size_t estimateToken(const vector<json>& history);
    void changeName(const string& n);
    void trimHistory();

	string getName() { return name; }
	void activate() { this->setStyleSheet(ActiveSS); }
	void deactivate() { this->setStyleSheet(DeactiveSS); }
    int getLoadSize() { return load_size; }
    int getHistorySize() { return history.size() - 1; }
	int getID() { return id; }

signals:
	void selected(Session* session, int page);
};