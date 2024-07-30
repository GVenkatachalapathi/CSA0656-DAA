#include <stdio.h>
#include <stdbool.h>
#define V 5 
void printSolution(int path[]);

bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCircuitUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            printSolution(path);
            return true;
        } else {
            return false;
        }
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianCircuitUtil(graph, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

void hamiltonianCircuit(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (!hamiltonianCircuitUtil(graph, path, 1)) {
        printf("No Hamiltonian circuit exists\n");
    }
}

void printSolution(int path[]) {
    printf("Hamiltonian Circuit found:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);
}

int main() {
    printf("Name :G Venkata Chalapathi\nReg no :192211150");
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCircuit(graph);

    return 0;
}