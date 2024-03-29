#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> tree1;
        vector<int> tree2;
        stack<TreeNode *> st;
        TreeNode *curr = root1;
        while (!st.empty() || curr != NULL)
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            tree1.push_back(curr->val);
            curr = curr->right;
        }
        curr = root2;
        while (!st.empty() || curr != NULL)
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            tree2.push_back(curr->val);
            curr = curr->right;
        }
        int ptr1 = 0;
        int ptr2 = 0;
        vector<int> result;
        while (ptr1 != tree1.size() && ptr2 != tree2.size())
        {
            if (tree1[ptr1] <= tree2[ptr2])
            {
                result.push_back(tree1[ptr1]);
                ptr1++;
            }
            else
            {
                result.push_back(tree2[ptr2]);
                ptr2++;
            }
        }
        while (ptr1 != tree1.size())
        {
            result.push_back(tree1[ptr1]);
            ptr1++;
        }
        while (ptr2 != tree2.size())
        {
            result.push_back(tree2[ptr2]);
            ptr2++;
        }
        return result;
    }
};

//Single Pass soln
class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> result;
        stack<TreeNode *> st1, st2;

        TreeNode *curr = root1;
        while (curr != NULL)
        {
            st1.push(curr);
            curr = curr->left;
        }

        curr = root2;
        while (curr != NULL)
        {
            st2.push(curr);
            curr = curr->left;
        }

        while (!st1.empty() || !st2.empty())
        {
            stack<TreeNode *> &currStack = (st1.empty() ? st2 : (st2.empty() ? st1 : (st1.top()->val < st2.top()->val ? st1 : st2)));

            TreeNode *curr = currStack.top();
            result.push_back(curr->val);
            currStack.pop();

            curr = curr->right;
            while (curr != NULL)
            {
                currStack.push(curr);
                curr = curr->left;
            }
        }

        return result;
    }
};