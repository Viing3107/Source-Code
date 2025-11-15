#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUpper(char c) {
        return c >= 'A' && c <= 'Z';
    }

    bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }

    bool isPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (isUpper(s[i])) s[i] = s[i] + 32;
            else if (!isAlphanumeric(s[i])) {
                s.erase(s.begin() + i);
                i--;
            }
        }
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
            if (s[l] != s[r]) return false;
        }
        return true;
    }
};

// https://leetcode.com/problems/valid-palindrome/