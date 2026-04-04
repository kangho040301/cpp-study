#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[32001];
int grade[32001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        grade[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(grade[i] == 0) {
            cout << i << ' ';
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cnt = q.front(); q.pop();
        for(int next : adj[cnt]) {
            grade[next]--;
            if(grade[next] == 0) {
                cout << next << ' ';
                q.push(next);
            }
        }
    }
    return 0;
}