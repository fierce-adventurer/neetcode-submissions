class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> ans;
        while(left < right){
            if(numbers[left] + numbers[right] == target) {
                ans = {left + 1 , right + 1};
                break;
            }
            else if(numbers[left] + numbers[right] < target) left++;
            else right--;

        }
        return ans;
    }
};
