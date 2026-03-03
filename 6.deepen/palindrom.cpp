#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string w;
    cin >> w;
    string nw = w;
    reverse(w.begin(),w.end());
    if(nw == w) cout << 1 << '\n';
    else cout << 0 << '\n';
    return 0;
}