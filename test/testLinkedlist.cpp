#include "gtest/gtest.h"
extern "C" {
#include "../implementation/linkedList.h"
}
TEST(TestLinkedList, HandleLinkedListCreation) {
  LinkedList *linkedList = newLinkedList();
  EXPECT_TRUE(linkedList != NULL);
}
TEST(TestLinkedList, HandleAddElementLinkedList) {
  LinkedList *linkedList = newLinkedList();
  const int ARRAY_LENGTH = 30;
  int elements[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elements[i] = i;
    LinkedListNode *lLNode = newLinkedListNode((int *)&elements[i]);
    linkedList->recAddLinkedListNode(linkedList, lLNode);
  }
  int arrayIndex = 0;
  while (linkedList->head != NULL) {
    ASSERT_EQ(*(int *)linkedList->head->element, arrayIndex++);
    linkedList->head = linkedList->head->next;
  }
}
TEST(TestLinkedList, HandleRemoveElementLinkedList) {

  LinkedList *linkedList = newLinkedList();
  const int ARRAY_LENGTH = 30;
  int elements[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elements[i] = i;
    LinkedListNode *lLNode = newLinkedListNode((int *)&elements[i]);
    linkedList->recAddLinkedListNode(linkedList, lLNode);
  }
  LinkedList *antLinkedList;
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    antLinkedList->head = NULL;
    LinkedListNode *lLNode = newLinkedListNode((int *)&elements[i]);
    linkedList->recDeleteLinkedListNode(linkedList, antLinkedList, lLNode);
    ASSERT_EQ(*(int *)linkedList->head->element, i + 1);
  }
}
