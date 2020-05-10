#include <iostream>
#include <vector>

bool HasPathCore(const std::vector<std::vector<char>>& matrix, const std::string& str,
                 int rows, int cols, int row, int col, int& path_len, std::vector<bool>& visited) {
    if (path_len == str.length()) return true;
    bool has_path = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols &&
        matrix[row][col] == str[path_len] && !visited[row * cols + col]) {
        ++path_len;
        visited[row * cols + col] = true;
        has_path = HasPathCore(matrix, str, rows, cols, row, col - 1, path_len, visited) ||
            HasPathCore(matrix, str, rows, cols, row - 1, col, path_len, visited) ||
            HasPathCore(matrix, str, rows, cols, row, col + 1, path_len, visited) ||
            HasPathCore(matrix, str, rows, cols, row + 1, col, path_len, visited);
        if (!has_path) {
            --path_len;
            visited[row * cols + col] = false;
        } else std::cout << matrix[row][col];
    }
    return has_path;
}

bool HasPath(const std::vector<std::vector<char>>& matrix, const std::string& str) {
    if (matrix.size() == 0 || matrix[0].size() == 0 || str.length() == 0) return false;

    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<bool> visited(rows * cols);
    int path_len = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (HasPathCore(matrix, str, rows, cols, i, j, path_len, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    std::vector<std::vector<char>> matrix = {
        {'a', 'b', 't', 'g'},
        {'c', 'f', 'c', 's'},
        {'j', 'd', 'e', 'h'}
    };
    bool has_path = HasPath(matrix, "bfce");
    std::cout << std::endl << has_path << std::endl;
}
