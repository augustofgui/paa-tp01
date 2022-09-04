#include "../headers/selection_sort.h"
#include "../headers/merge_sort.h"

int main(int argc, char *argv[])
{
  clock_t start_t, end_t;
  double total_t;

  // if (argc != 2)
  // {
  //   printf("Expected parameter to function.");
  //   exit(1);
  // }

  // bigNum tam = atoi(argv[1]);
  bigNum i;
  bigNum tam = 100;

  bigNum *numbers = NULL;

  start_t = clock();
  printf("Início do programa de ordenação, start_t = %ld\n", start_t);

  for(i = 1; i <= 20; i++){
    create_random_ordered_file(tam, i);
  }

  end_t = clock();
  printf("Fim do programa de ordenação, end_t = %ld\n", end_t);
   
  total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  printf("Tempo total da CPU: %f\n", total_t  );
  printf("Saindo do programa de ordenação...\n");

  //printf("AH NÃOOO \n");

  // numbers = create_ordered_numbers_array(numbers, tam);

  // numbers = random_shuffle_numbers_array(numbers, tam);

  // merge_sort(numbers, tam);

  // write_numbers_array_to_txt_file(numbers, tam);

  return 0;
}