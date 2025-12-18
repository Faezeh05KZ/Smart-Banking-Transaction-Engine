#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <iostream>
#include <string>
#include "Account.hpp"

class Transaction
{
    public :
    
        enum Type { DEPOSIT , WITHDRAWAL , TRANSFER }   ;
        Transaction (int i , Type t , double a , const std::string time) ;

        bool operator == (const Transaction& other ) const ;
        Transaction operator+ (const Transaction& other ) const ;
        void print() const ;
        
        
    private :

        int id ;
        Type type ;
        double amount ;
        std :: string timestamp ;
        
        
};

#endif