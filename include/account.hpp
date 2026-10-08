#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

#include "person.hpp"

class Account{

    public:
        Account();
        Account(
            std::string agency,
            std::string accountNumber,
            double balance,
            Person person1
        );
        ~Account();

        std::string getAgency() const;
        std::string getAccountNumber() const;
        double getBalance() const;
        std::string returnPrettyAccount() const;

    private:
        std::string agency;
        std::string accountNumber;
        double balance = 0.0;

        Person person1;
};

#endif // ACCOUNT_HPP