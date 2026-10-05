#include "ctui"


void TUIMenu::clear() {
    cout << "\033[2J\033[1;1H";
}

void TUIMenu::enter() {
    cout << "Нажмите Enter для продолжения...";
    cin.get();
    clear();
}

void TUIMenu::err() {
    cout << "\nНеправильный ввод!\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    enter();
}

void TUIMenu::show() {
    if (title != "") {cout << "=== " << title << " ===" << endl;}

    for (int i = 0; i < int(options.size()); i++) {
        cout << i+1 << ". " << options[i].first << endl;
    }

    cout << "0. Выход\nВаш выбор: ";
}

TUIMenu::TUIMenu(const string& title, vector<pair<string, function<void()>>> ops)
    : title(title), options(ops) {}
TUIMenu::TUIMenu(vector<pair<string, function<void()>>> ops)
    : title(""), options(ops) {}

void TUIMenu::Run() {
    
    int choose = 0;
    
    while (true) {
        show();
        if (!(cin >> choose) || choose < 0 || choose > options.size()) {
            err();
            continue;
        } else if (choose == 0) {return;}
        clear();

        options[choose-1].second();
        enter();
    }
}