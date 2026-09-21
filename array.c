#include <stdio.h>

void print_array(int* array, int size);

int main() {
  int array[4] = {1, 2, 3, 4};

  printf("%p\n", &array);
  printf("%p\n", array);
  printf("%p\n", array + 1);

  printf("%d\n", *(array + 0));
  printf("%d\n", *(array + 1));
  printf("%d\n", *(array + 2));
  printf("%d\n", *(array + 3));
  printf("\n");

  printf("%d\n", array[0]);
  printf("%d\n", array[1]);
  printf("%d\n", array[2]);
  printf("%d\n", array[3]);

  print_array(array, 5);

  return 0;
}

void print_array(int* array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}