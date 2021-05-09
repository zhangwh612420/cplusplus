#define ERROR 1
#include <iostream>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
// every function must be declration in the struct but can be define out of the struct
struct Sales_data {
    string book_num;
    unsigned units_sold = 0;
    double revenue = 0.0;
    // Sales_data's member function use point .  to call
    // this function is inline function, because this function define in the struct
    // we add CONST after the function means this function will not modify this instance's member data
    // and const object can't call non-const function
    // but non-const object can call const function
    // infact this's type is Sales_data *const
    // so we add const to make this become a pointer which point to const item
    // const Sales_data *const
    string isbn() const {
        return book_num;
        // this book_num infact == this -> book_num or this.book_num
        // but for us we can't define a this as a para or a varibale
        // but we can use this in a function's statement return this -> book_num;
        // because this always point to "this" so it is a const pointer
    }
    // these fucntion just declration
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
};
// Sales_data's no member function can't call these function by point
Sales_data add(const Sales_data&, const Sales_data&);
ostream& print(ostream&, const Sales_data&);
istream& read(istream&, Sales_data&);
Sales_data total;

// read will change the Sales_data instance so we need to use reference
// IO can't be copy so we also need to use reference
// also this function will change the content of stream so we use normal reference not const reference
istream& read(istream& is, Sales_data& item) {
    double price = 0;
    is >> item.book_num >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
// we need to point that print will not include \n this function we depend by user
ostream& print(ostream& os, const Sales_data& item) {
    double price = item.avg_price();
    os << item.isbn() << " " << item.units_sold << " " << price;
    return os;
}
Sales_data add(const Sales_data& item1, const Sales_data& item2) {
    Sales_data sum = item1;
    sum.combine(item2);
    return sum;
}
// when we define a function out of the struct when is function is CONST ,we need keep this
// and we need to define this funtion with struct's name
double Sales_data ::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0.0;
    }
}
// we build this function to mook + so we need to copy "+"'s function so we need to return a reference
Sales_data& Sales_data::combine(const Sales_data& rsale_data) {
    units_sold += rsale_data.units_sold;
    revenue += rsale_data.revenue;
    return *this;  //this is a pointer(include address),so we need to use *
}
int main() {
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            // we use point to call isbn function
            // total.isbn() == Sales_data::isbn(&total)
            // so we use point infact transfere itsself while call this function
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }
}
