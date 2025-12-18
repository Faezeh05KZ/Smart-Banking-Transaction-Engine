#include <iostream> 
#include "Customer.hpp"

using namespace std;

Customer :: Customer(int i , const string& n) : id(i) , name(n) {}

void Customer :: addAccount(const Account& account)
{
    accounts.push_back(account);
}

Account* Customer :: getAccount(int accountId)
{
    for (auto& a : accounts)
    {
        if (a.getId() == accountId)
        {
            return &a;
        }
    }

    return nullptr;
}

void Customer :: printReport() const
{
    cout << "Customer " << id << " " << name << endl ;

    for (const auto& a : accounts)
    {
        a.printBalance() ;
    }
}

const string& Customer::getName() const
{
    return name;
}

int Customer::getId() const
{
    return id;
}

