#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string a, b, c;
    cin >> a >> b >> c;
    if(isdigit(a[0])) {
        int n = stoi(a) + 3;
        if(n % 3 == 0 && n % 5 == 0) {
            cout << "FizzBuzz" << '\n';
        }
        else if(n % 3 == 0) {
            cout << "Fizz" << '\n';
        }
        else if(n % 5 == 0) {
            cout << "Buzz" << '\n';
        }
        else {
            cout << n << '\n';
        }
        return 0;
    }
    if(isdigit(b[0])) {
        int n = stoi(b) + 2;
        if(n % 3 == 0 && n % 5 == 0) {
            cout << "FizzBuzz" << '\n';
        }
        else if(n % 3 == 0) {
            cout << "Fizz" << '\n';
        }
        else if(n % 5 == 0) {
            cout << "Buzz" << '\n';
        }
        else {
            cout << n << '\n';
        }
        return 0;
    }
    if(isdigit(c[0])) {
        int n = stoi(c) + 1;
        if(n % 3 == 0 && n % 5 == 0) {
            cout << "FizzBuzz" << '\n';
        }
        else if(n % 3 == 0) {
            cout << "Fizz" << '\n';
        }
        else if(n % 5 == 0) {
            cout << "Buzz" << '\n';
        }
        else {
            cout << n << '\n';
        }
        return 0;
    }
}