class Solution {
public:

    bool canVisit(int row , int col , vector<vector<char>> &maze){

        int m = maze.size(), n = maze[0].size(); 
        if( (row >= 0 ) && (row != m) && (col >= 0 ) && (col != n ) && (maze[row][col] == '.'))
            return true ;
        
        return false;
    }

    bool isAtBorder(int row , int col , vector<vector<char>> & maze){

        if(row == 0 || col == 0 || row == maze.size()-1 || col ==maze[0].size()-1)
            return true;
        return false;

    }

    vector<int>rowDir = {-1, 1, 0, 0};
    vector<int>colDir = {0, 0, -1, 1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        queue<pair<int , int>>q;
        q.push({entrance[0] , entrance[1]});
        int pathLen = 0;
        maze[entrance[0]][entrance[1]] = '+';


        while(!q.empty()){

            int size = q.size();
            while(size--){

                int currRow = q.front().first;
                int currCol = q.front().second;
                q.pop();


                for(int dirIdx = 0 ; dirIdx < 4 ; dirIdx++){

                    int newRow = currRow + rowDir[dirIdx];
                    int newCol = currCol + colDir[dirIdx];

                    if(canVisit(newRow , newCol , maze)){

                        maze[newRow][newCol] = '+';
                        if(isAtBorder(newRow , newCol , maze))
                            return pathLen + 1;
                        
                        else q.push(, {newRow , newCol});
                    }
                }

            } 
            pathLen++;         
        }

        return -1;
    }
};
