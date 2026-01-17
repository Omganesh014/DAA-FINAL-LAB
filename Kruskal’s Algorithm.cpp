#include <iostream>
using namespace std;

int parent[10];

int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

void uni(int i, int j) {
    parent[j] = i;
}

int main() {
    int n, cost[10][10], mincost = 0;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    int edges = 0;
    while(edges < n - 1) {
        int min = 999, a, b;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }

        int u = find(a);
        int v = find(b);

        if(u != v) {
            uni(u, v);
            mincost += min;
            edges++;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    cout << "Minimum cost: " << mincost;
    return 0;
}
