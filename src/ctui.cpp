#include "ctui.h"

void TUIMenu::clear() {
    std::cout << "\033[2J\033[1;1H";
}

void TUIMenu::enter() {
    std::cout << "Нажмите Enter для продолжения...";
    std::cin.get();
    clear();
}

void TUIMenu::err() {
    std::cout << "\nНеправильный ввод!\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    enter();
}

void TUIMenu::show(const std::string& ctx_title) {
    if (ctx_title != "") {std::cout << "=== " << ctx_title << " ===" << std::endl;}
    else if (title != "") {std::cout << "=== " << title << " ===" << std::endl;}

    for (int i = 0; i < int(options.size()); i++) {
        std::cout << i+1 << ". " << options[i].first << std::endl;
    }

    if (!is_selector) { std::cout << "0. Выход\nВаш выбор: "; }
}

TUIMenu::TUIMenu(std::vector<std::pair<std::string, std::function<void()>>> ops, const std::string& title)
    : title(title), options(ops), is_selector(0) {}

TUIMenu::TUIMenu(const std::vector<std::string>& string_options, const std::string& title)
    : title(title), is_selector(1)
{
    for (const auto& str : string_options) {
        options.push_back({str, [](){}}); 
    }
}

int TUIMenu::getInt(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt << " (" << min << "-" << max << "): ";
        if (!(std::cin >> value) || value < min || value > max) {
            err();
            continue;
        }
        break;
    }
    enter();
    return value;
}

std::string getString(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    std::getline(std::cin, value);
    return value;
}

int TUIMenu::Run(const std::string& ctx_title) {
    while (true) {
        show(ctx_title);
        if (!(std::cin >> choose) || choose < 0 || choose > int(options.size())) {
            err();
            continue;
        } else if (is_selector && choose == 0) { 
            err();
            continue;
        } else if (!is_selector && choose == 0) {break;}

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        clear();
        
        options[choose-1].second();

        if (is_selector) {break;} else {
            enter();
        }
    }
    return choose;
}

int TUIMenu::getChoose() const {
    return choose;
}

TUIMenu& TUIMenu::operator=(const TUIMenu& other) {
    if (this != &other) {
        title = other.title;
        options = other.options;
        is_selector = other.is_selector;
        choose = other.choose;
    }
    return *this;
}

TUIMenu& TUIMenu::operator=(const std::string& new_title) {
    if (this->title != new_title) {
        this->title = new_title;
    }
    return *this;
}

TUIMenu& TUIMenu::operator+(const std::vector<std::pair<std::string, std::function<void()>>> ops) {
    for (const auto& op : ops) {
        options.push_back(op);
    }
    return *this;
}

TUIMenu& TUIMenu::operator+(const std::vector<std::string>& opts) {
    for (const auto& opt : opts) {
        options.push_back({opt, [](){}});
    }
    return *this;
}
