#ifndef WORDTREE_H
#define WORDTREE_H

#include <iostream> 
#include <string> 

typedef std::string WordType;

struct WordNode {
    WordNode(WordType v) {
        m_data = v;
        num_word = 1;
        m_left = nullptr;
        m_right = nullptr;
    }
    WordType m_data;
    int num_word;
    WordNode* m_left;
    WordNode* m_right;
    // You may add additional data members and a constructor  
    // in WordNode 
};

class WordTree {
private:
    WordNode* root;

    WordNode* CopyHelper(WordNode* &copy, WordNode* cur);
    int distinctHelper(WordNode* cur) const;
    int totalHelper(WordNode* cur) const;
    void printHelper(WordNode* cur, std::ostream& out) const;
    void DeconHelper(WordNode* cur);
public:
    // default constructor             
    WordTree() : root(nullptr) {};

    // copy constructor 
    WordTree(const WordTree& rhs);

    // assignment operator 
    const WordTree& operator=(const WordTree& rhs);

    // Inserts v into the WordTree     
    void add(WordType v);

    // Returns the number of distinct words / nodes    
    int distinctWords() const;

    // Returns the total number of words inserted, including  
    // duplicate values     
    int totalWords() const;

    // Prints the WordTree  
    friend std::ostream& operator<<(std::ostream& out, const
        WordTree& rhs);

    // Destroys all the dynamically allocated memory in the 
    // tree 
    ~WordTree();
};

#endif
