#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int maxSuf = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--) {
            res = max(res, maxSuf - prices[i]);
            maxSuf = max(maxSuf, prices[i]);
        }
        return res;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/