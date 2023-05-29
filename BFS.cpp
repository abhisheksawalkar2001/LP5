// BFS 

#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

using namespace std;

void bfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << "Visited node: " << curr << endl;

        #pragma omp parallel for
        for (int i = 0; i < graph[curr].size(); i++) {
            int neighbor = graph[curr][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int numNodes = 7;
    vector<vector<int>> graph(numNodes);
    vector<bool> visited(numNodes, false);

    // Graph initialization
    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {5};
    graph[3] = {};
    graph[4] = {6};
    graph[5] = {};
    graph[6] = {};

    int startNode = 0;

    cout << "BFS traversal using OpenMP:" << endl;
    bfs(startNode, graph, visited);

return 0;
}

    
  


