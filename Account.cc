#include <iostream>
#include "Account.hpp"

using namespace std;

Account :: Account (int i ,  string owner , double b , Type t)
: id (i) , ownerName(owner) , balance(b) , type(t) {}

bool Account :: deposit (double amount)
{
    if (amount  <= 0)
    {
        return false ;
    }

    balance += amount ;
    return true ;

}

bool Account :: withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        return false ;
    }

    balance -= amount ;
    return true ;
}

bool Account :: transfer(Account &to, double amount)
{
    if (!withdraw(amount))
    {
        return false ;
    }

    to.deposit(amount);
    return true;
}

void Account :: printBalance() const
{
    cout << "Account ID: " << id << endl;
    cout << "Account Type: " ;
    switch (type) 
    {
        case Type::SAVINGS:
            cout << "Savings";
            break;

        case Type::CHECKING:
            cout << "Checking";
            break;

        case Type::CREDIT:
            cout << "Credit";
            break;

        default:
            cout << "Unknown";
    }

    cout << endl;
    cout << "Balance: " << balance << " $" << endl;
}

int Account :: getId() const 
{
    return id ;
}

double Account :: getBalance() const 
{
    return balance ;

}