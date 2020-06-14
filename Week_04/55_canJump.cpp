/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        int  longest=0;
        for(int i=0;i<len;++i)
        {
            if(i<=longest)
            {
                longest=max(longest,i+nums[i]);
                if(longest>=len-1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
