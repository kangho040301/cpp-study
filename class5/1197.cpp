#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct line{
    int u, v, w;
};
bool compare(line& a, line& b) {
    return a.w < b.w;
}
int parent[10001];

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
    
    int n, e; cin >> n >> e;
    vector<line> lines(e);
    for(int i = 0; i < e; i++) {
        cin >> lines[i].u >> lines[i].v >> lines[i].w;
    }
    sort(lines.begin(), lines.end(), compare);

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int mst_weight = 0;
    int count = 0;
    for(int i = 0; i < e; i++) {
        if(find(lines[i].u) != find(lines[i].v)) {
            unite(lines[i].u, lines[i].v);
            mst_weight += lines[i].w;
            count++;

            if(count == n - 1) break;
        }
    }

    cout << mst_weight << '\n';
    return 0;
}