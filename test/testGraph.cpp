#include "testGraph.hpp"
#include <gtest/gtest.h>
#include <string>
void GraphTest::preSetup(void) {
  vertices = newDynamicArray();
  for (int i = 0; i < NUMBER_VERTICES; i++) {
    verticesTmp[i] = i;
  }
  for (int i = 0; i < NUMBER_VERTICES; i++) {
    Vertex *vertex = newVertex((int *)&verticesTmp[i]);
    vertices->addElement(vertices, vertex);
  }
  edges = newDynamicArray();
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
}
void GraphTest::show() {
  std::cout << "Graph" << std::endl;
  for (int i = 0; i < this->vertices->counter; i++) {
    std::cout << "vertex " << std::to_string(i) << ": "
              << std::to_string(*(
                     int *)(((Vertex *)this->vertices->getElement(vertices, i))
                                ->value))
              << std::endl;
  }
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

// TEST_F(GraphTest, HandleGraphAdjacent) {
//   const int testAdjacents = 5;
//   bool results[testAdjacents];
//   results[0] =
//       graph->graphAdjacent(graph, graph->vertices[0], graph->vertices[1]);
//   results[1] =
//       graph->graphAdjacent(graph, graph->vertices[2], graph->vertices[3]);
//   results[2] =
//       graph->graphAdjacent(graph, graph->vertices[2], graph->vertices[1]);
//   results[3] =
//       graph->graphAdjacent(graph, graph->vertices[0], graph->vertices[2]);
//   results[4] =
//       graph->graphAdjacent(graph, graph->vertices[4], graph->vertices[2]);
//   ASSERT_TRUE(results[0] == true);
//   ASSERT_TRUE(results[1] == true);
//   ASSERT_TRUE(results[2] == true);
//   ASSERT_TRUE(results[3] == false);
//   ASSERT_TRUE(results[4] == false);
// }
// TEST_F(GraphTest, HandleGraphNeighbors) {
//   // Vertex *ptrVertexArray = (Vertex *)malloc(sizeof(Vertex*) *
//   // NUMBER_VERTICES);
//   Vertex *ptrVertexArray[NUMBER_VERTICES];
//   ptrVertexArray[0] = (graph->vertices[0]);
//   ptrVertexArray[1] = (graph->vertices[1]);
//   ASSERT_TRUE(*(int *)(ptrVertexArray[0]->value) == 0);
//   ASSERT_TRUE(*(int *)(ptrVertexArray[1]->value) == 1);
//   graph->graphNeighbors(graph, graph->vertices[0], ptrVertexArray);
//   Vertex *neighbor1 = ptrVertexArray[0];
//   Vertex *neighbor2 = ptrVertexArray[1];
//   ASSERT_TRUE(*(int *)(neighbor1->value) == 1);
//   ASSERT_TRUE(*(int *)(neighbor2->value) == 4);

//   Vertex *ptrVertexArray2[NUMBER_VERTICES];
//   graph->graphNeighbors(graph, graph->vertices[1], ptrVertexArray2);
//   ASSERT_TRUE((*(int *)(ptrVertexArray2[0]->value) == 0));
//   ASSERT_TRUE((*(int *)(ptrVertexArray2[1]->value) == 2));
//   ASSERT_TRUE((*(int *)(ptrVertexArray2[2]->value) == 3));
//   ASSERT_TRUE((*(int *)(ptrVertexArray2[3]->value) == 4));
//   std::cout << "Vertex: "
//             << std::to_string(*(int *)((graph->vertices[1])->value))
//             << std::endl;
//   for (int i = 0; i < NUMBER_VERTICES; i++) {
//     std::cout << *(int *)((ptrVertexArray2[i])->value) << std::endl;
//   }
// }
