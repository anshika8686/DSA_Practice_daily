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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,long long>>q; //node,index
        long long maxWidth=0;
        long long first_index, last_index;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long minIndex=q.front().second;
            for(int i=0;i<size;i++)
            {
            TreeNode* node=q.front().first;
            long long index=q.front().second;
            q.pop();

             index=index-minIndex;

            if(i==0){
                first_index=index;
            }
            if(i==size-1){
                last_index=index;
            }
            if(node->left){
                q.push({node->left,2*index+1});
            }
            if(node->right){
                q.push({node->right,2*index+2});
            }
        }
        maxWidth=max(maxWidth,last_index-first_index+1);    
    }
    return (int)maxWidth;
    }
};