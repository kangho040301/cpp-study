#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> ans(9);
vector<bool> visited(9);
void solve(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) { // i를 안 썼다면
            visited[i] = true; // i를 사용 중
            ans[cnt] = i; // cnt자리를 i로
            solve(cnt + 1); // 다음 자리 이동
            visited[i] = false; // *다시 뒤로 가기*
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    solve(0);
    return 0;
}