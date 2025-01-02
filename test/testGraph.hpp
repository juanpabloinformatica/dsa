#ifndef __GRAPH_TEST__
#define __GRAPH_TEST__
extern "C" {
#include "../implementation/graph.h"
}
#include <gtest/gtest.h>
using ::testing::Test;
class GraphTest : public Test {
protected:
  Graph *graph;
  int verticesTmp[NUMBER_VERTICES];
  DynamicArray *vertices;
  DynamicArray *edges;
  // Vertex *vertices[NUMBER_VERTICES];
  // Edge *edges[NUMBER_EDGES];
  void preSetup(void);
  void SetUp() override;
  void TearDown() override;
  void show();
};
#endif
