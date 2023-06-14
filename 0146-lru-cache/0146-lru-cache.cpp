
class LRUCache {
public:
    class node{
    public:
        int key;
        int val;
        node* prev;
        node* next;
       node(int _key,int _val) {
           key=_key;
           val=_val;
       }
};
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    int cap;
    unordered_map<int,node*>mp;

    LRUCache(int capacity) {
        cap=capacity;
         head->next=tail;
         tail->prev=head;
    }
    
    
    void addnode(node* newnode){
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
         head->next=newnode;
        temp->prev=newnode;
    }
    
     
    void deletenode(node* delnode){
        node* delprev=delnode->prev;
         node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    
    int get(int key_) {
       if(mp.find(key_)!=mp.end()){
           node* address=mp[key_];
           int ans=address->val;
           mp.erase(key_);
           deletenode(address);
           addnode(address);
           mp[key_]=head->next;
           return ans;
       }
        return -1;
    }
    
    void put(int key_, int value) {
        if(mp.find(key_)!=mp.end()){
            node* exisiting=mp[key_];
            mp.erase(key_);
            deletenode(exisiting);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_,value));
        mp[key_]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */