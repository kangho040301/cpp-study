#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    int a4 = 0;
    int b4 = 0;
    if(a1 == a2) a4 = a3;
    else if(a1 == a3) a4 = a2;
    else if(a2 == a3) a4 = a1;
    
    if(b1 == b2) b4 = b3;
    else if(b1 == b3) b4 = b2;
    else if(b2 == b3) b4 = b1;
    cout << a4 << ' ' << b4 << '\n';
    return 0;
}
/* XOR 연산자 ^ 이용
int a4 = a1 ^ a2 ^ a3;
int b4 = b1 ^ b2 ^ b3;
//a ^ a = 0 , a ^ 0 = a 라는 성질이 있음
*/