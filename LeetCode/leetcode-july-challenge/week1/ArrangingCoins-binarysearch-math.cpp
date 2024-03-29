#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        return (-1 + sqrt((long int)n * 8 + 1)) / 2;
    }
};

class Solution
{
public:
    int arrangeCoins(int n)
    {
        int left = 0;
        int right = n;
        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            long long curr = ((long long)(mid) * (mid + 1)) / 2;

            if (curr <= n)
            {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }
};