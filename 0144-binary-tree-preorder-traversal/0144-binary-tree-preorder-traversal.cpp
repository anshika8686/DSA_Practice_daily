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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        TreeNode* curr=root;
        vector<int>preorder;
    
        while(curr!=nullptr){
            if(curr->left==nullptr){
                preorder.push_back(curr->val);
                curr=curr->right;
            }else{ 
                //IF ROOT->LEFT !=NULL
                //TO FIND PREDECCESOR MOVE TO TO RIGHTMOST NODE OF LEFT SUBTREE
                //MOVE TO THE LEFT SUBTREE
                TreeNode* prev=curr->left;
                //prev->right!=curr it is already threaded => no use in going to that
                //MOVE TO TO RIGHTMOST NODE OF LEFT SUBTREE
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                //CREATE THREAD ->MOVE TO LEFT PART
                if(prev->right==nullptr){
                    prev->right=curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                }
                //REMOE THREAD->MOVE TO RIGHT
                else if (prev->right==curr){
                    prev->right=nullptr;
                    curr=curr->right;
                }
                }
            }
            return preorder;
        }
};