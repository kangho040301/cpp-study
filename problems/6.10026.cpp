#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int ans1, ans2;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool visited1[101][101];
bool visited2[101][101];
int bfs1(vector<string> &plate, int i, int j) {
    int size = plate.size();
    queue<pair<int,int>> q;
    q.push({i,j});
    visited1[i][j] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < size && ny < size) {
                if(!visited1[nx][ny] && plate[nx][ny] == plate[x][y]) {
                    visited1[nx][ny] = true;
                    q.push({nx,ny});
                } 
            }
        }
    }
    return 1;
}
int bfs2(vector<string> &plate, int i, int j) {
    int size = plate.size();
    queue<pair<int,int>> q;
    q.push({i,j});
    visited2[i][j] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < size && ny < size) {
                if(!visited2[nx][ny]) {
                    if(plate[x][y] == 'B' && plate[x][y] == plate[nx][ny]) {
                        visited2[nx][ny] = true;
                        q.push({nx,ny});
                    }
                    else if((plate[x][y] == 'R' || plate[x][y] == 'G') 
                    && (plate[nx][ny] == 'R' || plate[nx][ny] == 'G')) {
                        visited2[nx][ny] = true;
                        q.push({nx,ny});
                    }

                }
            }
        }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<string> plate(n,"");
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    for(int i = 0; i < n; i++) {
        cin >> plate[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited1[i][j]) {
                ans1 += bfs1(plate,i,j);
            }
            if(!visited2[i][j]) {
                ans2 += bfs2(plate,i,j);
            }
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}