class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans(spells.size(),0);

        for(int i=0;i<spells.size();i++){
            int l=0,r=potions.size()-1,idx=-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if((long long)potions[m]*spells[i]>=success){
                    idx=m;
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            if(idx!=-1){
                ans[i]=potions.size()-idx;
            }


        }
        return ans;
        
    }
};
