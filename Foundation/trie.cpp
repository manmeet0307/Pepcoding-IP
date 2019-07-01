#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    char data;
    unordered_map<char, node*> children;
    bool eow;
};
class trie
{
private:
    node * root;
    int words;
    int nodes;
public:
    trie()
    {
        root = new node();
        root->data = '$';
        root->eow = false;
        words = 0;
        nodes = 1;
    }
    bool searchwrd(node * n , string s , int idx)
    {
        if(idx == s.length())
        {
            return n->eow;
        }
        char ch = s[0];
        if( n->children.count(ch) == 0 )
        {
            return false;
        }
        else
        {
            node * child = n->children[ch];
            return searchwrd(child , s , idx + 1);
        }
    }
    bool Searchword(string s)
    {
        return searchwrd(root , s , 0);
    }
    void addWord(node * t , string word , int idx)
    {
        if(idx == word.length())
        {
            words++;
            t->eow = true;
            return ;

        }

        char ch = word[idx];
        if(t->children.count(ch) == 0)
        {
            nodes++;
            node * child = new node();
            child->data = ch;
            child->eow = false;
            t->children[ch] = child;
            addWord(child , word , idx+1);
        }
        else
        {
            node * child = t->children[ch];
            addWord(child , word , idx+1);
        }
    }
    void add(string word)
    {
        addWord(root,word , 0);
    }
    void display(node * t)
    {
        //base case
        if(t->children.size() == 0)
        {
            return ;
        }
        cout<< t->data << " : ";
        unordered_map<char , node *> :: iterator it;
        for(it = (t->children).begin() ; it!= t->children.end() ; it++)
        {
            cout<<it->first<<" ";
        }
        cout<<endl;
        for(it = (t->children).begin() ; it!= t->children.end() ; it++)
        {
            display(it->second);
        }
    }
    void removewrd(node * t , string word ,int idx)
    {
        if(idx == word.length() && t->eow == true )
        {
            t->children.erase(word[idx]);
            return ;
        }
        else if(idx == word.length())
        {
            node * child = t->children[word[idx]];
            child->eow = false;
            return ;
        }

        node* child = t->children[word[0]];
        removewrd(child , word , idx+1);
    }
    void Remove(string word)
    {
        removewrd(root,word , 0);
    }
    void displaytrie()
    {
        display(root);
    }
    void displayWord(node * t , string wsf)
    {
        if(t->eow == true )
        {
            cout<< wsf<<endl;
        }
        for(auto itr = t->children.begin() ; itr != t->children.end() ; itr++)
        {
            displayWord(itr->second , wsf + itr->first );
        }
    }
    void displayword()
    {
        displayWord(root , "");
    }
    void removeWord(node * t, string word , int idx )
    {
        if(idx == word.length())
        {
            words--;
            t->eow = false;
            return ;
        }
        char ch = word[idx];
        node * child = t->children[ch];
        removeWord( child , word , idx+1);
        if(child->eow == false && child->children.size()==0)
        {
            t->children.erase(ch);
            nodes--;
            delete child;
        }
    }
    void removeword(string s)
    {
        removeWord(root , s , 0);
    }
};
int main()
{
  trie t;
  t.add("are");
  t.add("aye");
  t.add("hello");
  t.displaytrie();

   t.displayword();
    t.removeword("aye");
    cout<<endl;
    t.displayword();
}
