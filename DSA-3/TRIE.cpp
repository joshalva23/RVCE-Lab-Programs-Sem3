#include <iostream>
#include <string>
#define ALPHABET_SIZE 26
using namespace std;
class TRIE
{
    TRIE *child[ALPHABET_SIZE];
    char data;
    int n;
    bool isEndOfString;

public:
    TRIE()
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            child[i] = NULL;
        isEndOfString = false;
        n = 0;
    }

    TRIE(bool a)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            child[i] = NULL;
        isEndOfString = a;
        n = 0;
    }

    bool isEND()
    {
        return isEndOfString;
    }
    TRIE *getaddress(int index)
    {
        return child[index];
    }

    int insert(char ch, bool B)
    {
        child[n] = new TRIE(B);
        child[n]->data = ch;
        ++n;
        return n - 1;
    }

    int findindex(const char ch)
    {
        int i = 0;
        while (child[i] != NULL)
        {
            if (child[i]->data == ch)
                return i;
            i++;
        }
        return -1;
    }
};
TRIE *ROOT = NULL;

void InsertintoTRIE(const string s)
{
    TRIE *temp = ROOT;
    int index = 0;
    int i;
    for (i = 0; i < s.length(); i++)
    {
        index = temp->findindex(s[i]);
        if (index == -1)
            index = temp->insert(s[i], false);
        temp = temp->getaddress(index);
    }
    cout << endl;
}

void SearchinTRIE(const string s)
{
    TRIE *temp = ROOT;
    int index = 0;
    for (int i = 0; i < s.length(); i++)
    {
        index = temp->findindex(s[i]);
        if (index == -1)
        {
            cout << "Word doesn't exist in TRIE" << endl;
            return;
        }
        temp = temp->getaddress(index);
    }
    cout << "Word exists in TRIE" << endl;
}
int main()
{
    ROOT = new TRIE();
    TRIE *temp = ROOT;
    int index;
    int ch;
    string s;
    bool isAlpha = 0;
    while (1)
    {
        cout << "Your options\n"
             << "1.Insert\n"
             << "2.Search\n"
             << "Enter choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            std::cout << "Enter string to enter into TRIE:";
            std::cin >> s;
            InsertintoTRIE(s);
            break;
        case 2:
            std::cout << "Enter string to search:";
            std::cin >> s;
            SearchinTRIE(s);
            break;
        default:
            std::cout << "No such option" << endl;
        }
    }
}
