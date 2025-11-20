#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

class Graph {
private:
    int vertexCount;
    vector<Edge> edges;

public:
    Graph(int vertices) {
        vertexCount = vertices;
    }

    void addEdge(int u, int v, int w = 0) {
        if (u >= 1 && u <= vertexCount && v >= 1 && v <= vertexCount) {
            edges.push_back({u, v, w});
        }
    }

    vector<Edge> getOutgoingEdges(int u) const {
        vector<Edge> result;
        for (const auto& edge : edges) {
            if (edge.source == u) {
                result.push_back(edge);
            }
        }
        return result;
    }

    void displayGraph() const {
        for (int i = 1; i <= vertexCount; i++) {
            cout << i << ": ";
            for (const auto& edge : edges) {
                if (edge.source == i) {
                    cout << "{" << edge.destination << "} ";
                }
            }
            cout << endl;
        }
    }
};

vector<int> depthFirstSearch(const Graph& graph, int start) {
    stack<int> stk;
    set<int> visitedNodes;
    vector<int> traversalOrder;

    stk.push(start);
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        if (visitedNodes.find(node) == visitedNodes.end()) {
            visitedNodes.insert(node);
            traversalOrder.push_back(node);
            for (const auto& edge : graph.getOutgoingEdges(node)) {
                if (visitedNodes.find(edge.destination) == visitedNodes.end()) {
                    stk.push(edge.destination);
                }
            }
        }
    }
    return traversalOrder;
}

Graph createSampleGraph() {
    Graph g(8);

    map<int, vector<int>> adjacencyList = {
        {1, {2, 5}},
        {2, {1, 5, 4}},
        {3, {4, 7}},
        {4, {2, 3, 5, 6, 8}},
        {5, {1, 2, 4, 8}},
        {6, {4, 7, 8}},
        {7, {3, 6}},
        {8, {4, 5, 6}}
    };

    for (const auto& [u, neighbors] : adjacencyList) {
        for (const auto& v : neighbors) {
            g.addEdge(u, v);
        }
    }

    return g;
}

int main() {
    Graph graph = createSampleGraph();

    cout << "Graph's Adjacency List:" << endl;
    graph.displayGraph();
    cout << endl;

    cout << "DFS Traversal Order:" << endl;
    vector<int> dfsOrder = depthFirstSearch(graph, 1);
    for (int v : dfsOrder) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
