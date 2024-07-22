#include "weightedGraph.cpp"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void weightedGraph::BFS(int startNode)
{
    vector<int> result;

    vector<bool> visited(numOfNodes, false);
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while(!q.empty())
    {
        int curr = q.front();
        result.push_back(curr);
        q.pop();

        int neighCount = adjList[curr].size();
        for(int i=0; i < neighCount; ++i)
        {
            int neighbour = adjList[curr][i].first;
            if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }

    cout<<"BFS: ";
    for(int i=0; i<numOfNodes; ++i)
        cout<<result[i]<<" ";
}