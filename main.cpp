#include "weightedGraph.cpp"
#include "BFS.cpp"
#include "DFS.cpp"
#include "Dijkstra.cpp"
#include "BellmanFord.cpp"
#include "Prim.cpp"
#include "Kruskal.cpp"
#include <iostream>
using namespace std;

int main()
{
    weightedGraph equalWeights(5);
    equalWeights.addUndirectedEdge(0, 1, 1);
    equalWeights.addUndirectedEdge(0, 3, 1);
    equalWeights.addUndirectedEdge(0, 4, 1);
    equalWeights.addUndirectedEdge(1, 2, 1);
    equalWeights.addUndirectedEdge(1, 3, 1);
    equalWeights.addUndirectedEdge(2, 3, 1);
    equalWeights.addUndirectedEdge(3, 4, 1);

    
    weightedGraph negativeCycle(5);
    negativeCycle.addUndirectedEdge(0, 1, -3);
    negativeCycle.addUndirectedEdge(0, 3, 7);
    negativeCycle.addUndirectedEdge(0, 4, -8);
    negativeCycle.addUndirectedEdge(1, 2, 1);
    negativeCycle.addUndirectedEdge(1, 3, -4);
    negativeCycle.addUndirectedEdge(2, 3, 2);
    negativeCycle.addUndirectedEdge(3, 4, -3);


    weightedGraph directedGraph(6);
    directedGraph.addDirectedEdge(0, 1, 4);
    directedGraph.addDirectedEdge(0, 2, 3);
    directedGraph.addDirectedEdge(1, 2, 5);
    directedGraph.addDirectedEdge(1, 3, 2);
    directedGraph.addDirectedEdge(2, 3, 7);
    directedGraph.addDirectedEdge(3, 4, 2);
    directedGraph.addDirectedEdge(3, 0, 5);
    directedGraph.addDirectedEdge(4, 0, 4);
    directedGraph.addDirectedEdge(4, 1, 4);
    directedGraph.addDirectedEdge(4, 5, 6);


    weightedGraph undirectedGraph(6);
    undirectedGraph.addUndirectedEdge(0, 1, 4);
    undirectedGraph.addUndirectedEdge(0, 2, 3);
    undirectedGraph.addUndirectedEdge(1, 2, 5);
    undirectedGraph.addUndirectedEdge(1, 3, 2);
    undirectedGraph.addUndirectedEdge(2, 3, 7);
    undirectedGraph.addUndirectedEdge(3, 4, 2);
    undirectedGraph.addUndirectedEdge(4, 5, 6);

    equalWeights.BFS(0);
    cout<<endl;
    equalWeights.DFS(3);
    cout<<endl;

    directedGraph.DijkstraShortestPaths(1);
    cout<<endl;
    directedGraph.BellmanFordShortestPaths(1);
    cout<<endl;
    negativeCycle.BellmanFordShortestPaths(2);
    cout<<endl;
    undirectedGraph.PrimMST(4);
    cout<<endl;
    undirectedGraph.KruskalMST();
    

    return 0;
}