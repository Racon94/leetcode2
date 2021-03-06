// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem37.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution
{
public:
    bool row[9][9];
    bool col[9][9];
    bool box[3][3][9];
    vector<pair<int, int>> spaces; // 记录空格位
    bool valid;

    void dfs(vector<vector<char>> &board, int pos)
    {
        if (pos == spaces.size())
        {
            valid = true;
            return;
        }
        auto [i, j] = spaces[pos];
        for (int digit = 0; digit < 9 && !valid; digit++)
        {
            if (!row[i][digit] && !col[j][digit] && !box[i / 3][j / 3][digit])
            {
                row[i][digit] = col[j][digit] = box[i / 3][j / 3][digit] = true;
                board[i][j] = digit + '0' + 1;
                dfs(board, pos + 1);
                row[i][digit] = col[j][digit] = box[i / 3][j / 3][digit] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(box, false, sizeof(box));
        valid = false;

        // 先填充三个辅助数组
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    spaces.emplace_back(i, j);
                }
                else
                {
                    int digit = board[i][j] - '0' - 1;
                    row[i][digit] = col[j][digit] = box[i / 3][j / 3][digit] = true;
                }
            }
        }

        dfs(board, 0);
    }
};
// @lc code=end
