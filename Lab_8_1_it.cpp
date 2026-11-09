#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція підраховує кількість пар "SQ" або "QS"
int Count(char* str)
{
    size_t len = strlen(str);

    int k = 0;

    for (size_t i = 0; i + 1 < len; i++)
    {
        if ((str[i] == 'S' && str[i + 1] == 'Q') ||
            (str[i] == 'Q' && str[i + 1] == 'S'))
        {
            k++;
        }
    }

    return k;
}

// Функція замінює кожну пару "SQ" або "QS" на "***"
char* Change(char* str)
{
    size_t len = strlen(str);

    char* tmp = new char[len * 2 + 1];

    size_t i = 0;
    size_t j = 0;

    while (i < len)
    {
        if (i + 1 < len &&
            ((str[i] == 'S' && str[i + 1] == 'Q') ||
                (str[i] == 'Q' && str[i + 1] == 'S')))
        {
            tmp[j++] = '*';
            tmp[j++] = '*';
            tmp[j++] = '*';

            i += 2;
        }
        else
        {
            tmp[j++] = str[i++];
        }
    }

    tmp[j] = '\0';

    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str)
        << " groups of 'SQ' or 'QS'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param): " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;

    return 0;
}