//space O(2N)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n),right(n);
        left[0]=1,right[n-1]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
            else{
                left[i]=1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }
            else{
                right[i]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(left[i],right[i]);
        }
        return ans;
    }
};

//space O(1)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans=1;
        int i=1,n=ratings.size();
        while(i<n){
            
            if(ratings[i]==ratings[i-1]){
                ans+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak+=1;
                ans+=peak;
                i++;
            }
            int down=0;
            while(i<n && ratings[i]<ratings[i-1]){
                down+=1;
                ans+=down;
                i++;
            }
            down++;
            if(down>peak){
                ans+=(down-peak);
            
            }

        }
        return ans;
        
    }
};
