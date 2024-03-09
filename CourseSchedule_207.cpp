class Solution {

    bool checkCycle(int node , vector<bool> &visited , vector<bool> &dfsTree , 
                    vector<vector<int>> &al){
    
        visited[node] = true;
        dfsTree[node] = true;

        for(auto adj_node : al[node]){

            if(!visited[adj_node]){
                if (checkCycle(adj_node , visited , dfsTree , al))
                    return true;
            }
            else if(dfsTree[adj_node] == true)
                return true;
        }
        
        dfsTree[node] = false;
        return false;

    }


public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> al(numCourses);

        for(auto p : prerequisites){
            
            al[p[1]].push_back(p[0]);
        }
        
        vector<bool> visited(numCourses , false);
        vector<bool> dfsTree(numCourses , false);

        for(int i = 0 ;  i < numCourses ; i++){

            if(!visited[i])
                if(checkCycle(i , visited , dfsTree , al))
                    return false;

        }

        return true;
        
    }
};
