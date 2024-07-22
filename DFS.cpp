#include "weightedGraph.cpp"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void weightedGraph::DFS(int startNode)
{
    vector<int>result;

    vector<bool> visited(numOfNodes, false);
    stack<int> st;
    st.push(startNode);
    visited[startNode] = true;

    while(!st.empty())
    {
        int curr = st.top();
        result.push_back(curr);
        st.pop();

        int neighCount = adjList[curr].size();
        for(int i=0; i<neighCount; ++i)
        {
            int neighbour = adjList[curr][i].first;
            if(!visited[neighbour])
            {
                st.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }

    cout<<"DFS: ";
    for(int i=0; i<numOfNodes; ++i)
        cout<<result[i]<<" ";
}