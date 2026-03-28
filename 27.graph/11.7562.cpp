#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int l; cin >> l;
        vector<vector<bool>> visited(l,vector<bool>(l,false));
        vector<vector<int>> time(l,vector<int>(l,0));
        int u, v; cin >> u >> v;
        visited[u][v] = true;
        int a, b; cin >> a >> b;
        pair<int, int> end = {a, b};
        queue<pair<int,int>> p;
        p.push({u,v});
        pair<int, int> cnt = {0, 0};
        while(!p.empty()) {
            cnt = p.front(); p.pop();
            if(cnt == end) break;
            int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
            int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
            for(int i = 0; i < 8; i++) {
                pair<int, int> next = {cnt.first + dx[i], cnt.second + dy[i]};
                if(next.first >= 0 && next.first < l && next.second >= 0 && next.second < l) {
                    if(!visited[next.first][next.second]) {
                        visited[next.first][next.second] = true;
                        time[next.first][next.second] = time[cnt.first][cnt.second] + 1;
                        p.push(next);
                    }
                }
            }
        }
        cout << time[a][b] << '\n';
    }
    return 0;
}