#include "testGraph.hpp"
#include <gtest/gtest.h>
void GraphTest::preSetup(void) {
  for (int i = 0; i < NUMBER_VERTICES; i++) {
    verticesTmp[i] = i;
  }
  for (int i = 0; i < NUMBER_VERTICES; i++) {
    Vertex *vertex = newVertex((int *)&verticesTmp[i]);
    vertices[i] = vertex;
  }
  edges[0] = newEdge(vertices[0], vertices[1], NULL);
  edges[1] = newEdge(vertices[0], vertices[4], NULL);
  edges[2] = newEdge(vertices[1], vertices[0], NULL);
  edges[3] = newEdge(vertices[1], vertices[2], NULL);
  edges[4] = newEdge(vertices[1], vertices[3], NULL);
  edges[5] = newEdge(vertices[1], vertices[4], NULL);
  edges[6] = newEdge(vertices[2], vertices[1], NULL);
  edges[7] = newEdge(vertices[2], vertices[3], NULL);
  edges[8] = newEdge(vertices[3], vertices[1], NULL);
  edges[9] = newEdge(vertices[3], vertices[2], NULL);
  edges[10] = newEdge(vertices[3], vertices[4], NULL);
  edges[11] = newEdge(vertices[4], vertices[0], NULL);
  edges[12] = newEdge(vertices[4], vertices[1], NULL);
  edges[13] = newEdge(vertices[4], vertices[3], NULL);
}
void GraphTest::SetUp() {
  std::cout << "Setting up fixture" << std::endl;
  this->preSetup();
  graph = newGraph(this->vertices, this->edges);
}
void GraphTest::TearDown() { destroyGraph(this->graph); }
void GraphTest::show() {
  std::cout << "Graph" << std::endl;
  for (int i = 0; i < NUMBER_VERTICES; i++) {
    std::cout << "vertex " << std::to_string(i) << ": "
              << std::to_string(*(int *)(this->vertices[i]->value))
              << std::endl;
  }
  for (int i = 0; i < NUMBER_EDGES; i++) {
    std::cout << "Edge " << std::to_string(i) << ": "
              << std::to_string(*(int *)(this->edges[i]->source->value))
              << " --> "
              << std::to_string(*(int *)(this->edges[i]->destination->value))
              << std::endl;
  }
}

TEST_F(GraphTest, HandleGraphCreation) {
  show();
  // DynamicArray *edges;
  ASSERT_TRUE(graph != NULL);
  ASSERT_TRUE(edges[0]->source == vertices[0] &&
              edges[0]->destination == vertices[1]);
}

TEST_F(GraphTest, HandleGraphAdjacent) {
  const int testAdjacents = 5;
  bool results[testAdjacents];
  results[0] =
      graph->graphAdjacent(graph, graph->vertices[0], graph->vertices[1]);
  results[1] =
      graph->graphAdjacent(graph, graph->vertices[2], graph->vertices[3]);
  results[2] =
      graph->graphAdjacent(graph, graph->vertices[2], graph->vertices[1]);
  results[3] =
      graph->graphAdjacent(graph, graph->vertices[0], graph->vertices[2]);
  results[4] =
      graph->graphAdjacent(graph, graph->vertices[4], graph->vertices[2]);
  ASSERT_TRUE(results[0] == true);
  ASSERT_TRUE(results[1] == true);
  ASSERT_TRUE(results[2] == true);
  ASSERT_TRUE(results[3] == false);
  ASSERT_TRUE(results[4] == false);
}
TEST_F(GraphTest, HandleGraphNeighbors) {
  Vertex *ptrVertexArray = (Vertex *)malloc(sizeof(Vertex*) * NUMBER_VERTICES);
  ptrVertexArray[0] = *(graph->vertices[0]);
  ptrVertexArray[1] = *(graph->vertices[1]);
  ASSERT_TRUE(*(int *)(ptrVertexArray[0].value) == 0);
  ASSERT_TRUE(*(int *)(ptrVertexArray[1].value) == 4);
  // graph->graphNeighbors(graph, graph->vertices[0], &ptrVertexArray);
  // Vertex neighbor1 = ptrVertexArray[0];
  // Vertex neighbor2 = ptrVertexArray[1];
  // ASSERT_TRUE(*(int *)(neighbor1.value) == 1);
  // ASSERT_TRUE(*(int *)(neighbor2.value) == 4);
}
