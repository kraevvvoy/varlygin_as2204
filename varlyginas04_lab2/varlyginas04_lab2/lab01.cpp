#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Pipe
{
    string name_pipe;
    double length;
    double diametr;
    bool under_repair;
};

struct Compressor_station
{
    string name_station;
    int number_workshop;
    int work_workshop;
    int performance;
};

void save(Pipe& p, Compressor_station& s)
{
    ofstream out;
    out.open("file.txt", ios::out);
    if (out.is_open() && p.name_pipe != "empty" && s.name_station != "empty")
    {
        out << "Name pipe: " << p.name_pipe << endl
            << "Length: " << p.length << endl
            << "Diametr: " << p.diametr << endl
            << "Repair: " << p.under_repair << endl;
        out << "Name station: " << s.name_station << endl
            << "Workshops: " << s.number_workshop << endl
            << "Work workshops: " << s.work_workshop << endl
            << "Performance: " << s.performance << endl;
        out.close();
    }
    else if (out.is_open() && p.name_pipe == "empty" && s.name_station == "empty")
    {
        out << "Name pipe: " << endl
            << "Length: " << endl
            << "Diametr: " << endl
            << "Repair: " << endl;
        out << "Name station: " << endl
            << "Workshops: " << endl
            << "Work workshops: " << endl
            << "Performance: " << endl;
        out.close();
    }
    else if (out.is_open() && p.name_pipe == "empty")
    {
        out << "Name pipe: " << endl
            << "Length: " << endl
            << "Diametr: " << endl
            << "Repair: " << endl;
        out << "Name station: " << s.name_station << endl
            << "Workshops: " << s.number_workshop << endl
            << "Work workshops: " << s.work_workshop << endl
            << "Performance: " << s.performance << endl;
        out.close();
    }
    else if (out.is_open() && s.name_station == "empty")
    {
        out << "Name pipe: " << p.name_pipe << endl
            << "Length: " << p.length << endl
            << "Diametr: " << p.diametr << endl
            << "Repair: " << p.under_repair << endl;
        out << "Name station: " << endl
            << "Workshops: " << endl
            << "Work workshops: " << endl
            << "Performance: " << endl;
        out.close();
    }

}

string split(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ':')
        {
            str.erase(0, i + 2);
            return str;
        }
    }
}

void download(Pipe& p, Compressor_station& s)
{
    ifstream file;
    string line;
    file.open("file.txt", ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.find("Name pipe: ") != string::npos)
            {
                p.name_pipe = split(line);
            }
            else if (line.find("Length: ") != string::npos)
            {
                p.length = stod(split(line));
            }
            else if (line.find("Diametr: ") != string::npos)
            {
                p.diametr = stod(split(line));
            }
            else if (line.find("Repair: ") != string::npos)
            {
                p.under_repair = stoi(split(line));
            }
            else if (line.find("Name station: ") != string::npos)
            {
                s.name_station = split(line);
            }
            else if (line.find("Workshops: ") != string::npos)
            {
                s.number_workshop = stoi(split(line));
            }
            else if (line.find("Work workshops: ") != string::npos)
            {
                s.work_workshop = stoi(split(line));
            }
            else if (line.find("Performance: ") != string::npos)
            {
                s.performance = stod(split(line));
            }
        }
        file.close();
        cout << "Successful download!" << endl;
        cout << "Press enter to continue" << endl;
    }
}

int number_or_letter()
{
    int number;
    while (true)
    {
        cin >> number;
        if (cin.fail() || number <= 0)
        {
            cout << "Please, enter a number above zero!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            return number;
        }
    }

}

int proverka(int nw)
{
    int ww;
    while (true)
    {
        ww = number_or_letter();
        if (nw < ww)
        {
            cout << "Work workshops more than workshops! Try again" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
            return ww;
        }

    }
}

bool check(string number) {
    for (int i = 0; i < number.length(); i++) {
        if (isdigit(number[i]) || number[i] == '-') continue;
        else return false;
    }
    if (number.length() == 0) return false;
    return true;
}

int main() {
    string buf;
    int number = 0;
    buf.clear();
    Pipe new_pipe;
    Compressor_station new_compressor;
    new_pipe.name_pipe = "empty";
    new_compressor.name_station = "empty";

    while (true)
    {
        cin.ignore(10000, '\n');
        cout << "1. Add a pipe" << endl
            << "2. Add a compressor station" << endl
            << "3. Watch all objects" << endl
            << "4. Edit a pipe" << endl
            << "5. Edit a compressor station" << endl
            << "6. Save" << endl
            << "7. Download from file" << endl
            << "8. Exit" << endl;
        getline(cin, buf);
        if (check(buf) == true)
        {
            number = stoi(buf);
        }
    }
    return(0);
}