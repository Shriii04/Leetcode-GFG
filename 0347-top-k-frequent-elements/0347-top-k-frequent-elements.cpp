class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        map<int,int> mp;
    vector<int>ans;
    for(int i:arr){
        mp[i]++;
    }
    priority_queue<pair<int,int>>pq;
    for(auto i:mp){
        pq.push({i.second,i.first});
    }
    for(int i=0;i<k;i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
    }
};