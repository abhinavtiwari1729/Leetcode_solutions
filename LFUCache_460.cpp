class LFUCache {

    int capacity;
    int minFreq;
    unordered_map<int , pair<int,int>> keyVal;   // key-> (value , freqcount)
    unordered_map<int , list<int>> freqList;     // freq-> (list of key : most recently used in back)
    unordered_map<int , list<int>::iterator> pos; // key-> its position in freq list

public:
    LFUCache(int capacity) {
        
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        
        if(keyVal.find(key) == keyVal.end())
            return -1;
        
        freqList[keyVal[key].second].erase(pos[key]);  // delete key from freqList
        keyVal[key].second++;  
        freqList[keyVal[key].second].push_back(key);
        pos[key] = --freqList[keyVal[key].second].end();
        if(freqList[minFreq].empty())
            minFreq++;
        return keyVal[key].first;

    }
    
    void put(int key, int value) {
        
        if(keyVal.find(key) != keyVal.end()){

            keyVal[key].first = value;
            freqList[keyVal[key].second].erase(pos[key]);  // delete key from freqList
            keyVal[key].second++;  
            freqList[keyVal[key].second].push_back(key);
            pos[key] = --freqList[keyVal[key].second].end();
            if(freqList[minFreq].empty())
                minFreq++;
            return ;            

        }

        if(keyVal.size() == capacity){

            int delkey = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            keyVal.erase(delkey);
            pos.erase(delkey);
        }

        keyVal[key] = {value , 1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
