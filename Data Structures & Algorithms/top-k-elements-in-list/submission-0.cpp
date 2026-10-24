class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int , int> mp;
        int n = nums.size();
        for(int x : nums){
            mp[x]++;
        }
        vector<pair<int, int>> freq;
        for(auto it : mp){
            freq.push_back({it.second , it.first});
        }
        sort(freq.rbegin() , freq.rend());
        vector<int> ans;
        for(int i = 0 ; i < k ; i++){
            ans.push_back(freq[i].second);
        }
        return ans;

    }
};
