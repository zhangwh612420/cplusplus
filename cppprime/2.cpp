#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v1{1, 2};
    auto vector_size = sizeof v1;
    cout << vector_size << endl;
    return 0;
}
