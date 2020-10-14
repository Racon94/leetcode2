# LCP 19. 秋叶收藏集
小扣出去秋游，途中收集了一些红叶和黄叶，他利用这些叶子初步整理了一份秋叶收藏集 leaves， 字符串 leaves 仅包含小写字符 r 和 y， 其中字符 r 表示一片红叶，字符 y 表示一片黄叶。
出于美观整齐的考虑，小扣想要将收藏集中树叶的排列调整成「红、黄、红」三部分。每部分树叶数量可以不相等，但均需大于等于 1。每次调整操作，小扣可以将一片红叶替换成黄叶或者将一片黄叶替换成红叶。请问小扣最少需要多少次调整操作才能将秋叶收藏集调整完毕。

示例 1：

输入：leaves = "rrryyyrryyyrr"

输出：2

解释：调整两次，将中间的两片红叶替换成黄叶，得到 "rrryyyyyyyyrr"

示例 2：

输入：leaves = "ryr"

输出：0

解释：已符合要求，不需要额外操作

提示：

3 <= leaves.length <= 10^5
leaves 中只包含字符 'r' 和字符 'y'


# 用例
```
"rrryyyrryyyrr"
"ryr"
```

# 题解

## 动态规划

红黄红分为3个状态0,1,2。因为两个红色至少一个，以致有顺序要求，所以要分两个状态

设f[i][j]表示，当前第i片叶子调整为状态j时的最小移动次数

- 当j==0时，需要将i叶变为红色，而i-1也只能处于0
f[i][0] = f[i-1][0]+isYellow(i)
isYellow，当前是黄色时，返回1，红色返回0

- 当j==1时，需要将i叶变为黄色，而i-1可以是0，也可以是1
f[i][1]=min(f[i-1][0],f[i-1][1]) + isRed(i)
isYellow，当前是红色色时，返回1，黄色色返回0

- 当j==2时，需要将i叶变为红色，而i-1可以是1，也可以是2
f[i][2]=min(f[i-1][1],f[i-1][2]) + isYellow(i)

f[n-1][2]为所求

边界条件
f[0][0] = isYellow(0)


