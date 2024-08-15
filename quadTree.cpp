/*
https://massivealgorithms.blogspot.com/2019/04/leetcode-427-construct-quad-tree.html
*/


Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
    Node* build(vector<vector<int>>& grid, int x, int y, int len) {
        if (len <= 0) return NULL;
        for (int i = x; i < x + len; ++i) {
            for (int j = y; j < y + len; ++j) {
                if (grid[i][j] != grid[x][y]) {
                    return new Node(true, false,
                           build(grid, x, y, len / 2),
                           build(grid, x, y + len / 2, len / 2),
                           build(grid, x + len/ 2, y, len / 2),
                           build(grid, x + len / 2, y + len / 2, len / 2));
                }
            }
        }
        return new Node(grid[x][y] == 1, true, NULL, NULL, NULL, NULL);
    }
