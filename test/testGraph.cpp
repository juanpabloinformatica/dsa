#include "testGraph.hpp"
#include <gtest/gtest.h>
#include <string>
void GraphTest::preSetup(void) {
  vertices = newDynamicArray(NULL);
  for (int i = 0; i < NUMBER_VERTICES; i++) {
    verticesTmp[i] = i;
  }
  for (int i = 0; i < NUMBER_VERTICES; i++) {
    Vertex *vertex = newVertex((int *)&verticesTmp[i]);
    vertices->addElement(vertices, vertex);
  }
  edges = newDynamicArray(NULL);
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 0),
                            (Vertex *)vertices->getElement(vertices, 1), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 0),
                            (Vertex *)vertices->getElement(vertices, 4), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 1),
                            (Vertex *)vertices->getElement(vertices, 0), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 1),
                            (Vertex *)vertices->getElement(vertices, 2), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 1),
                            (Vertex *)vertices->getElement(vertices, 3), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 1),
                            (Vertex *)vertices->getElement(vertices, 4), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 2),
                            (Vertex *)vertices->getElement(vertices, 1), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 2),
                            (Vertex *)vertices->getElement(vertices, 3), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 3),
                            (Vertex *)vertices->getElement(vertices, 1), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 3),
                            (Vertex *)vertices->getElement(vertices, 2), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 3),
                            (Vertex *)vertices->getElement(vertices, 4), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 4),
                            (Vertex *)vertices->getElement(vertices, 0), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 4),
                            (Vertex *)vertices->getElement(vertices, 1), NULL));
  edges->addElement(edges,
                    newEdge((Vertex *)vertices->getElement(vertices, 4),
                            (Vertex *)vertices->getElement(vertices, 3), NULL));
}
void GraphTest::SetUp() {
  std::cout << "Setting up fixture" << std::endl;
  this->preSetup();
  graph = newGraph(this->vertices, this->edges);
}
void GraphTest::TearDown() {
  destroyDynamicArray(this->vertices);
  destroyDynamicArray(this->edges);
  destroyGraph(this->graph);
  std::cout << "Cleaning up fixture" << std::endl;
}
void GraphTest::show() {
  std::cout << "Graph" << std::endl;
  // I need to change to this->graph->....
  for (int i = 0; i < this->vertices->counter; i++) {
    std::cout << "vertex " << std::to_string(i) << ": "
              << std::to_string(*(
                     int *)(((Vertex *)this->vertices->getElement(vertices, i))
                                ->value))
              << std::endl;
  }
  // I need to change to this->graph->....
  for (int i = 0; i < this->edges->counter; i++) {
    std::cout
        << "Edge " << std::to_string(i) << ": "
        << std::to_string(*(int *)((
               ((Edge *)this->edges->getElement(edges, i))->source->value)))
        << " --> "
        << std::to_string(*(int *)((((Edge *)this->edges->getElement(edges, i))
                                        ->destination->value)))
        << std::endl;
  }
}

TEST_F(GraphTest, HandleGraphCreation) {
  show();
  ASSERT_TRUE(this->graph != NULL);
  Vertex *edgeSource, *edgeDestination;
  Vertex *vertex1, *vertex2;
  edgeSource = ((Edge *)this->edges->getElement(this->edges, 0))->source;
  edgeDestination =
      ((Edge *)this->edges->getElement(this->edges, 0))->destination;
  vertex1 = ((Vertex *)this->vertices->getElement(this->vertices, 0));
  vertex2 = ((Vertex *)this->vertices->getElement(this->vertices, 1));
  ASSERT_TRUE(edgeSource == vertex1 && edgeDestination == vertex2);
}

TEST_F(GraphTest, HandleGraphAdjacent) {
  const int testAdjacents = 5;
  bool results[testAdjacents];
  results[0] = graph->graphAdjacent(
      graph, ((Vertex *)graph->vertices->getElement(graph->vertices, 0)),
      ((Vertex *)graph->vertices->getElement(graph->vertices, 1)));
  results[1] = graph->graphAdjacent(
      graph, ((Vertex *)graph->vertices->getElement(graph->vertices, 2)),
      ((Vertex *)graph->vertices->getElement(graph->vertices, 3)));
  results[2] = graph->graphAdjacent(
      graph, ((Vertex *)graph->vertices->getElement(graph->vertices, 2)),
      ((Vertex *)graph->vertices->getElement(graph->vertices, 1)));
  results[3] = graph->graphAdjacent(
      graph, ((Vertex *)graph->vertices->getElement(graph->vertices, 0)),
      ((Vertex *)graph->vertices->getElement(graph->vertices, 2)));
  results[4] = graph->graphAdjacent(
      graph, ((Vertex *)graph->vertices->getElement(graph->vertices, 4)),
      ((Vertex *)graph->vertices->getElement(graph->vertices, 2)));
  ASSERT_TRUE(results[0] == true);
  ASSERT_TRUE(results[1] == true);
  ASSERT_TRUE(results[2] == true);
  ASSERT_TRUE(results[3] == false);
  ASSERT_TRUE(results[4] == false);
}
TEST_F(GraphTest, HandleGraphNeighbors) {
  // Vertex *ptrVertexArray[NUMBER_VERTICES];
  DynamicArray *vertexNeighbors = newDynamicArray(NULL);
  graph->graphNeighbors(
      graph, ((Vertex *)graph->vertices->getElement(graph->vertices, 0)),
      vertexNeighbors);
  Vertex *neighbor0 =
      ((Vertex *)vertexNeighbors->getElement(vertexNeighbors, 0));
  Vertex *neighbor1 =
      ((Vertex *)vertexNeighbors->getElement(vertexNeighbors, 1));
  ASSERT_TRUE(*(int *)(neighbor0->value) == 1);
  ASSERT_TRUE(*(int *)(neighbor1->value) == 4);
  destroyDynamicArray(vertexNeighbors);
  vertexNeighbors = newDynamicArray(NULL);
  graph->graphNeighbors(
      graph, ((Vertex *)graph->vertices->getElement(graph->vertices, 1)),
      vertexNeighbors);
  neighbor0 = ((Vertex *)vertexNeighbors->getElement(vertexNeighbors, 0));
  neighbor1 = ((Vertex *)vertexNeighbors->getElement(vertexNeighbors, 1));
  Vertex *neighbor2 =
      ((Vertex *)vertexNeighbors->getElement(vertexNeighbors, 2));
  Vertex *neighbor3 =
      ((Vertex *)vertexNeighbors->getElement(vertexNeighbors, 3));
  ASSERT_TRUE(*(int *)(neighbor0->value) == 0);
  ASSERT_TRUE(*(int *)(neighbor1->value) == 2);
  ASSERT_TRUE(*(int *)(neighbor2->value) == 3);
  ASSERT_TRUE(*(int *)(neighbor3->value) == 4);
  destroyDynamicArray(vertexNeighbors);
}
TEST_F(GraphTest, HandleGraphAddVertex) {
  const int VERTICES_VALUES_LENGTH = 10;
  int verticesValues[VERTICES_VALUES_LENGTH];
  for (int i = 0; i < VERTICES_VALUES_LENGTH; i++) {
    verticesValues[i] = i + 6;
  }
  for (int i = 0; i < VERTICES_VALUES_LENGTH; i++) {
    Vertex *vertex = newVertex((int *)&verticesValues[i]);
    graph->vertices->addElement(graph->vertices, vertex);
  }
  // show();
}
