#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int m, n; cin >> m >> n;
    vector<vector<int>> box(n,vector<int>(m));
    queue<pair<int,int>> q;
    vector<vector<int>> time(n,vector<int>(m,-1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) {
                q.push({i,j});
                time[i][j] = 0;
            }
        }
    }
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while(!q.empty()) {
        pair<int,int> cnt = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int next_x = cnt.first + dx[i];
            int next_y = cnt.second + dy[i];
            if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
                if(time[next_x][next_y] == -1 && box[next_x][next_y] == 0) {
                    time[next_x][next_y] = time[cnt.first][cnt.second] + 1;
                    box[next_x][next_y] = 1;
                    q.push({next_x, next_y});
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(box[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    vector<int> max_el(n);
    for(int i = 0; i < n; i++) {
        auto it = max_element(time[i].begin(),time[i].end());
        max_el[i] = *it;
    }
    auto it = max_element(max_el.begin(),max_el.end());
    cout << *it << '\n';
    return 0;
}