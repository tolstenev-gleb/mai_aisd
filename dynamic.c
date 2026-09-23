#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int capacity;
    int size;
} IntArray;

int add_element(IntArray *ptr_s, int new_elem) {
    if (ptr_s == NULL || ptr_s->array == NULL) {
        return 1; // некорректный указатель или неинициализированный массив
    }

    // Если места нет — увеличиваем ёмкость
    if (ptr_s->size >= ptr_s->capacity) {
        int new_capacity = ptr_s->capacity * 2;
        int *new_array = malloc(new_capacity * sizeof(int));
        if (new_array == NULL) {
            return 1; // не удалось выделить память
        }

        // Копируем старые элементы
        for (int i = 0; i < ptr_s->size; ++i) {
            new_array[i] = ptr_s->array[i];
        }

        free(ptr_s->array);
        ptr_s->array = new_array;
        ptr_s->capacity = new_capacity;
    }

    // Добавляем новый элемент и увеличиваем размер
    ptr_s->array[ptr_s->size] = new_elem;
    ptr_s->size++;

    return 0; // успех
}

int print_array(const IntArray *s) {
    if (s == NULL) {
        return 1;
    }
    printf("array ptr: %p\n", (void *)s->array);
    printf("size: %d\n", s->size);
    printf("capacity: %d\n", s->capacity);

    printf("elements: ");
    for (int i = 0; i < s->size; ++i) {
        printf("%d ", s->array[i]);
    }
    printf("\n");
    return 0;
}

int main(void) {
    IntArray A;
    A.size = 0;
    A.capacity = 2;          // уменьшил для наглядности роста
    A.array = malloc(A.capacity * sizeof(int));

    if (A.array == NULL) {
        return 1;
    }

    print_array(&A);

    add_element(&A, 5);
    add_element(&A, 10);
    add_element(&A, 20);     // вызовет рост массива
    add_element(&A, 30);

    print_array(&A);

    free(A.array);
    return 0;
}
