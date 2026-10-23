class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        vector<vector<string>> ans;
        unordered_map<string , vector<string>> mp;
        for(int i = 0 ; i < n ; i++){
            string key = s[i];
            sort(key.begin() , key.end());
            mp[key].push_back(s[i]);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;


    }
};
