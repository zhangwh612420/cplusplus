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
class Sales_data {
    //in order to makesure read print add function can access the private member so we need to define friend
    //friend does not means there function are this class's member
    // firend declration not real declration just give these function access to private data
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend ostream& print(ostream&, const Sales_data&);
    friend istream& read(istream&, Sales_data&);

   private:
    // so that user's code will not influence the data in the class
    // user only can call the interface api to change the data
    string book_num;
    unsigned units_sold = 0;
    double revenue = 0.0;
    // these fucntion just declration
    double avg_price() const;
    // contribute function
    // this default contribute function will told your complier that we need a default function
    // if we didn't have this function we must use other function below, so we can't bulit a Sales_data without ini value
   public:
    Sales_data() = default;
    Sales_data(const string& s)
        : book_num(s) {}
    Sales_data(const string& s, unsigned n, double p)
        : book_num(s), units_sold(n), revenue(p * n) {}
    Sales_data(istream&);  //this contribute function just a declration not define
    // Sales_data's member function
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
    Sales_data& combine(const Sales_data&);
};
// Sales_data's no member function can't call these function by point
// although we have declration in the friend statement but we still need to declration in here
Sales_data add(const Sales_data&, const Sales_data&);
ostream& print(ostream&, const Sales_data&);
istream& read(istream&, Sales_data&);
// read will change the Sales_data instance so we need to use reference
// IO can't be copy so we also need to use reference
// also this function will change the content of stream so we use normal reference not const reference
// these functions below are not member fucntion so when we define these we didn't need Sales_data ::
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
inline double Sales_data ::avg_price() const {
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
//define of contribute function
Sales_data ::Sales_data(istream& is) {
    read(is, *this);  //"this" means caller * to read address because read need Sales_data&
}

int main() {
    Sales_data total;
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
