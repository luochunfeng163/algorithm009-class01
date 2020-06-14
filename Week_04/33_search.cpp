/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index=-1;
        int len=nums.size();
        int left=0;
        int right=len-1;
        bool left_serch=true;
        bool right_serch=true;
        for(;left<=right&&(left_serch||right_serch);)
        {
            if(nums[left]==target)
            {
                index=left;
                break;
            }
            if(nums[right]==target)
            {
                index=right;
                break;
            }
            if(nums[left]<target)
            {
                left++;
            }
            else{
                left_serch=false;
            }
            if(nums[right]>target)
            {
                right--;
            }
            else
            {
                right_serch=false;
            }
        }
        return index;
    }
};
