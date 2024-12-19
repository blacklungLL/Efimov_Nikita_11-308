#include <hw02.h>
using namespace std;

string hw02(string str) {
    string result;
    for (char ch : str) {
        if (result.find(ch) == std::string::npos) {
            result += ch;
        }
    }
    return result;
}

