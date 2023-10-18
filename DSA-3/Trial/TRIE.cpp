#include <iostream>
#include <string>
#define ALPHABET_SIZE 26
#define ASCII_START 97
class TRIE
{
    TRIE *child[ALPHABET_SIZE];
    char data;
    bool isEndOfString;

public:
    TRIE()
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            child[i] = NULL;
        isEndOfString = false;
    }

    TRIE(bool a)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            child[i] = NULL;
        isEndOfString = a;
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
        int n = ch - ASCII_START;
        if(n >=0 && n <= ALPHABET_SIZE){
            child[n] = new TRIE(B);
            child[n]->data = ch;
        }
        else
        {
            exit(0);
        }
        return n;
    }

    int findindex(const char ch)
    {
        int i = 0;
        if(child[ch-97] != NULL)
        {
            if (child[ch-97]->data == ch)
                return ch-97;
        }
        return -1;
    }
};
TRIE *ROOT = NULL;

void InsertintoTRIE(const std::string s)
{
    TRIE *temp = ROOT;
    int index = 0;
    int i;
    for (i = 0; i < s.length()-1; i++)
    {
        index = temp->findindex(s[i]);
        if (index == -1)
            index = temp->insert(s[i], false);
        temp = temp->getaddress(index);
    }
    index = temp->findindex(s[i]);
    if (index == -1)
        index = temp->insert(s[i], true);
    std::cout << std::endl;
}

void SearchinTRIE(const std::string s)
{
    TRIE *temp = ROOT;
    int index = 0;
    int i;
    for (i = 0; i < s.length(); i++)
    {
        index = temp->findindex(s[i]);
        if (index == -1)
        {
            std::cout << "Word doesn't exist in TRIE" << std::endl;
            return;
        }
        temp = temp->getaddress(index);
    }
    if(temp->isEND())
        std::cout << "Word exists in TRIE" << std::endl;
    else
        std::cout << "Word doesn't exist in TRIE" << std::endl;
}

int main()
{
    ROOT = new TRIE();
    TRIE *temp = ROOT;
    int index;
    int ch;
    std::string s;
    bool isAlpha = 0;
    while (1)
    {
        std::cout << std::endl
             << "Your options\n"
             << "1.Insert\n"
             << "2.Search\n"
             << "3.EXIT\n"
             << "Enter choice:";
        std::cin >> ch;
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
        case 3:
            return EXIT_SUCCESS;
        default:
            std::cout << "No such option" << std::endl;
        }
    }
}
