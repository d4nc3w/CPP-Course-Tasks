/* Create a Phone structure. This structure will have 2 attributes.
Manufacturer (std::string) and a unique serial number (int).
Make sure to override the constructor, copy constructor, and destructor in this structure.
This structure should have a method called call, which takes a phone number as a parameter.
The task of this method will be to display the number on the console. */

#include <iostream>
#include <vector>
#include <string>
#include <fmt/ranges.h>
#include <map>

struct Phone {
    std::string Manufacture;
    int SerialNum;

    Phone(std::string Manufacture, int SerialNum)
    : Manufacture(Manufacture), SerialNum(SerialNum) {
       // std::cout << "Phone created\n";
    }

    Phone(Phone const &copyPhone)
    : Manufacture(copyPhone.Manufacture), SerialNum(copyPhone.SerialNum) {
      //  std::cout << "Phone copied" << std::endl;
    }

    ~Phone() {
       // std::cout << "Phone destroyed" << std::endl;
    }

    void call(int serialNum) {
        std::cout << "Calling " << serialNum << std::endl;
    }
};

/* Create a SmartPhone structure that will inherit from the Phone structure.
Objects of this structure will have an additional attribute in the form of a map,
where the key will be a phone number and the value will be the name and surname of a given person.
Override the call method in such a way that when we call a person saved in the contacts,
their name and surname will be displayed instead of the phone number.
Make sure the method uses polymorphism. Write an example that demonstrates a polymorphic call method invocation. */

struct SmartPhone : Phone {
    std::string Manufacture;
    int SerialNum;
    std::map<int, std::string> contacts;

    SmartPhone(std::string Manufacture, int SerialNum)
    : Phone(Manufacture, SerialNum) {
        //std::cout << "SmartPhone created\n";
    }

    SmartPhone(SmartPhone const &copySmartPhone)
    : Phone(Manufacture, SerialNum), contacts(copySmartPhone.contacts) {
        //std::cout << "SmartPhone copied" << std::endl;
    }

    ~SmartPhone() {
        //std::cout << "SmartPhone destroyed" << std::endl;
    }

    void call(int serialNum) {
        if (contacts.find(serialNum) != contacts.end()) {
            std::cout << "Calling " << contacts[serialNum] << std::endl;
        } else {
            std::cout << "Calling " << serialNum << std::endl;
        }
    }
};

     void printVec(std::vector<Phone> phones) {
        for (auto const &phone : phones) {
            fmt::print("{} {}\n", phone.Manufacture, phone.SerialNum);
        }
    }

auto main() -> int {
    Phone S22("Samsung", 987123);
    Phone Iphone("Apple", 934215);

    S22.call(123456789);
    Iphone.call(987654321);
    std::cout << std::endl;

    /* Using the structure from task 1, create a vector of several phones, sort them based on their serial numbers.
     Display the elements before and after sorting. */

    std::vector<Phone> phones = {
            Phone("Apple", 998765),
            Phone("Samsung", 123456),
            Phone("Xiaomi", 777888),
            Phone("Huawei", 666555),
            Phone("OnePlus", 111222),
            Phone("Apple", 245865),
            Phone("Apple", 754832),
            Phone("Samsung", 765493),
            Phone("Xiaomi", 123456),
            Phone("Huawei", 987654)
    };

    printVec(phones);
    std::cout << std::endl;

    std::sort(phones.begin(), phones.end(), [](Phone const &a, Phone const &b) {
        return a.SerialNum < b.SerialNum;
    });

    printVec(phones);
    std::cout << std::endl;

    /* Using the structure from task 1, create a map where the keys will be the manufacturers and
     * the values will be a vector of phones from a given manufacturer. Use std::ranges::partition. */

    std::map<std::string, std::vector<Phone>> phoneMap;

    for (auto const &phone : phones) {
        phoneMap[phone.Manufacture].push_back(phone);
    }

    for (auto const &phone : phoneMap) {
        fmt::print("{}: ", phone.first);
        for (auto const &phone : phone.second) {
            fmt::print("{} ", phone.SerialNum);
        }
        fmt::print("\n");
    }
    std::cout << std::endl;

   // SmartPhone x("Samsung", 987123, { {123456789, "John Smith"}, {987654321, "Jane Doe"} });

}
