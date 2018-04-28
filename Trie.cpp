#include <iostream>
#include <string>
#include <vector>
#include "Trie.h"
int main()
{
	Trie obj;
	obj.addWord("hello");
	obj.addWord("bye");
	obj.addWord("he");

	if (obj.isWord("he"))
	{
		std::cout << " is word\n"; // eg works true
	}
	else
	{
		std::cout << "isn\'t word\n";
	}
	system("pause");
	return 0;
}