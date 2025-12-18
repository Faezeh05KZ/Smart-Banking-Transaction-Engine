#ifndef BANKSYSTEM_HPP
#define BANKSYSTEM_HPP

#include <vector>
#include "Customer.hpp"
#include "Transaction.hpp"
#include "Account.hpp"

class BankSystem
{
    private :

        std::vector< Customer > customers ;
        std::vector< Transaction > transactions ;
        static int totalAccounts ;

public:

    void addCustomer(const Customer& c);
    Customer* findCustomer(int id) ;

    void addTransaction(const Transaction& t);
    void report() const ;

    void incrementTotalAccounts();

};

#endif
