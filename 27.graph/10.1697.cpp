#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    bool visited[100001];
    int time[100001];
    queue<int> q;
    q.push(n);
    time[n] = 0;
    visited[n] = true;
    int cnt = 0;
    while(!q.empty()) {
        cnt = q.front(); q.pop();
        if(cnt == k) break;
        int next1 = cnt - 1;
        int next2 = cnt + 1;
        int next3 = cnt * 2;
        int next[] = {next1, next2, next3};
        for(int i = 0; i < 3; i++) {
            if(next[i] >= 0 && next[i] <= 100000 && !visited[next[i]]) {
                time[next[i]] = time[cnt] + 1;
                visited[next[i]] = true;
                q.push(next[i]);
            }
        }
    }
    cout << time[k] << '\n';
    return 0;
}