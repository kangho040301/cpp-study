#include <iostream>
using namespace std;
int plate[503][503]{};
bool visited[503][503]{};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int sum = 0;
void dfs(int i, int j, int depth, int cntSum) {
    if(depth == 4) {
        sum = max(sum,cntSum);
        return;
    }

    for(int a = 0; a < 4; a++) {
        int ni = i + dx[a];
        int nj = j + dy[a];
        if(plate[ni][nj] != 0 && !visited[ni][nj]) {
            visited[ni][nj] = true;
            dfs(ni, nj, depth + 1,cntSum + plate[ni][nj]);
            visited[ni][nj] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> plate[i][j];
        }
    }
    int final_ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            visited[i][j] = true;
            dfs(i,j,1,plate[i][j]);
            visited[i][j] = false;
            sum = max(sum,plate[i][j] + plate[i][j+1] + plate[i][j+2] + plate[i-1][j+1]);
            sum = max(sum,plate[i][j] + plate[i][j+1] + plate[i][j+2] + plate[i+1][j+1]);
            sum = max(sum,plate[i][j] + plate[i+1][j] + plate[i+2][j] + plate[i+1][j-1]);
            sum = max(sum,plate[i][j] + plate[i+1][j] + plate[i+2][j] + plate[i+1][j+1]);
            final_ans = max(final_ans, sum);
            sum = 0;
        }
    }
    cout << final_ans << '\n';
    return 0;
}