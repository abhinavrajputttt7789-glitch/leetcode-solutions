class Solution {
public:
    class Node {
    public:
        Node* child[2];
        Node()
        {
            child[0] = NULL;
            child[1] = NULL;
        }
    };

    Node* root = new Node();

    void insert(int num)
    {
        Node* temp = root;
        for(int i = 30; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if(temp->child[bit] == NULL)
            {
                temp->child[bit] = new Node();
            }

            temp = temp->child[bit];
        }
    }

    int getMaxXOR(int num)
    {
        Node* temp = root;
        int ans = 0;

        for(int i = 30; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;

            if(temp->child[opposite] != NULL)
            {
                ans |= (1 << i);
                temp = temp->child[opposite];
            }
            else
            {
                temp = temp->child[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums)
    {

        for(int num : nums)
        {
            insert(num);
        }

        int ans = 0;

        for(int num : nums)
        {
            ans = max(ans, getMaxXOR(num));
        }

        return ans;
    }
};