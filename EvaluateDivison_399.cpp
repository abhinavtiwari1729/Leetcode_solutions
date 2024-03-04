class Solution {

    bool DFSUtil(string& from , string &to , map<string , vector<pair<string , double>>> &al , set<string> &visited , double &ans) {

        if(from == to)
            return true;

        visited.insert(from);
        auto reachable_nodes = al[from];
        int n = reachable_nodes.size();
        double result = 1;

        for(int i = 0 ;  i < n ; i++){
            
            if(visited.find(reachable_nodes[i].first) == visited.end()){
                
                ans *= reachable_nodes[i].second;
                if (DFSUtil(reachable_nodes[i].first , to , al , visited , ans))
                    return true;
                ans /= reachable_nodes[i].second;
                
            }
        }        
        
        return false;
    }


    bool FindDivision(string& from , string &to , map<string , vector<pair<string , double>>> &al , double &ans) {

        set<string> visited;
        return DFSUtil(from , to , al , visited , ans);

    }



public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        

        map<string, vector<pair<string , double>>> al;
        int n = equations.size();

        for(int i = 0 ; i < n ; i++){
            string from = equations[i][0];
            string to = equations[i][1];

            double cost = values[i];
            al[from].push_back(make_pair(to, cost));
            al[to].push_back(make_pair(from , (1.0/cost)));
        }

        int querie_no = queries.size();
        vector<double> result(querie_no);

        for(int i = 0 ;  i < querie_no ;  i++) {
            
            double ans = 1;

            if(al.find(queries[i][0]) == al.end() or al.find(queries[i][1]) == al.end())
                result[i] = -1;
            else if (FindDivision(queries[i][0] , queries[i][1] , al , ans))
                result[i] = ans;
            else 
                result[i] = -1;
        }

        return result;



    }
};
