#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using multi_ordered_set = tree<T, __gnu_pbds::null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class MedianFinder {
private:
    multi_ordered_set<int> s;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.insert(num);
    }
    
    double findMedian() {
        if (s.empty()) return 0.0;
        int k1 = s.size() / 2;
        int k2 = k1 - 1;
        if (s.size() % 2 == 1) { 
            double a = (*s.find_by_order(k1));
            return a;
        } else {
            double a = (*s.find_by_order(k1));
            double b = (*s.find_by_order(k2));
            return (a + b) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */