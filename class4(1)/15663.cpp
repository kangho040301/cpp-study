#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
bool visited[9];
int ans[9];
void solve(vector<int> &v, int cnt){
    if (cnt == m){
        for (int i = 0; i < m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int last_i = -1;
    for (int i = 0; i < n; i++){
        if (!visited[i] && last_i != v[i]){
            visited[i] = true;
            ans[cnt] = v[i];
            last_i = v[i];
            solve(v, cnt + 1);
            visited[i] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    solve(v, 0);
}