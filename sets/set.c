#include <stdio.h>
#include <stdlib.h>

// Struktur data Set
struct Set {
  int *integerMap;
  int size;
};

// Fungsi untuk membuat set baru
void newSet(struct Set *set) {
  set->integerMap = NULL;
  set->size = 0;
}

// Fungsi untuk memeriksa apakah elemen ada dalam set
int containsElement(struct Set *set, int element) {
  int i;
  for (i = 0; i < set->size; i++) {
    if (set->integerMap[i] == element) {
      return 1; // true
    }
  }
  return 0; // false
}

// Fungsi untuk menambahkan elemen ke dalam set
void addElement(struct Set *set, int element) {
  if (!containsElement(set, element)) {
    set->size++;
    set->integerMap = (int *)realloc(set->integerMap, set->size * sizeof(int));
    set->integerMap[set->size - 1] = element;
  }
}

// Fungsi untuk menghapus elemen dari set
void deleteElement(struct Set *set, int element) {
  int i, j;
  for (i = 0; i < set->size; i++) {
    if (set->integerMap[i] == element) {
      for (j = i; j < set->size - 1; j++) {
        set->integerMap[j] = set->integerMap[j + 1];
      }
      set->size--;
      set->integerMap =
          (int *)realloc(set->integerMap, set->size * sizeof(int));
      break;
    }
  }
}

// Fungsi untuk melakukan operasi irisan antara dua set
struct Set intersect(struct Set *set1, struct Set *set2) {
  struct Set intersectionSet;
  newSet(&intersectionSet);
  int i;
  for (i = 0; i < set1->size; i++) {
    if (containsElement(set2, set1->integerMap[i])) {
      addElement(&intersectionSet, set1->integerMap[i]);
    }
  }
  return intersectionSet;
}

// Fungsi untuk melakukan operasi gabungan antara dua set
struct Set unionSet(struct Set *set1, struct Set *set2) {
  struct Set unionSet;
  newSet(&unionSet);
  int i;
  for (i = 0; i < set1->size; i++) {
    addElement(&unionSet, set1->integerMap[i]);
  }
  for (i = 0; i < set2->size; i++) {
    addElement(&unionSet, set2->integerMap[i]);
  }
  return unionSet;
}

// Fungsi untuk mencetak elemen-elemen dalam set
void printSet(struct Set *set) {
  int i;
  printf("{ ");
  for (i = 0; i < set->size; i++) {
    printf("%d ", set->integerMap[i]);
  }
  printf("}\n");
}

int main() {
  // Inisialisasi set
  struct Set set1, set2;
  newSet(&set1);
  newSet(&set2);

  // Menambahkan elemen ke dalam set
  addElement(&set1, 1);
  addElement(&set1, 2);
  addElement(&set2, 2);
  addElement(&set2, 4);
  addElement(&set2, 5);

  // Mencetak set awal
  printf("Initial set: ");
  printSet(&set1);

  // Memeriksa apakah elemen ada dalam set
  printf("Contains element 1: %s\n",
         containsElement(&set1, 1) ? "true" : "false");

  // Mencetak set lain
  printf("Another set: ");
  printSet(&set2);

  // Menghitung irisan kedua set
  struct Set intersection = intersect(&set1, &set2);

  // Mencetak hasil irisan
  printf("Intersection of sets: ");
  printSet(&intersection);

  // Menghitung gabungan kedua set
  struct Set unionset = unionSet(&set1, &set2);

  // Mencetak hasil gabungan
  printf("Union of sets: ");
  printSet(&unionset);

  return 0;
}

