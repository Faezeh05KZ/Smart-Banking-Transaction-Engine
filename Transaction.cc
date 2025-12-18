#include <iostream>
#include "Transaction.hpp"

using namespace std;

Transaction :: Transaction (int i ,Type t , double a , const string time)
: id(i ) , type (t) , amount(a) , timestamp(time) {}

bool Transaction :: operator == (const Transaction& other ) const
{
    return id == other.id && type == other.type && amount == other.amount && timestamp == other.timestamp;
}

Transaction Transaction :: operator+(const Transaction& other ) const 
{
    return Transaction (id , type , amount + other.amount , timestamp) ;
}

void Transaction :: print () const
{
    cout << "Transaction " << id << ":" << "Amount " << amount << " Time " << timestamp << endl;
}
