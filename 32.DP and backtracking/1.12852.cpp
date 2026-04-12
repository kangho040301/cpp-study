#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    queue<pair<int,int>> q;
    vector<int> parent(n+1);
    vector<bool> visited(n+1);
    q.push({n,0});
    visited[n] = true;
    while(!q.empty()) {
        int cnt = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if(cnt == 1) {
            cout << depth << '\n';
            break;
        }

        int next[] = {cnt/3, cnt/2, cnt - 1};
        for(int i = 0; i < 3; i++) {
            int next_v = next[i];
            if(i == 0 && cnt%3 != 0) continue;
            if(i == 1 && cnt%2 != 0) continue;
            if(!visited[next_v]) {
                visited[next_v] = true;
                parent[next_v] = cnt;
                q.push({next_v, depth + 1});
            }
        }
    }

    vector<int> ans(1,1);
    int i = 0;
    while(ans[i] < n) {
        ans.push_back(parent[ans[i]]);
        i++;
    }
    reverse(ans.begin(),ans.end());
    for(int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
