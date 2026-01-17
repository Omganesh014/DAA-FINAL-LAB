#include <iostream>
using namespace std;

int main() {
    int n, cost[10][10], visited[10] = {0};
    int mincost = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    visited[0] = 1;

    for(int edges = 0; edges < n - 1; edges++) {
        int min = 999, u, v;
        for(int i = 0; i < n; i++)
            if(visited[i])
                for(int j = 0; j < n; j++)
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }

        visited[v] = 1;
        mincost += min;
    }

    cout << "Minimum cost: " << mincost;
    return 0;
}
