#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account 
{
    private :

        int id ;
        std :: string ownerName ;
        double balance ;

    public :

        enum Type { SAVINGS , CHECKING , CREDIT } type ;
        Account (int i ,  const std :: string owner ,  double b , Type t) ;

        
        bool deposit (double amount) ;
        bool withdraw (double amount) ;
        bool transfer(Account& to , double amount) ;
        void printBalance () const ;

        int getId() const ;
        double getBalance() const ;

};

#endif