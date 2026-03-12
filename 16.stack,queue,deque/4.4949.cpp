#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    while(true) {
        string s;
        getline(cin, s);
        if(s == ".") return 0;
        
        stack<int> ps;
        bool isPS = true;
        for(char a : s) {
            if(!isPS) break;
            
            switch (a) {
                case '(' :
                    ps.push(a);
                    break;
                case '[' :
                    ps.push(a);
                    break;
                case ')' :
                    if(ps.empty() || ps.top() == '[') isPS = false;
                    else ps.pop();
                    break;
                case ']' :
                    if(ps.empty() || ps.top() == '(') isPS = false;
                    else ps.pop();
                    break;
           }
        }
        cout << (isPS && ps.empty() ? "yes" : "no") << '\n';
    }
    return 0;
}