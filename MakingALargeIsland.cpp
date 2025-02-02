/*
The solution involves the following steps:

Label Islands:

Traverse the grid and assign a unique label to each island using a flood-fill approach.
Store the size of each island in a map for quick lookup.
Evaluate Flipping Each 0:

For each 0 in the grid, check its 4-directional neighbors.
If a neighbor is part of an island, add the size of that island to the total.
Use a set to ensure that the same island is not counted multiple times.
Track Maximum Island Size:

Keep track of the maximum island size obtained after flipping each 0.
Handle Edge Cases:

If there are no 0s, return the size of the largest existing island.
If there are no 1s, return 1 (since flipping one 0 will create an island of size 1).

TC: O(n^2)
SC: O(n^2)

*/


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;

        int n = grid.size();
        vector<vector<int>> labels(n,vector<int>(n, 0));
        unordered_map<int, int> islandSizes;
        int label = 1;
        int maxSize = 0;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && labels[i][j] == 0) {
                    int size = 0;
                    vector<pair<int, int>> stack;
                    stack.push_back({i, j});
                    labels[i][j] = label;

                    while (!stack.empty()) {
                        auto [x, y] = stack.back();
                        stack.pop_back();
                        size++;

                        for (auto [dx, dy] : dirs) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                                grid[nx][ny] == 1 && labels[nx][ny] == 0) {
                                labels[nx][ny] = label;
                                stack.push_back({nx, ny});
                            }
                        }
                    }

                    islandSizes[label] = size;
                    maxSize = max(maxSize, size);
                    label++;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighborLabels;
                    int total = 1;

                    for (auto [dx, dy] : dirs) {
                        int nx = i + dx, ny = j + dy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                            grid[nx][ny] == 1) {
                            neighborLabels.insert(labels[nx][ny]);
                        }
                    }

                    for (int lbl : neighborLabels) {
                        total += islandSizes[lbl];
                    }

                    maxSize = max(maxSize, total);
                }
            }
        }

        return maxSize;
    }
};
