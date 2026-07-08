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
//USING MORRIS TRAVERSAL
    vector<int> inorderTraversal(TreeNode* root) 
    {
        TreeNode* curr=root;
        vector<int>inorder;
       
        while(curr!=nullptr){
            //CASE1- WHEN LEFT PART IS NULL , WE MOVE TO RIGHT
            if(curr->left==nullptr){
            inorder.push_back(curr->val);
            curr=curr->right;
            }else{
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            //CREATE A THREAD
            if(prev->right==nullptr){
                prev->right=curr;
                curr=curr->left;

            //REMOVE THE THREAD
            }else if(prev->right==curr){
                prev->right=nullptr; 
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            }
        }
        return inorder;
        
    }
};