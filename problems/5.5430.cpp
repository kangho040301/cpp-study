#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    deque<int> num;
    while(t--) {
        string p; cin >> p;
        int n; cin >> n;
        string s; cin >> s;
        bool isfinish = false;
        string temp = "";
        for(char a : s) {
            if(isdigit(a)) temp += a;
            else {
                if(!temp.empty()) {
                    num.push_back(stoi(temp));
                    temp = "";
                }
            }
        }
        int rNum = 0;
        for(char f : p) {
            if(f == 'R') {
                rNum++;
            }
            else {
                if(num.empty()) {
                    cout << "error" << '\n';
                    isfinish = true;
                    break;
                }
                if(rNum%2 == 1) {
                    num.pop_back();
                }
                else {
                    num.pop_front();
                }
            }
        }
        if(isfinish) continue;
        if(num.empty()) {
            cout << "[]" << '\n';
            continue;
        }
        cout << "[";
        if(rNum%2 == 1) {
            cout << num.back(); num.pop_back();
            while(!num.empty()) {
                cout << "," << num.back(); num.pop_back();
            }
        }
        else {
            cout << num.front(); num.pop_front();
            while(!num.empty()) {
                cout << "," << num.front(); num.pop_front();
            }
        }
        cout << "]" << '\n';
    }
    return 0;
}