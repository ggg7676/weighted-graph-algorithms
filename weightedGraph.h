#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <cstdint>
#include <algorithm>
using namespace std;

//Weighted graph G(V, E, g)
//V - vertices
//E - edges
//g - weight function
class weightedGraph
{
    int numOfNodes;
    vector<pair<int, int>>* adjList;

    void copyGraph(const weightedGraph&  wg);
    void deleteGraph();

public:
    
    //Default constructor
    weightedGraph();

    //Constructing a graph with a given number of vertices
   weightedGraph(int numOfNodes);

   //Copy constructor
   weightedGraph(const weightedGraph& wg);

   //operator =
   weightedGraph& operator=(const weightedGraph& wg);

   //Destructor
   ~weightedGraph();

    //Adding an edge to the graph
   void addUndirectedEdge(int u, int v, int weight = 1);
   void addDirectedEdge(int u, int v, int weight = 1);

    //Traversal algorithms
    
    //for graph with equal weights( = 1) or no weights
   //O(V + E)
   void BFS(int startNode);
   void DFS(int startNode);


    //Shortest paths algorithms

    //O(E * lgV) with min priority queue; 
    //works for non-negative edges only
    void DijkstraShortestPaths(int start);

    //O(E * V) 
    //works for negative edges and detects negative cycles
    void BellmanFordShortestPaths(int start);


    //MST algorithms

    //O(E * lgV) with min priority queue
    void PrimMST(int start);

    //O(E * lgV) with union-find
    void KruskalMST();

};
