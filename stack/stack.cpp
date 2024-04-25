#include <iostream>
#include <vector>
using namespace std;

class Element {

public:
  int elementValue;
  Element(int value) : elementValue(value) {}
};

class Stack {
private:
  vector<Element *> elements;
  int elementCount;

public:
  Stack() : elementCount(0) {}

  // Metode untuk membuat stack baru dengan elemen kosong
  void New() {
    elements.clear();
    elementCount = 0;
  }

  void Push(Element *element) {
    elements.push_back(new Element(*element));
    elementCount++;
  }

  Element *Pop() {
    if (elementCount == 0) {
      return nullptr;
    }
    Element *element = elements.back(); // dapatkan element teratas
    elements.pop_back();                // hapus element teratas dari vector
    elementCount--;                     // kurangi jumlah element
    return element;
  }
};

int main() {
  Stack stack;
  stack.New();

  Element *element1 = new Element(3);
  Element *element2 = new Element(5);
  Element *element3 = new Element(7);
  Element *element4 = new Element(9);

  stack.Push(element1);
  stack.Push(element2);
  stack.Push(element3);
  stack.Push(element4);

  cout << stack.Pop()->elementValue << " ";
  cout << stack.Pop()->elementValue << " ";
  cout << stack.Pop()->elementValue << " ";
  cout << stack.Pop()->elementValue << " " << endl;
  return 0;
}
