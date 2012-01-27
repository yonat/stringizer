#include "stringizer.h"
#include <vector>
#include <algorithm>

int main()
{
    std::string s = "The answer, my friend, is " + stringize(42);

    // example: transforming a vector of doubles to a vector of strings
    std::vector<double> vf;
    std::vector<std::string> vs;
    vf.push_back(3.14159);
    vf.push_back(2.71828);
    vf.push_back(1.57079);
    std::transform(
        vf.begin(), vf.end(),   // from
        std::back_inserter(vs), // to
        stringizer() );         // transformation

    return 0;
}
