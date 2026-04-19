#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s; cin >> s;
    string ans, temp;
    for(char a : s) {
        if(a == '(') {
            temp.push_back(a);
        }
        else if(a == ')') {
            while(!temp.empty() && temp.back() != '(') {
                ans.push_back(temp.back());
                temp.pop_back();
            }
            temp.pop_back(); // '(' 소멸
        }
        else if(a == '*' || a == '/') {
            if(!temp.empty() && (temp.back() == '*' || temp.back() == '/')) {
                ans.push_back(temp.back());
                temp.pop_back();
                temp.push_back(a);
            }
            else temp.push_back(a);
        }
        else if(a == '+' || a == '-') {
            if((!temp.empty() && temp.back() == '(') || temp.empty()) {
                temp.push_back(a);
            }
            else {
                while(!temp.empty() && temp.back() != '(') {
                    ans.push_back(temp.back());
                    temp.pop_back();
                }
                temp.push_back(a);
            }
        }
        else {
            ans.push_back(a);
        }
    }
    while(!temp.empty()) {
        if(temp.back() == '(' || temp.back() == ')') {
            temp.pop_back();
        }
        else {
            ans.push_back(temp.back());
            temp.pop_back();
        }
    }
    cout << ans << '\n';
    return 0;
}