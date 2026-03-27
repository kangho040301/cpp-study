#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> plate(n+2,vector<int>(m+2));
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++) {
            plate[i][j] = s[j - 1] - '0';
        }
    }
    vector<vector<int>> length(n+2,vector<int>(m+2));
    queue<pair<int,int>> p;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    length[1][1] = 1;
    p.push({1,1});
    while(!p.empty()) {
        pair<int, int> cnt = p.front(); p.pop();
        for(int i = 0; i < 4; i++) {
            int next_i = cnt.first + dx[i];
            int next_j = cnt.second + dy[i];

            if(!length[next_i][next_j] && plate[next_i][next_j]) {
                length[next_i][next_j] = length[cnt.first][cnt.second] + 1;
                p.push({next_i, next_j});
            }
        }
    }
    cout << length[n][m] << '\n';
    return 0;
}