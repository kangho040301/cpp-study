#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> memo(n + 1); // i번째 잔까지 마실 수 있는 최대
    vector<int> point(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> point[i];
    }
    memo[1] = point[1];
    memo[2] = point[1] + point[2];
    for (int i = 3; i <= n; i++)
    {
        memo[i] = max(memo[i - 1], 
                max(point[i] + memo[i - 2],
                 point[i] + point[i - 1] + memo[i - 3]));
    }
    cout << memo[n] << '\n';
    return 0;
}