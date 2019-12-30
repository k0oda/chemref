#include <iostream>
#include <fstream>
#include "json.hpp"

using namespace std;
using namespace nlohmann;

json get_element_by_symbol(string symbol);
string get_input();

int main()
{
    string input;
    while (true)
    {
        input = get_input();
        json element = get_element_by_symbol(input);
        cout << element << endl;
    }
}

string get_input()
{
    string input;
    cout << "Enter element symbol to get full description of element or Q/q to exit" << endl;
    cout << "> ";
    cin >> input;
    
    if (input == "Q" || input == "q")
    {
        exit(0);
    }

    system("cls");

    return input;
}

json get_element_by_symbol(string symbol)
{
    ifstream database;
    database.open("PeriodicTableJSON.json", ios::in);

    if (database.is_open())
    {
        json elements = json::parse(database)["elements"];
        for (int i = 0; i < elements.size(); i++)
        {
            if (elements.at(i)["symbol"] == symbol)
            {
                database.close();
                return elements.at(i);
            }
        }
        database.close();
    }
    else
    {
        cout << "Unable to load database";
    }
}
