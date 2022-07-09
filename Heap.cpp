#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
    //堆排序入口
    void mysort(vector<int>&nums){
        int n = nums.size();
        
        //先建堆，下标为i的节点的父节点下标为（i-1）/2
        //想要元素升序建立堆的时候使用大顶堆
        for(int i =n/2-1;i>=0;i--){
            headjust(nums,n,i);
        }

        //后排序
        for(int i = n-1;i>0;i--){
            swap(nums[i],nums[0]);
            headjust(nums,i,0);
        }
    }
    

    //调整堆
    void headjust(vector<int>&nums,int n,int i){
       int largest = i;
       int lson = i*2+1;
       int rson = i*2+2;

    if(lson<n && nums[largest]<nums[lson]){
         largest = lson;
    }
    if(rson<n && nums[largest]<nums[rson]){
        largest = rson;
    }

    if(largest!=i){
        swap(nums[largest],nums[i]);
        headjust(nums,n,largest);
    }
    }

};

int main(){
   vector<int>nums={56,14,89,25,3,2,4,67,89,10,100};
   Heap heap;
   heap.mysort(nums);
   for(int num:nums){
       cout<<num<<" ";
   }
   system("pause");
   return 0;
}
//0605