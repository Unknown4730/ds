#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int v;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        v = vertices;
        adj.resize(v);
    }

    void addEdge(int u, int w) {
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    void display() {
        for (int i = 0; i < v; i++) {
            cout << i << " -> ";
            for (int x : adj[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void BFS(int start) {
        vector<bool> visited(v, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int x : adj[node]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int vertices, choice, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    do {
        cout << "\n1.Add Edge";
        cout << "\n2.Display";
        cout << "\n3.BFS";
        cout << "\n4.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source and destination: ";
                cin >> u >> v;
                g.addEdge(u, v);
                break;

            case 2:
                g.display();
                break;

            case 3:
                cout << "Enter starting vertex: ";
                cin >> start;
                g.BFS(start);
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 4);

    return 0;
}
