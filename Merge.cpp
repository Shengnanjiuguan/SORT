//归并排序
#include<iostream>
#include<vector>
using namespace std;

class Merge
{
    public:
    void mysort(vector<int>&nums,int left,int right)
    {
       if(left<right)
       {
           int  mid = left+(right-left)/2;
           mysort(nums,left,mid);
           mysort(nums,mid+1,right);
           merge(nums,left,right);
       }
       return ;
    }

    void merge(vector<int>&nums,int left,int right)
    {
        vector<int>temp(nums.size());
        int mid = left+(right-left)/2;
        int p = left;
        int q = mid+1;
        int k = left;
        while (p<=mid && q<=right)
        {
            /* code */
            if(nums[p]<nums[q])
            {
                temp[k++] = nums[p++];
            }else
            {
                temp[k++] = nums[q++];
            }
        }

        while(p<=mid)
        {
            temp[k++] = nums[p++];
        }
        while(q<=right){
            temp[k++]= nums[q++];
        }

        for(int i = left;i<=right;i++){
            nums[i] = temp[i];
        }
        
    }

};

int main()
{
   vector<int>nums = {5,8,9,5,6,2,4,8,56,100};
   Merge merge;
   merge.mysort(nums,0,nums.size()-1);
   for(auto num:nums)
   {
       cout<<num<<" ";
   }
   system("pause");
   return 0;
}