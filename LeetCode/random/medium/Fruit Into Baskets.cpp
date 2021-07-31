#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int ans = 0;

        map<int, int> mp;
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            mp[fruits[j]]++;
            while (mp.size() > 2)
            {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0)
                {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};