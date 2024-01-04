class Solution {


    string GetButtonStr(char ch){
        //string a ;
        // switch(i) {
        //     case 2 :
        //         a = "abc";
        //         return a;
        //         break;
        //     case 3 :
        //         return "def";
        //         break;
        //     case 4 :
        //         return "ghi";
        //         break;
        //     case 5 :
        //         return "jkl";
        //         break;
        //     case 6 :
        //         return "mno";
        //         break;
        //     case 7 :
        //         return "pqrs";
        //         break;
        //     case 8 :
        //         return "tuv";
        //         break;
        //     case 9 :
        //         return "wxyz";
        //         break;
        //     default :
        //         return "";
        //         break;
        
        // }

        if (ch == '2') {
            return "abc";
        }
        return "";
    }

    void GetCombinations(string digits , int i , string st , vector<string> & result) {

        if (i >= digits.size()){
            result.push_back(st);
            cout << "pushing into result : " << st << endl ; 
            return;
        }

        string button_chars = GetButtonStr(digits[i]);
        cout << "buttonstr is :" << button_chars << endl ;
        for (char ch : button_chars){
            st.push_back(ch);
            cout << "processing character : " << ch << endl; 
            GetCombinations(digits , i+1 , st , result);
            st.pop_back();
        }



    }



public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> result;
        string st("");
        int i  = 0 ;
        GetCombinations(digits , i , st , result);
        return result;

    }
};
