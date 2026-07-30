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

 
 class Info{ // struct class
//  packet of information that every recursive call sends to its parent.
public:
        int maxVal;
        int minVal;
        int sum;
        bool isBST;

        Info(int mn, int mx, int sz, bool BST)
        {
            minVal=mn;
            maxVal=mx;
            sum=sz;
            isBST=BST;
        }
 };

class Solution {
public:
     //LARGEST=>INT_MIN
     //SMALLEST=>INT_MAX
     //LEFT_SUBTREE-> FIND LARGEST AND RIGHT_SUBTREE->SMALLEST
    //  MAX OF LEFT SUBTREE<ROOT<MIN OF RIGHT SUBTREE
    //  INT_MIN<ROOT<INT_MAX

    int maxSum = 0;

    Info solve(TreeNode* root){
        //INFO IS AN RETURN TYPE WHICH WILL WILL RETURN OBJ CONTAINING FOUR VALUES

        if(root==nullptr){
            return Info(INT_MAX,INT_MIN,0,true);
        }

        //BOTTOM UP RECURSION->POST ORDER TRAVERSAL
        Info left=solve(root->left); //left is an object of the INFO class
        Info right=solve(root->right);


        //left. ->i can access the members of left object
        if(left.isBST && right.isBST && left.maxVal<root->val && root->val<right.minVal){
            int curr_sum=right.sum+left.sum+root->val;
            maxSum=max(maxSum,curr_sum);

            return Info(min(root->val,left.minVal), max(root->val, right.maxVal), curr_sum,true);
        }


        return Info(INT_MIN,INT_MAX, max(left.sum,right.sum),false);
        //this is not bst , hence we are trying to make condition false
        //INT_MAX<ROOT<INT_MIN
    }

    int maxSumBST(TreeNode* root) {
         maxSum=0;
         solve(root);
         return maxSum;     
    }

};