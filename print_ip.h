#ifndef PRINT_IP
#define PRINT_IP

#include <type_traits>
#include <iostream>

#ifndef __PRETTY_FUNCTION__
#include "pretty.h"
#endif

/**
 * @brief print ip as integral type
 * 
 * @tparam T 
 * @param integralIp 
 * @return std::enable_if_t<std::is_integral_v<T>> 
 */
template<class T>
std::enable_if_t<std::is_integral_v<T>> printIp(T integralIp, std::ostream& out = std::cout)
{
#ifdef USE_PRETTY
    out << __PRETTY_FUNCTION__ << std::endl;
#endif
    uint8_t* first = reinterpret_cast<uint8_t*>(&integralIp);
    size_t size = sizeof(integralIp);
    for (size_t i = 0; i < size; ++i)
    {
        if (i != 0)
            out << ".";
        out << static_cast<uint32_t>(*(first + i));
    }
}

/**
 * @brief print ip as container
 * 
 * @tparam Container 
 * @tparam typename 
 * @param containerIp 
 */
template<class Container, typename = typename Container::iterator>
void printIp(Container containerIp, std::ostream& out = std::cout)
{
#ifdef USE_PRETTY
    out << __PRETTY_FUNCTION__ << std::endl;
#endif
    for (const auto& it : containerIp)
    {
        if (&it != &containerIp.front())
            out << ".";
        out << static_cast<uint32_t>(it);
    }
}

/**
 * @brief print ip as string
 * 
 * @param ip 
 */
void printIp(std::string ip, std::ostream& out = std::cout)
{
#ifdef USE_PRETTY
    out << __PRETTY_FUNCTION__ << std::endl;
#endif
    out << ip;
}

#endif // PRINT_IP
