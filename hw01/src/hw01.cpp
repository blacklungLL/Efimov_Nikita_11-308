#include <hw01.h>

int hw01(int start, int end)
{
  if (start < 10 || start > 99 || end < 10 || end > 99 || start > end)
    return -1;

  int total = 0;

  for (int i = start; i <= end; ++i)
  {
    bool isPrime = true;
    if (i < 2)
    {
      isPrime = false;
    }
    for (int j = 2; j * j <= i; ++j)
    {
      if (i % j == 0)
      {
        isPrime = false;
        break;
      }
    }

    if (isPrime)
    {
      int summary = 0;
      int number = i;
      while (number > 0)
      {
        summary += number % 10;
        number /= 10;
      }
      total += summary;
    }
  }

  return total;
}