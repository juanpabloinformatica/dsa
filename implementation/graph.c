#include "graph.h"
Graph *newGraph(DynamicArray *vertices, DynamicArray *edges) {
  Graph *ptrGraph = (Graph *)malloc(sizeof(Graph));
  ptrGraph->vertices = newDynamicArray();
  ptrGraph->edges = newDynamicArray();
  if (vertices != NULL && vertices->size == ptrGraph->vertices->size) {
    memcpy(ptrGraph->vertices, vertices, vertices->size);
  }
  if (edges != NULL && edges->size == ptrGraph->edges->size) {
    memcpy(ptrGraph->edges, edges, edges->size);
  }
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
