#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int m; cin >> m;
    int a = 0; //32비트 공집합
    while(m--) {
        string str; cin >> str;
        if(str == "add") {
            int x; cin >> x;
            a |= (1 << x); //x비트 켬
        }
        else if(str == "remove") {
            int x; cin >> x;
            a &= ~(1 << x); //x비트 끔
        }
        else if(str == "check") {
            int x; cin >> x;
            if(a & (1 << x)) cout << 1 << '\n'; //a의 x비트가 1인가?
            else cout << 0 << '\n';
        }
        else if(str == "toggle") {
            int x; cin >> x;
            a ^= (1 << x); //XOR연산; 0 -> 1 , 1 -> 0
        }
        else if(str == "all") {
            a = (1 << 21) - 1; // 21비트 1 -> -1 하면 0~20비트가 다 1됨
        }
        else if(str == "empty") {
            a = 0; //공집합
        }
    }
    return 0;
}