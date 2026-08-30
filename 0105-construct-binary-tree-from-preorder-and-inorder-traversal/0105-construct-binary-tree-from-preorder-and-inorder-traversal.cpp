
class Solution {
public:
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int& preIndex,int inStart,int inEnd)
    {
        if(inStart>inEnd)
        {
            return NULL;
        }
        int rootValue=preorder[preIndex++];
        TreeNode* root=new TreeNode(rootValue);
        int index = inStart;
        while (inorder[index] != rootValue)
        {
            index++;
        }
        root->left = build(preorder, inorder,preIndex, inStart, index - 1);
        root->right = build(preorder, inorder,preIndex, index + 1, inEnd);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int preIndex=0;    
        return build (preorder,inorder,preIndex,0,inorder.size()-1);
    }
};