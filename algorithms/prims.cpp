#include <iostream>
using namespace std;

class Prim {

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
            graph[v][u] = w;
        }
    }

    void mst() {
        bool selected[10] = {false};
        selected[0] = true;
        int edges = 0;
        cout << "\nEdges in MST:\n";

        while(edges < n - 1) {
            int min = 999;
            int x = 0;
            int y = 0;

            for(int i = 0; i < n; i++) {
                if(selected[i]) {
                    for(int j = 0; j < n; j++) {
                        if(!selected[j] && graph[i][j]) {
                            if(graph[i][j] < min) {
                                min = graph[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }

            cout << x << " - " << y
                 << " : " << graph[x][y] << endl;
            selected[y] = true;
            edges++;
        }
    }
};

int main() {
    Prim p;
    p.input();
    p.mst();
    return 0;
}