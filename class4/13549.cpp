#include <iostream>
#include <deque>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    bool visited[100001]{};
    int ans[100001]{};
    deque<int> q;
    q.push_back(n);
    visited[n] = true;
    int dx[] = {2, -1, 1};
    while(!q.empty()) {
        int cnt = q.front(); q.pop_front();

        if(cnt == k) {
            cout << ans[k] << '\n';
            return 0;
        }

        for(int i = 0; i < 3; i++) {
            if(i == 0) {
                int next = dx[i]*cnt;
                if(next >= 0 && next <= 100000 && !visited[next] ) {
                    visited[next] = true;
                    q.push_front(next);
                    ans[next] = ans[cnt];
                }
            }
            else {
                int next = cnt + dx[i];
                if(next >= 0 && next <= 100000 && !visited[next] ) {
                    visited[next] = true;
                    q.push_back(next);
                    ans[next] = ans[cnt] + 1;
                }
            }
        }
    }
}