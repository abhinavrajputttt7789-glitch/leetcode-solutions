
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        unsigned long long maxWidth = 0;
        while(q.size()>0){
            unsigned long long currlevelsize=q.size();
            unsigned long long curridx=q.front().second;
            unsigned long long endidx=q.back().second;
            maxWidth = max(maxWidth,endidx-curridx+1);
            for(unsigned long long i=0;i<currlevelsize;i++)
            {
                auto curr=q.front();
                q.pop();
                if(curr.first->left)
                {
                    q.push({curr.first->left,curr.second*2+1});
                }
                if(curr.first->right)
                {
                    q.push({curr.first->right ,curr.second*2+2});
                }
            }
        }
        return maxWidth;
        
    }
};