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
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

    void recoverTree(TreeNode* root) 
    {
        first=middle=last=nullptr;
         prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
    void inorder(TreeNode* root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        if(prev!=nullptr && prev->val>root->val){
            if(first==nullptr){ // it is the first violation
            first=prev;
            middle=root;
        }
        else{
            last=root;
        }
    }
    prev=root;
    inorder(root->right);
    }
};