#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (m.find(k - nums[i]) != m.end())
            {
                if (m[k - nums[i]] == 0)
                {
                    m.erase(k - nums[i]);
                }
                else
                {
                    cnt++;
                    m[k - nums[i]]--;
                    if (m[k - nums[i]] == 0)
                    {
                        m.erase(k - nums[i]);
                    }
                    m[nums[i]]--;
                }
            }
            m[nums[i]]++;
        }
        return cnt;
    }
};