class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        int l=0,r=0,ans=n;
        int a=0,b=0,c=0;
        vector<int> arr(3,0);
        for(char c:s){
            arr[c-'a']++;
        }
        if(*min_element(arr.begin(),arr.end())<k) return -1;

        while(r<n){
            if(s[r]=='a') a++;
            if(s[r]=='b') b++;
            if(s[r]=='c') c++;
            r++;

            if(a>arr[0]-k || b>arr[1]-k || c>arr[2]-k){
                if(s[l]=='a')a--;
                if(s[l]=='b') b--;
                if(s[l]=='c')c--;
                l++;
            }
            ans=min(ans,n-(r-l));
        }
        return ans;
    }
};
