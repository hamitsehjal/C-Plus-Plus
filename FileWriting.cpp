// CREATING A SEQUENTIAL FILE!!

#include <iostream>
#include <string>
#include <fstream> // contains file streaming types
#include <cstdlib> //exit function prototypes

using namespace std;

int main()
{
    // 1. ios::in allows input(read operations) from a stream.
    // 2. ios::out allows output (write operations) to a stream.

    // 3. | (bitwise OR operator) is used to combine the two ios flags,
    // meaning that passing ios::in | ios::out to the constructor
    // of std::fstream enables both input and output for the stream.

    // 1. std::ifstream automatically has the ios::in flag set.
    // 2. std::ofstream automatically has the ios::out flag set.
    // 3. std::fstream has neither ios::in or ios::out automatically
    // set.

    // ofstream outClientFile{"clients.txt", ios ::out};  // FIRST WAY

    // SECOND - WAY
    ofstream outClientFile;
    outClientFile.open("clients.txt", ios ::ate);

    //** IMPORTANT --> the overload ios operator "!" returns ture if either the "failbit" or "badbit" is set for the streaml
    // exit program if unable to create file
    if (!outClientFile) // overloaded ! operator
    {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enter the account,name, and balance. \n"
         << "Enter end-of-file to end input. \n? ";

    int account;    // account number
    string name;    // account owner's name
    double balance; // the account balance

    // reading values of account, name, and balance from cin

    // using the Return Value of a stream Extraction a a Condition!!
    // Reference:
    //     1. StackOverflow: https://stackoverflow.com/questions/15202697/using-return-value-of-extraction-operator-in-condition
    //     3. Book: Pg-582 - How to Program C++ ( Harvey and Paul Dietal)

    while (cin >> account >> name >> balance)
    {

        outClientFile
            << account << " " << name << " " << balance << endl;
        cout << "?";
    }
    outClientFile.close();
    return 0;
}