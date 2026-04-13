#include <iostream>
#include <string>
#include <vector>
using namespace std;
int r, c;
bool visited[26];
vector<string> board;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int ans = 0;
void dfs(int cntr, int cntc, int dep) {
    visited[board[cntr][cntc] - 'A'] = true;
    ans = max(ans, dep);

    for(int i = 0; i < 4; i++) {
        int nr = cntr + dr[i];
        int nc = cntc + dc[i];
        if(nr >= 0 && nc >= 0 && nr < r && nc < c) {
            if(!visited[board[nr][nc] - 'A']) {
                dfs(nr,nc,dep + 1);
                visited[board[nr][nc] - 'A'] = false;
            }
        } 
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> r >> c;
    board.resize(r);
    for(int i = 0; i < r; i++) {
        cin >> board[i];
    }
    dfs(0, 0, 1);
    cout << ans << '\n';
    return 0;
}
