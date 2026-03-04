#include <iostream>
#include <vector>
using namespace std;
void cin_matrix(vector<vector<int>> &matrix, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        } 
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix1(n, vector<int>(m, 0));
    vector<vector<int>> matrix2(n, vector<int>(m, 0));
    cin_matrix(matrix1, n, m);
    cin_matrix(matrix2, n, m);
    
    vector<vector<int>> n_matrix(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            n_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            cout << n_matrix[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
/*
void cin_matrix(vector<vector<int>> &matrix) {
    int n = matrix.size();       // 행의 개수
    int m = matrix[0].size();    // 열의 개수
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
}
*/