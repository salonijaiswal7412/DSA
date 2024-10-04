class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long s=skill[0]+skill.back();
        long long ans=0;
        vector<pair<long,long>> m;
        int l=0,r=skill.size()-1;
        while(l<=r){
            int t=skill[l]+skill[r];
            if(t==s){
                m.push_back({skill[l],skill[r]});
                l++;
                r--;
            }
            else{
                return -1;
            }
        }
        for(auto i:m){
            ans+=(i.first*i.second);
        }
        return ans;

        
    }
};