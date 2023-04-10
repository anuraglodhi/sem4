#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define ROW_1 4
#define COL_1 4
#define ROW_2 4
#define COL_2 4


vector<vector<int>> add_matrix(vector<vector<int>> matrix_A, vector<vector<int>> matrix_B, int split_index, int multiplier = 1) {
    for (int i = 0; i < split_index; i++) {
        for (int j = 0; j < split_index; j++) {
            matrix_A[i][j] = matrix_A[i][j] + multiplier * matrix_B[i][j];
        }
    }

    return matrix_A;
}

vector<vector<int>> multiply_matrix(vector<vector<int>> matrix_A, vector<vector<int>> matrix_B) {
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();

    if (col_1 != row_2) {
        cout << "Matrix not compatible for multiplication" << endl;
        return {};
    }

    vector<vector<int>> result_matrix(row_1, vector<int>(col_2, 0));

    if (col_1 == 1) {
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
        return result_matrix;
    }

    int split_index = col_1 / 2;

    vector<vector<int>> a11(split_index, vector<int>(split_index, 0));
    vector<vector<int>> a12(split_index, vector<int>(split_index, 0));
    vector<vector<int>> a21(split_index, vector<int>(split_index, 0));
    vector<vector<int>> a22(split_index, vector<int>(split_index, 0));
    vector<vector<int>> b11(split_index, vector<int>(split_index, 0));
    vector<vector<int>> b12(split_index, vector<int>(split_index, 0));
    vector<vector<int>> b21(split_index, vector<int>(split_index, 0));
    vector<vector<int>> b22(split_index, vector<int>(split_index, 0));

    for (int i = 0; i < split_index; i++) {
        for (int j = 0; j < split_index; j++) {
            a11[i][j] = matrix_A[i][j];
            a12[i][j] = matrix_A[i][j + split_index];
            a21[i][j] = matrix_A[split_index + i][j];
            a22[i][j] = matrix_A[split_index + i][j + split_index];
            b11[i][j] = matrix_B[i][j];
            b12[i][j] = matrix_B[i][j + split_index];
            b21[i][j] = matrix_B[split_index + i][j];
            b22[i][j] = matrix_B[split_index + i][j + split_index];
        }
    }

    vector<vector<int>> p(multiply_matrix(add_matrix(a11, a22, split_index), add_matrix(b11, b22, split_index)));
    vector<vector<int>> q(multiply_matrix(add_matrix(a21, a22, split_index), b11));
    vector<vector<int>> r(multiply_matrix(a11, add_matrix(b12, b22, split_index, -1)));
    vector<vector<int>> s(multiply_matrix(a22, add_matrix(b21, b11, split_index, -1)));
    vector<vector<int>> t(multiply_matrix(add_matrix(a11, a12, split_index), b22));
    vector<vector<int>> u(multiply_matrix(add_matrix(a21, a11, split_index, -1), add_matrix(b11, b12, split_index)));
    vector<vector<int>> v(multiply_matrix(add_matrix(a12, a22, split_index, -1), add_matrix(b21, b22, split_index)));

    vector<vector<int>> result11(add_matrix(add_matrix(p, v, split_index), add_matrix(s, t, split_index, -1), split_index));
    vector<vector<int>> result12(add_matrix(r, t, split_index));
    vector<vector<int>> result21(add_matrix(q, s, split_index));
    vector<vector<int>> result22(add_matrix(add_matrix(p, u, split_index), add_matrix(r, q, split_index, -1), split_index));

    for (int i = 0; i < split_index; i++) {
        for (int j = 0; j < split_index; j++) {
            result_matrix[i][j] = result11[i][j];
            result_matrix[i][j + split_index] = result12[i][j];
            result_matrix[i + split_index][j] = result21[i][j];
            result_matrix[i + split_index][j + split_index] = result22[i][j];
        }
    }

    a11.clear();
    a12.clear();
    a21.clear();
    a22.clear();
    b11.clear();
    b12.clear();
    b21.clear();
    b22.clear();
    p.clear();
    q.clear();
    r.clear();
    s.clear();
    t.clear();
    u.clear();
    v.clear();
    result11.clear();
    result12.clear();
    result21.clear();
    result22.clear();

    return result_matrix;
}

void print(string display, vector<vector<int> > matrix,
           int start_row, int start_column, int end_row,
           int end_column)
{
    cout << endl << display << " =>" << endl;
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_column; j <= end_column; j++) {
            cout << setw(10);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return;
}

int main()
{
    vector<vector<int> > matrix_A = { { 1, 1, 1, 1 },
                                      { 2, 2, 2, 2 },
                                      { 3, 3, 3, 3 },
                                      { 2, 2, 2, 2 } };
 
    print("Array A", matrix_A, 0, 0, ROW_1 - 1, COL_1 - 1);
 
    vector<vector<int> > matrix_B = { { 1, 1, 1, 1 },
                                      { 2, 2, 2, 2 },
                                      { 3, 3, 3, 3 },
                                      { 2, 2, 2, 2 } };
 
    print("Array B", matrix_B, 0, 0, ROW_2 - 1, COL_2 - 1);
 
    vector<vector<int> > result_matrix(
        multiply_matrix(matrix_A, matrix_B));
 
    print("Result Array", result_matrix, 0, 0, ROW_1 - 1,
          COL_2 - 1);
}