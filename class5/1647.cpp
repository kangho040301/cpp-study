#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, w;

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};
int parent[100001];
int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) parent[y] = x;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<Edge> edge(m);
    for(int i = 0; i < m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    
    sort(edge.begin(), edge.end());
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int mst_weight = 0;
    int count = 0;
    for(int i = 0; i < m; i++) {
        if(count == n - 2) break; //마지막 간선을 연결 안 함
        
        if(find(edge[i].u) != find(edge[i].v)) {
            unite(edge[i].u, edge[i].v);
            mst_weight += edge[i].w;
            count++;
        }
    }

    cout << mst_weight << '\n';
    return 0;
}