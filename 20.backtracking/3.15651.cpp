#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> ans(8);

void solve(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++) {
        ans[cnt] = i;
        solve(cnt + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    solve(0);
    return 0;
}