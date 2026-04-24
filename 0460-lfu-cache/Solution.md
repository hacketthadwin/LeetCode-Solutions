# EASY APPROACH DOUBLY LINKED LIST DESIGN APPROACH

# Intuition
The intuition for this problem will be the toughest to get.
My thought process went from first creating 2 maps -> one for LFU and second for LRU, then I encountered that with this, we really cannot do the thing of choosing those elements from LRU whose LFU is the same, even if we can do it, it will be in at least O(n).

The main thing about this problem is that you have to solve this in O(1) for a properly optimized version, though I have used a map (which makes the solution O(log n)) to maintain the frequency and doubly linked list thought process, but it can be easily optimized by the use of unordered_maps and a variable something like min_freq, we can do it ourselves.

Now my intuition really came from the challenge that even if I make 2 unordered maps, I cannot fetch the elements with the same LRU in O(1). After thinking for a long time (yeah, spent almost the whole day on this thinking about data structures), I thought of everything like priority_queue, stacks, queues, double ended queues, graphs, trees, but I never went in the direction of doubly linked list (because who uses LL other than interviews, though used practically in almost all places but not much in DSA problems). I finally took the hint of choosing a correct data structure, then I got to know that this can be solved using a doubly linked list, then spent some time figuring out how... this didn't take much time because within minutes I figured out how we can use a doubly linked list because of its node removal and attaching ability at any point (but in this problem, we are mainly concerned about the head and tail pointer or start and end pointer).

# Approach
Now my approach for this problem is to first create an unordered map which will store the key and its value obviously.
Then as I have already got the key and its value, if I can store key and its frequency, it will be even better, so I did it too.

Then as I told that I understood how I am going to use the doubly linked list and how I will be needing only the head and tail pointer (because start pointer will denote which key came first or the least recently used key and the key at the end will be the most recent key in that frequency count and as I have frequency count attached with each key, I can find the least frequency count by just doing mp.begin() which returns an iterator to the first key of the map because map is a sorted data structure). So by this I got the least frequency and from that least frequency I got all the keys of that frequency in the order of when they entered in that frequency list from start to end pointer. This thought process was just awesome and definitely not trivial to come up with.

Then I also needed to store the node address of the key so that whenever the frequency of that key is needed to be updated, I can just go to that address, unlink the key and connect its previous and next key together. That's why storing this was necessary.

Now all it required is keen focus and correctness to code the whole thing without any bugs because it is so easy to get caught in bugs while coding this.

You can see my code and my comments for the whole step by step process from my thinking to coding it up (ignore some of the comments because those were my thought process from initial to final approach, so they may contain wrong approaches too).


# Complexity
- Time complexity:
O(log n) but can be easily converted to O(1) by replacing maps with unordered maps (didn't do it because of simplicity by not maintaining another variable)

- Space complexity:
O(N)

# Code
```cpp []
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
```