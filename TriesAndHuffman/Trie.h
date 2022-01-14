#include "TrieNode.h"
#include <string>
using namespace std;
class Trie {
    TrieNode *root;

   public:
    Trie() { 
        root = new TrieNode('\0'); 
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word) { 
        insertWord(root, word); 
    }
	bool search(TrieNode *root,string word)
    {
        if (word.size() == 0)
        {
            if (root->isTerminal == true)
                return true;
            return false;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        
        if (root->children[index] == nullptr)
            return false;
        
        child = root->children[index];
        
        return search(child,word.substr(1));
    }
    bool search(string word) {
        // Write your code here
        return search(root,word);
    }
    void remove(TrieNode *root,string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        TrieNode *child;
        int index = word[0] - 'a';

        if (root->children[index] == nullptr)
            return;
        child = root->children[index];
        remove(child,word.substr(1));

        if (child->isTerminal == false)
        {
            for (int i{0}; i<26; i++)
            {
                if (child->children[i] != nullptr)
                    return;
            }
            delete child;
            root->children[index] = nullptr;
        }
    }
    void remove(string word)
    {
        remove(root,word);
    }
};