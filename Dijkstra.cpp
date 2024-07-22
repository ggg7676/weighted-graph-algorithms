#include "weightedGraph.cpp"
#include <iostream>
#include <queue>
using namespace std;
void weightedGraph::DijkstraShortestPaths(int start)
{   
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    const int MAX_DIST = 1000;
    vector<int> dist(numOfNodes, MAX_DIST);

    dist[start] = 0;
    q.push(make_pair(0, start));

    while(!q.empty())
    {
        pair<int, int> uPair = q.top();
        q.pop();

        int u = uPair.second;
        vector<pair<int, int>>::iterator it = adjList[u].begin();
        for(it; it != adjList[u].end(); ++it)
        {
            pair<int, int> vPair = *it;
            int v = vPair.first;
            int vWeight = vPair.second;
            if(dist[v] > dist[u] + vWeight)
            {
                dist[v] = dist[u] + vWeight;
                q.push(make_pair(dist[v], v));
            }
        }
        
    }

    cout<<"(Dijkstra)Shortest path to each vertex: ";
    for(int i=0; i<numOfNodes; ++i)
    {
        cout<<dist[i]<<" ";
    }
}