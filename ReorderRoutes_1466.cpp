class Solution {

    int dfs(vector<vector<int>> &al , vector<bool> &visited , int src) {

        int change = 0;
        visited[src] = true;
        for(auto to : al[src]){

            if(!visited[abs(to)]){
                if(to > 0)
                    change++;
                change += dfs(al , visited , abs(to));
            }
        }

        return change;
    }


public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adjacency_list(n);
        for(auto &c: connections) {
            adjacency_list[c[0]].push_back(c[1]);
            adjacency_list[c[1]].push_back(-c[0]);
        }

        vector<bool> visited(n , false);
        return dfs(adjacency_list , visited , 0);
    }
};
