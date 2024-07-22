#include "weightedGraph.cpp"
#include <iostream>
using namespace std;

void weightedGraph::BellmanFordShortestPaths(int start)
{
    const int MAX_DIST = 1000;
    vector<int>dist(numOfNodes, MAX_DIST);
    dist[start] = 0;
    
    for(int counter = 1; counter <= numOfNodes-1; ++counter)
    {
        int i = start;
        int c = 1;
        while(c <= numOfNodes)
        {
            vector<pair<int, int>>::iterator it = adjList[i].begin();
            for(it; it != adjList[i].end(); ++it)
            {
                int v = (*it).first;
                int vWeight = (*it).second;
                if(dist[v] > dist[i] + vWeight)
                    dist[v] = dist[i] + vWeight;
            }

            i = (i+1) % numOfNodes;
            c++;
        }
    }

    //checking for negative cycles
    for(int i=0; i<numOfNodes - 1; ++i)
    {
        vector<pair<int, int>>::iterator it = adjList[i].begin();
        for(it; it != adjList[i].end(); ++it)
        {
            int v = (*it).first;
            int vWeight = (*it).second;
            if(dist[v] > dist[i] + vWeight)
            {
                    cout<<"(Bellman-Ford)Negative cycle.";
                    return;
            }
        }
    }

    cout<<"(Bellman-Ford)Shortest path to each vertex: ";
    for(int i=0; i<numOfNodes; ++i)
        cout<<dist[i]<<" ";
}
