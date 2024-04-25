#include <stdio.h>
#include <stdlib.h>

// Definisi struktur Element
struct Element {
  int elementValue;
};

// Fungsi untuk mengonversi nilai elemen menjadi string
char *toString(struct Element *element) {
  // Alokasikan memori untuk string
  char *str = (char *)malloc(
      12 * sizeof(char)); // Panjang maksimum digit dalam int adalah 10, plus 1
                          // untuk karakter null terminator

  // Konversi nilai integer menjadi string
  sprintf(str, "%d", element->elementValue);

  return str;
}

// Definisi struktur Stack
struct Stack {
  struct Element **elements;
  int elementCount;
};

// Fungsi untuk membuat stack baru
void newStack(struct Stack *stack) {
  stack->elements = NULL;
  stack->elementCount = 0;
}

// Fungsi untuk menambahkan elemen ke dalam stack
void push(struct Stack *stack, struct Element *element) {
  stack->elementCount++;
  stack->elements = (struct Element **)realloc(
      stack->elements, stack->elementCount * sizeof(struct Element *));
  stack->elements[stack->elementCount - 1] = element;
}

// Fungsi untuk menghapus dan mengembalikan elemen teratas dari stack
struct Element *pop(struct Stack *stack) {
  if (stack->elementCount == 0) {
    return NULL;
  }

  struct Element *element = stack->elements[stack->elementCount - 1];
  stack->elementCount--;

  if (stack->elementCount > 0) {
    stack->elements = (struct Element **)realloc(
        stack->elements, stack->elementCount * sizeof(struct Element *));
  } else {
    free(stack->elements);
    stack->elements = NULL;
  }

  return element;
}

int main() {
  // Inisialisasi stack
  struct Stack stack;
  newStack(&stack);

  // Buat elemen-elemen baru
  struct Element element1 = {3};
  struct Element element2 = {5};
  struct Element element3 = {7};
  struct Element element4 = {9};

  // Push elemen-elemen ke dalam stack
  push(&stack, &element1);
  push(&stack, &element2);
  push(&stack, &element3);
  push(&stack, &element4);

  // Pop dan cetak elemen-elemen dari stack
  printf("%s ", toString(pop(&stack)));
  printf("%s ", toString(pop(&stack)));
  printf("%s ", toString(pop(&stack)));
  printf("%s\n", toString(pop(&stack)));

  return 0;
}

