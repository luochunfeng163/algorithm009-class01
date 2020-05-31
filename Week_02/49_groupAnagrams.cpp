/*
49. 字母异位词分组
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int lenth=strs.size();
        vector<vector<string>> result; 
        int result_index=0;  //结果vector的下标值
        string tmp; //临时string
        unordered_map<string,int> sortedResult;
         //判断排序后单词是否存在，即字母组成是否一致

         for(int i=0;i<lenth;++i)
         {
             tmp=strs[i];
             sort(tmp.begin(),tmp.end());
             if(sortedResult.count(tmp))
             {
                 result[sortedResult[tmp]].push_back(strs[i]);
             }
             else
             {
                 vector<string> new_tmp(1,strs[i]);
                 result.push_back(new_tmp);
                 sortedResult[tmp]=result_index++;
             }
         }
         return result;
    } 
};
