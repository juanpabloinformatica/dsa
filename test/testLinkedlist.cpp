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
  linkedList->recShowLinkedList(linkedList);
  int arrayIndex = 0;
  while (linkedList->head != NULL) {
    ASSERT_EQ(*(int *)linkedList->head->element, arrayIndex++);
    linkedList->head = linkedList->head->next;
  }
  std::cout << "\nHERE";
  std::cout << arrayIndex;
  EXPECT_TRUE(arrayIndex > 5);
}
// TEST(TestLinkedList, HandleRemoveElementLinkedList) {
//
//   LinkedList *linkedList = newLinkedList();
//   const int ARRAY_LENGTH = 30;
//   int elements[ARRAY_LENGTH];
//   for (int i = 0; i < ARRAY_LENGTH; i++) {
//     elements[i] = i;
//     LinkedListNode *lLNode = newLinkedListNode((int *)&elements[i]);
//     linkedList->recAddLinkedListNode(linkedList, lLNode);
//   }
//   linkedList->recShowLinkedList(linkedList);
//   for (int i = 0; i < ARRAY_LENGTH; i++) {
//     LinkedListNode *lLNode = newLinkedListNode((int *)&elements[i]);
//     linkedList->recDeleteLinkedListNode(linkedList, lLNode);
//     ASSERT_EQ(*(int *)linkedList->head->element, i + 1);
//   }
// }
