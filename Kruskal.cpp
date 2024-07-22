#include "weightedGraph.cpp"

struct compareWeight
{
    bool operator() (pair<int, int>& u, pair<int, int>& v)
    {
        return u.second < v.second;
    }
};

int weightedGraph::Find(int u, vector<int>& parent)
{
    if(u != parent[u])
        return Find(parent[u], parent);
    else return u;
}

void weightedGraph::Union(int u, int v, vector<int>& parent)
{
    int uParent = Find(u, parent);
    int vParent = Find(v, parent);

    if(uParent != vParent)
        parent[uParent] = vParent;
    
}

void weightedGraph::KruskalMST()
{
    sort(adjList->begin(), adjList->end(), compareWeight());

    int mstWeight = 0;
    vector<int>parent(numOfNodes);
    vector<int>rank(numOfNodes, 0);

    for(int i=0; i<numOfNodes; ++i)
        parent[i] = i;
    
    for(int i=0; i<numOfNodes; ++i)
    {
        vector<pair<int, int>>::iterator it = adjList[i].begin();
        for(it; it != adjList[i].end(); ++it)
        {
            int v = (*it).first;
            int vWeight = (*it).second;

            if(Find(i, parent) != Find(v, parent))
            {
                //cout << i << " - " << v << endl;
                mstWeight += vWeight;
                Union(i, v, parent);
            }
        }

    }
    cout<<"(Kruskal)MST weight: "<<mstWeight;
}
