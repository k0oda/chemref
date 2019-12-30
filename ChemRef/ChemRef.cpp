#include <iostream>
#include <fstream>
#include "json.hpp"

using namespace std;
using namespace nlohmann;

json get_element_by_symbol(string);
string get_input();
void output_element(json);

int main()
{
    string input;
    while (true)
    {
        input = get_input();
        json element = get_element_by_symbol(input);
        output_element(element);
    }
}

void output_element(json element)
{
    cout << "Name: " << element["name"] << endl;
    cout << "Symbol: " << element["symbol"] << endl;
    cout << "Appearance: " << element["appearance"] << endl;
    cout << "Atomic mass: " << element["atomic_mass"] << endl;
    cout << "Boil: " << element["boil"] << endl;
    cout << "Category: " << element["category"] << endl;
    cout << "Color: " << element["color"] << endl;
    cout << "Density: " << element["density"] << endl;
    cout << "Discovered by: " << element["discovered_by"] << endl;
    cout << "Melting point: " << element["melt"] << endl;
    cout << "Molar heat: " << element["molar_heat"] << endl;
    cout << "Named by: " << element["named_by"] << endl;
    cout << "Period: " << element["period"] << endl;
    cout << "Phase: " << element["phase"] << endl;
    cout << "Source: " << element["source"] << endl;
    cout << "Spectral image: " << element["spectral_img"] << endl;
    cout << "Summary: " << element["summary"] << endl;
    cout << "Shells: " << element["shells"] << endl;
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
