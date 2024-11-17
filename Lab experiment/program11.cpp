/**
 * 
 * Find Minimum Cost Spanning Tree of a given connected undirected graph using Prim's algorithm.
 * 
 * Author: Shourya Gupta 
 * Copyright: ShouryaBrahmastra
 * 
 * **/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int findMinVertex(vector<int> &key, vector<bool> &inMST, int vertices) 
{
    int minKey = INT_MAX, minIndex = -1;
    for (int v = 0; v < vertices; v++) 
    {
        if (!inMST[v] && key[v] < minKey) 
        {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}


void primMST(vector<vector<int>> &graph, int vertices) 
{
    
    vector<int> key(vertices, INT_MAX);    
    vector<bool> inMST(vertices, false);    
    vector<int> parent(vertices, -1);    
    key[0] = 0;

    for (int count = 0; count < vertices - 1; count++) 
    {        
        int u = findMinVertex(key, inMST, vertices);        
        inMST[u] = true;        
        for (int v = 0; v < vertices; v++) 
        {            
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) 
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

   
    cout << "Edge \tWeight\n";
    for (int i = 1; i < vertices; i++) 
    {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

int main() 
{
    int vertices;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

    cout << "Enter the adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < vertices; i++) 
    {
        for (int j = 0; j < vertices; j++) 
        {
            cin >> graph[i][j];
        }
    }

    primMST(graph, vertices);

    return 0;
}
