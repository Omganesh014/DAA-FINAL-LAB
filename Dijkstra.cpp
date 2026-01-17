#include <iostream>
using namespace std;

int main() {
    int n, cost[10][10], dist[10], visited[10] = {0};

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    for(int i = 0; i < n; i++)
        dist[i] = cost[0][i];

    visited[0] = 1;

    for(int count = 1; count < n; count++) {
        int min = 999, u;
        for(int i = 0; i < n; i++)
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;
        for(int i = 0; i < n; i++)
            if(!visited[i] && dist[i] > dist[u] + cost[u][i])
                dist[i] = dist[u] + cost[u][i];
    }

    cout << "Shortest distances:\n";
    for(int i = 0; i < n; i++)
        cout << dist[i] << " ";
    return 0;
}
