class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> m;
        for(auto c:s){
            m[c]++;
        }
        priority_queue<char> pq;
        for(auto [ch,c]:m){
            pq.push(ch);
        }
        string ans;
        while(!pq.empty()){
            char ch=pq.top();
            pq.pop();
            int c=m[ch];
            int use=min(c,repeatLimit);
            ans.append(use,ch);
            m[ch]-=use;
            if(m[ch]>0 && !pq.empty()){
                char next=pq.top();
                pq.pop();
                ans.push_back(next);
                m[next]--;
                if(m[next]>0){
                    pq.push(next);
                }
                pq.push(ch);
            }
        }
        return ans;
        
    }
};
