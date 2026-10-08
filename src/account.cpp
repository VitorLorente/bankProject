#include "account.hpp"
#include "person.hpp"

Account::Account() : balance(0.0), person1() {}

Account::Account(
    std::string agency,
    std::string accountNumber,
    double balance,
    Person person1
) : agency(agency), accountNumber(accountNumber), balance(balance), person1(person1) {}

Account::~Account() {}

std::string Account::getAgency() const {
    return agency;
}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::returnPrettyAccount() const {
    return "Agência: " + agency + ";\nConta: " + accountNumber + ";\nSaldo: R$" + std::to_string(balance);
}