#include "gtest/gtest.h"
extern "C" {
#include "../implementation/graph.h"
}
TEST(GraphTest, HandleGraphCreation) {
  Graph *graph = newGraph(NULL, NULL);
  ASSERT_TRUE(graph != NULL);
}
