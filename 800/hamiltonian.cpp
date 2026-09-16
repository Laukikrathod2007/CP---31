#include <iostream>
using namespace std;

bool isSafe(int v, int graph[20][20], int path[], int pos) {

    // Check if vertex is connected
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if vertex is already in path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(int graph[20][20], int path[], int pos, int n) {

    if (pos == n) {
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < n; v++) {

        if (isSafe(v, graph, path, pos)) {

            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1, n))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

int main() {

    int n;
    int graph[20][20];
    int path[20];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;

    if (hamCycleUtil(graph, path, 1, n)) {

        cout << "\nHamiltonian Cycle:\n";

        for (int i = 0; i < n; i++)
            cout << path[i] << " -> ";

        cout << path[0] << endl;

    } else {
        cout << "No Hamiltonian Cycle exists.";
    }

    return 0;
}