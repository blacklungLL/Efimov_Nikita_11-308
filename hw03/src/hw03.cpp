#include <hw03.h>
#include <cstring>
#include <cstddef>


void hw03(char* str, const char* pattern)
{
    if (str == nullptr || pattern == nullptr)
        return;

    if (*str == '\0')
        return;

    size_t str_len = std::strlen(str);
    size_t pattern_len = std::strlen(pattern);

    if (pattern_len == 0)
         return;

    char* pos = str;

    while (pos - str <= str_len - pattern_len) {
        if (std::strncmp(pos, pattern, pattern_len) == 0) {
            std::memmove(pos, pos + pattern_len, str_len - (pos - str) - pattern_len + 1);
            return;
        }
        pos++;
    }
}
