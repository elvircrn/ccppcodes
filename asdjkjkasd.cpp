#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <list>
#include <iterator>
#include <vector>

using namespace std;

int char_to_number(char c)
{
  if (c >= 'a' && c <= 'c')
    return 2;
  else if (c >= 'd' && c <= 'f')
    return 3;
  else if (c >= 'g' && c <= 'i')
    return 4;
  else if (c >= 'j' && c <= 'l')
    return 5;
  else if (c >= 'm' && c <= 'o')
    return 6;
  else if (c >= 'p' && c <= 's')
    return 7;
  else if (c >= 't' && c <= 'v')
    return 8;
  else if (c >= 'w' && c <= 'z')
    return 9;
  else
    return 1;
}

struct Contact
{
  char data[44];
  bool operator<(const Contact &c) const
  {
    return strcmp(data+12, c.data+12) < 0;
  }
};

struct TreeNode
{
  TreeNode *children[9];
  list<const Contact*> values;
  TreeNode(){fill(children, children+9, (TreeNode*)0);}
} *tree_root = new TreeNode();

void tree_add(const string &id, const Contact &value)
{
  TreeNode *current_node = tree_root;
  for (int i = 0; i < (int)id.length(); ++i)
  {
    int child_id = char_to_number(id[i]) - 1;
    if (current_node->children[child_id] == 0)
      current_node->children[child_id] = new TreeNode();
    current_node = current_node->children[child_id];
    if (current_node->values.empty() || current_node->values.back() != &value)
      current_node->values.push_back(&value);
  }
}

void tree_node_print(const Contact* c)
{
  cout << c->data << "\n";
}

TreeNode *tree_find(const string &id)
{
  TreeNode *current_node = tree_root;
  for (int i = 0; i < min((int)id.length(), 10); ++i)
  {
    int child_id = id[i] - '0' - 1;
    if (current_node->children[child_id] != 0)
      current_node = current_node->children[child_id];
    else
      return 0;
  }
  return current_node;
}

void tree_delete(TreeNode *current_node = tree_root)
{
  for (int i = 0; i < 9; ++i)
  {
    if (current_node->children[i] != 0)
      tree_delete(current_node->children[i]);
  }
  delete current_node;
}

int main()
{

    freopen ("in.txt", "r", stdin);
    freopen ("out1.txt", "w", stdout);
    //ifstream fin("podaci.txt");
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    cin.ignore(10000, '\n');
    vector<Contact> contacts(n);
    while (n--)
      cin.getline(contacts[n].data, 44);

    sort(contacts.begin(), contacts.end());

    for (int i = 0; i < (int)contacts.size(); ++i)
    {
      string name (contacts[i].data+12);
        transform(name.begin(), name.end(), name.begin(), ::tolower);
      stringstream sin(name);
      string name_single;
      while (sin >> name_single)
        tree_add(name_single, contacts[i]);
    }

    while (m--)
    {
      string id;
      cin >> id;
      TreeNode *result = tree_find(id);
      cout << id << ":\n";
      if (result != 0)
        for_each (result->values.begin(), result->values.end(), tree_node_print);
    }
    //tree_delete();
    return 0;
}
