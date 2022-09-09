#include "WordTree.h"
#include <iostream>
#include <string>

WordNode* WordTree::CopyHelper(WordNode* &copy, WordNode* cur)
{
	if (cur == nullptr)
	{
		return nullptr;
	}
	copy = new WordNode(cur->m_data);
	copy->num_word = cur->num_word;
	copy->m_left = CopyHelper(copy->m_left, cur->m_left);
	copy->m_right = CopyHelper(copy->m_right, cur->m_right);
	return copy;
}

// copy constructor 
WordTree::WordTree(const WordTree& rhs)
{
	this->root = nullptr;
	CopyHelper(this->root, rhs.root);
}

// assignment operator 
const WordTree& WordTree::operator=(const WordTree& rhs)
{
	if (&rhs == this)
		return rhs;
	DeconHelper(this->root);
	this->root = nullptr;
	CopyHelper(this->root, rhs.root);
	return *this;
}

// Inserts v into the WordTree     
void WordTree::add(WordType v)
{
	if (root == nullptr)
	{
		root = new WordNode(v);
		return;
	}

	WordNode* cur = root;
	for (;;)
	{
		if (v == cur->m_data)
		{
			cur->num_word++;
			return;
		}
		if (v < cur->m_data)
		{
			if (cur->m_left != nullptr)
				cur = cur->m_left;
			else
			{
				cur->m_left = new WordNode(v);
				return;
			}
		}
		else if (v > cur->m_data)
		{
			if (cur->m_right != nullptr)
				cur = cur->m_right;
			else
			{
				cur->m_right = new WordNode(v);
				return;
			}
		}
	}
}

int WordTree::distinctHelper(WordNode* cur) const
{
	if (cur == nullptr)
		return 0;
	return 1+ distinctHelper(cur->m_left) + distinctHelper(cur->m_right);
}

// Returns the number of distinct words / nodes    
int WordTree::distinctWords() const
{
	return distinctHelper(root);
}

int WordTree::totalHelper(WordNode* cur) const
{
		if (cur == nullptr)
			return 0;
		return cur->num_word + totalHelper(cur->m_left) + totalHelper(cur->m_right);
}

// Returns the total number of words inserted, including  
// duplicate values     
int WordTree::totalWords() const
{
	return totalHelper(root);
}

void WordTree::printHelper(WordNode* cur, std::ostream& out) const
{
	if (cur == nullptr)
		return;
	printHelper(cur->m_left, out);
	out << cur->m_data << " " << cur->num_word << std::endl;
	printHelper(cur->m_right, out);
}

// Prints the WordTree  
std::ostream& operator<<(std::ostream& out, const WordTree& rhs)
{
	rhs.printHelper(rhs.root, out);
	return out;
}

void WordTree::DeconHelper(WordNode* cur)
{
	if (cur == nullptr)
	{
		return;
	}
	DeconHelper(cur->m_left);
	DeconHelper(cur->m_right);
	delete cur;
}

// Destroys all the dynamically allocated memory in the 
// tree 
WordTree::~WordTree()
{
	DeconHelper(root);
}