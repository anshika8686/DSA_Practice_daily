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
        queue<pair<TreeNode*,int>>q;
        unsigned long long start,last;
        int max_width=INT_MIN;
        //starting with 1
        q.push({root,1});//node,current_index
        while(!q.empty()){
            int size=q.size();
            unsigned long long min_index=q.front().second;// access min indexof every level

            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                unsigned long long index=q.front().second;
                unsigned long long curr_index=index-min_index;
                q.pop();
                
                if(i==0) start=curr_index;
                if(i==size-1) last=curr_index;

                if(node->left)
                q.push({node->left,2*curr_index+1});

                if(node->right)
                q.push({node->right,2*curr_index+2});
            }
            max_width=max(max_width,(int)(last-start+1));
        }
        return max_width;
        
    }
};