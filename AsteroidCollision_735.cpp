class Solution {

    void RecurCollision(stack<int> &st, int ast){

        while(!st.empty() && st.top() > 0 && ast < 0){

            int top_ast = st.top();
            st.pop();
            int winner_ast = abs(top_ast) > abs(ast) ? top_ast : ast;
            if(abs(top_ast) == abs(ast))
                return;
            if(abs(top_ast) != abs(ast)){
                ast = winner_ast;
                continue;
            }
        }

        st.push(ast);

    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto ast : asteroids){

            if(st.empty())
                st.push(ast);
            else {
                auto prev_ast = st.top();
                if(prev_ast > 0 && ast < 0){

                    st.pop();
                    int winner_ast = abs(prev_ast) > abs(ast) ? prev_ast : ast;
                    if(abs(prev_ast) != abs(ast))
                        RecurCollision(st, winner_ast);
                    //RecurCollision(st );
                }
                else
                    st.push(ast);
            }

        }

        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin() , result.end());
        
        return result;
    }
};
