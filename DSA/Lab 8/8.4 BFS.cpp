//	BFS

#include <iostream>

using namespace std;

// Function to perform BFS traversal of the graph
void BFS(int V, int** graph, int startVertex) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;

    int* queue = new int[V];
    int front = 0, rear = 0;

    queue[rear++] = startVertex;
    visited[startVertex] = true;

    while (front < rear) {
        int currentVertex = queue[front++];
        cout << currentVertex << " ";

        for (int i = 0; i < V; ++i) {
            if (graph[currentVertex][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }

    delete[] visited;
    delete[] queue;
}

int main() {
    int V; // V is the number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    int** graph = new int*[V];
    for (int i = 0; i < V; ++i)
        graph[i] = new int[V];

    cout << "Enter the graph matrix (enter 0 for no edge, 1 for an edge):" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j];
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "BFS traversal: ";
    BFS(V, graph, startVertex);

    for (int i = 0; i < V; ++i)
        delete[] graph[i];
    delete[] graph;

    return 0;
}

