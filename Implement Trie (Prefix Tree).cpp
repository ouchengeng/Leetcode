const int N = 26;
class TrieNode {
public:
	bool leaf;
    TrieNode *path[N];
    TrieNode() {
		leaf = false;
		for(int i = 0; i < 26; i++) 
			path[i] = NULL;
    }
	bool contains(char c) {
		if(path[c - 'a'] == NULL)
			return false;
		return true;
	}

	TrieNode* insert(char c) {
		path[c - 'a'] = new TrieNode();
		return path[c - 'a'];
	}

	TrieNode* findNext(char c) {
		return path[c - 'a'];
	}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
		TrieNode *r = root;
		for(int i = 0; i < s.length(); i++)
		{
			if(!r->contains(s[i]))
				r->insert(s[i]);
			r = r->findNext(s[i]);
		}
		r->leaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
		TrieNode *r = root;
		for(int i = 0; i < key.length(); i++)
		{
			if(!r->contains(key[i]))
				return false;
			r = r->findNext(key[i]);
		}
		return r->leaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *r = root;
		for(int i = 0; i < prefix.length(); i++)
		{
			if(!r->contains(prefix[i]))
				return false;
			r = r->findNext(prefix[i]);
		}
		return true;
    }
private:
    TrieNode* root;
};