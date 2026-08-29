
class Solution {
public:
    bool isIden(TreeNode* p, TreeNode*q)
    {
        if (p==NULL || q== NULL){
            return p==q;
        }
        bool isleft=isIden(p->left,q->left);
        bool isright=isIden(p->right,q->right);
        return isleft && isright && p->val==q->val;
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL || subRoot==NULL)
        {
            return root==subRoot;
        }
        if(root->val == subRoot->val && isIden(root,subRoot))
        {
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    
};