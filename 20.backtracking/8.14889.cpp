#include <iostream>
#include <vector>
using namespace std;
int n;
int ans = 1000000;
vector<vector<int>> value(21,vector<int>(21));
vector<bool> team(21);
void diff_result()  {
    int start_result = 0;
    int link_result = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(team[i] && team[j]) {
                start_result += value[i][j] + value[j][i];
            }
            else if(!team[i] && !team[j]) {
                link_result += value[i][j] + value[j][i];
            }
        }
    }
    if(abs(start_result - link_result) < ans) ans = abs(start_result - link_result);
}
void solve(int cnt, int idx) {
    if(cnt == n/2) {
        diff_result();
        return;
    }
    for(int i = idx; i <= n; i++) {
        if(!team[i]) {
            team[i] = true;
            solve(cnt + 1, i + 1);
            team[i] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> value[i][j];
        }
    }
    solve(0, 1);
    cout << ans << '\n';
    return 0;
}   