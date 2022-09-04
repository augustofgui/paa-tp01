#include "../headers/utils.h"

bigNum *create_ordered_numbers_array(bigNum *numbers, bigNum tam)
{
  bigNum i;

  numbers = calloc(tam, sizeof(bigNum));
  if (numbers == NULL)
  {
    printf("Memory not allocated.\n");
    exit(0);
  }

  for (i = 0; i < tam; i++)
  {
    numbers[i] = i + 1;
  }

  return numbers;
}

bigNum *random_shuffle_numbers_array(bigNum *numbers, bigNum tam)
{
  bigNum i, j;

  for (i = tam - 1; i > 0; i--)
  {
    j = rand() % (i + 1);

    swap(&numbers[i], &numbers[j]);
  }

  return numbers;
}

void print_array(bigNum arr[], bigNum n)
{
  bigNum i;
  for (i = 0; i < n; i++)
    printf("%llu ", arr[i]);
  printf("\n\n");
}

void swap(bigNum *a, bigNum *b)
{
  bigNum temp = *a;
  *a = *b;
  *b = temp;
}

void write_numbers_array_to_txt_file(bigNum *numbers, bigNum tam, bigNum numArq)
{
  FILE *file;
  bigNum i;

  char filename[40] = "unordered";

  int length1 = snprintf(NULL, 0, "%llu", numArq);
  char *str1 = malloc(length1 + 1);
  snprintf(str1, length1 + 1, "%llu", numArq);

  strcat(filename, str1);
  strcat(filename, "_");

  int length2 = snprintf(NULL, 0, "%llu", tam);
  char *str2 = malloc(length2 + 1);
  snprintf(str2, length2 + 1, "%llu", tam);

  strcat(filename, str2);
  strcat(filename, ".txt");

  free(str1);
  free(str2);

  file = fopen(filename, "w");
  if (NULL == file)
  {
    printf("File can't be opened \n");
  }

  for (i = 0; i < tam; i++)
  {
    fprintf(file, "%llu ", numbers[i]);
  }

  fclose(file);
}

void read_numbers_array_from_txt_file(bigNum *numbers, bigNum tam, bigNum numArq)
{
  FILE *file;
  bigNum i;

  char filename[40] = "unordered_";

  int length1 = snprintf(NULL, 0, "%llu", numArq);
  char *str1 = malloc(length1 + 1);
  snprintf(str1, length1 + 1, "%llu", numArq);

  strcat(filename, str1);
  strcat(filename, "_");

  int length2 = snprintf(NULL, 0, "%llu", tam);
  char *str2 = malloc(length2 + 1);
  snprintf(str2, length2 + 1, "%llu", tam);

  strcat(filename, str2);
  strcat(filename, ".txt");

  free(str1);
  free(str2);

  file = fopen(filename, "r");
  if (NULL == file)
  {
    printf("File can't be opened \n");
  }

  i = 0;
  while (!feof(file))
  {
    fscanf(file, "%llu", &numbers[i++]);
  }

  fclose(file);
}

void create_random_ordered_file(bigNum tam, bigNum numArq)
{
  bigNum *numbers = NULL;

  numbers = create_ordered_numbers_array(numbers, tam);

  numbers = random_shuffle_numbers_array(numbers, tam);

  write_numbers_array_to_txt_file(numbers, tam, numArq);
}