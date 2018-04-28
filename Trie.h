#pragma once

struct Node
{
	char key;
	std::vector<Node*> kids;
	bool isWordEnd = false;
	Node()
	{}
	Node(char key, bool isWordEnd) :key(key)
	{
		if (this->isWordEnd == false)
		{
			this->isWordEnd = isWordEnd;
		}
		else
		{

		}
	}
	~Node(){}
	void makeTrue()
	{
		isWordEnd = true;
	}
	bool addKid(char key, bool isWordEnd)
	{
		Node* temp = new Node(key, isWordEnd);
		kids.push_back(temp);
		return true;
	}
	int hasKid(char key)
	{
		size_t i = 0;
		for (i = 0; i < kids.size(); ++i)
		{
			if (kids[i]->key == key)
			{
				return i;
			}
		}
		return -1;
	}
};
class Trie
{
public:
	Trie()
	{
		root = new Node;
	}
	bool addWord(std::string word)
	{
		size_t i = 0;
		int index = 0;
		Node* temp = new Node;
		temp = root;
		while (i < word.length())
		{
			index = temp->hasKid(word[i]);
			if (index == -1)
			{
				if (i == word.length() - 1)
				{
					temp->addKid(word[i], true);

				}
				else
				{
					temp->addKid(word[i], false);
				}
			}
			index = temp->hasKid(word[i]);
			temp = temp->kids[index];
			++i;
		}
		temp->makeTrue();
		return true;
	}
	bool find(std::string word)
	{
		size_t i = 0;
		int index = 0;
		Node* temp = new Node;
		temp = root;
		while (i < word.length())
		{
			index = temp->hasKid(word[i]);
			if (index == -1)
			{
				return false;
			}
			temp = temp->kids[index];
			++i;
		}
		return true;
	}
	bool isWord(std::string word)
	{
		if (find(word))
		{
			size_t i = 0;
			Node* temp = new Node;
			temp = root;
			while (i < word.length())
			{
				temp = temp->kids[temp->hasKid(word[i])];
				++i;
			}
			return temp->isWordEnd;
		}
		return false;
	}

private:
	Node * root;
};
