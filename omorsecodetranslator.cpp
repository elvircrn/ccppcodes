#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

vector <char> input;
bool english(true);

const char * morse_code [30] = {
".-",
"-...",
"-.-.",
"-..",
".",
"..-.",
"--.",
"....",
"..",
".---",
"-.-",
".-..",
"--",
"-.",
"---",
".--.",
"--.-",
".-.",
"...",
"-",
"..-",
"...-",
".--",
"-..-",
"-.--",
"--..",
"--..--",
".-.-.-",
".--.-.",
"..--.."
};
//, 26
//. 27
//@ 28
//? 29

int char_to_int(char character)
{
    character = tolower (character);
    if (isalpha (character))
        return character - 'a';
}

int get_index (char character)
{
    character = tolower (character);

    if (character >= 'a' && character <= 'z')
        return character - 'a';
    else
    {
        if (character == ',')
            return 26;
        else if (character == '.')
            return 27;
        else if (character == '@')
            return 28;
        else
            return 29;
    }
}

int get_bit (char character)
{
    if (character == '.')
        return 0;
    else
        return 1;
}

struct node
{
    node *next [3];
    char value;

    node() { value = 0; }
    node(char character) { value = character; }
};

node *root;

void generate()
{
    root = new Node();
    node *Node = root;
    for (int i = 0; i < 30; i++)
    {
        int len = strlen (morse_code [i]);
        for (int j = 0; j < len; i++)
        {
            char current_char = morse_code [i] [j];
            if (Node->next [get_bit(current_char)] == NULL)
            {
                Node->next [get_bit(current_char)] = new Node();
                Node = Node->next [get_bit(current_char)];
            }
        }
        Node->value =
    }
}

int main()
{
    generate();
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    char c;
    while ((c = getchar()) != EOF)
    {
        input.push_back (c);
        if (c == ' ' && input [input.size() - 2] == ' ')
            english = false;
    }

    if (english)
    {
        for (int i = 0; i < input.size(); i++)
        {
            if (input [i] == ' ')
                printf (" ");
            else
                printf ("%s ", morse_code [get_index (input [i])]);
        }
    }
    else
    {
        for (int i = 0; i < input.size(); i++)
        {

        }
    }

    putchar ('\n');

    return 0;
}
/*
Kako da PREVEDEM .,@?
*/













