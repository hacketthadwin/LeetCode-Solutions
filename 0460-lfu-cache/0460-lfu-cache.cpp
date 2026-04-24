class LFUCache {
public:
class node {
public:
    int val;
    node* prev;
    node* next;

    node(int key) {
        this->val=key;
        this->prev=nullptr;
        this->next=nullptr;
    }
};
//i can maintain the lfu, but on the tiebreaker, i should use lru and for lru, i need to also update the time when that key was updated, nice nice, so i need to maintain the time also which i can do by using global time but then i should also use it in such a way that i always get the sorted result by its time, so that i can get the value in least time, one thing i can do is for each value, i can maintain the time 
//see our priority is lfu then lru ok, i will keep adding keys and when the number of keys exceed the capacity i will remove one of the key which depends on 2 things , so 2 things, one is frequency which is counting how many times the key is used and second is global time which is when that key was updated last, then i will pick the one with least frequency and if tie then i will pick which has least time
//i guess priority queue will do this, but if i will be solving, i would be a dbms like thing where i will have a primary key which will be my key only and the values i need to associate with this one key is value+frequency+time in which value is just returning thing, so i can even store it in one map and keep returning, but since it depends on lfu and lru i will also have to ensure that i get these values from another data structure, so one map is key -> value and one more data structure which will associate 3 things key+frequency+time and it will be always sorted in 2 things first frequency and second is time, but see 2 things if it depends on then why can't i use 3 variables, -> key, frequency and time and for each time we do a put operation, we will check and update these 3 variables,
//let's think if we can miss some cases, we are maintaining lowest frequency we see, we are maintaining a global time and a least time, and yes a key associated with both, yeah i guess it's fine, 2 pairs will be used which will both have 2 things {key,frequency} , {key, time}
//i will update the time of those keys only
// and since there is no remove thing before capacity i will remove that
// yeah i got it, do you think queue can be a better approach, nah because i can't update any other thing other than the top element, this is really nice,
unordered_map<int,int>mp;
map<int, pair<node*,node*>>lfu_cnt; //will store the count of frequency-> first element will be the frequency and second will be the node pointer of start and end(that's why pair), also as this is unordered_map, i will have to write one more variable which will store the least frequency
int least_freq=INT_MAX;
unordered_map<int,node*>key_pos; //this is key -> node position
unordered_map<int,int>freq_cnt; // Standardized to freq_cnt to match your logic usage
//the first will denote the least recently used as i will be updating the list as they come, also i should store the map of key and its node pointer, so when i will have to do a put operation (update operation, i can simply visit to that node directly, disconnect from the node and then add it to the end of each node)
//also if i am using doubly linked list, it is clear that in both cases, the number will either be added at the end of row of each cnt or at the  
int max_size=-1;
    LFUCache(int capacity) {
        max_size=capacity;
    }
    
    int get(int key) {
        if(mp.count(key))
        {
            //now we will update the frequency of this element by increasing finding its node position, then removing it from that list and then adding it to next frequency list
            node* pos = key_pos[key];
            
            //now the back node of this node will be directly connecting with the next node of this node
            node* next_node=pos->next;
            node* prev_node=pos->prev;
            // prev_node->next=next_node; 
            // next_node->prev=prev_node;
            
            // head/tail update
            if(prev_node) prev_node->next = next_node;
            else lfu_cnt[freq_cnt[key]].first = next_node;
            
            if(next_node) next_node->prev = prev_node;
            else lfu_cnt[freq_cnt[key]].second = prev_node;

            // erase freq from map if list is empty so lfu_cnt.begin() stays accurate
            if(lfu_cnt[freq_cnt[key]].first == nullptr) lfu_cnt.erase(freq_cnt[key]);

            //the previous line unlinked the node from the doubly linked list
            //now adding it as next pointer in the lfu_cnt as
            if(lfu_cnt.count(freq_cnt[key]+1))
            {
                lfu_cnt[freq_cnt[key]+1].second->next=pos;
                pos->prev = lfu_cnt[freq_cnt[key]+1].second; // Link back
                pos->next = nullptr;
                lfu_cnt[freq_cnt[key]+1].second = pos;
            }
            else
            {
                // lfu_cnt[freq_cnt[key]+1].first= new Node(pos->val); 
                // lfu_cnt[freq_cnt[key]+1].second= lfu_cnt[freq_cnt[key]+1].first;
                // pos=lfu_cnt[freq_cnt[key]+1].first;
                
                // we can reuse pos node instead of new allocation
                lfu_cnt[freq_cnt[key]+1].first = lfu_cnt[freq_cnt[key]+1].second = pos;
                pos->prev = pos->next = nullptr;
            }
            int freq=freq_cnt[key];
            // if(lfu_cnt[freq_cnt[key]].first==nullptr) { lfu_cnt.erase(freq_cnt[key]); } // moved up for correct logic
            freq_cnt[key]=freq+1;
            // pos->prev=lfu_cnt[freq_cnt[key]].second; // handled inside if/else above
            // pos->next=nullptr;
            // lfu_cnt[freq_cnt[key]].second=pos;
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(max_size <= 0) return;
        if(mp.count(key))  // handling update existing key
        { 
            mp[key]=value; 
            get(key); 
            return; 
        } 

        if(mp.size() < max_size)
        {
            mp[key]=value;
        }
        else
        {
            //remove the lfu/lru key
            //here the dilemma is sorted that which key is lru because the key in the starting node of lfu_cnt is the least recently used
            
            // if(lfu_cnt[lfu_cnt.begin()].first->next!=nullptr) // .begin() is an iterator 
            node* head = lfu_cnt.begin()->second.first;
            if(head->next!=nullptr)
            {
                // int keys=lfu_cnt[lfu_cnt.begin()].first->val;
                // lfu_cnt[lfu_cnt.begin()].first=lfu_cnt[lfu_cnt.begin()].first->next;
                
                int keys = head->val; // head->val stores the key
                lfu_cnt.begin()->second.first = head->next;
                lfu_cnt.begin()->second.first->prev = nullptr;
                mp.erase(keys); key_pos.erase(keys); freq_cnt.erase(keys); // clear all maps
            }
            else
            {
                // int keys=lfu_cnt[lfu_cnt.begin()].first->val;
                // mp.erase(keys);
                // lfu_cnt.erase(lfu_cnt.begin());
                
                int keys = head->val;
                mp.erase(keys); key_pos.erase(keys); freq_cnt.erase(keys);
                lfu_cnt.erase(lfu_cnt.begin());
            }
            delete head; 
            mp[key]=value;
        }
        
        // now insert logic for new key into frequency 1
        freq_cnt[key] = 1;
        node* new_node = new node(key); // val is key
        key_pos[key] = new_node;
        if(lfu_cnt.count(1)) {
            lfu_cnt[1].second->next = new_node;
            new_node->prev = lfu_cnt[1].second;
            lfu_cnt[1].second = new_node;
        } else {
            lfu_cnt[1].first = lfu_cnt[1].second = new_node;
        }
    }
};