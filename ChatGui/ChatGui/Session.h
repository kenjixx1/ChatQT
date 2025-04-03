#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using nlohmann::json;

const int MAX_TOKEN = 8192;
const int SAFE_MARGIN = 1024;

class Session {
    protected:
        int id;
        string name;
        int load_size;
        vector<json> history;

    public:
        explicit Session(int id, const string& n, string& response, int l = 0, const string& input = "");

        string getResponse(const string& input);
        string getAIResponse(const vector<json>& history);
        static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
        size_t estimateToken(const vector<json>& history);
        void trimHistory();

        int getHistorySize() { return history.size() - 1; }
};