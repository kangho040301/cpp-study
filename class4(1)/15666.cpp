#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v;
int ans[8];
void solve(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < v.size(); i++) {
        if(v[i] < ans[cnt - 1]) continue;
        ans[cnt] = v[i];
        solve(cnt + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(find(v.begin(),v.end(),x) == v.end()) v.push_back(x);
    }
    sort(v.begin(),v.end());
    solve(0);
    return 0;
}