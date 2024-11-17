/**
 * 
 * Implement BFS and DFS traversing algorithms.
 * 
 * Author: Shourya Gupta 
 * Copyright: ShouryaBrahmastra
 * 
 * **/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


class Graph {
private:
    int vertices; 
    vector<vector<int>> adjList; 

public:
    
    Graph(int v) : vertices(v) {
        adjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }


    void BFS(int start) {
        vector<bool> visited(vertices, false); 
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    
    void DFSRecursive(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSRecursive(neighbor, visited);
            }
        }
    }

    
    void DFSIterative(int start) {
        vector<bool> visited(vertices, false); 
        stack<int> st;

        st.push(start);

        cout << "DFS Traversal (Iterative): ";
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                visited[node] = true;
                cout << node << " ";
            }

            for (auto it = adjList[node].rbegin(); it != adjList[node].rend(); ++it) {
                if (!visited[*it]) {
                    st.push(*it);
                }
            }
        }
        cout << endl;
    }

  
    void DFS(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS Traversal (Recursive): ";
        DFSRecursive(start, visited);
        cout << endl;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges:\n";
    cin >> vertices >> edges;

    Graph g(vertices);

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter the starting vertex:\n";
    cin >> start;

    g.BFS(start);        
    g.DFS(start);        
    g.DFSIterative(start); 

    return 0;
}
