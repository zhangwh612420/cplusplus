#include <string>
using std::string;
class Screeb {
   public:
    typedef string::size_type pos;
    Screeb(/* args */);
    ~Screeb();

   private:
    pos cursor = 0;
    pos height = 0;
    string content;
};

Screeb::Screeb(/* args */) {
}

Screeb::~Screeb() {
}
