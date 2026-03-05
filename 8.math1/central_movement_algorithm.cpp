/*
1*2 + 1 = 3
2*2 + 1 = 5
4*2 + 1 = 9
8*2 + 1 = 17
16*2 + 1 = 33 ...
*/
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    int num = 1;
    for(int i = 0; i < n; i++) {
        num = num*2;
    }
    int answer = (num+1)*(num+1);
    cout << answer << '\n';
    return 0;
}
