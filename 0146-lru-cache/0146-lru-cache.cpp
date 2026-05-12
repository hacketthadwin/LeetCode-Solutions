class LRUCache {
public:
    class Node {
        public:
        int val;
        Node* next;
        Node* prev;
        Node(int value)
        {
            val=value;
            next=nullptr;
            prev=nullptr;
        }
    };

    //i will use doubly linked list here where first element will denote the least recently used and last element will denote the first recently used
    //i will have map of keys and values
    //i will also have a map of key and its address of node, so that i can change its position anytime i want
    int max_capacity;
    map<int,int>mp;
    map<int,Node*>key_pos;
    Node* first=nullptr;
    Node* last=nullptr;
    Node* dll=nullptr;
    int cnt;

    LRUCache(int capacity) {
        max_capacity=capacity;
        cnt=0;
    }
    
    int get(int key) {
        if(mp.count(key))
        {
            int new_val=mp[key];
            put(key,mp[key]);
            return new_val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(max_capacity==0)return;

        //if key is present, then update its value, if not then enter it
        //if the size of map exceeds capacity, remove the LRU element
        if(mp.count(key))
        {
            mp[key]=value;

            //here also we will add it at the end of the doubly linked list

            Node* curr = key_pos[key];
            if(curr==last)return;

            if(curr->prev!=nullptr)curr->prev->next=curr->next;
            if(curr->next!=nullptr)curr->next->prev=curr->prev;

            if(curr == first)first = first->next;

            curr->prev=last;
            curr->next=nullptr;

            if(last!=nullptr)last->next=curr;

            last=curr;

            if(first==nullptr)first=curr;
            
        }
        else
        {
            if(mp.size()==max_capacity)
            {
                //will need to remove the LRU and then add the element (removing first element of dll and then adding new element at end)
                //will also need to store the original first node to delete to free memory

                Node* temp = first;

                mp.erase(first->val);
                key_pos.erase(first->val);

                first = first->next;

                if(first!=nullptr)first->prev=nullptr;

                if(first==nullptr)last=nullptr;
                delete temp;
                mp[key]=value;

                Node* latest= new Node(key);
                if(last==nullptr)
                {
                    first=latest;
                    last=latest;
                }
                else
                {
                    last->next= latest;
                    latest->prev= last;
                    last= latest;
                }

                key_pos[key] = latest;
            }
            else
            {
                mp[key]=value;

                if(cnt==0)
                {
                    dll = new Node(key);

                    first= dll;
                    last= dll;

                    key_pos[key]=dll;
                }
                else
                {
                    Node* latest= new Node(key);

                    last->next= latest;
                    latest->prev= last;

                    key_pos[key] = latest;

                    last= latest;
                }

                cnt++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */