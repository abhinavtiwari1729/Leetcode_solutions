class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int altitude = 0 ;
        int max_altitude = 0 ;
        for(int gain_altitude : gain) {
            altitude += gain_altitude;
            max_altitude = max(max_altitude , altitude); 
        }

    return max_altitude;   
    }
};
