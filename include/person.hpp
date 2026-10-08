#ifndef PERSON_HPP
#define PERSON_HPP

#include <array>
#include <string>


class Person {
    public:
        Person();
        Person(std::string firstName, std::string lastName, std::array<std::string, 2> phoneNumbers);
        ~Person();

        int getId() const;
        void setId(int id);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getFullName() const;
        std::array<std::string, 2> getPhoneNumbers() const;

        std::string returnPrettyId() const;
        std::string returnPrettyName() const;
        std::string returnPrettyPhoneNumbers() const;

        void setFirstName(const std::string& firstName);
        void setLastName(const std::string& lastName);
        void setPhoneNumbers(const std::array<std::string, 2>& phoneNumbers);

    private:
        int id;
        std::string firstName;
        std::string lastName;
        std::array<std::string, 2> phoneNumbers;
    
};

#endif // PERSON_HPP