
class Solution {
public:
    TreeNode* Prev = NULL;
    TreeNode* First = NULL;
    TreeNode* Second = NULL;
    void inorder(TreeNode* root)
    {
        if (root == NULL)
        {
            return ;
        }
        inorder(root->left);
        if(Prev!=NULL && root->val<Prev->val)
        {
            if (!First)
            {
                First = Prev ;
            }
            Second=root;
        }
        Prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp=First->val;
        First->val=Second->val;
        Second->val=temp;
    }
};