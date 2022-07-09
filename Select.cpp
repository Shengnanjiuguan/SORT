//选择排序：找最小元素，放到最终位置，非稳定排序
#include<iostream>
#include<vector>
using namespace std;

class Select{
	public:
		void mysort(vector<int>&nums){
			int n = nums.size();
			for(int i = 0;i<n;i++)
            {
                int minPos = i;
                for(int j = i+1;j<n;j++)
                {
                    if(nums[j]<nums[minPos])
                    {
                        minPos = j;
                    }
                }
               // swap(nums[i],nums[minPos]);
               int temp = nums[i];
               nums[i] = nums[minPos];
               nums[minPos] = temp;
            }
		}
};

int main(){
	vector<int>nums={7,2,34,5,67,8,9,1};
	Select select;
	select.mysort(nums);
    for(auto num:nums)
    {
        cout<<num<<" ";
    }
    system("pause");
    return 0;
}