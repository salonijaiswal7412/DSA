#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int digit_sum(int i) {
        int s = 0;
        while (i != 0) {
            s += i % 10;
            i /= 10;
        }
        return s;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<priority_queue<int, vector<int>, greater<int>>> pq(82);
        int ans = -1;
        
        for (int i : nums) {
            int temp = digit_sum(i);
            pq[temp].push(i);
            if (pq[temp].size() > 2) {
                pq[temp].pop();
            }
        }

        for (auto& i : pq) {
            if (i.size() == 2) {
                int f = i.top();
                i.pop();
                int s = i.top();
                ans = max(ans, f + s);
            }
        }
        return ans;
    }
};
