#include <iostream>
#include <vector>

void PrintMarixInCircle(const std::vector<std::vector<int>>& matrix, int columns, int rows, int start) {
    int end_x = columns - start - 1;
    int end_y = rows - start - 1;

    // from left to right
    for (int i = start; i <= end_x; ++i) {
	std::cout << matrix[start][i] << " ";
    }

    // from top to bottom
    if (start < end_y) {
	for (int i = start + 1; i <= end_y; ++i) {
	    std::cout << matrix[i][end_x] << " ";
	}
    }
 
    // from right to left
    if (start < end_x && start < end_y) {
	for (int i = end_x - 1; i >= start; --i) {
	    std::cout << matrix[end_y][i] << " ";
	}
    }
 
    // from bottom to top
    if (start < end_x && start < end_y - 1) {
	for (int i = end_y - 1; i >= start + 1; --i) {
	    std::cout << matrix[i][start] << " ";
	}
    }
}

void PrintMatrixClockwisely(const std::vector<std::vector<int>>& matrix) {
    const int rows = matrix.size();
    if (rows <= 0) return;
    const int columns = matrix[0].size();
    if (columns <= 0) return;

    std::cout << rows << ", " << columns << std::endl;

    int start = 0;
    while (columns > start * 2 && rows > start * 2) {
	PrintMarixInCircle(matrix, columns, rows, start++);
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> matrix = {
	{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12},
	// {13, 14, 15, 16}
    };
    PrintMatrixClockwisely(matrix);
    return 0;
}
