#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Path {
    int s, e;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    int visited[101]{};
    vector<Path> path(n+m);
    for(int i = 0; i < n+m; i++) {
        cin >> path[i].s >> path[i].e;
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int cnt = q.front(); q.pop();
        for(int i = 6; i >= 1; i--) {
            int next = cnt + i;
            for(int a = 0; a < n+m; a++) {
                if(next == path[a].s) next = path[a].e;
            }
            if(next <= 100 && !visited[next]) {
                visited[next] = visited[cnt] + 1;
                if(next == 100) {
                    cout << visited[100] << '\n';
                    return 0;
                }
                q.push(next);
            }
        }
    }
}