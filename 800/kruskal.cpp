#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int findParent(int parent[], int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

void unionSet(int parent[], int rank[], int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);

    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);

        parent[b] = a;

        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), compare);

    int parent[V];
    int rank[V] = {0};

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;
    int edgeCount = 0;

    cout << "\nMinimum Spanning Tree:\n";

    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (findParent(parent, u) != findParent(parent, v)) {
            cout << u << " - " << v << " : " << edges[i].w << endl;
g++ kruskal.cpp -o kruskal.exe
            totalCost += edges[i].w;
            edgeCount++;

            unionSet(parent, rank, u, v);
        }
    }

    cout << "Minimum Cost = " << totalCost << endl;

    return 0;
}