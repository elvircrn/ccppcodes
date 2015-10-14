#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct node
{
	node *nodes [26];
	bool word;

	node() { for (int i = 0; i < 26; i++) nodes [i] = NULL; word = false; }
	
	node *add_node(char c)
	{
		if (nodes [c - 'a'] == NULL)
			nodes [c - 'a'] = new node();
		return nodes [c - 'a'];
	}
};

struct trie
{
	node *root;

	trie() { root = new node(); }
	
	bool add_word (const string &word)
	{
		node *current_node = root;

		for (int i = 0; i < word.length(); i++)
		{
			if (current_node->word)
			{
				cout<<"BAD SET\n"<<word<<endl;
				return false;
			}
			current_node = current_node->add_node(word [i]);
		}

		if (current_node->word)
		{
			cout<<"BAD SET\n"<<word<<endl;
			return false;
		}

		current_node->word = true;

		return true;
	}
	
	void traverse(node *current_node, string string_stack)
	{
		if (current_node->word)
			cout<<string_stack<<endl;
		for (int i = 0; i < 26; i++)
		{
			if (current_node->nodes [i] != NULL)
			{
				string_stack += (i + 'a');
				traverse(current_node->nodes [i], string_stack);
			}
		}
	}

	void traverse()
	{
		traverse(root, "");
	}
};

int main()
{
	trie dict;
	int n;
	string word;

	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>word;
		if (!dict.add_word(word))
			return 0;
	}

	cout<<"GOOD SET"<<endl;

	return 0;
}


