#include <iostream>
#include <limits>
#include "BankSystem.hpp"
#include "Account.hpp"


using namespace std;

int main()
{
    BankSystem bankSystem;

    while (true)
    {
        cout << "\n1.Add Customer\n" ;
        cout << "2.Add Account\n" ;
        cout << "3.Show Account Balance\n" ;
        cout << "4.Make Transaction\n" ;
        cout << "5.Customer Report\n" ;
        cout << "6.System Report\n" ;
        cout << "0.Exit\n" ;

        int Choice;
        cin >> Choice;

        if (cin.fail()) 
        {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max() , '\n');
            continue;
        }

        if (Choice == 0)
        {
            break;
        }

        else if (Choice == 1)
        {
            int cId ;
            string cName ;

            cout << "Enter customerId and customerName\n";
            cin >> cId >> cName ;

            bankSystem.addCustomer(Customer(cId , cName)) ;
        }

        else if (Choice == 2)
        {
            int cId ;
            int accountId;
            int accountType;
            double initialBalance;

            cout << "Enter customerId , accountId , initialBalance , accountType" <<endl  ;
            cin >> cId >> accountId >> initialBalance >> accountType ;

            if (initialBalance < 0)
            {
                 cout << "Initial balance cannot be negative." <<endl ;
                 continue;
            }

            Customer* customer = bankSystem.findCustomer(cId ) ;
            if (customer)
            {
                if (accountType != Account::SAVINGS && accountType != Account::CHECKING && accountType != Account::CREDIT )
                {
                    cout << "Invalid account type!!! Account not added " << endl ;
                    continue;
                }

                Account newAccount(
                    accountId,
                    customer -> getName(),
                    initialBalance,
                    static_cast<Account::Type>(accountType)
                );

                customer -> addAccount(newAccount);
                bankSystem.incrementTotalAccounts();
                cout << "Account added successfully.\n";
            }

            else
            {
                cout << "Customer not found \n";
            }
        }

        else if (Choice == 3)
        {
            int cId;
            int accountId;

            cout << "Enter customerId and accountId\n";
            cin >> cId >> accountId;

            Customer* customer = bankSystem.findCustomer(cId) ;
            if (customer)
            {
                Account* account = customer->getAccount(accountId) ;
                if (account)
                {
                    account->printBalance();
                }

                else
                {
                    cout << "Account not found\n" ;
                }
            }

            else
            {
                cout << "Customer not found\n" ;
            }
        }

        else if (Choice == 4)
        {
            int tId , tType, cId , AccountId , dCustomerId , dAccountId ;

            double tAmount;
            string timestamp;

            cout << "Enter transactionId transactionType " << endl;
            cout << "sourceCustomerId sourceAccountId " <<endl ;
            cout << "destinationCustomerId destinationAccountId " <<endl;
            cout << "amount timestamp\n";

            cin >> tId >> tType >> cId >> AccountId >> dCustomerId >> dAccountId >> tAmount >> timestamp;

            if (tAmount <= 0) 
            {
                cout << "Transaction amount must be positive.\n";
                continue ;
            }

            Customer* sourceCustomer = bankSystem.findCustomer(cId ) ;
            Customer* destinationCustomer = bankSystem.findCustomer(dCustomerId);

            if (sourceCustomer && destinationCustomer)
            {
                Account* sourceAccount = sourceCustomer -> getAccount (AccountId);
                Account* destinationAccount = destinationCustomer -> getAccount(dAccountId );


                if (sourceAccount && destinationAccount)
                {
                    if (sourceAccount == destinationAccount) 
                    {
                         cout << "Transaction failed: Source and destination accounts cannot be the same.\n";
                         continue ;
                    }

                    if (sourceAccount->transfer(*destinationAccount , tAmount))
                    {
                        Transaction transaction(
                            tId ,
                            static_cast <Transaction::Type> (tType),
                            tAmount ,
                            timestamp
                        );

                        bankSystem.addTransaction(transaction) ;

                        cout << "Transaction completed successfully !!\n";
                    }

                    else
                    {
                        cout << "Transaction failed !!!\n";
                    }
                }

                else
                {
                    cout << "Account not found !!!\n";
                }
            }

            else
            {
                cout << "Customer not found !!!\n";
            }
        }

        else if (Choice == 5)
        {
            int cId;
            cout << "Enter customerId : \n";
            cin >> cId ;

            Customer* customer = bankSystem.findCustomer(cId ) ;
            if (customer)
            {
                customer->printReport();
            }

            else
            {
                cout << "Customer not found !!! \n" ;
            }
        }

        else if (Choice == 6)
        {
            cout << "System Report " <<endl ;
            bankSystem.report() ;
        }

        else
        {
             cout << "Invalid choice. Please select from the menu \n";
        }
    }

    return 0;
}