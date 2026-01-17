#include <iostream>
using namespace std;

int adj[10][10], visited[10], n;

void dfs(int v) {
    visited[v] = 1;
    cout << v << " ";
    for(int i = 0; i < n; i++)
        if(adj[v][i] && !visited[i])
            dfs(i);
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "DFS traversal: ";
    dfs(0);
    return 0;
}
