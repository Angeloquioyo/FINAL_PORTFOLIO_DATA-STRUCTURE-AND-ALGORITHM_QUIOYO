#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

// Edge structure template
template <typename T>
struct Edge {
    size_t source;
    size_t destination;
    T weight;

    // Comparison operators for sorting based on edge weight
    bool operator<(const Edge<T>& e) const {
        return weight < e.weight;
    }
    bool operator>(const Edge<T>& e) const {
        return weight > e.weight;
    }
};

// Graph class template
template <typename T>
class Graph {
public:
    Graph(size_t vertices) : vertexCount(vertices) {}

    // Add an edge to the graph
    void add_edge(size_t u, size_t v, T w) {
        if (u >= 1 && u <= vertexCount && v >= 1 && v <= vertexCount) {
            edges.push_back({u, v, w});
        } else {
            cerr << "Invalid edge!" << endl;
        }
    }

    vector<Edge<T>> outgoing_edges(size_t v) const {
        vector<Edge<T>> result;
        for (const auto& e : edges) {
            if (e.source == v) result.push_back(e);
        }
        return result;
    }

    size_t vertices() const {
        return vertexCount;
    }

    void display() const {
        for (size_t i = 1; i <= vertexCount; ++i) {
            cout << i << " -> ";
            auto adj = outgoing_edges(i);
            for (const auto& e : adj) {
                cout << "{" << e.destination << ":" << e.weight << "} ";
            }
            cout << endl;
        }
    }

private:
    size_t vertexCount;
    vector<Edge<T>> edges;
};

template <typename T>
Graph<T> create_graph() {
    Graph<T> G(8);
    
    map<int, vector<pair<int, T>>> adjacencyList = {
        {1, {{2, 2}, {5, 3}}},
        {2, {{1, 2}, {5, 5}, {4, 1}}},
        {3, {{4, 2}, {7, 3}}},
        {4, {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}}},
        {5, {{1, 3}, {2, 5}, {4, 2}, {8, 3}}},
        {6, {{4, 4}, {7, 4}, {8, 1}}},
        {7, {{3, 3}, {6, 4}}},
        {8, {{4, 5}, {5, 3}, {6, 1}}}
    };

    for (const auto& entry : adjacencyList) {
        for (const auto& neighbor : entry.second) {
            G.add_edge(entry.first, neighbor.first, neighbor.second);
        }
    }

    return G;
}

template <typename T>
vector<size_t> breadth_first_search(const Graph<T>& G, size_t start) {
    queue<size_t> q;
    set<size_t> visited;
    vector<size_t> order;

    q.push(start);
    while (!q.empty()) {
        size_t current = q.front();
        q.pop();
        if (visited.find(current) == visited.end()) {
            visited.insert(current);
            order.push_back(current);
            for (const auto& e : G.outgoing_edges(current)) {
                if (visited.find(e.destination) == visited.end()) {
                    q.push(e.destination);
                }
            }
        }
    }

    return order;
}

template <typename T>
void run_BFS() {
    auto G = create_graph<T>();

    cout << "Graph adjacency list:" << endl;
    G.display();

    cout << "BFS traversal order of vertices:" << endl;
    auto order = breadth_first_search(G, 1);
    for (auto v : order) {
        cout << v << endl;
    }
}

int main() {
    run_BFS<unsigned>();
    return 0;
}
