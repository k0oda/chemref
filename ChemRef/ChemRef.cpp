#include <iostream>
#include <fstream>
#include "json.hpp"

using namespace std;
using namespace nlohmann;

int main()
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
            cout << element.dump(4) << endl;
        }
        database.close();
    }
    else
    {
        cout << "Unable to load database";
    }
}
