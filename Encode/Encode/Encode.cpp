#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void SetLocale()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

string HtmlEncode(const string& text) 
{
    string result;
    for (char c : text)
    {
        switch (c) {
        case '"':
            result += "&quot;";
            break;
        case '\'':
            result += "&apos;";
            break;
        case '<':
            result += "&lt;";
            break;
        case '>':
            result += "&gt;";
            break;
        case '&':
            result += "&amp;";
            break;
        default:
            result += c;
            break;
        }
    }
    return result;
}

string HtmlDecode(const string& html) 
{
    string result;
    result.reserve(html.size());
    for (size_t i = 0; i < html.size(); ++i) 
    {
        if (html[i] == '&')
        {
            size_t entityEnd = html.find(';', i); 
            if (entityEnd != string::npos)
            {
                string entity = html.substr(i, entityEnd - i + 1);
                if (entity == "&quot;")
                    result += '"';
                else if (entity == "&apos;")
                    result += '\'';
                else if (entity == "&lt;")
                    result += '<';
                else if (entity == "&gt;")
                    result += '>';
                else if (entity == "&amp;")
                    result += '&';
                else
                    result += entity;
                i = entityEnd;
            }
            else 
            {
                result += '&';
            }
        }
        else 
        {
            result += html[i];
        }
    }
    return result;
}

int main()
{
    SetLocale();
    cout << "Выберите операцию:" << endl;
    cout << "1. Кодирование (Encode)" << endl;
    cout << "2. Декодирование (Decode)" << endl;

    int choice;
    cin >> choice;
    cin.ignore();

    string line;
    switch (choice) 
    {
    case 1:
        cout << "Введите текст для кодирования:" << endl;
        getline(cin, line);
        cout << "Результат кодирования:" << endl;
        cout << HtmlEncode(line) << endl;
        break;
    case 2:
        cout << "Введите HTML-код для декодирования:" << endl;
        getline(cin, line);
        cout << "Результат декодирования:" << endl;
        cout << HtmlDecode(line) << endl;
        break;
    default:
        cout << "Ошибка: неверный выбор операции." << endl;
        return 1;
    }

    return 0;
}
