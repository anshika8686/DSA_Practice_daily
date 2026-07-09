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
//ITERATIVE USING STACK
// TC O(N) SC=O(N)
    void flatten(TreeNode* root) {
        stack<TreeNode*>st;
       
        if(root!=nullptr){
        st.push(root);
        }
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            //I need to access left one node first
            if(node->right){
                 st.push(node->right);
            }
            if(node->left){
                 st.push(node->left);
            }
            if(!st.empty()){
            node->right=st.top();
            }
            else{
            node->right=nullptr;
            }
         node->left=nullptr;
        }    
    }
};