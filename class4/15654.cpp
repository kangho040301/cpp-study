#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans[9];
bool visited[9];
int n, m;
void solve(vector<int>& v, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            ans[cnt] = v[i];
            solve(v, cnt + 1);
            visited[i] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    solve(v, 0);
    return 0;
}