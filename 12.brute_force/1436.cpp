#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;

    int num = 666;
    int count = 0;
    while(true) {
        string s(to_string(num));
        if(s.find("666") != string::npos) count++;
        if(n == count) {
            cout << num << '\n';
            return 0;
        }
        num++;
    }
}
