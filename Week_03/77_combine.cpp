/*
77. 组合
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
https://leetcode-cn.com/problems/combinations/
*/
class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<vector<int>> combine(int n, int k) {
        if(n<=k)
        {
            for(int i=1;i<=n;i++)
            {
                tmp.push_back(i);  
            }
            result.push_back(tmp);
            return result;
        }
        Travetor(1, k,n,k);
        return result;
    }

    void Travetor(int start, int left_count,int n,int k)
        {
            if(n<=k)
            {
               return ;
            }
            if(left_count==0&&tmp.size()==k)
            {
                result.push_back(tmp);
                return;
            }
            for(int i=start;i<=n;++i)
            {
                tmp.push_back(i);
                int inside_left_count=left_count-1;
                Travetor(i+1,inside_left_count,n,k); 
                tmp.pop_back(); 
            }
        }
};

