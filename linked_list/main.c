#include "stdio.h"
#include <stdlib.h>

struct Node {
  int property;
  struct Node *nextNode;
};

// linked list class
struct LinkedList {
  struct Node *headNode;
};

void addToHead(struct LinkedList *linkedList, int property) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->property = property;
  if (linkedList->headNode != NULL) {
    node->nextNode = linkedList->headNode;
  }
  linkedList->headNode = node;
}

void iterateList(struct LinkedList *linkedList) {
  struct Node *node;

  for (node = linkedList->headNode; node != NULL; node = node->nextNode) {
    printf("%d\n", node->property);
  }
}

struct Node *lastNode(struct LinkedList *linkedList) {
  struct Node *node;
  struct Node *lastNode = NULL;

  for (node = linkedList->headNode; node != NULL; node = node->nextNode) {
    if (node->nextNode == NULL) {
      lastNode = node;
    }
  }
  return lastNode;
}

void AddToEnd(struct LinkedList *linkedList, int property) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->property = property;
  node->nextNode = NULL;
  struct Node *last = lastNode(linkedList);
  if (last != NULL) {
    last->nextNode = node;
  }
}

struct Node *NodeWithValue(struct LinkedList *linkedList, int property) {
  struct Node *node;
  struct Node *nodeWith = NULL;
  for (node = linkedList->headNode; node != NULL; node = node->nextNode) {
    if (node->property == property) {
      nodeWith = node;
      break;
    }
  }
  return nodeWith;
}

void AddAfter(struct LinkedList *linkedList, int nodeProperty, int property) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->property = property;
  node->nextNode = NULL;
  struct Node *nodeWith = NodeWithValue(linkedList, nodeProperty);
  if (nodeWith != NULL) {
    node->nextNode = nodeWith->nextNode;
    nodeWith->nextNode = node;
  }
}

int main() {
  struct LinkedList linkedList;
  linkedList.headNode = NULL;
  addToHead(&linkedList, 1);
  addToHead(&linkedList, 3);
  AddToEnd(&linkedList, 5);
  AddAfter(&linkedList, 1, 7);
  iterateList(&linkedList);
  return 0;
}
