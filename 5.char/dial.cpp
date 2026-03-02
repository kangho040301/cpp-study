#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int len = s.length();
    int t = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] < 'D')
            t += 3;
        else if (s[i] < 'G')
            t += 4;
        else if (s[i] < 'J')
            t += 5;
        else if (s[i] < 'M')
            t += 6;
        else if (s[i] < 'P')
            t += 7;
        else if (s[i] < 'T')
            t += 8;
        else if (s[i] < 'W')
            t += 9;
        else
            t += 10;
    }
    cout << t << '\n';
    return 0;
}