class Trie
{
public:
    class Node //class node 
    {
    public:
        Node* child[26]; //store 26 alphabets 
        bool end; ///flag 

        Node() //constructor 
        {
            end = false; //sbhi ed ko false krra h 

            for(int i = 0; i < 26; i++)
            {
                child[i] = NULL; //sb nodes ko null krdia 
            }
        }
    };

    Node* root; 

    Trie()
    {
        root = new Node(); //new node bnaya 
    }

    void insert(string word)
    {
        Node* temp = root; //temp bnaya use root pe likha 

        for(char ch : word)
        {
            int index = ch - 'a'; //ye index deta h us word ka 

            if(temp->child[index] == NULL) // agar wo null ni h to 
            {
                temp->child[index] = new Node(); //agar null h to new node bnado 
            }

            temp = temp->child[index]; //fir temp ko temp ke next pe lejao 
        }

        temp->end = true; //flag true krdo  
    }

    bool search(string word)
    {
        Node* temp = root; // temp banay 

        for(char ch : word)
        {
            int index = ch - 'a';

            if(temp->child[index] == NULL)
            {
                return false;
            }

            temp = temp->child[index];
        }

        return temp->end;
    }

    bool startsWith(string prefix)
    {
        Node* temp = root;

        for(char ch : prefix)
        {
            int index = ch - 'a';

            if(temp->child[index] == NULL)
            {
                return false;
            }

            temp = temp->child[index];
        }

        return true;
    }
};