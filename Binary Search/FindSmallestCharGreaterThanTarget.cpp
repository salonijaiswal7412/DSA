class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0,r=letters.size();
        char ans=' ';
        while(l<r){
            int m=l+(r-l)/2;
            if(letters[m]>target){
                ans=letters[m];
                r=m;
            }
            else l=m+1;
        }
        return ans==' '?letters[0]:ans;
        
    }
};
