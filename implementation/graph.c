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
  ptrGraph->graphSetVertexValue = graphSetVertexValue;
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
  if (iE == (edges->counter - edges->bottomIndex) - 1) {
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
  graph->vertices->addElement(graph->vertices, vertex);
}
void graphAddEdge(Graph *graph, Edge *edge) {
  graph->edges->addElement(graph->edges, edge);
}
/* void **array; */
static void _getEdgePosition(DynamicArray *edges, int iE, int *ptrResult,
                             Edge *edge) {
  if (iE == (edges->counter - edges->bottomIndex) || *ptrResult != -1) {
    return;
  }
  int iEVertexSValue =
      *(int *)((((Edge *)edges->getElement(edges, iE))->source)->value);
  int iEVertexDValue =
      *(int *)((((Edge *)edges->getElement(edges, iE))->destination)->value);
  int tgtVertexSvalue = *(int *)((edge->source)->value);
  int tgtVertexDvalue = *(int *)((edge->destination)->value);
  if (iEVertexSValue == tgtVertexSvalue && iEVertexDValue == tgtVertexDvalue) {
    *ptrResult = iE;
  }
  _getEdgePosition(edges, ++iE, ptrResult, edge);
}
void graphRemoveEdge(Graph *graph, Edge *edge) {
  int result = -1;
  int *ptrResult = &result;
  _getEdgePosition(graph->edges, graph->edges->bottomIndex, ptrResult, edge);
  if (result != -1) {
    graph->edges->removeElementBack(graph->edges, result);
  }
}
static void _findVertexPosition(DynamicArray *vertices, int iV, Vertex *vertex,
                                int *ptrPosition) {
  if (iV == (vertices->counter - vertices->bottomIndex) || *ptrPosition != -1) {
    return;
  }
  int iVVertexValue =
      *(int *)(((Vertex *)vertices->getElement(vertices, iV))->value);
  if (iVVertexValue == *(int *)vertex->value) {
    *ptrPosition = iV;
  }
  _findVertexPosition(vertices, ++iV, vertex, ptrPosition);
}
void *graphGetVertexValue(Graph *graph, Vertex *vertex) {
  int position = -1;
  int *ptrPosition = &position;
  _findVertexPosition(graph->vertices, graph->vertices->bottomIndex, vertex,
                      ptrPosition);
  if (position == -1) {
    return NULL;
  }
  Vertex *gottenVertex =
      ((Vertex *)graph->vertices->getElement(graph->vertices, *ptrPosition));
  return gottenVertex->value;
}
void graphSetVertexValue(Graph *graph, Vertex *vertex, void *value) {
  int position = -1;
  int *ptrPosition = &position;
  _findVertexPosition(graph->vertices, graph->vertices->bottomIndex, vertex,
                      ptrPosition);
  if (position == -1) {
    return;
  }
  graph->vertices->setElement(graph->vertices, position, value);
}
void *graphGetEdgeValue(Graph *graph, Edge *edge) {
  int position = -1;
  int *ptrPosition = &position;
  _getEdgePosition(graph->edges, graph->edges->bottomIndex, ptrPosition, edge);
  if (position == -1) {
    return NULL;
  }
  Edge *gotEdge = ((Edge *)graph->edges->getElement(graph->edges, position));
  return gotEdge->edgeValue;
}
void graphSetEdgeValue(Graph *graph, Edge *edge, void *value) {}
void destroyGraph(Graph *graph) {
  destroyDynamicArray(graph->vertices);
  destroyDynamicArray(graph->edges);
  free(graph);
  graph = NULL;
}
void destroyVertex(Vertex *vertex) {
  free(vertex);
  vertex = NULL;
}
void destroyEdge(Edge *edge) {
  free(edge);
  edge = NULL;
}
