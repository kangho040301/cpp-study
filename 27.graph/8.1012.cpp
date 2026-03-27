#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(vector<vector<int>> &plate, vector<vector<bool>> &visited, int a, int b) {
    visited[a][b] = true;
    int m = visited.size();
    int n = visited[a].size();
    for(int i = 0; i < 4; i++) {
        int next_a = a + dx[i];
        int next_b = b + dy[i];
        if(next_a >= 0 && next_b >= 0 && next_a < m && next_b < n) {
            if(!visited[next_a][next_b] && plate[next_a][next_b]) {
                dfs(plate, visited, next_a, next_b);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int m, n, k; cin >> m >> n >> k;
        vector<vector<int>> plate(m,vector<int>(n));
        for(int i = 0; i < k; i++) {
            int a, b; cin >> a >> b;
            plate[a][b] = 1;
        }
        vector<vector<bool>> visited(m,vector<bool>(n));
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && plate[i][j]) {
                    dfs(plate, visited, i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}