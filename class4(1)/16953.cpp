#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b; cin >> a >> b;
    queue<pair<ll,ll>> q;
    q.push({a,0});
    while(!q.empty()) {
        ll cnt = q.front().first;
        ll d = q.front().second;
        q.pop();
        if(cnt == b) {
            cout << d + 1 << '\n';
            return 0;
        }

        ll next1 = 10*cnt + 1;
        ll next2 = 2*cnt;
        if(next1 <= b) q.push({next1,d+1});
        if(next2 <= b) q.push({next2,d+1});
    }
    cout << -1 << '\n';
    return 0;
}