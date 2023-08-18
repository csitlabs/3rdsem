//	DFS

#include <iostream>

using namespace std;

// Function to perform DFS traversal of the graph
void DFS(int V, int** graph, bool* visited, int startVertex) {
    cout << startVertex << " ";
    visited[startVertex] = true;

    for (int i = 0; i < V; ++i) {
        if (graph[startVertex][i] && !visited[i])
            DFS(V, graph, visited, i);
    }
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

    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "DFS traversal: ";
    DFS(V, graph, visited, startVertex);

    for (int i = 0; i < V; ++i)
        delete[] graph[i];
    delete[] graph;
    delete[] visited;

    return 0;
}

