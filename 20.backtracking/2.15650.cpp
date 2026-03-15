#include <iostream>
#include <vector>
using namespace std;
vector<int> ans(9);
int n, m;
void solve(int cnt, int start) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = start; i <= n; i++) {
        ans[cnt] = i; //현재 = i;
        solve(cnt + 1, i + 1); //다음 칸, i + 1부터
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    solve(0, 1);
    return 0;
}