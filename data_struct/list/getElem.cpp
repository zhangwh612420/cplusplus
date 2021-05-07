//get elem function for list
#define OK 1
#define ERROR 0
#define True 1
#define False 0
#define MAXSIZE 20
#include <iostream>
using std::cout;
using std::endl;
typedef int Status;
typedef int elemtype;
typedef struct
{
    elemtype data[MAXSIZE];
    int length;
} sqlist;

// we use reference to return e Because we need to return the Status
Status getElem(sqlist L, int i, elemtype* e) {
    if (L.length == 0 || i < 0 || i > L.length) {
        return ERROR;
    }
    *e = L.data[i - 1];
    return OK;
}

int main() {
    cout << "Hello,world!" << endl;
    return 0;
}