#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void blank(vector<string> &s, int start_x, int start_y, int size) {
    if(size == 1) return;
    
    int third = size/3;
    //가운데 비우기
    for(int i = start_y + third; i < start_y + 2*third; i++) {
        fill(s[i].begin() + start_x + third, s[i].begin() + start_x + 2*third, ' ');
    }
    //1~9 실행
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) continue;
            int x = start_x + j*third;
            int y = start_y + i*third;
            blank(s,x,y,third);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> s(n,string(n,'*'));
    blank(s,0,0,n);
    
    
    
    for(string a : s) {
        cout << a << '\n';
    }
    return 0;
}