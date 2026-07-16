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

    TreeNode* findMin(TreeNode* root){
        while(root->left!=nullptr){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //LOCATE THE KEY VALUE
        if(root==nullptr)
        return nullptr;

        if(root->val>key){
        root->left=deleteNode(root->left,key);
        }
        else if (root->val<key){
        root->right=deleteNode(root->right,key);
        }
        else{
            //IF LOCATED 
            //WITH A SINGLE CHILD
            if(root->left==nullptr){
                TreeNode* temp=root->right;
                delete(root);
                return temp;
            }
            else if(root->right==nullptr){
                TreeNode* temp=root->left;
                delete(root);
                return temp;
            }
            else{
                //RIGHT SUBTREE WITH MIN VLALUE
                TreeNode* successor=findMin(root->right);
                root->val=successor->val;
                root->right=deleteNode(root->right,successor->val);

            }
        }
        return root;
        
    }
};