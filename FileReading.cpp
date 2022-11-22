#include <iostream>
#include <fstream> // processing file stream types

#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void outputLine(int, const string &, double); // prototype

int main()
{
    // ifstream constructor opens the File
    ifstream inClientFile("clients.txt", ios::in);

    // exit program if ifstream could not open file

    if (!inClientFile)
    {
        cerr << "Unable to open the file!!" << endl;
        exit(EXIT_FAILURE);
    }

    cout << left << setw(10) << "Account" << setw(13) << "Name"
         << "Balance\n"
         << fixed << showpoint;

    int account;
    string name;
    double balance;

    // display each record in the file
    while (inClientFile >> account >> name >> balance)
    {
        outputLine(account, name, balance);
    }
    return 0;
}

void outputLine(int accountNo, const string &owner, double amount)
{
    cout << accountNo << " " << owner << " " << amount << endl;
}