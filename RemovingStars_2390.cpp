class Solution {
public:
    string removeStars(string s) {
        
        stack<char> st;
        for(char ch : s){
            if(ch != '*')
                st.push(ch);
            else {
                st.pop();
            }
        }

        string result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin() , result.end());
        return result;
    }
};
