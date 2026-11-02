#ifndef CTUI_H
#define CTUI_H

#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <limits>


class TUIMenu {
    private:

    std::vector<std::pair<std::string, std::function<void()>>> options;
    bool is_selector;
    int choose;

    static void clear();
    static void err();
    static void enter();
    void show(const std::string& title = "");
    public:
    
    TUIMenu(std::vector<std::pair<std::string, std::function<void()>>> ops);
    TUIMenu(const std::vector<std::string>& ops);

    static int getInt(const std::string& prompt, int min, int max);
    static std::string getString(const std::string& prompt);
    int Run(const std::string& title = "");
    int getChoose() const;

    TUIMenu& operator=(const TUIMenu& other);
};

#endif