class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        int n=s.size();
        priority_queue<pair<int,char>> pq;
        for(auto [ch,c]:m){
            if(c>(n+1)/2) return "";
            pq.push({c,ch});
        }
        string ans="";
        while(!pq.empty()){
            auto[cnt1,ch1]=pq.top();
            pq.pop();
            if(!ans.empty() && ch1==ans.back()){
                if(pq.empty()) break;

                auto [cnt2,ch2]=pq.top();
                pq.pop();
                ans+=ch2;
                cnt2--;
                if(cnt2) pq.push({cnt2,ch2});

                pq.push({cnt1,ch1});
            }
            else{
                ans+=ch1;
                cnt1--;
                if(cnt1) pq.push({cnt1,ch1});
            }
        }
        return ans;

        
    }
};