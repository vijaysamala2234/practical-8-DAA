#include <iostream>
using namespace std;

int main() {
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    int graph[100][100] = {0};

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    int visited[100] = {0};
    int stack[100];

    int top = -1;

    stack[++top] = start;

    cout << "DFS Traversal: ";

    while (top >= 0) {
        int current = stack[top--];

        if (visited[current] == 0) {
            visited[current] = 1;

            cout << current << " ";

            for (int i = n - 1; i >= 0; i--) {
                if (graph[current][i] == 1 && visited[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }

    return 0;
}
