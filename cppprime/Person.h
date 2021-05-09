#include <iostream>
#include <string>
using std::istream;
using std::ostream;
using std::string;
struct Person {
    string first_name;
    string last_name;
    string address;
    string name() const {
        return first_name + " " + last_name;
    }
};

ostream& print(ostream& os, const Person& item) {
    os << item.name() << " " << item.address;
    return os;
}
istream& read(istream& is, Person& item) {
    is >> item.first_name >> item.last_name >> item.address;
    return is;
}