#include <iostream>
#include <vector>
using namespace std;
int n;
int ans = 0;
vector<vector<int>> die(15,vector<int>(15)); // 공격 범위면 true, 아니면 false
void put(int i, int j);
void back(int i, int j);
void queen(int cnt) {
    if(cnt == n) {
        ans++;
        return;
    }
    int i = cnt; // 퀸이 있는 가로축은 검사 x
    for(int j = 0; j < n; j++) {
        if(!die[i][j]) { // (i, j)에 퀸을 놓을 수 있다면?
            put(i, j); // 퀸 놓기 + 공격 범위 설정
            queen(cnt + 1); // 다음 퀸
            back(i, j); // 퀸 빼기 
        }
    }
}

void put(int i, int j) {
    for(int a = 0; a < n; a++) {
        die[i][a]++; //세로축
        die[a][j]++; //가로축
    }
    int a = 1;
    while(i-a >= 0 && j-a >=0) { // \ 방향
        die[i-a][j-a]++; a++;
    }
    a = 1;
    while(i+a < n && j+a < n) {
        die[i+a][j+a]++; a++;
    }
    a = 1;
    while(i-a >= 0 && j+a < n) { // / 방향
        die[i-a][j+a]++; a++;
    }
    a = 1;
    while(i+a < n && j-a >= 0) {
        die[i+a][j-a]++; a++;
    }
    die[i][j]--; // 중복 빼기
}
void back(int i, int j) {
    for(int a = 0; a < n; a++) {
        die[i][a]--; //세로축
        die[a][j]--; //가로축
    }
    int a = 1;
    while(i-a >= 0 && j-a >=0) { // \ 방향
        die[i-a][j-a]--; a++;
    }
    a = 1;
    while(i+a < n && j+a < n) {
        die[i+a][j+a]--; a++;
    }
    a = 1;
    while(i-a >= 0 && j+a < n) { // / 방향
        die[i-a][j+a]--; a++;
    }
    a = 1;
    while(i+a < n && j-a >= 0) {
        die[i+a][j-a]--; a++;
    }
    die[i][j]++; // 중복 빼기
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    queen(0);
    cout << ans << '\n';
    return 0;
}