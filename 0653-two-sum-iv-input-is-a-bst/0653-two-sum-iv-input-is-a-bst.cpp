/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        findinorder(root,inorder);
        int n=inorder.size();
        int l=0,r=n-1;
        while(l<r){
            if (inorder[l]+inorder[r]==k){
                return true;
            }
            else if (inorder[l]+inorder[r]>k){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
    void findinorder(TreeNode* root, vector<int>&inorder){
        if (root==nullptr){
            return;
        }
        findinorder(root->left,inorder);
        inorder.push_back(root->val);
        findinorder(root->right,inorder);
    }
};
