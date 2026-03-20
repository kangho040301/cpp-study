#include <iostream>
#include <vector>
using namespace std;
struct Bag { // 무게, 가치
    int w, v;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<Bag> bag(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> bag[i].w >> bag[i].v;
    }
    //dp[w] w kg 가방에 넣을 수 있는 최대 가치
    vector<int> dp(k+1, 0);
    for(int i = 1; i <= n; i++) {
        for(int w = k; w >= bag[i].w; w--) {
            dp[w] = max(dp[w], dp[w - bag[i].w] + bag[i].v);
        }
    }
    cout << dp[k] << '\n';
    return 0;
}