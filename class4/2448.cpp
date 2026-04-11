#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
void blank(vector<string> &shape, int cntr, int cntc, int size)
{
    if (size == 3)
    {
        shape[cntr + 1][cntc] = ' ';
        return;
    }

    int cntsize = size / 2;
    int j = cntsize - 1;
    for (int i = cntr + cntsize; i < cntr + 2 * cntsize; i++)
    {
        fill(shape[i].begin() + cntc - j, shape[i].begin() + cntc + j + 1, ' ');
        j--;
    }

    blank(shape, cntr, cntc, cntsize);
    blank(shape, cntr + cntsize, cntc - cntsize, cntsize);
    blank(shape, cntr + cntsize, cntc + cntsize, cntsize);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<string> shape(n, string(2 * n - 1, ' '));
    for (int i = 0; i < n; i++)
    {
        fill(shape[i].begin() + n - 1 - i, shape[i].begin() + n + i, '*');
    }
    blank(shape, 0, n - 1, n);
    for (string s : shape)
    {
        cout << s << '\n';
    }
    return 0;
}