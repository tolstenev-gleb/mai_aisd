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

void sum(int a, int b, int *ptr_res) {
  *ptr_res = a + b;
}

int main() {
  int x = 5;
  int y = 7;
  int res = 0;

  printf("res: %d\n", sum(x, y, &res));

  printf("x: %d\n", x);
  printf("y: %d\n", y);

  swap(&x, &y);

  printf("x: %d\n", x);
  printf("y: %d\n", y);
  return 0;
}
