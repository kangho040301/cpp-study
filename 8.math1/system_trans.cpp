#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string n;
    int b;
    cin >> n >> b;
    int answer = 0;
    int len = n.length();
    for(int i = 0; i < len; i++) {
        if(n[i] <= '9' && n[i] >= '0') {
            answer += (n[i] - '0')*int(pow(b,len-i-1));
        }
            else {
            answer += (n[i] - 'A' + 10)*int(pow(b,len-i-1));
        }
    }
    cout << answer << '\n';
    return 0;
}
/*
int answer = 0;
for(int i = 0; i < n.length(); i++) {
    int num;
    if(n[i] >= '0' && n[i] <= '9') {
        num = n[i] - '0';
    } else {
        num = n[i] - 'A' + 10;
    }
    // 이전에 구한 값에 진수(b)를 곱하고 새 숫자를 더함 (호너의 방법)
    answer = answer * b + num;
}
*/