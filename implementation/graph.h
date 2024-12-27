// link to follow the adt:
// https://en.wikipedia.org/wiki/Graph_(abstract_data_type)

#ifndef __GRAPH__
#define __GRAPH__
#include "dynamicArray.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct Vertex Vertex;
struct Vertex {
  // I will handle int but for keep the tradition
  void *value;
};
typedef struct Edge Edge;
struct Edge {
  Vertex *source;
  Vertex *destination;
};
typedef struct Graph Graph;
struct Graph {
  DynamicArray *edges;
  // I haven't implemented set so will use an array and keep  in mind different
  // values
  DynamicArray *vertices;

  bool (*graphAdjacent)(Graph *graph, Vertex *vertex1, Vertex *Vertex2);
  // this should return vertices
  DynamicArray *(*graphNeighbors)(Graph *graph, Vertex *vertex);
  void (*graphAddVertex)(Graph *graph, Vertex *vertex);
  void (*graphAddEdge)(Graph *graph, Edge *edge, void *value);
  void (*graphRemoveEdge)(Graph *graph, Edge *edge);
  void *(*graphGetVertexValue)(Graph *graph, Vertex *vertex);
  void (*graphSetVertexValue)(Graph *graph, Vertex *vertex, void *value);
  void *(*graphGetEdgeValue)(Graph *graph, Edge *edge);
  void (*graphSetEdgeValue)(Graph *graph, Edge *edge, void *value);
};
Graph *newGraph(DynamicArray *vertices, DynamicArray *edges);
bool graphAdjacent(Graph *graph, Vertex *vertex1, Vertex *Vertex2);
// this should return vertices
DynamicArray *graphNeighbors(Graph *graph, Vertex *vertex);
void graphAddVertex(Graph *graph, Vertex *vertex);
void graphAddEdge(Graph *graph, Edge *edge, void *value);
void graphRemoveEdge(Graph *graph, Edge *edge);
void *graphGetVertexValue(Graph *graph, Vertex *vertex);
void graphSetVertexValue(Graph *graph, Vertex *vertex, void *value);
void *graphGetEdgeValue(Graph *graph, Edge *edge);
void graphSetEdgeValue(Graph *graph, Edge *edge, void *value);
void destroyGraph(Graph *graph);

#endif
