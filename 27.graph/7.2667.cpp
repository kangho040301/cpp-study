#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> plate(n + 2, vector<int>(n + 2));
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            plate[i][j] = s[j - 1] - '0';
        }
    }
    vector<vector<bool>> visited(n + 2, vector<bool>(n + 2));
    queue<pair<int, int>> point;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!visited[i][j] && plate[i][j])
            {
                int s = 1;
                visited[i][j] = true;
                point.push({i, j});
                int a = i, b = j;
                while (!point.empty())
                {
                    pair<int, int> cnt = point.front();
                    point.pop();
                    int x1 = cnt.first - 1, y1 = cnt.second;
                    int x2 = cnt.first + 1, y2 = cnt.second;
                    int x3 = cnt.first, y3 = cnt.second - 1;
                    int x4 = cnt.first, y4 = cnt.second + 1;
                    if (!visited[x1][y1] && plate[x1][y1])
                    {
                        visited[x1][y1] = true;
                        s++;
                        point.push({x1, y1});
                    }
                    if (!visited[x2][y2] && plate[x2][y2])
                    {
                        visited[x2][y2] = true;
                        s++;
                        point.push({x2, y2});
                    }
                    if (!visited[x3][y3] && plate[x3][y3])
                    {
                        visited[x3][y3] = true;
                        s++;
                        point.push({x3, y3});
                    }
                    if (!visited[x4][y4] && plate[x4][y4])
                    {
                        visited[x4][y4] = true;
                        s++;
                        point.push({x4, y4});
                    }
                }
                ans.push_back(s);
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for (int a : ans)
    {
        cout << a << '\n';
    }
    return 0;
}
