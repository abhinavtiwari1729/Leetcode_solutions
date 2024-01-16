class Solution {

    void dfs(vector<vector<int>> &rooms , int s , vector<bool> &visited) {

        visited[s] = true;
        for (int i = 0 ; i<rooms[s].size() ; i++) {

            if (!visited[rooms[s][i]]){
                dfs(rooms , rooms[s][i] , visited);
            }
        }

    }



public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int size = rooms.size();
        vector<bool> visited(size , false);
        dfs(rooms , 0 , visited);

        for(auto visit : visited) {
            if(!visit)
                return false;
        }

        return true;

    }
};
