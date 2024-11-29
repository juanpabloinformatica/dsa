#include "dsa.h"

int main(void) {
  LinkedList *linkedList = newLinkedList();
  const int ARRAY_LENGTH = 30;
  int elements[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elements[i] = i;
    LinkedListNode *lLNode = newLinkedListNode((int *)&elements[i]);
    linkedList->recAddLinkedListNode(linkedList, lLNode);
  }
  linkedList->recShowLinkedList(linkedList);
  // linkedList->recShowLinkedList(linkedList);
}
