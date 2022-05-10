#include <iostream>
#include <vector>
#include <list>
#include "print_ip.h"

/**
 * @brief main
 * 
 * @return int 
 */
int main()
{
    try
    {
        std::vector<int> vec = {12, 34, 56, 78};
        std::list<int> list = {98, 76, 54, 32};

        printIp(vec);
        std::cout << std::endl;
        printIp(list);
        std::cout << std::endl;

        printIp(char(-1));
        std::cout << std::endl;
        printIp(short(0));
        std::cout << std::endl;
        printIp(int(2130706433));
        std::cout << std::endl;
        printIp(long(8875824491850138409));
        std::cout << std::endl;

        printIp("123.123.123.123");
        std::cout << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
