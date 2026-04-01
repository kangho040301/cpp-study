#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<string> campus(n);
    vector<vector<bool>> visited(n,vector<bool>(m));
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++) {
        cin >> campus[i];
        for(int j = 0; j < m; j++) {
            if(campus[i][j] == 'I') {
                q.push({i,j});
                visited[i][j] = true;
            }
        }
    }
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    int ans = 0;
    while(!q.empty()) {
        int cntX = q.front().first;
        int cntY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nextX = cntX + dx[i];
            int nextY = cntY + dy[i];
            if(nextX >= 0 && nextY >= 0 && nextX < n && nextY < m && campus[nextX][nextY] != 'X') {
                if(!visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    if(campus[nextX][nextY] == 'P') ans++;
                    q.push({nextX,nextY});
                }
            }
        }
    }
    if(ans == 0) cout << "TT" << '\n';
    else cout << ans << '\n';
    return 0;
}