#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Account.hpp"


class Customer
{
    private :

        int id ;
        std :: string name ;
        std :: vector <Account> accounts ;
        

    public :

        Customer(int id , const std :: string& name ) ;

        Account* getAccount(int accountId ) ;
        void addAccount(const Account& account ) ;
        void printReport() const ;

        int getId() const ;
        const std::string& getName() const;

};

#endif