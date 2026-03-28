#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Point {
    int x, y, z;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int m, n, h; cin >> m >> n >> h;
    vector<vector<vector<int>>> box(h+2,vector<vector<int>>(n+2,vector<int>(m+2, -1)));
    vector<vector<vector<int>>> time(h+2,vector<vector<int>>(n+2,vector<int>(m+2, -1)));
    queue<Point> q;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1) {
                    q.push({i,j,k});
                    time[i][j][k] = 0;
                }
            }
        }
    }
    int dx[] = {-1, 1, 0, 0, 0, 0};
    int dy[] = {0, 0, -1, 1, 0 ,0};
    int dz[] = {0, 0, 0, 0, -1, 1};
    int ans = 0;
    while(!q.empty()) {
        Point cnt = q.front(); q.pop();
        for(int i = 0; i < 6; i++) {
            Point next;
            next.x = cnt.x + dx[i];
            next.y = cnt.y + dy[i];
            next.z = cnt.z + dz[i];
            if(box[next.x][next.y][next.z] == 0) {
                box[next.x][next.y][next.z] = 1;
                time[next.x][next.y][next.z] = time[cnt.x][cnt.y][cnt.z] + 1;
                ans = max(ans, time[next.x][next.y][next.z]);
                q.push(next);
            }
        }
    }
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                if(box[i][j][k] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}