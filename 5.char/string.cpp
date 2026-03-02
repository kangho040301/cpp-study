#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int i;
    cin >> i;
    cout << s[i-1] << '\n';
    return 0;
}