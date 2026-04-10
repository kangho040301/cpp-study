#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    int max_dp[3] = {a, b, c};
    int min_dp[3] = {a, b, c};
    int next_max[3], next_min[3];

    for(int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        next_max[0] = max(max_dp[0] + a, max_dp[1] + a);
        next_max[1] = max({max_dp[0] + b, max_dp[1] + b, max_dp[2] + b});
        next_max[2] = max(max_dp[1] + c, max_dp[2] + c);

        next_min[0] = min(min_dp[0] + a, min_dp[1] + a);
        next_min[1] = min({min_dp[0] + b, min_dp[1] + b, min_dp[2] + b});
        next_min[2] = min(min_dp[1] + c, min_dp[2] + c);

        for(int j = 0; j < 3; j++) {
            max_dp[j] = next_max[j];
            min_dp[j] = next_min[j];
        }
    }
    int ans_max = max({max_dp[0],max_dp[1],max_dp[2]});
    int ans_min = min({min_dp[0],min_dp[1],min_dp[2]});
    cout << ans_max << ' ' << ans_min << '\n';
    return 0;
}