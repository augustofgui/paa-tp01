#include "../headers/selection_sort.h"

void selection_sort(bigNum *numbers, bigNum tam)
{
  bigNum i, j, min;
  for (i = 0; i < (tam - 1); i++)
  {
    min = i;
    for (j = (i + 1); j < tam; j++)
    {
      if (numbers[j] < numbers[min])
        min = j;
    }
    if (i != min)
    {
      swap(&numbers[i], &numbers[min]);
    }
  }
}