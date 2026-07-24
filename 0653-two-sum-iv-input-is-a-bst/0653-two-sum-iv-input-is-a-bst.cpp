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

class BSTIterator{
    // reverse->true= before
    // reverse->false=next
    stack<TreeNode*>st;
    bool reverse=false;
    public:
    BSTIterator(TreeNode* root,int isreverse){
        reverse=isreverse;
        pushAll(root,reverse);
    }
    void pushAll(TreeNode* root,bool reverse){
        while(root!=nullptr){
            st.push(root);
            root=reverse?root->right:root->left;
            //reverse=>true->(root->right) BEFORE
            //reverse=>false->(root->left) NEXT
        }
    }
    int next(){
        TreeNode* topnode=st.top();
        st.pop();
        if (reverse && topnode->left){
            pushAll(topnode->left,reverse); 
        } 
        else if(!reverse && topnode->right){
            pushAll(topnode->right,reverse);
        }
        return topnode->val;
    }
};

class Solution {
public:

    bool findTarget(TreeNode* root, int k) {
        if(!root)
        return false;
//creating object
BSTIterator l(root,false); //obj objname(parameters)
BSTIterator r(root,true);

int i=l.next();
int j=r.next();

while(i<j){
if(i+j==k) return true;
else if (i+j>k) j=r.next();
else i=l.next();
}
return false;   
    }
};