#include <string>>
using std::string;
typedef double money;
string bal;  // in order  to make the class can recogonize this type we often declration before this class

class Account {
   public:
    // money is a type which is defined by us, complier will search all declration before this name
    // WARNING: will not search anything after this name
    // if did not find the declration,complier will search in outside area
    money balance() {
        return bal;
    }
    money add(money bal) {  // this statment is not very good please have a different name
        all = ratio * bal;
        // in this funtion we have a argument which has a same name with our member data
        // in this case,bal means the bal as a argument because the function'area prior to class's area
        // if you really want to call the member bal please use this -> bal or Account::bal
        // also if you want to call a globle varible you can use ::bal just missing the area it will auto see as globle
    }

   private:
    // typedef double money; // the compiler will pass this code, but in fact this code is unright
    money bal;
    money all;
    money ratio;
};

typedef string Type;
Type init_val();
class Exercise {
   public:
    typedef double Type;
    Type set_val(Type);
    Type init_val();

   private:
    int val;
};
Exercise::Type Exercise ::set_val(Type parm) {
    val = parm + init_val();
    return val;
}

struct X {
    X(int i, int j)
        : rem(i % j), base(i) {}
    int rem, base;
};