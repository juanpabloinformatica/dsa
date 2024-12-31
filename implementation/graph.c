#include "graph.h"
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
Graph *newGraph(Vertex *verticesP[], Edge *edgesP[]) {
  Graph *ptrGraph = (Graph *)malloc(sizeof(Graph));
  /* ptrGraph->vertices = ptrGraph->edges = */
  memcpy(ptrGraph->vertices, verticesP, sizeof(Vertex *) * NUMBER_VERTICES);
  memcpy(ptrGraph->edges, edgesP, sizeof(Edge *) * NUMBER_EDGES);
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

static void _adjacentVertex(Edge *tmpEdge, Edge *edges[], int i, int edgeSize,
                            bool *ptrFound) {
  if (i == edgeSize || *ptrFound == true) {
    return;
  }

  // As I am using both sides, I should compare with an or for the inverse order
  if (*(int *)(edges[i]->destination->value) ==
          *(int *)(tmpEdge->destination->value) &&
      (*(int *)(edges[i]->source->value) == *(int *)(tmpEdge->source->value))) {
    *ptrFound = true;
  }
  _adjacentVertex(tmpEdge, edges, ++i, edgeSize, ptrFound);
}
// I should use a hashmap I know proximately
bool graphAdjacent(Graph *graph, Vertex *vertex1, Vertex *vertex2) {
  Edge *tmpEdge = newEdge(vertex1, vertex2, NULL);
  bool found = false;
  bool *ptrFound = &found;
  _adjacentVertex(tmpEdge, graph->edges, 0, NUMBER_EDGES, ptrFound);
  destroyEdge(tmpEdge);
  return found;
}
// this should return vertices
static void _getNeighbors(Vertex *vertex, Edge *edges[], int iE, int edgeSize,
                          Vertex **neighbors, int iN) {
  if (iE == edgeSize - 1) {
    return;
  }
  if (*(int *)(edges[iE]->source->value) == *(int *)(vertex->value)) {
    neighbors[iN++] = edges[iE]->destination;
  }
  _getNeighbors(vertex, edges, ++iE, edgeSize, neighbors, iN);
}
void graphNeighbors(Graph *graph, Vertex *vertex, Vertex **neighbors) {
  // dangerous, I need to do this all dynamic after
  // I will clean all of this i think
  /* Vertex *ptrVertexArray = (Vertex *)malloc(sizeof(Vertex) *
   * NUMBER_VERTICES); */

  _getNeighbors(vertex, graph->edges, 0, NUMBER_EDGES, neighbors, 0);
  // for been able to destroy outside the scope of the file
  return;
}
void graphAddVertex(Graph *graph, Vertex *vertex) {}
void graphAddEdge(Graph *graph, Edge *edge, void *value) {}
void graphRemoveEdge(Graph *graph, Edge *edge) {}
void *graphGetVertexValue(Graph *graph, Vertex *vertex) {}
void graphSetVertexValue(Graph *graph, Vertex *vertex, void *value) {}
void *graphGetEdgeValue(Graph *graph, Edge *edge) {}
void graphSetEdgeValue(Graph *graph, Edge *edge, void *value) {}
void destroyGraph(Graph *graph) { printf("is being called."); }
void destroyVertex(Vertex *vertex) {}
void destroyEdge(Edge *edge) {}
