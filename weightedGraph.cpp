#pragma once
#include "weightedGraph.h"
void weightedGraph::copyGraph(const weightedGraph& wg)
{
    numOfNodes = wg.numOfNodes;
    adjList = new(nothrow)vector<pair<int, int>>[numOfNodes];
    if(!adjList)
    {
        delete[] adjList;
        cerr<<"No dynamic memory allocated";
    }

    for(int i=0; i<numOfNodes; ++i)
        adjList[i] = wg.adjList[i];
    
}

void weightedGraph::deleteGraph()
{
    delete[] adjList;
}

weightedGraph::weightedGraph(const weightedGraph& wg)
{
    copyGraph(wg);
}

weightedGraph& weightedGraph::operator=(const weightedGraph& wg)
{
    if(this != &wg)
    {
        deleteGraph();
        copyGraph(wg);
    }

    return *this;
}

weightedGraph::weightedGraph()
{
    numOfNodes = 0;
}

weightedGraph::weightedGraph(int numOfNodes)
{
    this->numOfNodes = numOfNodes;
    adjList = new(nothrow)vector<pair<int, int>>[numOfNodes];
    if(!adjList)
    {
        delete[] adjList;
        cerr<<"No dynamic memory allocated";
    }
}

weightedGraph::~weightedGraph()
{
    deleteGraph();
}

void weightedGraph::addUndirectedEdge(int u, int v, int weight)
{
    adjList[u].push_back(make_pair(v, weight));
    adjList[v].push_back(make_pair(u, weight));
}

void weightedGraph::addDirectedEdge(int u, int v, int weight)
{
    adjList[u].push_back(make_pair(v, weight));
}
