#include<iostream>
#include<string>
#include<unordered_map>
#define hashmap unordered_map<char,node*>

using namespace std;
class node{
    public :
        char data;
        bool isTerminal;
        hashmap mp;
    node(int d){
            data=d;
            isTerminal=false;

    }
};
class Trie{

    public :
        node* root;

    Trie(){
        root = new node('\0');
    }
    void insertString(string str){
        node* temp;
        temp=root;
        for(int i=0;i<str.length();i++)
            {
                if(temp->mp.count(str[i])==0)   
                    {
                        node * child= new node(str[i]);
                        temp->mp[str[i]]=child;
                        temp=child;
                    }
                    else
                    {
                            temp=temp->mp[str[i]];
                    }
                    
            }
            temp->isTerminal=true;

            return ;
    }
    bool isPresent(string str){
            node * temp= root;
            for(int i=0;i<str.length();i++)
                {
                    char s=str[i];

                    if(temp->mp.count(s)==0)
                        return false;
                    else
                    {
                            temp=temp->mp[s];
                    }
                    
                }
                return temp->isTerminal;

    }
};
int main(){




    return 0;
}