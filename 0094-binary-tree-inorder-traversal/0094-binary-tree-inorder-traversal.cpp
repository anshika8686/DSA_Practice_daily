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
    vector<int> inorderTraversal(TreeNode* root) {
        //CONCEPT OF NODE=NULL->MEANS LEFT PART IS NULL SO MOVE TO THE ROOT PART AND THEN RIGHT
        //CONCEPT OF NODE!=NULL->MEANS LEFT PART IS NOT NULL HENCE MOVE TO THE LEFT PART UNTIL IT BECOMES NULL AND THEN WE MOVE TO THE FIRST CASE
        //tc=o(n) sc=o(1)
        vector<int>inorder;
        if(root==nullptr)
        return inorder;
        stack<TreeNode*>st;
        TreeNode* node=root;
      
        while(true){
            if(node!=nullptr){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
            }
        }
        return inorder;
        
        
    }
};