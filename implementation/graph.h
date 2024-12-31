// link to follow the adt:
// https://en.wikipedia.org/wiki/Graph_(abstract_data_type)
#ifndef __GRAPH__
#define __GRAPH__
#include "dynamicArray.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define NUMBER_VERTICES 5
// considering directed and as is and undirecte graph the edge has to be x2
#define NUMBER_EDGES 14
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
  // DynamicArray *edges;
  // I haven't implemented set so will use an array and keep  in mind different
  // values
  // DynamicArray *vertices;
  Vertex *vertices[NUMBER_VERTICES];
  Edge *edges[NUMBER_EDGES];

  bool (*graphAdjacent)(Graph *graph, Vertex *vertex1, Vertex *Vertex2);
  // this should return vertices
  // DynamicArray *(*graphNeighbors)(Graph *graph, Vertex *vertex);
  // Vertex **(*graphNeighbors)(Graph *graph, Vertex *vertex);
  void (*graphNeighbors)(Graph *graph, Vertex *vertex, Vertex **neighbors);
  void (*graphAddVertex)(Graph *graph, Vertex *vertex);
  void (*graphAddEdge)(Graph *graph, Edge *edge, void *value);
  void (*graphRemoveEdge)(Graph *graph, Edge *edge);
  void *(*graphGetVertexValue)(Graph *graph, Vertex *vertex);
  void (*graphSetVertexValue)(Graph *graph, Vertex *vertex, void *value);
  void *(*graphGetEdgeValue)(Graph *graph, Edge *edge);
  void (*graphSetEdgeValue)(Graph *graph, Edge *edge, void *value);
};
// Graph *newGraph(DynamicArray *vertices, DynamicArray *edges);
// i think is the same
Graph *newGraph(Vertex *vertices[], Edge *edges[]);
Vertex *newVertex(void *value);
Edge *newEdge(Vertex *vertexS, Vertex *vertexD, void *value);
bool graphAdjacent(Graph *graph, Vertex *vertex1, Vertex *Vertex2);
// this should return vertices
// DynamicArray *graphNeighbors(Graph *graph, Vertex *vertex);
// Vertex **graphNeighbors(Graph *graph, Vertex *vertex);
void graphNeighbors(Graph *graph, Vertex *vertex, Vertex **neighbors);
void graphAddVertex(Graph *graph, Vertex *vertex);
void graphAddEdge(Graph *graph, Edge *edge, void *value);
void graphRemoveEdge(Graph *graph, Edge *edge);
void *graphGetVertexValue(Graph *graph, Vertex *vertex);
void graphSetVertexValue(Graph *graph, Vertex *vertex, void *value);
void *graphGetEdgeValue(Graph *graph, Edge *edge);
void graphSetEdgeValue(Graph *graph, Edge *edge, void *value);
void destroyGraph(Graph *graph);
void destroyVertex(Vertex *vertex);
void destroyEdge(Edge *edge);

#endif
