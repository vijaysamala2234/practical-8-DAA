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
    int queue[100];

    int front = 0;
    int rear = 0;

    queue[rear] = start;
    rear++;
    visited[start] = 1;

    cout << "BFS Traversal: ";

    while (front < rear) {
        int current = queue[front];
        front++;

        cout << current << " ";

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                queue[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
