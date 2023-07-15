
#include <iostream>
#include <string>

class Bad_length : public std::exception
{
public:
    const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }
};

int func(std::string str, int forbidden_length) { 
    int length = str.length(); 
    if (length == forbidden_length) throw Bad_length();
    return length;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    int forbidden_length;
    char length;// Семантическая ошибка. Должен быть тип int.
    char c = 34;
    std::string str;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;
    try
    {
        while (true) {
            std::cout << "Введите слово: ";
            std::cin >> str// Синтаксическая ошибка. Пропущена ;.
            length = function(str, forbidden_length); // Ошибка линковки. Необходимо изменить function на func.
            std::cout << "Длина слова " << c << " " << str << " " << c << " равна " << length;
            std::cout << std::endl;
        }
    }
    catch (const Bad_length& ex) { std::cout << ex.what() << std::endl; }
    catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
}
