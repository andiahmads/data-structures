#include <iostream>
using namespace std;

class Node {
public:
  int property;
  Node *nextNode;
  Node(int prop) : property(prop), nextNode(nullptr) {}
};

class LinkedList {
private:
  Node *headNode;

public:
  LinkedList() : headNode(nullptr) {}

  void addToHead(int property) {
    Node *node = new Node(property);
    if (headNode != nullptr) {
      node->nextNode = headNode;
    }
    headNode = node;
  }

  void iterateList() {
    Node *node = headNode;
    while (node != nullptr) {
      cout << node->property << endl;
      node = node->nextNode;
    }
  }

  Node *lastNode() {
    Node *node = headNode;
    Node *lastNode = nullptr;
    while (node != nullptr) {
      if (node->nextNode == nullptr) {
        lastNode = node;
      }
      node = node->nextNode;
    }

    return lastNode;
  }

  void addToEnd(int property) {
    Node *node = new Node(property);
    Node *last = lastNode();
    if (last != nullptr) {
      last->nextNode = node;
    } else {
      headNode = node;
    }
  }

  Node *nodeWithValue(int property) {
    Node *node = headNode;
    Node *nodeWith = nullptr;
    while (node != nullptr) {
      if (node->property == property) {
        nodeWith = node;
        break;
      }
      node = node->nextNode;
    }
    return nodeWith;
  }

  void addAfter(int nodeProperty, int property) {
    Node *node = new Node(property);
    Node *nodeWith = nodeWithValue(nodeProperty);
    if (nodeWith != nullptr) {
      node->nextNode = nodeWith->nextNode;
      nodeWith->nextNode = node;
    }
  }
};

int main() {
  LinkedList linkedList;
  linkedList.addToHead(1);
  linkedList.addToHead(3);
  linkedList.addToEnd(5);
  linkedList.addAfter(1, 7);
  linkedList.iterateList();
  return 0;
}
