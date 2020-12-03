// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem204.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
// 埃氏筛
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> primes(n, 0);
        int ans = 0;
        // primes[2] = 1;
        // primes[3] = 1;
        for (int i = 2; i * i < n; i++)
        {
            for (int j = i; i * j < n; j++)
            {
                primes[i*j] = 1;
            }
        }
        
        for(int i=2;i<n;i++){
            if(primes[i]==0) ans++;
        }
        return ans;
    }
};
// @lc code=end
