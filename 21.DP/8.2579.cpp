#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> point(n);
    vector<vector<int>> memo(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> point[i];
    }
    if(n == 1) {
        cout << point[0] << '\n';
        return 0;
    }
    if(n == 2) {
        cout << point[0] + point[1] << '\n';
        return 0;
    }
    memo[0][1] = memo[0][2] = point[0];
    memo[1][1] = point[1] + memo[0][1];
    memo[1][2] = point[1];
    for (int i = 2; i < n; i++)
    {
        // 한 칸 뛰어넘을 때 : 전 칸은 무조건 두번 뛰어넘었어야함
        memo[i][1] = point[i] + memo[i - 1][2];
        // 두 칸 뛰어넘을 때 : 전 칸이 한 칸, 두 칸 뛰어넘은 것 중에 큰 거
        memo[i][2] = point[i] + max(memo[i - 2][1], memo[i - 2][2]);
    }
    int ans = max(memo[n - 1][1], memo[n - 1][2]);
    cout << ans << '\n';
    return 0;
}
