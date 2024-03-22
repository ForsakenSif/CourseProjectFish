#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <windows.h>
#include <conio.h>
#include<array>

using namespace std;

// Базовый класс рыба
class Fish {
protected:
    string name;
    string description;

public:
    Fish(const string& n,const string& d) : name(n), description(d) {} // Конструктор
    virtual ~Fish() {}
    virtual void display() const = 0; // Виртуальная функция для отображения информации о рыбе

    string getName() {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }

    string getDescription() {
        return description;
    }
    void setDescription(string description) {
        this->description = description;
    }
};

// Дочерний класс для подвида рыб
class FreshwaterFish : public Fish {
    string type;
public:
    FreshwaterFish(const string& n, const string& d, const string& t = "Пресноводная") : Fish(n, d), type(t) {} // Конструктор
    void display() const override {
        cout << "Рыба: " << name << endl << "Тип: " << type << endl << "Описание: " << description << endl;
    }

    string getType() {
        return type;
    }
    void setType(string type) {
        this->type = type;
    }

};

// Дочерний класс для подвида рыб
class MarineFish : public Fish {
    string type;
public:
    MarineFish(const string& n, const string& d, const string& t = "Морская") : Fish(n, d), type(t) {} // Конструктор
    void display() const override {
        cout << "Рыба: " << name << endl << "Тип: " << type << endl << "Описание: " << description << endl;
    }

    string getType() {
        return type;
    }
    void setType(string type) {
        this->type = type;
    }
};



void showAddMenu() {

    cout << "=== Добавление новой рыбы ===" << endl;

    cout << "Какого типа рыба?" << endl;
    cout << "1 - Пресноводная" << endl;
    cout << "2 - Морская" << endl;

}


void showMainMenu() {

    cout << endl;
    cout << "========== РЫБЫ ==========" << endl;
    cout << "1 - Список" << endl;
    cout << "2 - Добавить новую рыбу" << endl;
    cout << "3 - Удалить рыбу из списка" << endl;
    cout << "4 - Выход" << endl;
}



int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");
    std::wstring wstr;

    int choice;
    string number;
    string code;
    int productChoice;
    vector<Fish*> fishes;
    string fishName;
    string fishDescription;
    string type;
    string inputAdminPass;
    vector<Fish*> fishList;
    string userName;

    fishList.push_back(new FreshwaterFish("Карась","Не имеет усов. Неприхотлив, может жить в грязной воде."));
    fishList.push_back(new FreshwaterFish("Щука", "Одна из крупных рыб. Удлинённое тело, большая голова."));
    fishList.push_back(new MarineFish("Скумбрия", "Одна из самых популярных видов рыб, используемых человеком в промысле."));
    fishList.push_back(new MarineFish("Камбала", "Плоская, как блин, всегда лежит на дне."));
    do {


        showMainMenu();
        
        cout << endl << ">>";
        cin >> choice;




        switch (choice) {

        case 1:


            system("CLS");

            for (size_t i = 0; i < fishList.size(); ++i) {
                cout << endl;
                cout << i + 1 << ". ";
               fishList[i]->display();

            }

            break;


        case 2:

            system("CLS");
            showAddMenu();


            cout << endl << ">>";
            cin >> choice;

            if (choice == 1) {

                cout << "Название: ";
                std::cin.ignore(32767, '\n');
                getline(cin, fishName);
                cout << "Описание: ";
                getline(cin, fishDescription);


                fishList.push_back(new FreshwaterFish(fishName, fishDescription));
                system("CLS");
                cout << endl << "|Рыба успешно добавлена в список|";
            }
            else if (choice == 2) {
                cout << "Название: ";
                std::cin.ignore(32767, '\n');
                getline(cin, fishName);
                cout << "Описание: ";
                getline(cin, fishDescription);


                fishList.push_back(new MarineFish(fishName, fishDescription));
                system("CLS");
                cout << endl << "|Рыба успешно добавлена в список|";
            }
            else {
                cout << "Ошибка ввода!" << endl;
            }
            
            
     
            break;

        case 3:

            system("CLS");
            cout << "===== Удаление рыбы =====" << endl;
            for (size_t i = 0; i < fishList.size(); ++i) {
                cout << endl;
                cout << i + 1 << ". ";
                fishList[i]->display();

            }
            cout << endl;
            cout << endl;
            if (fishList.empty()) {
                system("CLS");
                cout << "Рыб нет" << endl;
                choice = 0;
                break;
            }


            int index;
            cout << "Выберите индекс рыбы, которую необходимо убрать из списка:";
            cout << endl << ">>";
            cin >> index;
            if (index >= 1 && index <= fishList.size()) {
                delete fishList[index - 1];
                fishList.erase(fishList.begin() + index - 1);

                system("CLS");
                cout << endl << "|Рыба успешно убрана из списка|";
            }
            else {
                cout << "Ошибка ввода" << endl;
            }
            break;



        };



    } while (choice != 4);

    return 0;
}
