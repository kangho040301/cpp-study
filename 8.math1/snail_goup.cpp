// 6 - (5-1) = 2 <= 5
// 11 -(5-1)*2 = 3 <= 5
// 5 - (2-1)*3 = 2 <= 2
// 1000000000 - (100-99)*999999900 = 100 <= 100

//5 - 2 = 3 <= (2-1)*3
//6 - 5 = 1 <= (5-1)*1
//6 4 10   10 - 6 = 4 <= (6-4)*2
//19 4 143   143 - 19 = 124 <= (19-4)*9
//28 17 294  294 - 28 = 266 <= (28-17)*25
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int a, b, v;
    cin >> a >> b >> v;
    int n = v - a;
    int m = n/(a-b);
    if(n%(a-b) == 0) cout << m+1 << '\n';
    else cout << m+2 << '\n';
}