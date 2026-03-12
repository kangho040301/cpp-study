#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    while(n--) {
        string p;
        cin >> p;
        int isPS = 0;
        for(char a : p) {
            if(a == '(') {
                isPS++;
            }
            else if(a == ')'){
                isPS--;
                if(isPS < 0) {
                    cout << "NO" << '\n';
                    break;
                }
            }
        }
        if(isPS == 0) cout << "YES" << '\n';
        else if(isPS > 0) cout << "NO" << '\n';
    }
    return 0;
}