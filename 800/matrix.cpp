#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> addMatrix(vector<vector<int>> A,
                              vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;
}

vector<vector<int>> subtractMatrix(vector<vector<int>> A,
                                   vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;
}

vector<vector<int>> strassen(vector<vector<int>> A,
                             vector<vector<int>> B) {
    int n = A.size();

    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;

    vector<vector<int>> A11(k, vector<int>(k));
    vector<vector<int>> A12(k, vector<int>(k));
    vector<vector<int>> A21(k, vector<int>(k));
    vector<vector<int>> A22(k, vector<int>(k));

    vector<vector<int>> B11(k, vector<int>(k));
    vector<vector<int>> B12(k, vector<int>(k));
    vector<vector<int>> B21(k, vector<int>(k));
    vector<vector<int>> B22(k, vector<int>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    vector<vector<int>> M1 = strassen(
        addMatrix(A11, A22),
        addMatrix(B11, B22)
    );

    vector<vector<int>> M2 = strassen(
        addMatrix(A21, A22),
        B11
    );

    vector<vector<int>> M3 = strassen(
        A11,
        subtractMatrix(B12, B22)
    );

    vector<vector<int>> M4 = strassen(
        A22,
        subtractMatrix(B21, B11)
    );

    vector<vector<int>> M5 = strassen(
        addMatrix(A11, A12),
        B22
    );

    vector<vector<int>> M6 = strassen(
        subtractMatrix(A21, A11),
        addMatrix(B11, B12)
    );

    vector<vector<int>> M7 = strassen(
        subtractMatrix(A12, A22),
        addMatrix(B21, B22)
    );

    vector<vector<int>> C11 = addMatrix(
        subtractMatrix(
            addMatrix(M1, M4),
            M5
        ),
        M7
    );

    vector<vector<int>> C12 = addMatrix(M3, M5);

    vector<vector<int>> C21 = addMatrix(M2, M4);

    vector<vector<int>> C22 = addMatrix(
        subtractMatrix(
            addMatrix(M1, M3),
            M2
        ),
        M6
    );

    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    return C;
}

int main() {
    int n;

    cout << "Enter matrix size (power of 2): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    cout << "Enter first matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter second matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    vector<vector<int>> C = strassen(A, B);

    cout << "\nResult Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";

        cout << endl;
    }

    return 0;
}