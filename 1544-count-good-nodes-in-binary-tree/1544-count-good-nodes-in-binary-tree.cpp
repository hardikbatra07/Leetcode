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
    int func(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        int f1=0,f2=0;
        if(root->left!=NULL){if(root->left->val<maxi) f1=func(root->left,maxi);
        else  f1=1+func(root->left,root->left->val);}
        if(root->right!=NULL){if(root->right->val<maxi) f2=func(root->right,maxi);
        else f2=1+func(root->right,root->right->val);}
        return f1+f2;
    }
public:
    int goodNodes(TreeNode* root) {
      return 1+func(root,root->val);
    }
};