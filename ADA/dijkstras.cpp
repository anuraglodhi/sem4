#include <iostream>
#include <vector>
#define I 1000000
using namespace std;

vector<int> dijkstras(int v, vector<vector<int>> cost, int n) {
    vector<int> dist(n);
    bool selected[n];

    for (int i = 0; i < n; i++) {
        selected[i] = false;
        dist[i] = cost[v][i];
    }
    selected[v] = true;
    dist[v] = 0;

    for (int i = 1; i < n-1; i++) {
        int minDist = I;
        int u = 1;
        for (int j =  1; j < n; j++) {
            if (!selected[j] && dist[j] < minDist) {
                u = j;
                minDist = dist[u];
            }
        }

        selected[u] = true;

        for (int w = 0; w < n; w++) {
            if (!selected[w] && cost[u][w] != I) {
                if (dist[w] > dist[u] + cost[u][w]) {
                    dist[w] = dist[u] + cost[u][w];
                }
            }
        }
    }
    return dist;
}

int main() {
    int s = 0, n = 6;
    vector<vector<int>> cost = {
        {0, 4 , 5 , I , I , I},
        {4, 0 , 11, 9 , 7 , I},
        {6, 11, 0 , I , 3 , I},
        {I, 9 , I , 0 , 13, 2},
        {I, 7 , 3 , 13, 0 , 6},
        {I, I , I , 2 , 6 , 0}
    };
    vector<int> dist = dijkstras(s, cost, 6);
    for (int i: dist) {
        cout << i << " ";
    }
    cout << endl;
}