#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::istream;
using std::ostream;
using std::string;
using std::vector;
class Screen {
   public:
    void some_member() const;
    // if you want to definne a member of a class you must define fist use second
    typedef string::size_type pos;  // this statement == using pos = string :: size_type
    Screen() = default;             //because we have another contribute function so this default function is necessary
    Screen(pos ht, pos wd)
        : height(ht), width(wd), content(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c)
        : height(ht), width(wd), content(ht * wd, c) {}
    char get() const {
        return content[cursor];
    }
    char get(pos ht, pos wd) const;
    // we should make these funtion return a reference not a copy
    // if we use Screen as  a return type although we retun *this these function still will return a copy of this
    Screen& move(pos r, pos c);
    Screen& set(char);
    Screen& set(pos r, pos c, char);
    Screen& display(ostream& os) {
        do_display(os);
        return *this;
    }
    // we overload this funtion if the instance is const will call this function
    const Screen& display(ostream& os) const {
        do_display(os);
        return *this;  // rear const will make *this point to a const
    }

   private:
    // this functio really realize the display's function
    // first : we reduce duplicate code
    // second : if we need to change the function of display we only need to modify in one place
    // third : if we want to debug add some info in this funtion we cant test all case
    // fourth : this function will declration as a inline funtion won't add any usage
    void do_display(ostream& os) const {
        os << content;
    }
    mutable size_t access_ctr;
    pos cursor = 0;
    pos height = 0, width = 0;
    string content;
};

// when we define member function out of class we need to keep the function's area Screen::
// if we want to define a function which is not member function this prefix is not need
// because member function we will use point(.) to call these function
// will not use funtion(instance) to call so we will not use item.XXX
// although this fuuntion's declration is not a inline funtion but we can declration this in define
// and we did better declration inline in the define not in the declration which in the class
inline Screen& Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}
inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return content[row + c];
}
inline Screen& Screen::set(pos r, pos c, char ch) {
    content[r * width + c] = ch;
    return *this;
}
inline Screen& Screen::set(char ch) {
    content[cursor] = ch;
    return *this;
}
// although we can have a const object but this object's access_ctr still can be change because this data is mutable
void Screen::some_member() const {
    ++access_ctr;
}

class Windows_mgr {
   private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

int main() {
    Screen my_screen(5, 5, 'X');
    my_screen.move(4, 0).set('#').display(cout);
    cout << "\n";
    my_screen.display(cout);
    cout << "\n";
}