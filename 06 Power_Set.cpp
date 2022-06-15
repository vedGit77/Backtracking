// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums,int i)
    {
        if(i == nums.size())  //base case.....DONT DO { i == nums.size() -1 }.....-1 not there because we are calling solve recursively for i+1...
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);  //the number is considered
        solve(ans,temp,nums,i+1);
        
        temp.pop_back();  //the number is not considered
        solve(ans,temp,nums,i+1);
    }
  
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int>temp;
        solve(ans,temp,nums,0);
        return ans;   
    }
};

