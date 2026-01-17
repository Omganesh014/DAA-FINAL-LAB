#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, adj[10][10], visited[10] = {0};
    queue<int> q;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];

    q.push(0);
    visited[0] = 1;

    cout << "BFS traversal: ";
    while(!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";
        for(int i = 0; i < n; i++) {
            if(adj[v][i] && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    return 0;
}
