#define TEST_MODULE test_print_ip

#include "gtest/gtest.h"

#include <sstream>
#include <vector>
#include <list>
#include "print_ip.h"


/**
 * @brief integral test
 * 
 */
TEST(print_ip_test_case, integral_test) {
    std::stringstream ss;
    printIp(char(0), ss);
    ASSERT_EQ("0", ss.str());

    ss.str("");
    printIp(char(127), ss);
    ASSERT_EQ("127", ss.str());

    ss.str("");
    printIp(char(-1), ss);
    ASSERT_EQ("255", ss.str());

    ss.str("");
    printIp(short(0), ss);
    ASSERT_EQ("0.0", ss.str());

    ss.str("");
    printIp(short(31611), ss);
    ASSERT_EQ("123.123", ss.str());

    ss.str("");
    printIp(short(-1), ss);
    ASSERT_EQ("255.255", ss.str());

    ss.str("");
    printIp(int(0), ss);
    ASSERT_EQ("0.0.0.0", ss.str());

    ss.str("");
    printIp(int(2130706433), ss);
    ASSERT_EQ("1.0.0.127", ss.str());

    ss.str("");
    printIp(int(-1), ss);
    ASSERT_EQ("255.255.255.255", ss.str());

    ss.str("");
    printIp(long(8875824491850138409), ss);
    ASSERT_EQ("41.131.112.101.89.67.45.123", ss.str());
}

/**
 * @brief container test
 * 
 */
TEST(print_ip_test_case, container_test) {
    std::stringstream ss;
    printIp(std::vector<int>(), ss);
    ASSERT_EQ("", ss.str());

    ss.str("");
    printIp(std::vector<int>{123}, ss);
    ASSERT_EQ("123", ss.str());
    
    ss.str("");
    printIp(std::vector<int>{12, 34, 56, 78}, ss);
    ASSERT_EQ("12.34.56.78", ss.str());

    ss.str("");
    printIp(std::list<int>{}, ss);
    ASSERT_EQ("", ss.str());

    ss.str("");
    printIp(std::list<int>{123}, ss);
    ASSERT_EQ("123", ss.str());
    
    ss.str("");
    printIp(std::list<int>{98, 76, 54, 32}, ss);
    ASSERT_EQ("98.76.54.32", ss.str());
}

/**
 * @brief string test
 * 
 */
TEST(print_ip_test_case, string_test) {
    std::stringstream ss;
    printIp("123.123.123.123", ss);
    ASSERT_EQ("123.123.123.123", ss.str());
    
    ss.str("");
    printIp(std::string("1.2.3.4"), ss);
    ASSERT_EQ("1.2.3.4", ss.str());

    ss.str("");
    printIp(std::string("hello"), ss);
    ASSERT_EQ("hello", ss.str());
}
