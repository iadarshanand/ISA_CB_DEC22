class Node
{
    public:
    int key,val;
    Node *next, *prev;
    //constructor
    Node(int key,int val)
    {
        this->key=key;
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class LRUCache {
    private:
    int capacity;
    unordered_map<int,Node*>mp; //map<key,Node*>
    Node *head, *tail;

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1); //dummyHead
        tail=new Node(-1,-1); //dummyTail
        head->next=tail;
        tail->prev=head;    
    }

    void insetNodeAtFront(Node* head, Node* p)
    {
        p->next=head->next;
        head->next->prev=p;
        head->next=p;
        p->prev=head;
    }
    
    void dislocateNode(Node* p)
    {
        p->next->prev=p->prev;
        p->prev->next=p->next;        
    }
    
    int get(int key) {
        //if key is not present in cache
        if(!mp.count(key))return -1;
        //otherwise key present
        Node* p=mp[key];
        //dislocate node
        dislocateNode(p);
        //Insert Node At front
        insetNodeAtFront(head,p);
        return p->val;
    }
    
    void put(int key, int value) {
        //if key is present 
        if(mp.count(key))
        {
            //key is present
            Node* p=mp[key];
            p->val=value;

            //dislocate
            dislocateNode(p);

            // insert Pnode at front
            insetNodeAtFront(head,p);
        }
        else
        {
            //key is not present
            // create a new Node with key-val pair
            Node* newNode=new Node(key,value);
            //check capacity
            if(mp.size()==capacity)
            {
                //Remove LRU Node from DLL
                Node* LRUnode=tail->prev;
                int LRUnodeKey=LRUnode->key;
                //erase this node from map
                mp.erase(LRUnodeKey);

                //remove LRUnode from list
                dislocateNode(LRUnode);
                // LRUnode->next->prev=LRUnode->prev;
                // LRUnode->prev->next=LRUnode->next;

            }

            //Insert newNode At front
            insetNodeAtFront(head,newNode);

            //put newNode in map
            mp[key]=newNode;

        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */