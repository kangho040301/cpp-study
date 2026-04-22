#include <iostream>
#include <vector>
using namespace std;
bool visited[100001];
vector<vector<int>> adj;
vector<vector<int>> child; //child[n] = {a, b, c}; n의 자식은 a, b, c
int treeSize[100001];
void makeTree(int cnt) {
    visited[cnt] = true;
    for(int next : adj[cnt]) {
        if(!visited[next]) {
            child[cnt].push_back(next);
            makeTree(next);
        }
    }
}
int countSubTree(int cnt) {
    treeSize[cnt] = 1;
    for(int next : child[cnt]) {
        treeSize[cnt] += countSubTree(next);
    }
    return treeSize[cnt];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, r, q; cin >> n >> r >> q;
    adj.resize(n+1);
    child.resize(n+1);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    makeTree(r);
    countSubTree(r);
    for(int i = 0; i < q; i++) {
        int x; cin >> x;
        cout << treeSize[x] << '\n';
    }
    return 0;
}