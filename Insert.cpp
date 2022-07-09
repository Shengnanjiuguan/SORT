#include<iostream>
#include<vector>
using namespace std;

class Insert{
    public:
    void mysort(vector<int>&nums){
       // int n = nums.size();
        for(int i = 1;i<nums.size();i++)
        {
           int pos = i-1;
           int cur = nums[i];
           while(pos>=0 && cur<nums[pos])
           {
               nums[pos+1] = nums[pos];
               pos--;
           }
           nums[pos+1] = cur;
        }
    }
};

int main()
{
   vector<int>nums = {5,8,9,5,6,2,4,8,56,100};
   Insert insert;
   insert.mysort(nums);
   for(auto num:nums)
   {
       cout<<num<<" ";
   }
   system("pause");
   return 0;
}