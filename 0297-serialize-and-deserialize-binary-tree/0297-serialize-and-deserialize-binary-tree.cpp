/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string ans ="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL){
                ans+="null,";
            }
            else{
                ans+=to_string(node->val)+",";

                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return NULL;
        }
        stringstream ss(data);
        string val;
        getline(ss,val,',');
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if (getline(ss, val, ',')) {
            if (val != "null") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
        }
        if (getline(ss, val, ',')) {
            if (val != "null") {

                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
    }

    return root;
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));