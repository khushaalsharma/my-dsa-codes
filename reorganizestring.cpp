//leetcode 767

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26);
        int n = s.length(); 
        for(auto i : s){
            ++cnt[i - 'a'];
        }
        priority_queue<pair<int, char>> maxheap;
        for(int i=0;i<26;i++){
            if(cnt[i]>(n+1)/2){
                return "";
            }
            if(cnt[i]){
                maxheap.push({cnt[i],'a'+i});
            }
        }
        queue<pair<int,char>> q;
        string ans = "";
        while(!maxheap.empty() || q.size()>1){
            if(q.size() > 1){
                pair<int,char> p = q.front();
                q.pop();
                if(p.first != 0){
                    maxheap.push(p);
                }
            }
            if(!maxheap.empty()){
                pair<int,char> p = maxheap.top();
                maxheap.pop();
                ans += p.second;
                p.first--;
                q.push(p);
            }
        }
        return ans;
    }
};
