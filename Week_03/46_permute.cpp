/*
46. 全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;

    vector<vector<int>> permute(vector<int>& nums) {
        int  _length=nums.size();
        if(_length<=1)
        {
            result.push_back(nums);
            return result;
        }
        map<int,int> tmp;
        for(int i=0;i<_length;++i)
        {
            tmp[nums[i]];
        }
        Travetor(0,tmp,_length);
        return result;
    }

    void Travetor(int start, map<int,int>& nums,int n)
    {
        if(start==n&&tmp.size()==n)
        {
           // cout<<start<<": "<<n<<"\n";
            result.push_back(tmp);
            return;
        }
        map<int,int>::iterator inside_it =nums.begin();
        for(;inside_it!=nums.end();inside_it++)
        {
                 if(inside_it->second==0)
                  {
                     inside_it->second++;
                     tmp.push_back(inside_it->first);
                     Travetor(++start,nums,n); 
                     inside_it->second--;
                     start--;
                     tmp.pop_back();
                }
        } 
        
    }
};
