#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> ans(9);

void solve(int cnt, int start) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = start; i <= n; i++) {
        ans[cnt] = i;
        solve(cnt + 1, i);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    solve(0, 1);
    return 0;
}