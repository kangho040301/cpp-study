#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
struct Point {
    bool visited_y;
    bool visited_n;
    int wall;
    int time_y;
    int time_n;
};
struct qPoint {
    bool broken;
    int x;
    int y;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<Point>> plate(n+2,vector<Point>(m+2,{false,false,-1,-1,-1}));
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        for(int j = 1; j <= m; j++) {
            plate[i][j].wall = s[j - 1] - '0';
        }
    }
    queue<qPoint> q;
    q.push({false,1,1});
    plate[1][1].visited_n = true;
    plate[1][1].time_n = 1;
    while(!q.empty()) {
        qPoint cnt = q.front(); q.pop();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++) {
            int nx = cnt.x + dx[i];
            int ny = cnt.y + dy[i];
            if(!plate[nx][ny].visited_y && !cnt.broken && plate[nx][ny].wall == 1) {
                plate[nx][ny].visited_y = true;
                plate[nx][ny].time_y = plate[cnt.x][cnt.y].time_n + 1;
                q.push({true,nx,ny});
            }
            else if(plate[nx][ny].wall == 0) {
                if(cnt.broken) {
                    if(!plate[nx][ny].visited_y) {
                        plate[nx][ny].visited_y = true;
                        plate[nx][ny].time_y = plate[cnt.x][cnt.y].time_y + 1;
                        q.push({true,nx,ny});
                    }
                }
                else {
                    if(!plate[nx][ny].visited_n) {
                        plate[nx][ny].visited_n = true;
                        plate[nx][ny].time_n = plate[cnt.x][cnt.y].time_n + 1;
                        q.push({false,nx,ny});
                    }
                }
            }
        }
    }
    if(!plate[n][m].visited_n && !plate[n][m].visited_y) {
        cout << -1 << '\n';
        return 0;
    }
    if(plate[n][m].time_y == -1 || plate[n][m].time_n == -1) {
        cout << max(plate[n][m].time_n,plate[n][m].time_y) << '\n';
    }
    else {
        cout << min(plate[n][m].time_n,plate[n][m].time_y) << '\n';
    }
    return 0;
}