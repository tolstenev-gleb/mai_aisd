#include <stdio.h>

int main() {
  int k = 42;  // Объявление переменной k

  printf("    k: %d\n", k);   // Значение переменной k
  printf("   &k: %p\n", &k);  // Адрес переменной k
  printf("\n");

  int *pk = &k;  // Объявление указателя pk, который хранит адрес k

  printf("   pk: %p\n", pk);   // Значение указателя pk
  printf("  *pk: %d\n", *pk);  // Разыменование указателя pk
  printf("  &pk: %p\n", &pk);  // Адрес указателя pk
  printf("\n");

  *pk = 21;                  // Изменение значения по указателю pk
  printf("    k: %d\n", k);  // Новое значение k
  printf("\n");

  int **ppk = &pk;  // Объявление ppk - указателя на указатель pk

  printf("  ppk: %p\n", ppk);    // Значение указателя ppk
  printf(" *ppk: %p\n", *ppk);   // Разыменование указателя ppk
  printf("**ppk: %d\n", **ppk);  // Двойное разыменование указателя ppk

  return 0;
}
