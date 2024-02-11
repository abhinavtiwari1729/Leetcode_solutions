class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int , int> ele_to_occ_map;
        for (auto ele : arr){
            ele_to_occ_map[ele]++;
        }

        unordered_map<int, int> occ_to_ele_map;
        for (auto it = ele_to_occ_map.begin() ; it != ele_to_occ_map.end(); it++){
            if(occ_to_ele_map.find(it->second) != occ_to_ele_map.end())
                return false;
            
            occ_to_ele_map[it->second] = it->first;
        }

        return true;
    }
};
