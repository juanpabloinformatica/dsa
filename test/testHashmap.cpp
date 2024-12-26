// #include "gtest/gtest.h"
// extern "C" {
// #include "../implementation/hashmap.h"
// }
// TEST(HashmapTest, HandleHashmapCreation) {
//   Hashmap *hashmap = newHashmap((char *)"number", (char *)"number");
//   EXPECT_TRUE(hashmap != NULL);
// }
// // TEST(HashmapTest, HandleHashmapAddElement) {
// //   Hashmap *hashmap = newHashmap((char *)"number", (char *)"number");
// //   int HASHMAP_SIZE = 16;
// //   int keys[16];
// //   int values[16];
// //   for (int i = 0; i < HASHMAP_SIZE; i++) {
// //     keys[i] = i;
// //     values[i] = i * 120;
// //     hashmap->hashmapPut(hashmap, (int *)&keys[i], (int *)&values[i]);
// //   }
// //   for (int i = 0; i < HASHMAP_SIZE; i++) {
// //     // std::cout << "inside here" << std::endl;
// //     LinkedList *listT = ((LinkedList *)(hashmap->array)[i]);
// //     LinkedListNode *lln = (LinkedListNode *)listT->head;
// //     HashmapNode *hn = (HashmapNode *)lln->element;
// //     // std::cout << hn << std::endl;
// //     ASSERT_EQ(*(int *)hn->key, keys[i]);
// //     ASSERT_EQ(*(int *)hn->value, values[i]);
// //   }
// // }
// // TEST(HashmapTest, HandleHashmapRemoveElement) {
// //   Hashmap *hashmap = newHashmap((char *)"number", (char *)"number");
// //   int HASHMAP_SIZE = 32;
// //   int keys[HASHMAP_SIZE];
// //   int values[HASHMAP_SIZE];
// //   for (int i = 0; i < HASHMAP_SIZE; i++) {
// //     keys[i] = i;
// //     values[i] = i * 120;
// //     hashmap->hashmapPut(hashmap, (int *)&keys[i], (int *)&values[i]);
// //   }
// //   for (int i = 0; i < HASHMAP_SIZE; i++) {
// //     hashmap->hashmapRemove(hashmap, (int *)&keys[i]);
// //   }
// //   // for (int i = 0; i < HASHMAP_SIZE / 2; i++) {
// //   //   hashmap->hashmapRemove(hashmap, (int *)&keys[i]);
// //   // }

// //   for (int i = 0; i < HASHMAP_SIZE / 2; i++) {
// //     LinkedList *listT = ((LinkedList *)(hashmap->array)[i]);
// //     EXPECT_TRUE(listT->head == NULL);
// //   }
// //   // for (int i = 0; i < HASHMAP_SIZE; i++) {
// //   //   std::cout << "inside here" << std::endl;
// //   //   LinkedList *listT = ((LinkedList *)(hashmap->array)[i]);
// //   //   ASSERT_TRUE(listT != NULL);
// //   //   LinkedListNode *lln = (LinkedListNode *)listT->head;
// //   //   ASSERT_TRUE(lln == NULL);
// //   // }
// // }
// TEST(HashmapTest, HandleGetElement) {

//   Hashmap *hashmap = newHashmap((char *)"number", (char *)"number");
//   int HASHMAP_SIZE = 32;
//   int keys[HASHMAP_SIZE];
//   int values[HASHMAP_SIZE];
//   for (int i = 0; i < HASHMAP_SIZE; i++) {
//     keys[i] = i;
//     values[i] = i * 120;
//     hashmap->hashmapPut(hashmap, (int *)&keys[i], (int *)&values[i]);
//   }

//   for (int i = 0; i < HASHMAP_SIZE; i++) {
//     keys[i] = i;
//     values[i] = i * 120;
//     LinkedListNode *lln =
//         ((LinkedListNode *)hashmap->hashmapGet(hashmap, (int *)&keys[i]));
//     ASSERT_TRUE(lln != NULL);
//     HashmapNode *hhn = ((HashmapNode *)lln->element);
//     ASSERT_TRUE(hhn->key != NULL);
//     ASSERT_TRUE(hhn->value != NULL);
//     // int value = hashmap->hashmapGet(hashmap, (int *)&keys[i]);
//     ASSERT_TRUE(*(int *)hhn->value == values[i]);
//   }
// }
// TEST(HashmapTest, HandleContainsKey) {

//   Hashmap *hashmap = newHashmap((char *)"number", (char *)"number");
//   int HASHMAP_SIZE = 32;
//   int keys[HASHMAP_SIZE];
//   int values[HASHMAP_SIZE];
//   for (int i = 0; i < HASHMAP_SIZE; i++) {
//     keys[i] = i;
//     values[i] = i * 120;
//     hashmap->hashmapPut(hashmap, (int *)&keys[i], (int *)&values[i]);
//   }
//   bool exist;
//   for (int i = 0; i < HASHMAP_SIZE; i++) {
//     exist = hashmap->hashmapContainsKey(hashmap, (int *)&keys[i]);
//     ASSERT_TRUE(exist == true);
//   }
//   int inventedKey = 40;
//   int *ptrInventedKey = &inventedKey;
//   exist = hashmap->hashmapContainsKey(hashmap, ptrInventedKey);
//   ASSERT_TRUE(exist == false);
// }
