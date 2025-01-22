#include <hw05.h>
#include <vector>
#include <string>
#include <cctype>

using VecOfStr = std::vector<std::string>;

VecOfStr hw05(const VecOfStr& strings)
{
    VecOfStr palindromes;

    auto is_palindrome = [](const std::string& s) {
        auto start = s.begin();
        auto end = s.rbegin();
        while (start != s.end() && end != s.rend()) {
            while (start != s.end() && !std::isalnum(*start)) {
                ++start;
            }
            while (end != s.rend() && !std::isalnum(*end)) {
                ++end;
            }
            if (start == s.end() || end == s.rend()) {
                break;
            }
            if (std::tolower(*start) != std::tolower(*end)) {
                return false;
            }
            ++start;
            ++end;
        }
        return true;
    };

    for (const auto& str : strings) {
        if (is_palindrome(str)) {
            palindromes.push_back(str);
        }
    }

    return palindromes;
}