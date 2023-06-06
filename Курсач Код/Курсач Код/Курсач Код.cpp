#include<iostream>
#include <vector>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    vector <string> shopcart; //Вектор для зберігання товарів у кошику
    int choice = 0;
    while (choice <= 5) // Головний цикл програми
    {
        cout << "\n |МАГАЗИН ІГРАШОК| ";
        cout << "\n 1. Магазин ";
        cout << "\n 2. Кошик ";
        cout << "\n 3. Замовлення";
        cout << "\n 4. Вихід ";
        cout << "\n-----------------";
        cout << "\n Вибрати дію:";
        cin >> choice;
        switch (choice)
        {
        case 1: cout << " |КАТАЛОГ|";
            cout << "\n 1) Лего - 500 грн (вік: 3-99р, к.виробник: Китай, матер: пластик) ";
            cout << "\n 2) Лялька - 300 грн (вік: 1-99р, к.виробник: США, матер: такнина) ";
            cout << "\n 3) Робот - 450 грн (вік: 8-99р, к.виробник: Китай, матер: пластик)";
            cout << "\n 4) Олівці - 150 грн (вік: 3-99р, к.виробник: Україна, матер: дерево)";
            cout << "\n 5) М'яч - 200 грн (вік: 2-99р, к.виробник: Україна, матер: пластик)";
            cout << "\n 1. Додати в кошик ";
            cout << "\n 2. Головне меню ";
            cout << "\n-----------------";
            cout << "\n Вибрати дію:";
            cin >> choice;
            switch (choice)
            {
            case 1: {
                cout << "Введіть номер товару: ";
                int toychoice;
                cin >> toychoice;
                string toy;
                switch (toychoice)
                {
                case 1:toy = "Лего - 500 грн";
                    break;
                case 2: toy = "Лялька - 300 грн";
                    break;
                case 3:toy = "Робот - 450 грн";
                    break;
                case 4: toy = "Олівці - 150 грн";
                    break;
                case 5: toy = "М'яч - 200 грн";
                    break;
                default:
                    cout << "Некоректний вибір!";
                    continue;
                }
                shopcart.push_back(toy); // Додати вибраний товар до кошика
                cout << toy << " додано до кошика";
                break;
            }
            case 2:
                break;
            default: cout << " Помилка ! \n";
                break;
            }
            break;

        case 2: cout << " |КОШИК|";
            if (shopcart.empty())
            {
                cout << "\n Немає товарів";
            }
            else
            {
                cout << "\n Товари в кошику: ";
                for (int i = 0; i < shopcart.size(); i++)
                {
                    cout << i + 1 << ") " << shopcart[i];
                }
            }
            cout << "\n 1. Видалити товар з кошика ";
            cout << "\n 2. Головне меню ";
            cout << "\n-----------------";
            cout << "\n Вибрати дію:";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                if (shopcart.empty())
                {
                    cout << "\n Кошик порожній";
                }
                else
                {
                    int toynom;
                    cout << "Виберіть номер товару для видалення: ";
                    cin >> toynom;
                    if (toynom >= 1 && toynom <= shopcart.size())
                    {
                        string removedToy = shopcart[toynom - 1];
                        shopcart.erase(shopcart.begin() + (toynom - 1)); // Видалити вибраний товар з кошика
                        cout << removedToy << " видалено з кошика";
                    }
                    else
                    {
                        cout << "Некоректний вибір!";
                    }
                }
                break;
            }
            case 2:
                break;
            default: cout << " Помилка ! \n";
                break;
            }
            break;
        case 3: cout << " |ЗАМОВЛЕННЯ|";
            if (shopcart.empty())
            {
                cout << "\n Кошик порожній ";
            }
            else
            {
                cout << "\n Ваше замовлення:";
                for (int i = 0; i < shopcart.size(); i++)
                {
                    cout << i + 1 << ") " << shopcart[i];
                }
                shopcart.clear(); // Очистити кошик після замовлення
                cout << "Товар замовлено";
                break;
            }
            break; 
        case 4:
            break;
        default: cout << " Помилка ! \n";
        }
        break;
    }
    cout << " \n До побачення ! ";
    return 0;
}