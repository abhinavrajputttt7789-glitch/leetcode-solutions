class Trie
{
public:
    class Node
    {
    public:
        Node* child[26];
        bool end;
        Node()
        {
            end = false;
            for(int i = 0; i < 26; i++)
            {
                child[i] = NULL;
            }
        }
    };

    Node* root;

    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node* temp = root;
        for(char ch : word)
        {
            int index = ch - 'a';

            if(temp->child[index] == NULL)
            {
                temp->child[index] = new Node();
            }
            temp = temp->child[index];
        }
        temp->end = true;
    }

    bool search(string word)
    {
        return searchHelper(root, word, 0);
    }

    bool searchHelper(Node* temp, string& word, int pos)
    {
        if(pos == word.size())
        {
            return temp->end;
        }

        char ch = word[pos];
        if(ch != '.')
        {
            int index = ch - 'a';

            if(temp->child[index] == NULL)
            {
                return false;
            }

            return searchHelper(temp->child[index], word, pos + 1);
        }
        for(int i = 0; i < 26; i++)
        {
            if(temp->child[i] != NULL)
            {
                if(searchHelper(temp->child[i], word, pos + 1))
                {
                    return true;
                }
            }
        }

        return false;
    }
};


class WordDictionary
{
public:
    Trie t;

    WordDictionary()
    {
    }

    void addWord(string word)
    {
        t.insert(word);
    }

    bool search(string word)
    {
        return t.search(word);
    }
};