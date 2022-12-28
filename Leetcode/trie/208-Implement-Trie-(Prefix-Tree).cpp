/**
 * @problem: https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=study-plan&id=level-2
*/

class Node {
public:
    vector<Node*> a = vector<Node*>(26, nullptr);
    bool isEnd = false;
    char c;
};

class Trie {
public:
    Node *h;
    Trie() {
        h = new Node();
    }
    
    void insert(string word) {
        Node *t = h;
        for (auto c: word) {
            if (!t->a[c-'a']) {
                t->a[c-'a'] = new Node();
                t->a[c-'a']->c = c;
            }
            t = t->a[c-'a'];
        }
        t->isEnd = true;
        t = h;
        for (int i=0; i<26; ++i) {
            if (t->a[i]) {
                t = t->a[i];
                cout << i << " ";
                break;
            }    
        }
        cout << "\n";
    }
    
    bool search(string word) {
        int i=0;
        Node *t = h;
        while (i < word.size() && t) {
            t = t->a[word[i]-'a'];
            ++i;
        }
        return i == word.size() && t && t->isEnd;
    }
    
    bool startsWith(string prefix) {
        int i=0;
        Node *t = h;
        while (i < prefix.size() && t) {
            t = t->a[prefix[i]-'a'];
            ++i;
        }
        return i == prefix.size() && t;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */