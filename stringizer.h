/*
 * basic_stringizer - a functor that turns an object into a basic_string
 * stringize/wstringize - functions that turn an object into a string/wstring
 *
 * The object you stringize must have the output operator defined
 * (operator<< with an ostream argument).
 *
 * Note: For ANSI-challenged compilers, you may want to #define
 * NO_PARTIAL_SPECIALIZATION.
 *
 * // example: creating a string from an int
 * std::string s = "The answer, my friend, is " + stringize(42);
 * 
 * // example: transforming a vector of doubles to a vector of strings
 * std::vector<double> vf;
 * std::vector<std::string> vs;
 * vf.push_back(3.14159);
 * vf.push_back(2.71828);
 * vf.push_back(1.57079);
 * std::transform(
 *     vf.begin(), vf.end(),   // from
 *     std::back_inserter(vs), // to
 *     stringizer() );         // transformation
 */

#ifndef STRINGIZER_H
#define STRINGIZER_H

#include <sstream>

template <typename Char>
struct basic_stringizer
{
    typedef std::basic_string<Char> String;

    template <typename T>
    String operator()(const T& t)
    {
        std::basic_stringstream<Char> s;
        s << t;
        return s.str();
    }

#ifndef NO_PARTIAL_SPECIALIZATION
    template <>
    String operator()<Char*>(const Char* s)
    { return s; }

    template <>
    String operator()<String>(const String& s)
    { return s; }

    template <typename T>
    String operator()<T*>(const T* p)
    { return operator()<void*>(p); }

    template <>
    String operator()<void*>(const void* p)
    {
        std::basic_stringstream<Char> s;
        s << const_cast<void*>(p);
        return s.str();
    }
#endif // NO_PARTIAL_SPECIALIZATION
};


typedef basic_stringizer<char> stringizer;
typedef basic_stringizer<wchar_t> wstringizer;

template <typename T>
inline std::string stringize(T t)
{ return stringizer()(t); }

template <typename T>
inline std::wstring wstringize(T t)
{ return wstringizer()(t); }

#endif // STRINGIZER_H
