class WordDictionary {
	struct node
	{
		char c;
		bool leaf;
		node *next[26];
		node()
		{
			leaf = false;
			for(int i = 0; i < 26; i++)
				next[i] = NULL;
		}
	};
	node *root;
	void insert(string &s)
	{
		node *p = root;
		for(int i = 0; i < s.length(); i++)
		{
			if(p->next[s[i] - 'a'] == NULL)
			{
				node *n = new node();
				n->c = s[i];
				p->next[s[i] - 'a'] = n;
			}
			if(i == s.length() - 1)
				(p->next[s[i] - 'a'])->leaf = true;
			p = p->next[s[i] - 'a'];
		}
	};
public:

    WordDictionary(){
        root = new node();
    };
	bool dfs(node *root, int pos, string &s){
		if(pos == s.length() - 1)
		{
			if(s[pos] == '.')
			{
			    for(int i = 0; i < 26; i++)
			        if(root->next[i] != NULL && root->next[i]->leaf)
			            return true;
				return false;
			}
			return (root->next[s[pos] - 'a'] != NULL && root->next[s[pos] - 'a']->leaf == true);
		}
		if(s[pos] == '.')
		{
			for(int i = 0; i < 26; i++)
				if(root->next[i] != NULL && dfs(root->next[i], pos + 1, s))
					return true;
			return false;
		}
		else
		{
			if(root->next[s[pos] - 'a'] == NULL)
				return false;
			else dfs(root->next[s[pos] - 'a'], pos+1, s);
		}
	}
    // Adds a word into the data structure.
    void addWord(string word) {
    	insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(root, 0, word);
    }
};