#include "ctui"

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

void TUIMenu::show() {
    if (title != "") {std::cout << "=== " << title << " ===" << std::endl;}

    for (int i = 0; i < int(options.size()); i++) {
        std::cout << i+1 << ". " << options[i].first << std::endl;
    }

    std::cout << "0. Выход\nВаш выбор: ";
}

TUIMenu::TUIMenu(const std::string& title, std::vector<std::pair<std::string, std::function<void()>>> ops)
    : title(title), options(ops) {}

TUIMenu::TUIMenu(std::vector<std::pair<std::string, std::function<void()>>> ops)
    : title(""), options(ops) {}

void TUIMenu::Run() {
    
    int choose = 0;
    
    while (true) {
        show();
        if (!(std::cin >> choose) || choose < 0 || choose > int(options.size())) {
            err();
            continue;
        } else if (choose == 0) {return;}
        clear();

        options[choose-1].second();
        enter();
    }
}