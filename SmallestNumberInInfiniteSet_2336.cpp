class SmallestInfiniteSet {
public:

    int curr;
    set<int> s;

    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if(s.size()){
            int res = *s.begin();
            s.erase(res);
            return res;
        }
        else {
            curr = curr+1;
            return curr-1;
        }
    }                                                                                                       
    
    void addBack(int num) {
        if(num < curr)
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
