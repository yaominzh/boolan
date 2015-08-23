#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > Matrix;

size_t dfs(const Matrix& mat, int i, int j, Matrix& visited) {
    // 检测下标是否在合理的范围内
    if (0 <= i && i < mat.size() && 0 <= j && j < mat[0].size()) {
        // 如果当前元素为 1 且未访问过，则递归地访问上下左右相邻的元素
        if (mat[i][j] && !visited[i][j]) {
            visited[i][j] = true;
            dfs(mat, i - 1, j, visited);
            dfs(mat, i + 1, j, visited);
            dfs(mat, i, j - 1, visited);
            dfs(mat, i, j + 1, visited);
            // 返回 true 表示新开始了一个连通分量
            return true;
        }
    }
    return false;
}

size_t connected_components(const Matrix& mat) {
    // 把辅助矩阵 visited 的元素全部初始化为 0，表示所有结点都还没有访问过
    Matrix visited(mat.size(), vector<int>(mat[0].size(), 0));
    size_t count = 0;
    for (int i = 0; i < mat.size(); ++i)
        for (int j = 0; j < mat[0].size(); ++j)
            if (dfs(mat, i, j, visited))
                ++count;
    return count;
}

int main() {
    // 输入数据第一行有两个正整数，表示矩阵的行数和列数
    size_t rows, columns;
    cin >> rows >> columns;

    // 之后的每一行都是矩阵的元素
    Matrix mat(rows, vector<int>(columns, 0));
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < columns; ++j)
            cin >> mat[i][j];

    // 输出连通分量的个数
    cout << connected_components(mat) << endl;
    return 0;
}