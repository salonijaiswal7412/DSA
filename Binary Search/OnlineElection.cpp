class TopVotedCandidate {
public:
    vector<pair<int,int>> poll;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int maxVotes=0,leader=-1;
        unordered_map<int,int> m;
        int n=persons.size();
        poll.resize(n);
        for(int i=0;i<n;i++){
            m[persons[i]]++;
            if(m[persons[i]]>=maxVotes){
                maxVotes=m[persons[i]];
                leader=persons[i];
            }
            poll[i]={times[i],leader};

        }
        
    }
    
    int q(int t) {
        int l=0,h=poll.size()-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(poll[m].first<=t){
                l=m+1;
            }
            else h=m-1;
        }
        return poll[h].second;
        
    }
    
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
