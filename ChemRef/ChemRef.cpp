#include <iostream>
#include <fstream>
#include "json.hpp"

using namespace std;
using namespace nlohmann;

json get_element_by_symbol(string symbol);

int main()
{
    string input;
    while (true)
    {
        cout << "> ";
        cin >> input;
        system("cls");
        json element = get_element_by_symbol(input);
        cout << element << endl;
    }
}

json get_element_by_symbol(string symbol)
{
    ifstream database;
    database.open("periodic_table.json", ios::in);

    if (database.is_open())
    {
        string line;
        json element;

        while (getline(database, line))
        {
            element = json::parse(line);
            if (element["symbol"] == symbol)
            {
                database.close();
                return element;
            }
        }
        database.close();
    }
    else
    {
        cout << "Unable to load database";
    }
}
