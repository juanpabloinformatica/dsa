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
// normal keep a integer value instead of hashmapValue
// TEST(TestLinkedList, HandleGetElementFromNormalNode) {
//   LinkedList *linkedList = newLinkedList();
//   const int ARRAY_LENGTH = 30;
//   int elements[ARRAY_LENGTH];
//   for (int i = 0; i < ARRAY_LENGTH; i++) {
//     elements[i] = i;
//     LinkedListNode *lLNode = newLinkedListNode((int *)&elements[i]);
//     linkedList->addLinkedListNode(linkedList, lLNode);
//   }
//   for (int i = 0; i < ARRAY_LENGTH; i++) {
//     elements[i] = i;
//     LinkedListNode *lLNode = newLinkedListNode((int *)&elements[i]);
//     LinkedListNode *lln =
//         (LinkedListNode *)(linkedList->getLinkedListNode(linkedList, lLNode));
//     int value = *(int *)(lln->element);
//     ASSERT_TRUE(value == elements[i]);
//   }
// }
TEST(TestLinkedList, HandleGetElementFromHashmapNode) {
  LinkedList *linkedList = newLinkedList();
  const int ARRAY_LENGTH = 30;
  int keys[ARRAY_LENGTH];
  int values[ARRAY_LENGTH];
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    keys[i] = i;
    values[i] = i * 120;
    HashmapNode *hNode = newHashmapNode((int *)&keys[i], (int *)&values[i]);
    LinkedListNode *lLNode = newLinkedListNode(hNode);
    linkedList->addLinkedListNode(linkedList, lLNode);
  }
  for (int i = 0; i < ARRAY_LENGTH; i++) {
    HashmapNode *hNode = newHashmapNode((int *)&keys[i], (int *)&values[i]);
    LinkedListNode *lLNode = newLinkedListNode(hNode);
    LinkedListNode *lln =
        (LinkedListNode *)(linkedList->getLinkedListNode(linkedList, lLNode));
    HashmapNode *hn = ((HashmapNode *)lln->element);
    int key = *(int *)(hn->key);
    int value = *(int *)(hn->value);
    ASSERT_TRUE(key == keys[i]);
    ASSERT_TRUE(value == values[i]);
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
