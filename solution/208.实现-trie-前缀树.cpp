// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include "commoncppproblem208.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie
{
    vector<Trie *> children;
    bool isEnd;

private:
    Trie *searchPrefix(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    /** Initialize your data structure here. */
    Trie() : children(26), isEnd(false)
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *pre = this->searchPrefix(word);
        return pre != nullptr && pre->isEnd == true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
