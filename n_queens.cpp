#include <iostream>
#include <vector>
#include <string>

class NQueensSolver {
private:
    int n;
    int solutionCount;

    std::vector<bool> cols;
    std::vector<bool> mainDiag;
    std::vector<bool> antiDiag;
    std::vector<std::string> board;

    void printBoard() {
        std::cout << "Solution #" << solutionCount << ":\n";

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }

        std::cout << "\n";
    }

    void solve(int row) {
        // All queens have been placed
        if (row == n) {
            solutionCount++;
            printBoard();
            return;
        }

        // Try placing a queen in every column
        for (int col = 0; col < n; ++col) {

            int mdIdx = row - col + (n - 1);
            int adIdx = row + col;

            // Check if position is safe
            if (!cols[col] &&
                !mainDiag[mdIdx] &&
                !antiDiag[adIdx]) {

                // Place queen
                board[row][col] = 'Q';

                cols[col] = true;
                mainDiag[mdIdx] = true;
                antiDiag[adIdx] = true;

                // Move to next row
                solve(row + 1);

                // Backtrack
                board[row][col] = '.';

                cols[col] = false;
                mainDiag[mdIdx] = false;
                antiDiag[adIdx] = false;
            }
        }
    }

public:
    NQueensSolver(int size) : n(size), solutionCount(0) {
        cols.assign(n, false);
        mainDiag.assign(2 * n - 1, false);
        antiDiag.assign(2 * n - 1, false);
        board.assign(n, std::string(n, '.'));
    }

    void findSolutions() {
        solve(0);

        std::cout << "Total solutions found: "
                  << solutionCount << "\n";
    }
};

int main() {
    int n = 4;  // Modify this value for different board sizes

    std::cout << "Starting N-Queens Solver for N = "
              << n << "\n\n";

    NQueensSolver solver(n);
    solver.findSolutions();

    return 0;
}