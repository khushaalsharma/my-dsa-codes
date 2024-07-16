class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string ans;
        string temp;
        stringstream ss(path);

        while (getline(ss, temp, '/')) { //The statement getline(ss, temp, '/') is used to read a string from a stringstream object (ss) up to the next delimiter ('/' in this case) and store it in the variable temp.
            if (temp == "" || temp == ".") {
                continue;
            }
            if (temp == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(temp);
            }
        }

        for (const string& dir : stack) {
            ans += "/" + dir;
        }

        return ans.empty() ? "/" : ans;
    }
};


//MY INITIAL CODE: Time Limit Exceeded with incorrect handling of three dots case:
string simplifyPath(string s) {
        stack<char> st;
        int n = s.length();
        int i = 0;

        while(i < n){
            if(s[i] == '/'){
                if(!st.empty() && st.top() == '/'){
                    i++;
                }
                else{
                    st.push(s[i]);

                }
                i++;
            }
            else if(s[i] == '.'){
                if(s[i+1] == '.'){
                    if(s[i+2] == '.'){
                        st.push('.');
                        st.push('.');
                        st.push('.');
                        i += 3;
                    }
                    else{
                        while(st.top() == '/'){
                            st.pop();
                        }
                        while(st.top() != '/'){
                            st.pop();
                        }
                        i += 2;
                    }
                }
                else{
                    i++;
                }
            }
            else{
                st.push(s[i]);
                i++;
            }
        }

        string ans = "";

        while(!st.empty()){
            ans.insert(0, to_string(st.top()));
            st.pop();
        }

        return ans;
    }
