#include "graph.h"
#include "dynamicArray.h"
Vertex *newVertex(void *value) {
  Vertex *ptrVertex = (Vertex *)malloc(sizeof(Vertex));
  ptrVertex->value = value;
  return ptrVertex;
}
Edge *newEdge(Vertex *vertexS, Vertex *vertexD, void *value) {
  Edge *ptrEdge = (Edge *)malloc(sizeof(Edge));
  ptrEdge->source = vertexS;
  ptrEdge->destination = vertexD;
  return ptrEdge;
}
Graph *newGraph(DynamicArray *vertices, DynamicArray *edges) {
  Graph *ptrGraph = (Graph *)malloc(sizeof(Graph));
  ptrGraph->vertices = newDynamicArray(vertices);
  ptrGraph->edges = newDynamicArray(edges);
  ptrGraph->graphAdjacent = graphAdjacent;
  ptrGraph->graphNeighbors = graphNeighbors;
  ptrGraph->graphAddVertex = graphAddVertex;
  ptrGraph->graphAddEdge = graphAddEdge;
  ptrGraph->graphRemoveEdge = graphRemoveEdge;
  ptrGraph->graphGetVertexValue = graphGetVertexValue;
  ptrGraph->graphGetEdgeValue = graphGetEdgeValue;
  ptrGraph->graphSetEdgeValue = graphSetEdgeValue;
  return ptrGraph;
}

static void _adjacentVertex(Edge *tmpEdge, DynamicArray *edges, int i,
                            int edgeSize, bool *ptrFound) {
  if (i == edgeSize || *ptrFound == true) {
    return;
  }
  // As I am using both sides, I should compare with an or for the inverse
  // order
  if (*(int *)(((Edge *)edges->getElement(edges, i))->destination->value) ==
          *(int *)(tmpEdge->destination->value) &&
      (*(int *)(((Edge *)edges->getElement(edges, i))->source->value) ==
       *(int *)(tmpEdge->source->value))) {
    *ptrFound = true;
  }
  _adjacentVertex(tmpEdge, edges, ++i, edgeSize, ptrFound);
}
// I should use a hashmap I know proximately
bool graphAdjacent(Graph *graph, Vertex *vertex1, Vertex *vertex2) {
  Edge *tmpEdge = newEdge(vertex1, vertex2, NULL);
  bool found = false;
  bool *ptrFound = &found;
  _adjacentVertex(tmpEdge, graph->edges, 0, graph->edges->counter, ptrFound);
  destroyEdge(tmpEdge);
  return found;
}
// this should return vertices
static void _getNeighbors(Vertex *vertex, DynamicArray *edges, int iE,
                          DynamicArray *vertexNeighbors) {
  if (iE == (edges->counter) - 1) {
    return;
  }
  if (*(int *)(((Edge *)edges->getElement(edges, iE))->source->value) ==
      *(int *)(vertex->value)) {
    vertexNeighbors->addElement(
        vertexNeighbors,
        ((Vertex *)((Edge *)edges->getElement(edges, iE))->destination));
  }
  _getNeighbors(vertex, edges, ++iE, vertexNeighbors);
}
void graphNeighbors(Graph *graph, Vertex *vertex,
                    DynamicArray *vertexNeighbors) {
  _getNeighbors(vertex, graph->edges, 0, vertexNeighbors);
  // for been able to destroy outside the scope of the file
  return;
}
/* static bool _vertexExist(){ */

/* } */
void graphAddVertex(Graph *graph, Vertex *vertex) {
  // I will use my dynamic array definitely.
  /* if (_vertexExist() == false) { */

  /* } */
}
void graphAddEdge(Graph *graph, Edge *edge, void *value) {}
void graphRemoveEdge(Graph *graph, Edge *edge) {}
void *graphGetVertexValue(Graph *graph, Vertex *vertex) {}
void graphSetVertexValue(Graph *graph, Vertex *vertex, void *value) {}
void *graphGetEdgeValue(Graph *graph, Edge *edge) {}
void graphSetEdgeValue(Graph *graph, Edge *edge, void *value) {}
void destroyGraph(Graph *graph) { printf("is being called."); }
void destroyVertex(Vertex *vertex) {}
void destroyEdge(Edge *edge) {}
