class Node{
    public:
    Node* links[26];
    bool flag=false;
    
    //checks if the reference trie is present or not
    bool iscontain(char ch){
        return (links[ch-'a']!= NULL);
    }
       
    
    //creating reference trie
    void put(char ch,Node * node){
        links[ch-'a']=node;
    }
    
    //to get the next node for traversal
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    	//setting flag to true at the end of the word
    void setEnd(){
        flag= true;
    }
    
    bool isEnd(){
          return flag;
    }
      
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->iscontain(word[i])){
              node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool check(string word){
        bool flag=true;
         Node* node=root;
        
         for(int i=0;i<word.length();i++){
            if(node->iscontain(word[i])){
               node=node->get(word[i]);
               flag=flag & node->isEnd() ;
            }
            else
            return false;
        }

        return flag;
    }
};

class Solution {
public:
    string longestWord(vector<string>& a) {
          Trie* trie=new Trie();
    for(auto &it:a){
        trie->insert(it);
    }

     string longest="";

    for(auto &it:a){
        if(trie->check(it)){
            if(it.length()>longest.length())
            longest=it;
            else if(it.length()==longest.length() && it<longest)
             longest=it;
        }
    }
   
    return longest;
    }
};