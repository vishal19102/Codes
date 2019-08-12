#include<iostream>
#include<string>
#include<unordered_map>
#define hashmap unordered_map<char,node*>
using namespace std;

class node{

    public:
        char data;
        hashmap mp;
        bool isTerminal;

        node(char dt){
            data=dt;
            isTerminal=false;
        }


};

class Trie{

    public :
    node *root ;

    Trie(){
        root= new node('\0');
    }

    //insert strings 
    void insertString(string str){
        node *temp=root;
        for(int i=0;i<str.length();i++)
            {
                char ch=str[i];
                if(temp->mp.count(ch)==0)
                        {
                            node* child= new node(ch);
                            temp->mp[ch]=child;
                            temp=child;
                        }
                else
                    {
                            temp=temp->mp[ch];
                    }
            }
            temp->isTerminal=true;

    }
    //find the string if available
    bool isPresent(string str){
            node* temp= root;
            for(int i=0;i<str.length();i++)
                {
                    if(temp->mp.count(str[i])==0)
                        return false;
                    else
                    {
                        temp=temp->mp[str[i]];
                    }
                    
                }


        return temp->isTerminal;
    }
};



int main(){
    Trie t;
    int n;
    cin>>n;
    string str[n+1];
    for(int i=0;i<=n;i++)
    {
        getline(cin,str[i]);
        t.insertString(str[i]);    
    }
    cout<<t.isPresent("apples are ")<<endl;
 
    
   
    return 0;
}


