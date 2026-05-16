#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

class Puzzle {

    struct Node {
        vector<vector<int>> mat;
        int x, y;
        int g, h;

        // For Priority Queue
        bool operator<(const Node& other) const {
            return (g + h) > (other.g + other.h);
        }
    };

    vector<vector<int>> goal = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

public:

    // Heuristic Function (Manhattan Distance)
    int heuristic(vector<vector<int>> &mat) {

        int h = 0;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {

                if(mat[i][j] != 0) {

                    int val = mat[i][j];

                    int targetX = (val - 1) / 3;
                    int targetY = (val - 1) % 3;

                    h += abs(i - targetX) + abs(j - targetY);
                }
            }
        }

        return h;
    }

    // Convert Matrix to String
    string matrixToString(vector<vector<int>> &mat) {

        string s = "";

        for(auto row : mat) {
            for(auto val : row) {
                s += to_string(val);
            }
        }

        return s;
    }

    // Print Puzzle
    void print(vector<vector<int>> &mat) {

        for(auto row : mat) {
            for(auto val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    // Solve Function
    void solve(vector<vector<int>> start, int x, int y) {

        priority_queue<Node> pq;
        set<string> visited;

        Node root;

        root.mat = start;
        root.x = x;
        root.y = y;
        root.g = 0;
        root.h = heuristic(start);

        pq.push(root);

        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        while(!pq.empty()) {

            Node current = pq.top();
            pq.pop();

            // Convert current state to string
            string state = matrixToString(current.mat);

            // Skip if already visited
            if(visited.find(state) != visited.end()) {
                continue;
            }

            visited.insert(state);

            cout << "\nCurrent State:\n";
            print(current.mat);

            cout << "g(n) = " << current.g << endl;
            cout << "h(n) = " << current.h << endl;
            cout << "f(n) = " << current.g + current.h << endl;

            // Goal Check
            if(current.h == 0) {

                cout << "\nGoal State Reached!\n";
                return;
            }

            // Generate Possible Moves
            for(int i = 0; i < 4; i++) {

                int newX = current.x + row[i];
                int newY = current.y + col[i];

                // Boundary Check
                if(newX >= 0 && newX < 3 &&
                   newY >= 0 && newY < 3) {

                    Node child = current;

                    // Move blank tile
                    swap(child.mat[current.x][current.y],
                         child.mat[newX][newY]);

                    child.x = newX;
                    child.y = newY;

                    child.g = current.g + 1;
                    child.h = heuristic(child.mat);

                    // Push only if not visited
                    string childState =
                        matrixToString(child.mat);

                    if(visited.find(childState)
                        == visited.end()) {

                        pq.push(child);
                    }
                }
            }
        }

        cout << "No Solution Found!\n";
    }
};

int main() {

    vector<vector<int>> start = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };

    Puzzle p;

    p.solve(start, 1, 1);

    return 0;
}