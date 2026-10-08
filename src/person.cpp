#include "person.hpp"

Person::Person() : id(0) {}

Person::Person(
    std::string firstName,
    std::string lastName,
    std::array<std::string, 2> phoneNumbers
) : id(0), firstName(firstName), lastName(lastName), phoneNumbers(phoneNumbers) {}

Person::~Person() {}

std::string Person::getFirstName() const {
    return firstName;
}

std::string Person::getLastName() const {
    return lastName;
}

void Person::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Person::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Person::setId(int id) {
    this->id = id;
}

void Person::setPhoneNumbers(const std::array<std::string, 2>& phoneNumbers) {
    this->phoneNumbers = phoneNumbers;
}

int Person::getId() const {
    return id;
}

std::string Person::getFullName() const {
    return firstName + " " + lastName;
}

std::array<std::string, 2> Person::getPhoneNumbers() const {
    return phoneNumbers;
}

std::string Person::returnPrettyName() const {
    return "Nome: " + getFullName();
}

std::string Person::returnPrettyPhoneNumbers() const {
    return "Telefone (1): " + phoneNumbers[0] + ";\nTelefone (2): " + phoneNumbers[1];
}

std::string Person::returnPrettyId() const {
    return "ID: " + std::to_string(id);
}