#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void printList(Node* head);
void pushFront(Node** head, int data);
void pushBack(Node** head, int data);
void popFront(Node** head);
void removeValue(Node** head, int data);
void swapNodes(Node* first, Node* second);
void freeList(Node** head);

int main(void) {
    //   ========================================
    //   1. СОЗДАНИЕ СПИСКА ВРУЧНУЮ
    //   ========================================

  Node node1;
  Node node2;
  Node node3;

  node1.data = 10;
  node2.data = 20;
  node3.data = 30;

  node1.next = &node2;
  node2.next = &node3;
  node3.next = NULL;

  Node* head = &node1;

//   printf("Список, созданный вручную:\n");
//   printList(head);
  // ========================================
  // 2. СОЗДАНИЕ СПИСКА ЧЕРЕЗ ФУНКЦИИ
  // ========================================

  Node* list = NULL;

  pushBack(&list, 10);
  pushBack(&list, 20);
  pushBack(&list, 30);
  pushBack(&list, 40);

  printf("\nСписок после pushBack:\n");
  printList(list);

  // Добавление в начало

  pushFront(&list, 5);

  printf("\nПосле pushFront(5):\n");
  printList(list);

  // ========================================
  // 3. УДАЛЕНИЕ ПЕРВОГО ЭЛЕМЕНТА
  // ========================================

  popFront(&list);

  printf("\nПосле popFront():\n");
  printList(list);

  // ========================================
  // 4. УДАЛЕНИЕ ЭЛЕМЕНТА ПО ЗНАЧЕНИЮ
  // ========================================

  removeValue(&list, 30);

  printf("\nПосле removeValue(30):\n");
  printList(list);

  // ========================================
  // 5. ОБМЕН ЗНАЧЕНИЙ
  // ========================================

  swapNodes(list, list->next);

  printf("\nПосле swap первых двух элементов:\n");
  printList(list);

  // ========================================
  // 6. УДАЛЕНИЕ ВСЕГО СПИСКА
  // ========================================

  freeList(&list);

  printf("\nПосле freeList():\n");
  printList(list);
  
  return 0;
}


//----------------------------------------------
//     РЕАЛИЗАЦИИ ФУНКЦИЙ
//----------------------------------------------


/* Печать списка */
void printList(Node* head) {
  Node* current = head;

  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }

  printf("NULL\n");
}

/* Добавление элемента в начало списка */
void pushFront(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));

  if (newNode == NULL) {
    printf("Ошибка выделения памяти\n");
    return;
  }

  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

/* Добавление элемента в конец списка */
void pushBack(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));

  if (newNode == NULL) {
    printf("Ошибка выделения памяти\n");
    return;
  }

  newNode->data = data;
  newNode->next = NULL;

  /* Если список пуст */
  if (*head == NULL) {
    *head = newNode;
    return;
  }

  /* Ищем последний элемент */
  Node* current = *head;

  while (current->next != NULL) {
    current = current->next;
  }
  
  current->next = newNode;
}



/* Удаление первого элемента */
void popFront(Node** head) {
  if (*head == NULL) {
    return;
  }

  Node* temp = *head;
  *head = (*head)->next;

  free(temp);
}

/* Удаление элемента с заданным значением */
void removeValue(Node** head, int data) {
  if (*head == NULL) {
    return;
  }

  /* Если удаляем первый элемент */
  if ((*head)->data == data) {
    popFront(head);
    return;
  }

  Node* current = *head;

  while (current->next != NULL) {
    if (current->next->data == data) {
      Node* temp = current->next;

      current->next = temp->next;
      free(temp);

      return;
    }

    current = current->next;
  }
}

/* Обмен значений двух соседних узлов */
void swapNodes(Node* first, Node* second) {
  if (first == NULL || second == NULL) {
    return;
  }

  int temp = first->data;
  first->data = second->data;
  second->data = temp;
}

/* Удаление всего списка */
void freeList(Node** head) {
  Node* current = *head;

  while (current != NULL) {
    Node* temp = current;
    current = current->next;

    free(temp);
  }

  *head = NULL;
}
