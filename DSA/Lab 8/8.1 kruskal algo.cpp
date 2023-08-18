//	kruskals algorithm

#include <iostream>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set for Union-Find
struct DisjointSet {
    int *parent, *rank;
    int size;

    DisjointSet(int n) {
        size = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return;

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

// Function to find the MST using Kruskal's algorithm
void kruskalMST(int V, int E, Edge* edges) {
    DisjointSet ds(V);
    Edge* mst = new Edge[V - 1];
    int mstIndex = 0;

    // Sort edges in ascending order of weight using Bubble Sort (simple version)
    for (int i = 0; i < E - 1; ++i) {
        for (int j = 0; j < E - i - 1; ++j) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < E && mstIndex < V - 1; ++i) {
        int srcRoot = ds.find(edges[i].src);
        int destRoot = ds.find(edges[i].dest);

        if (srcRoot != destRoot) {
            // Add the edge to MST
            mst[mstIndex++] = edges[i];
            // Merge the two disjoint sets
            ds.unionSets(srcRoot, destRoot);
        }
    }

    cout << "Minimum Spanning Tree edges:" << endl;
    for (int i = 0; i < V - 1; ++i)
        cout << mst[i].src << " - " << mst[i].dest << " : " << mst[i].weight << endl;

    delete[] mst;
}

int main() {
    int V, E; // V is the number of vertices, E is the number of edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Edge* edges = new Edge[E];
    cout << "Enter the source, destination, and weight of each edge:" << endl;
    for (int i = 0; i < E; ++i)
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;

    kruskalMST(V, E, edges);

    delete[] edges;

    return 0;
}

