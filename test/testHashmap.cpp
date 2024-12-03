#include "gtest/gtest.h"
extern "C" {
#include "../implementation/dsa.h"
}
TEST(HashmapTest, HandleHashmapCreation) {
  Hashmap *hashmap = newHashmap((char *)"number", (char *)"number");
  EXPECT_TRUE(hashmap != NULL);
}
TEST(HashmapTest, HandleHashmapAddElement) {
  Hashmap *hashmap = newHashmap((char *)"number", (char *)"number");
  int HASHMAP_SIZE = 16;
  int keys[16];
  int values[16];
  for (int i = 0; i < HASHMAP_SIZE; i++) {
    keys[i] = i;
    values[i] = i * 120;
    hashmap->hashmapPut(hashmap, (int *)&keys[i], (int *)&values[i]);
  }
  for (int i = 0; i < 32 / 2; i++) {
    LinkedList *listT = &((LinkedList *)(hashmap->array))[i];
    // assert(listT->deleteLinkedListNode != NULL);
    assert(listT->showLinkedList != NULL);
    printf("\n------ I:%i------\n", i);
    listT->showLinkedList(listT);
    printf("\n-------------\n", i);
  }
  // for (int i = 0; i < 32 / 2; i++) {
  //   LinkedList *listT = &((LinkedList *)hashmap->array)[i];
  //   // assert(listT->deleteLinkedListNode != NULL);
  //   assert(listT->showLinkedList != NULL);
  //   printf("\n------ I:%i------\n", i);
  //   listT->showLinkedList(listT);
  //   printf("\n-------------\n", i);
  // }
  // for (int i = 0; i < HASHMAP_SIZE; i++) {
  //   std::cout << "inside here" << std::endl;
  //   LinkedList ll = ((LinkedList *)hashmap->array)[0];
  //   LinkedListNode *lln = (LinkedListNode *)ll.head;
  //   HashmapNode *hn = (HashmapNode *)lln->element;
  //   std::cout << hn << std::endl;
  //   ASSERT_EQ(*(int *)hn->key, keys[i]);
  //   ASSERT_EQ(*(int *)hn->value, values[i]);
  // }
}
// TEST()
