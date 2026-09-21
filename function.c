#include <stdio.h>

int square(int x);  // прототип функции / заголовок / объявление / декларация

// вычисляет квадрат числа
int square(int x) {  // реализация функции
  return x * x;
}

// меняет местами значения двух переменных
void swap(int* ptr_x, int* ptr_y) {
  int tmp = *ptr_x;
  *ptr_x = *ptr_y;
  *ptr_y = tmp;
}

int main() {
  int x = 5;
  int y = 7;

  printf("x: %d\n", x);
  printf("y: %d\n", y);

  swap(&x, &y);

  printf("x: %d\n", x);
  printf("y: %d\n", y);
  return 0;
}
