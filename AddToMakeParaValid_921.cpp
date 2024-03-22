class Solution {
public:
    int minAddToMakeValid(string s) {
       
       int min_add = 0;
       stack<char> st;
       for(char ch : s) {
            if(ch == '(')
                st.push(ch);
            if(ch == ')'){
                if (!st.empty())
                    st.pop();
                else 
                    min_add++;
            } 
       }
        min_add += st.size();
        return min_add;
    }
};
