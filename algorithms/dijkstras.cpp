#include <iostream>
using namespace std;

class Dijkstra {

    int graph[10][10];
    int n, e;

public:

    void input() {

        cout << "Enter number of vertices: ";
        cin >> n;
        cout << "Enter number of edges: ";
        cin >> e;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                graph[i][j] = 0;
            }
        }

        cout << "Enter source destination weight:\n";
        for(int i = 0; i < e; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u][v] = w;
            graph[v][u] = w; // Undirected graph
        }
    }

    void shortestPath() {

        int dist[10];
        bool visited[10];

        for(int i = 0; i < n; i++) {
            dist[i] = 999;
            visited[i] = false;
        }

        dist[0] = 0;

        for(int count = 0; count < n - 1; count++) {
            int min = 999;
            int u;
            for(int i = 0; i < n; i++) {
                if(!visited[i] && dist[i] < min) {
                    min = dist[i];
                    u = i;
                }
            }
            visited[u] = true;

            for(int v = 0; v < n; v++) {
                if(graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        cout << "\nShortest distances from source 0:\n";

        for(int i = 0; i < n; i++) {
            cout << "0 -> " << i << " = " << dist[i] << endl;
        }
    }
};

int main() {

    Dijkstra d;
    d.input();
    d.shortestPath();
    return 0;
}