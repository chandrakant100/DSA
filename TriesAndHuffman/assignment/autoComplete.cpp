#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
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

    bool insertWord(TrieNode *root, string word) {
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
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    vector<string> getall(TrieNode* root){
        vector<string> ans;
        if(root->isTerminal){
            string k;
            k+=root->data;
            ans.push_back(k);
        }
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                vector<string> smallans=getall(root->children[i]);
                for(int i=0;i<smallans.size();i++){
                    ans.push_back(root->data+smallans.at(i));
                }
            }
        }
        return ans;
    }
    void print(TrieNode* root,string pattern,string ans){
        if(root->isTerminal){
            cout<<pattern+ans+root->data<<endl;
        }
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                print(root->children[i],pattern,ans+root->data);
            }
        }
    }
    TrieNode* find(TrieNode* root,string pattern){
        if(pattern.size()==0){
            return root;
        }
        int ci=pattern[0]-'a';
        if(root->children[ci]!=NULL){
            return find(root->children[ci],pattern.substr(1));
            
        }else{
            return NULL;
        }
    }

    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        for(int i=0;i<input.size();i++){
            insertWord(input.at(i));
        }
        TrieNode* ans=find(root,pattern);
        if(ans!=NULL){
            string k;
            if(ans->isTerminal){
                cout<<pattern<<endl;
            }
            for(int i=0;i<26;i++){
                if(ans->children[i]!=NULL){
                    print(ans->children[i],pattern,k);
                }
            }   
        }
    }
};
int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}