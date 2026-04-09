#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> weight(n+1);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
        sum += weight[i];
    }
    //dp[i][w] i번째 추를 확인할 때, w(무게)를 판단
    vector<vector<bool>> dp(n+1,vector<bool>(40001,false));
    dp[0][0] = true;
    for(int i = 0; i < n; i++) {
        for(int w = 0; w <= sum; w++) {
            if(dp[i][w]) {
                dp[i+1][w+weight[i]] = true; //구슬 반대편에 놓는 경우
                dp[i+1][w] = true; //안 놓는 경우
                dp[i+1][abs(w-weight[i])] = true; //구슬과 같은 곳에 놓는 경우
            }
        }
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        if(dp[n][x]) cout << "Y ";
        else cout  << "N ";
    }
    cout << '\n';
    return 0;
}