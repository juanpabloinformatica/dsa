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
    linkedList->addLinkedListNode(linkedList, lLNode);
  }
  int arrayIndex = 0;
  while (linkedList->head != NULL) {
    ASSERT_EQ(*(int *)linkedList->head->element, arrayIndex++);
    linkedList->head = linkedList->head->next;
  }
  EXPECT_TRUE(arrayIndex == ARRAY_LENGTH);
}
TEST(TestLinkedList, HandleGetElement) {
  LinkedList *linkedList = newLinkedList();
  const int ARRAY_LENGTH = 30;
  int elements[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elements[i] = i;
    LinkedListNode *lLNode = newLinkedListNode((int *)&elements[i]);
    linkedList->addLinkedListNode(linkedList, lLNode);
  }
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    elements[i] = i;
    LinkedListNode *lLNode = newLinkedListNode((int *)&elements[i]);
    LinkedListNode *lln =
        (LinkedListNode *)(linkedList->getLinkedListNode(linkedList, lLNode));
    HashmapNode*hln = (HashmapNode*)(lln->element);
    ASSERT_TRUE(*(int*)hln->);
  }
}
// TEST(TestLinkedList, HandleRemoveElementLinkedList) {
//   //
//   LinkedList *linkedList = newLinkedList();
//   const int ARRAY_LENGTH = 30;
//   int elements[ARRAY_LENGTH];
//   for (int i = 0; i < ARRAY_LENGTH; i++) {
//     elements[i] = i;
//     LinkedListNode *lLNode = newLinkedListNode((int *)&elements[i]);
//     linkedList->addLinkedListNode(linkedList, lLNode);
//   }
//   std::cout << "First linkedList\n";
//   linkedList->showLinkedList(linkedList);
//   // for (int i = 0; i < ARRAY_LENGTH; i++) {
//   //   LinkedListNode *lLNode = newLinkedListNode((int *)&elements[i]);
//   //   linkedList->deleteLinkedListNode(linkedList, lLNode);
//   //   // ASSERT_EQ(*(int *)linkedList->head->element, i + 1);
//   //   std::cout << "\nI:" << i << std::endl;
//   //   linkedList->showLinkedList(linkedList);
//   // }
//   LinkedListNode *lLNode =
//       newLinkedListNode((int *)&elements[ARRAY_LENGTH - 1]);
//   linkedList->deleteLinkedListNode(linkedList, lLNode);
//   std::cout << "\nFinal result\n";
//   linkedList->showLinkedList(linkedList);
//   // linkedList->showLinkedList(linkedList);
// }
