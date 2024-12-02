//memoization sc=o(n)+o(n*4)
class Solution {
  public:
    int f(int day,int last ,vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(dp[day][last]!=-1) return dp[day][last];
        if(day==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    maxi=max(maxi,arr[0][i]);
                }
            }
            return dp[day][last]=maxi;
            
        }
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                int point=arr[day][i]+f(day-1,i,arr,dp);
                maxi=max(maxi,point);
            }
        }
        return dp[day][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return f(n-1,3,arr,dp);
    }
};

//tabulation sc=o(n*4)
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,-1));
        
        dp[0][0]=max(arr[0][1],arr[0][2]);
        dp[0][1]=max(arr[0][0],arr[0][2]);
        dp[0][2]=max(arr[0][1],arr[0][0]);
        dp[0][3]=max(arr[0][1],max(arr[0][0],arr[0][2]));
        
        for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                dp[day][last]=0;
                for(int i=0;i<3;i++){
                    if(i!=last){
                        int p=arr[day][i]+dp[day-1][i];
                        dp[day][last]=max(p,dp[day][last]);
                    }
                }
            }
        }
        return dp[n-1][3];
    }
};

//space optimization o(4)
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,-1));
        vector<int> prev(4);
        prev[0]=max(arr[0][1],arr[0][2]);
        prev[1]=max(arr[0][0],arr[0][2]);
        prev[2]=max(arr[0][1],arr[0][0]);
        prev[3]=max(arr[0][1],max(arr[0][0],arr[0][2]));
        
        for(int day=1;day<n;day++){
            vector<int> temp(4);
            for(int last=0;last<4;last++){
                temp[last]=0;
                for(int i=0;i<3;i++){
                    if(i!=last){
                       temp[last]=max(temp[last],arr[day][i]+prev[i]);
                    }
                }
            }
            prev=temp;
        }
        return prev[3];
    }
};
