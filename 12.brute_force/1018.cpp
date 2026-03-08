#include <iostream>
#include <string>
#include <vector>
using namespace std;
int paint_board(vector<string> &board, int i, int j) {
    int count_W = 0;
    int count_B = 0;
    for(int r = 0; r < 8; r ++) {
        for(int c = 0; c < 8; c ++) { 
            //r+c가 짝수면, 맨 왼쪽 위 색과 같음
            if((r+c)%2 == 0) {
                if(board[i+r][j+c] != 'W') count_W++;
                if(board[i+r][j+c] != 'B') count_B++;
            }
            else {
                if(board[i+r][j+c] != 'W') count_B++;
                if(board[i+r][j+c] != 'B') count_W++;
            }
        }
    }
    return min(count_W,count_B);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    int min = 32;

    //보드 받기
    vector<string> board(n);
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }
    for(int i = 0; i < n-7; i++) {
        for(int j = 0; j < m-7; j++) { 
            //보드를 검토하며 색칠하고 수 세기
            int paint_t = paint_board(board, i, j);
            //색칠한 개수가 최솟값인가?
            if(paint_t < min) min = paint_t;
        }
    }
    cout << min << '\n';
    return 0;
}