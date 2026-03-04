#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<vector<int>> matrix(9, vector<int>(9, 0));
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<int> max_matrix(9, 0);
    vector<int> max_column(9, 0);
    for(int i = 0; i < 9; i++) {
        auto it = max_element(matrix[i].begin(),matrix[i].end());
        int idx = it - matrix[i].begin();
        max_matrix[i] = matrix[i][idx];
        max_column[i] = idx + 1;
    }
    auto it = max_element(max_matrix.begin(),max_matrix.end());
    int max_idx = it - max_matrix.begin();
    cout << max_matrix[max_idx] << '\n';
    cout << max_idx + 1 << ' ' << max_column[max_idx] << '\n';
    return 0;
}
/*
//값을 저장하지 않고 바로 비교 후 출력 
int max_val = -1; // 최솟값이 0이므로 -1로 초기화
int row_idx = 0, col_idx = 0;

for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
        int current;
        cin >> current;
        if(current > max_val) {
            max_val = current;
            row_idx = i + 1;
            col_idx = j + 1;
        }
    }
}
cout << max_val << '\n' << row_idx << " " << col_idx << '\n';
*/