#include <hw01.h>

int hw01(int start, int end)
{
  if (start < 10 || start > 99 || end < 10 || end > 99 || start > end) {
    return -1;
  }

  int total = 0;
  for (int i = start; i <= end; ++i) {
    bool prime = true;
    if (i < 2)
    {
        prime = false;
    }
    for (int j = 2; j * j <= i; ++j)
    {
      if (i % j == 0)
      {
        prime = false;
        break;
      }
    }

    if (prime) {
      int summary = 0;
      int num = i;
      while (num > 0) {
        summary += num % 10;
        num /= 10;
      }
      total += summary;
    }
  }

  return total;
}
