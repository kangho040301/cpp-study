#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    int n = 0;
    while(cin >> word) n++;
    cout << n << '\n';
    return 0;
}