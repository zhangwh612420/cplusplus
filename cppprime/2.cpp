#include <iostream>

int main()
{
    int flagVal = 0, countNum = 0, currVal = 0;
    if (std::cin >> flagVal)
    {
        countNum = 1;
        while (std::cin >> currVal)
        {
            if (currVal == flagVal)
            {
                countNum += 1;
            }
            else
            {
                std::cout << "This number " << flagVal << " occurs " << countNum << " times" << std::endl;
                flagVal = currVal;
                countNum = 1;
            }
        }
        std::cout << "This number " << flagVal << " occurs " << countNum << " times" << std::endl;
    }
}
