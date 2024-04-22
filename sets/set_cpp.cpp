#include <iostream>
#include <unordered_map>
#include <vector>

class Set {
private:
  std::unordered_map<int, bool> integerMap;

public:
  // Constructor
  Set() {}

  // Method untuk membuat set baru
  void New() { integerMap.clear(); }

  // Method untuk menambahkan elemen ke dalam set
  void AddElement(int element) {
    if (!ContainsElement(element)) {
      integerMap[element] = true;
    }
  }

  // Method untuk menghapus elemen dari set
  void DeleteElement(int element) { integerMap.erase(element); }

  // Method untuk memeriksa apakah elemen ada dalam set
  bool ContainsElement(int element) const {
    return integerMap.find(element) != integerMap.end();
  }

  // Method untuk mengembalikan set irisan dengan set lainnya
  Set Intersect(const Set &anotherSet) const {
    Set intersectionSet;
    for (const auto &pair : integerMap) {
      if (anotherSet.ContainsElement(pair.first)) {
        intersectionSet.AddElement(pair.first);
      }
    }
    return intersectionSet;
  }

  // Method untuk mengembalikan set gabungan dengan set lainnya
  Set Union(const Set &anotherSet) const {
    Set unionSet(*this);
    for (const auto &pair : anotherSet.integerMap) {
      unionSet.AddElement(pair.first);
    }
    return unionSet;
  }

  // Method untuk mencetak elemen-elemen dalam set
  void PrintSet() const {
    std::cout << "{ ";
    for (const auto &pair : integerMap) {
      std::cout << pair.first << " ";
    }
    std::cout << "}\n";
  }
};

int main() {
  // Inisialisasi set
  Set set, anotherSet;

  set.New();

  set.AddElement(1);
  set.AddElement(2);

  std::cout << "Initial set: ";
  set.PrintSet();

  std::cout << "Contains element 1: " << std::boolalpha
            << set.ContainsElement(1) << std::endl;

  anotherSet.New();

  anotherSet.AddElement(2);
  anotherSet.AddElement(4);
  anotherSet.AddElement(5);

  std::cout << "Another set: ";
  anotherSet.PrintSet();

  std::cout << "Intersection of sets: ";
  set.Intersect(anotherSet).PrintSet();

  std::cout << "Union of sets: ";
  set.Union(anotherSet).PrintSet();

  return 0;
}

