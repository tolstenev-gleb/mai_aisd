#include <stdio.h>
#include <stdlib.h>

// add_element(int **ptr_array, int size, int capacity, int new_elem) {
//   int *array = 0x7ff4;
//   int *ptr = malloc( 2 * capacity);  // 0x7fd0
//   if (ptr == NULL) {
//     return 1;
//   }
//   array = ptr;
//   // array = 0x7fd0;
// }

int main() {
  int size = 0;      // реальное кол-во элементов
  int capacity = 10; // ёмкость (резерв)
  int *ptr = (int *)malloc(capacity * sizeof(int)); // 0x7ff4

  if (ptr == NULL) {
    return 1;
  }
    printf("%p\n", ptr);
    *ptr = 10;
    free(ptr);
    
  // add_element(array, size, capacity, 5);
  // add_element(&array, size, capacity, 5);
  return 0;
}
