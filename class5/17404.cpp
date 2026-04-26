#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct RGB
{
    int r, g, b;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a, b, c;
    vector<RGB> house(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> house[i].r >> house[i].g >> house[i].b;
    }
    int final_ans = 1e9;
    for (int start = 0; start <= 2; start++)
    {
        vector<vector<int>> dp(n + 1, vector<int>(3));
        if (start == 0)
        {
            dp[1][0] = house[1].r;
            dp[1][1] = 1e8;
            dp[1][2] = 1e8;
        }
        if (start == 1)
        {
            dp[1][0] = 1e8;
            dp[1][1] = house[1].g;
            dp[1][2] = 1e8;
        }
        if (start == 2)
        {
            dp[1][0] = 1e8;
            dp[1][1] = 1e8;
            dp[1][2] = house[1].b;
        }

        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = house[i].r + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = house[i].g + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = house[i].b + min(dp[i - 1][0], dp[i - 1][1]);
        }

        if (start == 0)
        {
            int ans = min(dp[n][1], dp[n][2]);
            final_ans = min(final_ans, ans);
        }
        if (start == 1)
        {
            int ans = min(dp[n][0], dp[n][2]);
            final_ans = min(final_ans, ans);
        }
        if (start == 2)
        {
            int ans = min(dp[n][0], dp[n][1]);
            final_ans = min(final_ans, ans);
        }
    }
    cout << final_ans << '\n';
    return 0;
}