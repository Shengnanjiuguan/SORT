//基数排序：从低位开始分桶收集
//适用：max和min的差值不太大
#include<iostream>
#include<vector>
using namespace std;

class Radix{
    public:
    void mysort(vector<int>&nums,int d){
      int p = 1;
      int n = nums.size();

      vector<vector<int>>buckets(10,vector<int>(n));
      vector<int>order(10);

      while(p<d){
          //进行分桶
          for(int num:nums){
              int index = num/p%10;
              buckets[index][order[index]] = num;
              order[index]++;
          }

          //进行一轮排序
           int k = 0;
          for (int i = 0; i < 10; i++)
         {
            if (order[i] == 0) continue;
            for (int j = 0; j < order[i]; j++)
          {
              nums[k] = buckets[i][j];
              k++;
          }
            order[i] = 0; //各桶计数器清零
        }
        
          p *= 10;
      }
    
    }

};

int main(){
   vector<int>nums={999,765,780,215,13,66,230,450,599,21};
   Radix radix;
   radix.mysort(nums,1000);
   for(auto num:nums){
       cout<<num<<" ";
    }
   system("pause");
   return 0;
}
