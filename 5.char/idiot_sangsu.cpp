#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    cout << max(a,b) << '\n'; // max, >, <는 알아서 string도 사전 순으로 골라준다. (길이 상관 없음)
    return 0;
}