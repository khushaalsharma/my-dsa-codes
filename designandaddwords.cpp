// Time Complexity : O(N * word.size()), all words can be of the same size thus will need a traversal of vector once.
// Space Complexity : O(N), N number of words are stored.

//211. Design Add and Search Words Data Structure
class WordDictionary {
public:
    
    WordDictionary *child[26] = {};
    bool isWord = false;
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        WordDictionary *root = this;
        for(char &x : word) {
            int ind = x-'a';
			// check if the child already exists, create if not
            if(!root->child[ind]) root->child[ind] =  new WordDictionary();
            root = root->child[ind];
        }
        root->isWord = true;
    }
    
    bool search(string word) {
        return search(word, 0, this);
    }
    
	/* Start with index 0 and recursively check if the string matches with our existing WordDictionary
	Conditional validations for each index include,
	- If the index contains a character which is not "." -> then check if the character exists as child of root & proceed to the next index
	- If the index contains "." -> recursively call the search function for all the available 26 childs and proceed with the next index
	- Termination Condition : When we complete all the characters of the given word (index == word.length()), check if the root is a valid word here (using root->isWord) and return accordingly. */
	
    bool search(string &word, int ind, WordDictionary *root) {
        if(ind==word.length()) return root->isWord;
        char x = word[ind];
        if(x!='.') {
            return root->child[x-'a'] && search(word, ind+1, root->child[x-'a']);
        }
        else {
            for(int i=0;i<26;i++) {
                if(root->child[i] && search(word, ind+1, root->child[i])) return true;
            }
            return false;
        }
        return root->isWord;
    }
};
