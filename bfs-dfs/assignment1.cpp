#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int vertices;
    vector <vector <int>> adj;

    public:
    Graph (int v){
        vertices = v;
        adj.resize(v);
    }

    void addEdge(int u, int v){ // undirected graph
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int node, vector<bool>& visited){
        visited[node] = true;
        cout << node+1 << " ";

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                DFS(neighbour, visited);
            }
        }
    }

    void BFSRecursive(queue<int>& q, vector<bool>& visited){
        if(q.empty()){
            return;
        }

        int node = q.front();
        q.pop();

        cout << node+1 << " ";

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
        BFSRecursive(q, visited);
    }

    void BFS(int start){
        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        BFSRecursive(q, visited);
    }
};

int main(){
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "\nEnter the number of edges: ";
    cin >> e;
    cout << endl;
    Graph g(v);
    cout << "Enter the edges (u v): " << endl;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
        cout << endl;
    }

    int start;
    cout << "Enter the starting vertex:";
    cin >> start;
    start--;
    cout << endl;
    vector<bool> visited(v, false);
    cout << "DFS Traversal: ";
    g.DFS(start, visited);
    cout << endl;
    cout << "BFS Traversal: ";
    g.BFS(start);
    cout << endl;

    return 0;
}