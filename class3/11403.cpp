#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& l, vector<bool>& go, int cnt) {
    for(int next : l[cnt]) {
        if(!go[next]) {
            go[next] = true;
            dfs(l, go, next);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<vector<int>> l(n+1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x; cin >> x;
            if(x) l[i].push_back(j);
        }
    }
    vector<vector<bool>> go(n+1,vector<bool>(n+1));
    for(int i = 1; i <= n; i++) {
        dfs(l, go[i], i);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(go[i][j]) cout << 1 << ' ';
            else cout << 0 << ' ';
        }
        cout << '\n';
    }
    return 0;
}