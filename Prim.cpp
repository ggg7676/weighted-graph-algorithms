#include "weightedGraph.cpp"
#include <iostream>
using namespace std;

void weightedGraph::PrimMST(int start)
{
    int mstWeight = 0;
    vector<bool>visited(numOfNodes, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, start));

    while(!q.empty())
    {
        pair<int, int> curr = q.top();
        q.pop();

        int u = curr.second;
        int uWeight = curr.first;
        if(!visited[u])
        {
            visited[u] = true;
            mstWeight += uWeight;

            vector<pair<int, int>>::iterator it = adjList[u].begin();
            for(it; it != adjList[u].end(); ++it)
            {
                int v = (*it).first;
                int vWeight = (*it).second;
                q.push(make_pair(vWeight, v));
            }
        }
    }
   
   cout<<"(Prim)MST weight: "<<mstWeight; 

}