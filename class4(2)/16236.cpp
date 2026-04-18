#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Point{
    int r, c, t;
};
vector<vector<int>> p;
int ans = 0;
int b_size= 2;
int lv_up = 0;
int sr, sc;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
bool finish = false;
void search() {
    vector<vector<bool>> visited(22,vector<bool>(22,false));
    queue<Point> q;
    vector<pair<int,int>> sub;
    int t = 100000;
    q.push({sr,sc,0});
    visited[sr][sc] = true;
    while(!q.empty()) {
        int cntr = q.front().r;
        int cntc = q.front().c;
        int cntt = q.front().t;
        q.pop();

        if(cntt > t) {
            break;
        }
        if(p[cntr][cntc] > 0 && p[cntr][cntc] < b_size) {
            t = cntt;
            sub.push_back({cntr, cntc});
        }
        for(int i = 0; i < 4; i++) {
            int nr = cntr + dr[i];
            int nc = cntc + dc[i];
            if(!visited[nr][nc] && p[nr][nc] <= b_size) {
                visited[nr][nc] = true;
                q.push({nr, nc, cntt + 1});
            }
        }
    }

    if(!sub.empty()) {
        sort(sub.begin(), sub.end());
        int r = sub[0].first;
        int c = sub[0].second;
        p[r][c] = 0;
        lv_up++;
        if(lv_up == b_size) {
            b_size++;
            lv_up = 0;
        }
        ans += t;
        sr = r;
        sc = c;
    }
    else finish = true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    p.resize(n+2,vector<int>(n+2,1000));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> p[i][j];
            if(p[i][j] == 9) {
                p[i][j] = 0;
                sr = i; sc = j;
            }
        }
    }
    while(!finish) {
        search();
    }
    cout << ans << '\n';
    return 0;
}