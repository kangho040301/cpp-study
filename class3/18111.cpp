#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, b;
    cin >> n >> m >> b;
    vector<int> g(n*m);
    int mintime = INT_MAX, maxheight = 0, minheight = INT_MAX;
    int ansheight = minheight;
    for (int i = 0; i < n*m; i++)
    {
        cin >> g[i];
        maxheight = max(maxheight, g[i]);
        minheight = min(minheight, g[i]);
    }

    if(maxheight == minheight) {
        cout << 0 << ' ' << maxheight << '\n';
        return 0;
    }
    
    for (int h = minheight; h <= maxheight; h++)
    {
        int time = 0;
        int tempB = b;
        for (int i = 0; i < n*m; i++)
        {
            if (g[i] > h)
            {
                time += (g[i] - h) * 2;
                tempB += (g[i] - h);
            }
            else if (g[i] < h)
            {
                tempB -= (h - g[i]);
                time += (h - g[i]);
            }
        }
        if(tempB >= 0) {
            if (time <= mintime) {
                mintime = time;
                ansheight = h;
            }
        }
    }

    cout << mintime << ' ' << ansheight << '\n';
    return 0;
}