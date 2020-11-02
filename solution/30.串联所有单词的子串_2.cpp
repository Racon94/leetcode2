// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem30.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
// 优化2
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        int m = s.size();
        if (m == 0)
            return res;
        int wc = words.size();
        if (wc == 0)
            return res;
        int wl = words[0].size();
        int tl = wc * wl;
        if (tl == 0)
        {
            for (int i = 0; i <= m; i++)
                res.emplace_back(i);
            return res;
        }
        unordered_map<string, int> hm1;
        unordered_map<string, int> hm2;
        vector<string> vc1;
        int flag = 0;
        int sc = 0;
        for (auto &it : words)
        {
            hm1[it]++;
        }
        for (int k = 0; k < wl; k++)
        {
            vc1.clear();
            hm2.clear();
            sc = (m - k) / wl;
            int i = 0;
            int last = 0;
            for (int j = 0; j < sc; j++)
            {
                vc1.emplace_back(s.substr(k + j * wl, wl));
            }
            while (last <= sc - wc)
            {
                int i = last + wc - 1;
                flag = 0;
                while (i >= last)
                {
                    if (hm1.find(vc1[i]) == hm1.end())
                    {
                        break;
                    }
                    i--;
                }
                if (last - 1 == i)
                {
                    // hm数单词
                    for (int j = i + 1; j <= last + wc - 1; j++)
                    {
                        hm2[vc1[j]]++;
                    }
                    // 比较
                    for (const auto &it : hm1)
                    {
                        if (it.second != hm2[it.first])
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                    {
                        res.emplace_back(k + last * wl);
                    }
                    hm2[vc1[last]]--;
                    last++;
                }
                else
                {
                    for (int j = last; j <= i + 1; j++)
                    {
                        hm2[vc1[j]]--;
                    }
                    last = i + 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
