#include <iostream>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;

    stack<int> line;
    int i = 1;
    while(n--) {
        int num;
        cin >> num;

        if(num == i) i++;
        else {
            line.push(num);
        }
        while(!(line.empty()) && line.top() == i) {
            i++;
            line.pop();
        }
    }
    
    cout << (line.empty() ? "Nice" : "Sad") << '\n';
    return 0;
}