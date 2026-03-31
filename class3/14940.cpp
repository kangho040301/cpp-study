#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Point {
    int x, y;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> ground(n+2,vector<int>(m+2,0));
    queue<Point> q;
    Point start = {0,0};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> ground[i][j];
            if(ground[i][j] == 2) {
                start = {i,j};
                ground[i][j] = 1;
            }
        }
    } 
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    q.push(start);
    while(!q.empty()) {
        int cntX = q.front().x;
        int cntY = q.front().y;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nextX = cntX + dx[i];
            int nextY = cntY + dy[i];
            if(ground[nextX][nextY] == 1 && !(nextX == start.x && nextY == start.y)) {
                q.push({nextX,nextY});
                ground[nextX][nextY] = ground[cntX][cntY] + 1;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(ground[i][j] == 0) {
                cout << 0 << ' ';
            }
            else if(!(start.x == i && start.y == j) && ground[i][j] == 1) {
                cout << -1 << ' ';
            }
            else {
                cout << ground[i][j] - 1 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}