class Solution {

    bool canVisit(int row , int col , vector<vector<int>> &grid){

        if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1)
            return true;

        return false;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int , int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int no_of_fresh_oranges = 0;

        for(int i=0 ; i < m ; i++){
            for(int j=0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }
                else if(grid[i][j] == 1)
                    no_of_fresh_oranges++;
            }
        }

        if(no_of_fresh_oranges == 0)
            return 0;
        vector<int> rowDir = {-1 , 1 , 0 , 0};
        vector<int> colDir = {0 , 0 , -1 , 1};

        int minutes = 0;
        while(!q.empty()){

            int size = q.size();
            while(size--){
                
                auto curr_pair = q.front();
                q.pop();
                int curr_i = curr_pair.first;
                int curr_j = curr_pair.second;  

                for(int dirIdx = 0 ; dirIdx < 4 ; dirIdx++){

                    int new_i = curr_i + rowDir[dirIdx];
                    int new_j = curr_j + colDir[dirIdx];

                    if(canVisit(new_i , new_j , grid)){
                        
                        grid[new_i][new_j] = 2;
                        no_of_fresh_oranges--;
                        q.push({new_i , new_j});
                    
                    }


                }
            }

            minutes++;
        }

        if(no_of_fresh_oranges == 0)
            return minutes-1;
        
        return -1;
    }
};
