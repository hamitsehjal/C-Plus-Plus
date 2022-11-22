// Case Study: CREDIT INQUIRY PROGRAM

//
//*** IMPORTANT: enumerators
// Each enumerator is associated with a value of the underlying type. When initializers are provided in the enumerator-list,
// the values of enumerators are defined by those initializers. If the first enumerator does not have an initializer,
// the associated value is zero. For any other enumerator whose definition does not have an initializer, the associated value is the value of the previous enumerator plus one.

#include <iostream>
#include <iomanip> // for manipulating the output
#include <fstream> // processing file streaming types
#include <cstdlib> // it contains exit function prototype
#include <string>

using namespace std;

enum class RequestType
{
    ZERO_BALANCE = 1,
    CREDIT_BALANCE,
    DEBIT_BALANCE,
    END
};

bool shouldDisplay(RequestType, double);
void outputLine(int, const string &, double);
RequestType getRequest();
int main()
{
    ifstream inClientfile{"clients.txt", ios::in};

    // IN CASE WE AREN'T TO ACCESS THE FILE
    if (!inClientfile)
    {
        cerr << "Unable to open the File!!" << endl;
        exit(EXIT_FAILURE);
    }

    // Get users request
    RequestType request{getRequest()};

    // process "User's Request"
    while (request != RequestType::END)
    {
        switch (request)
        {
        case RequestType::ZERO_BALANCE:
            cout << "Accounts with zero balances:" << endl;
            break;
        case RequestType::CREDIT_BALANCE:
            cout << "Accounts with credit balances:" << endl;
            break;
        case RequestType::DEBIT_BALANCE:
            cout << "Accounts with debit balances:" << endl;
            break;
        case RequestType::END:
            cout << "End of run" << endl;
            break;

        default:
            break;
        }

        int account;
        string owner;
        double balance;

        // inClientfile >> account >> owner >> balance;
        while (inClientfile >> account >> owner >> balance)
        {
            if (shouldDisplay(request, balance))
                outputLine(account, owner, balance);

            // inClientfile >> account >> owner >> balance;
        }

        inClientfile.clear();  // reset the eof for next input
        inClientfile.seekg(0); // reposition to the beginning of the file
        request = getRequest();
    }
}

bool shouldDisplay(RequestType request, double amount)
{
    if (request == RequestType::ZERO_BALANCE && amount == 0)
        return true;
    if (request == RequestType::CREDIT_BALANCE && amount < 0)
        return true;
    if (request == RequestType::DEBIT_BALANCE && amount > 0)
        return true;

    return false;
}
void outputLine(int account, const string &name, double balance)
{
    cout << left << setw(10) << account << setw(13) << name << setw(7) << setprecision(2) << right << balance << endl;
}

RequestType getRequest()
{
    cout << "\nEnter Request" << endl;
    cout << " 1 - List accounts with zero balances" << endl;
    cout << " 2 - List accounts with credit balances" << endl;
    cout << " 3 - List accounts with debit balances" << endl;
    cout << " 4 - End of run" << endl;
    int userInput = 0;

    do
    {
        cout << "\n? ";
        cin >> userInput;
        if (userInput < static_cast<int>(RequestType::ZERO_BALANCE) || userInput > static_cast<int>(RequestType::END))
        {
            cout << "ERROR: Please choose from the options provided" << endl;
        }
    } while (userInput < static_cast<int>(RequestType::ZERO_BALANCE) || userInput > static_cast<int>(RequestType::END));

    return static_cast<RequestType>(userInput);
}