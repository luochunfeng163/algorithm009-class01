/*
在柠檬水摊上，每一杯柠檬水的售价为 5 美元。

顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

注意，一开始你手头没有任何零钱。

如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lemonade-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int reserve=0;
        map<int,int> tmp={ {5,0}, {10,0}, {20,0} };
        for(int i=0;i<bills.size();++i)
        {
            //cout<<"i: "<<i<<"tmp[5]:"<<tmp[5]<<"tmp[10]:"<<tmp[10]<<"bill:"<<bills[i]<<"\n";
            if(bills[i]-5-reserve>0)
            {
                return false;
            }
            reserve+=5;
            if(bills[i]== 5 )
            {
                tmp[5]++;
                continue;
            }
            if(bills[i]==10)
            {
                if(tmp[5]<1) return false;
                else
                {
                   tmp[5]--;
                   tmp[10]++;
                   continue;
                }      
            }    
            if(bills[i] == 20)
            {
               // cout<<"20 i:"<<i<<"\n";
                if(tmp[5]<1) return false;
                else if(tmp[5]<3&&tmp[10]<1) return false;
                else if(tmp[10]<1)
                {
                    tmp[5]-=3;
                    tmp[20]++;
                }
                else
                {
                    tmp[5]--;
                    tmp[10]--;
                    tmp[20]++;
                }
            }
        }
        return true;
    }
};
