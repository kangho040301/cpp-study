#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int cheese = 0;
int ans = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void sealed(vector<vector<int>>& paper) {
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(101,vector<bool>(101,false));
    q.push({1,1}); q.push({1,m});
    q.push({n,1}); q.push({n,m});
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx > 0 && ny > 0 && nx <= n && ny <= m) {
                if(!visited[nx][ny] && (paper[nx][ny] == 0 || paper[nx][ny] == 2)) {
                    visited[nx][ny] = true;
                    paper[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
        }
    }   
}
void melt(vector<vector<int>>& paper) {
    vector<vector<int>> p = paper;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(paper[i][j] == 1) {
                int ismelt = 0;
                for(int x = 0; x < 4; x++) {
                    int nx = i + dx[x];
                    int ny = j + dy[x];
                    if(paper[nx][ny] == 2) {
                        ismelt++;
                        if(ismelt >= 2) {
                            p[i][j] = 2;
                            cheese--;
                            break;
                        }
                    }
                }
            }
        }
    }  
    paper = p;
    return;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    vector<vector<int>> paper(n+1,vector<int>(m+1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> paper[i][j];
            if(paper[i][j] == 1) cheese++;
        }
    }
    while(cheese > 0) {
        sealed(paper);
        melt(paper);
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
