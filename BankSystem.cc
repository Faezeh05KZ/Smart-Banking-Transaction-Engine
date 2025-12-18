#include "BankSystem.hpp"
#include "Customer.hpp"
#include <iostream>

using namespace std;

int BankSystem :: totalAccounts = 0;

void BankSystem :: addCustomer(const Customer& c)
{
    customers.push_back(c) ;
}

Customer* BankSystem::findCustomer(int id)
{
    for (auto& c : customers)
    {
        if (c.getId() == id)
        {
            return &c;
        }
    }

    return nullptr;
}

void BankSystem::addTransaction(const Transaction& t)
{
    transactions.push_back(t);
}

void BankSystem::report() const
{
    cout << "System Report\n" ;

    for (const auto& c : customers)
    {
        c.printReport();
    }

    for (const auto& t : transactions)
    {
        t.print();
    }
}

void BankSystem::incrementTotalAccounts()
{
    totalAccounts++;
}
