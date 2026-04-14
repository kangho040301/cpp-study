#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> lab;
vector<pair<int,int>> start;
int n, m;
int initial_safe = 0;
int ans = 0;
void simulate() {
    vector<vector<int>> local_lab = lab;
    int safe = initial_safe - 3;
    queue<pair<int,int>> q;
    for(auto& s : start) {
        q.push(s);
    }
    while(!q.empty()) {
        int cntr = q.front().first;
        int cntc = q.front().second;
        q.pop();
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++) {
            int nr = cntr + dr[i];
            int nc = cntc + dc[i];
            if(local_lab[nr][nc] == 0) {
                local_lab[nr][nc] = 2;
                safe--;
                q.push({nr,nc});
            }
        }
    }
    ans = max(ans, safe);
    return;
}
void solve(int cnt) {
    if(cnt == 3) {
        simulate();
        return;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(lab[i][j] == 0) {
                lab[i][j] = 1;
                solve(cnt + 1);
                lab[i][j] = 0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    lab.resize(n+2, vector<int>(m+2, 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> lab[i][j];
            if(lab[i][j] == 0) initial_safe++;
            if(lab[i][j] == 2) start.push_back({i,j});
        }
    }

    solve(0);

    cout << ans << '\n';
    return 0;
}