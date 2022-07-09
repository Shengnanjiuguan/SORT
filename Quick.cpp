//特点：时间O（nlogn）空间：O（logn）不稳定排序
//适用：广泛（最快）

#include<iostream>
#include<vector>
using namespace std;

class Quick{
 public:
    void mysort(vector<int>&nums,int start,int end)
    {
       if(start>=end){
           return ;
       }

       int left = start;
       int right = end;
       int temp = nums[left];

       while (left<right)
       {
           while (left<right && nums[right]>=temp)
           {
               right--;       
           }
           nums[left] = nums[right];
           while(left<right && nums[left]<=temp)
           {
               left++;
           }
           nums[right] = nums[left];
       }
       
       nums[left] = temp;
       mysort(nums,start,left-1);
       mysort(nums,left+1,end);
    }    

};

int main()
{
   vector<int>nums = {9,56,12,100,59,68,72,2,4,3};
   Quick quick;
   quick.mysort(nums,0,nums.size()-1);
   for(auto num:nums){
       cout<<num<<" ";
   }
   system("pause");
   return 0;
}
//0605
