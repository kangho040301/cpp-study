#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
void cantor(string &s, int start, int len) {
    if(len == 1) return;

    int third = len / 3;
    fill(s.begin() + start + third, s.begin() + start + 2*third, ' ');
    cantor(s, start, third);
    cantor(s, start + 2*third, third);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    while(cin >> n) {
        int len = static_cast<int>(round(pow(3,n)));
        string s(len,'-');

        cantor(s, 0 , len);

        cout << s << '\n';
    }
    return 0;
}