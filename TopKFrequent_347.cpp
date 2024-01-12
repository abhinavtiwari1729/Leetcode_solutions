class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int ,int> um;
        for (int num : nums)
            um[num]++;
        
        vector<int> result;
        priority_queue<pair<int , int>> pq;
        for (auto iterator = um.begin() ; iterator != um.end() ; iterator++) {

            pq.push({iterator->second , iterator->first});
            if (pq.size() > um.size()-k){
                result.push_back(pq.top().second);
                pq.pop();
            }
        }

        return result;
    }
};
