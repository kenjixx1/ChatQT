#include "Session.h"


Session::Session(int id, const string& n, string& response, int l, const string& input, QWidget* parent) : id{ id }, load_size{ l }, QWidget{ parent } {
    string prompt = "You are a male AI assistant named Typhoon. Typhoon is happy to help with analysis, question answering, math, coding, creative writing, teaching, role-play, general discussion, and all sorts of other tasks. Typhoon responds directly to all human messages without unnecessary affirmations or filler phrases like “Certainly!”, “Of course!”, “Absolutely!”, “Great!”, “Sure!”, etc. Specifically, Typhoon avoids starting responses with the word “Certainly” in any way. Typhoon follows this information in all languages, and always responds to the user in the language they use or request. Typhoon is now being connected with a human. Write in fluid, conversational prose, Show genuine interest in understanding requests, Express appropriate emotions and empathy. Also showing information in terms that are easy to understand and visualized. The first system content is your prompt, and the rest is your previous responses for context. The last user content in the vector is your first priority.";
    history.push_back({
        {"role", "system"},
        {"content", prompt}
        });

    // Generate a title if it's a new session
    if (name == "" && input != "") {
        response = getResponse(input);
        string getTitle = "Give me a title to this conversation in the language the user used. Write only a noun, no more than three words if it's in English, but no more than a sentence if it's in Thai.";
        history.push_back({ {"role", "user"}, {"content", getTitle} });
        string title = getAIResponse(history);
        history.pop_back();
        name = title;
        cout << "Title: " << title << endl;
    }

	button = new QPushButton(parent);
	button->setText(QString::fromStdString(name));
	button->setMinimumSize(QSize(100, 35));
	button->setStyleSheet("QPushButton{\n""background-color:#2aa5ff;\n""color: rgb(255, 255, 255);\n""border-radius:0px;\n""}\n""QPushButton::hover{\n""background-color:#0865c5;\n""}");
	button->setFont(QFont("Arial", 12, QFont::Bold));
    button->setText(QString::fromStdString(name));
    
    
	connect(button, &QPushButton::clicked, this, [this]() {
        emit selected(this, page_index);
	});

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(button, 0, Qt::AlignTop);
    setLayout(mainLayout);
}

// Add a message to the history. If system is true, it's a system message; otherwise, it's a user message.
void Session::addHistory(const string& msg, bool system) {
    (system) ? history.push_back({ {"role", "system"}, {"content", msg} }): history.push_back({ {"role", "user"}, {"content", msg} });
}

// Construct a POST request to the chat model endpoint and process the response.
string Session::getAIResponse(const vector<json>& history) {
    CURL* curl;
    CURLcode res;
    string response;

    // My API Key
    string api_key = "sk-SwTRcVUVjSktbFl2A0nBPM2O7Hxeg1dtmU3Tu5BNR9ORNcXK";

    // JSON Request Body
    json requestData;
    requestData["model"] = "typhoon-v2-8b-instruct";
    requestData["messages"] = history;
    requestData["max_tokens"] = 1024;
    requestData["temperature"] = 0.6;
    requestData["top_p"] = 0.95;
    requestData["repetition_penalty"] = 1.05;
    requestData["stream"] = false;

    string requestDataStr = requestData.dump(); // Convert JSON to string

    // Initialize curl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + api_key).c_str());
        headers = curl_slist_append(headers, "Content-Type: application/json");

        // Set CURL options for POST request
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.opentyphoon.ai/v1/chat/completions");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestDataStr.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, requestDataStr.size());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &Session::WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }

        // Cleanup
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    // Parse and return response
    json jresponse = json::parse(response);
    string ai_response = "";

    if (!jresponse["choices"][0]["message"]["content"].is_null()) {
        ai_response += jresponse["choices"][0]["message"]["content"].get<string>();
    }
    else {
        ai_response = "[Error: No response received from AI]";
    }

    return ai_response;
}

string Session::getResponse(const string& input) {
    trimHistory();
    // Append user message to history
    history.push_back({ {"role", "user"}, {"content", input} });
    // Get AI response
    string response = getAIResponse(history);
    // Append AI response to history
    history.push_back({ {"role", "system"}, {"content", response} });
    return response;
}

// Estimate the total tokens of history
size_t Session::estimateToken(const vector<json>& history) {
    size_t totalToken = 0;
    for (const auto& message : history) {
        string content = message["content"];
        totalToken += content.size() / 4;
    }
    return totalToken;
}

// Erase the oldest chat history if the token is exceeded
void Session::trimHistory() {
    while (estimateToken(history) > MAX_TOKEN - SAFE_MARGIN && history.size() > 2) {
        history.erase(history.begin() + 1);
    }
}

// Change the name of the session
void Session::changeName(const string& n) {
	name = n;
	button->setText(QString::fromStdString(name));
}

// Handle data received from the server
size_t Session::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}