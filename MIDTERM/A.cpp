#include <iostream>
#include <vector>
#include <list>
using namespace std;

class AdjacencyMatrixGraph {
private:
    int vertexCount;
    vector<vector<int>> matrix;

public:
    AdjacencyMatrixGraph(int v) {
        vertexCount = v;
        matrix.resize(v, vector<int>(v, 0));
    }

    void addEdge(int u, int v, int weight = 1, bool directed = false) {
        matrix[u][v] = weight;
        if (!directed) {
            matrix[v][u] = weight;
        }
    }

    void printMatrix() {
        cout << "Adjacency Matrix Representation:" << endl;
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// =====================================
// Graph Representation using Adjacency List
// =====================================
class AdjacencyListGraph {
private:
    int vertexCount;
    vector<list<int>> listAdj;

public:
    AdjacencyListGraph(int v) {
        vertexCount = v;
        listAdj.resize(v);
    }

    void addEdge(int u, int v, bool directed = false) {
        listAdj[u].push_back(v);
        if (!directed) {
            listAdj[v].push_back(u);
        }
    }

    void printList() {
        cout << "Adjacency List Representation:" << endl;
        for (int i = 0; i < vertexCount; i++) {
            cout << i << " -> ";
            for (int v : listAdj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

// ==========================
// Main Program
// ==========================
int main() {
    int V = 5;

    // Undirected Graph
    cout << "UNDIRECTED GRAPH:" << endl;
    AdjacencyMatrixGraph matrixGraph1(V);
    matrixGraph1.addEdge(0, 1); // A-B
    matrixGraph1.addEdge(0, 2); // A-C
    matrixGraph1.addEdge(0, 3); // A-D
    matrixGraph1.addEdge(1, 4); // B-E
    matrixGraph1.addEdge(2, 3); // C-D
    matrixGraph1.addEdge(3, 4); // D-E
    matrixGraph1.printMatrix();
    cout << endl;

    AdjacencyListGraph listGraph1(V);
    listGraph1.addEdge(0, 1);
    listGraph1.addEdge(0, 2);
    listGraph1.addEdge(0, 3);
    listGraph1.addEdge(1, 4);
    listGraph1.addEdge(2, 3);
    listGraph1.addEdge(3, 4);
    listGraph1.printList();
    cout << endl;

    // Directed Graph
    cout << "DIRECTED GRAPH:" << endl;
    AdjacencyMatrixGraph matrixGraph2(V);
    matrixGraph2.addEdge(0, 1, 1, true); // A->B
    matrixGraph2.addEdge(0, 2, 3, true); // A->C
    matrixGraph2.addEdge(0, 3, 4, true); // A->D
    matrixGraph2.addEdge(1, 4, 2, true); // B->E
    matrixGraph2.addEdge(2, 3, 1, true); // C->D
    matrixGraph2.addEdge(3, 4, 5, true); // D->E
    matrixGraph2.printMatrix();
    cout << endl;

    AdjacencyListGraph listGraph2(V);
    listGraph2.addEdge(0, 1, true);
    listGraph2.addEdge(0, 2, true);
    listGraph2.addEdge(0, 3, true);
    listGraph2.addEdge(1, 4, true);
    listGraph2.addEdge(2, 3, true);
    listGraph2.addEdge(3, 4, true);
    listGraph2.printList();
    cout << endl;

    return 0;
}
