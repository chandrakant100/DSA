#include <bits/stdc++.h>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
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
    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        string word;
        int i{0};
        for (auto x:words)
        {
            i = 0;
            word = x;
            while(x.size() != 0)
            {
                add(x);
                add(word.substr(0,i));
                x = x.substr(1);
                i++;
            }
        }
        for (auto x:words)
        {
            string y = x;
            reverse(y.begin(),y.end());
            if (search(y) == true)
                return true;
        }
        return false;
    }
};
int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}