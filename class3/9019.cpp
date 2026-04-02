#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int D(int num) {
    return (num*2)%10000;
}
int S(int num) {
    if(num == 0) return 9999;
    else return num - 1;
}
int L(int num) {
    return (num*10)%10000 + num/1000;
}
int R(int num) {
    return num/10 + (num%10)*1000;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        bool visited[10000]{};
        pair<int,char> p[10000]{};
        queue<int> q;
        q.push(a);
        visited[a] = true;
        while(!q.empty()) {
            int cnt = q.front(); q.pop();
            if(cnt == b) break;
            int n1 = D(cnt);
            if(!visited[n1]) {
                visited[n1] = true;
                p[n1] = {cnt, 'D'};
                q.push(n1);
            }
            int n2 = S(cnt);
            if(!visited[n2]) {
                visited[n2] = true;
                p[n2] = {cnt, 'S'};
                q.push(n2);
            }
            int n3 = L(cnt);
            if(!visited[n3]) {
                visited[n3] = true;
                p[n3] = {cnt, 'L'};
                q.push(n3);
            }
            int n4 = R(cnt);
            if(!visited[n4]) {
                visited[n4] = true;
                p[n4] = {cnt, 'R'};
                q.push(n4);
            }
        }
        string ans = "";
        int cnt = b;
        while(cnt != a) {
            ans += p[cnt].second;
            cnt = p[cnt].first;
        }
        reverse(ans.begin(),ans.end());
        cout << ans << '\n';
    }
    return 0;
}