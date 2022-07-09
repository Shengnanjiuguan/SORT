//希尔排序
#include<iostream>
#include<vector>
using namespace std;

class Shell
{
    public:
    void mysort(vector<int>&nums){
    int n = nums.size();
    int tmp = 0;
	int gap = n / 2;
	while (gap>0)
	{
		for (int i = gap; i < n; i++)
		{
			tmp = nums[i];
			int j = i;
			while (j >= gap && tmp < nums[j - gap])   //采用直接插入排序
			{
				nums[j] = nums[j - gap];
				j -= gap;
			}
 
			nums[j] = tmp;
		}
 
		gap = gap / 2;
	}
        
    }
};

int main()
{
    vector<int>nums = {0,9,7,5,1,10,8,4,6,2};
    Shell shell;
    shell.mysort(nums);
    for(auto num:nums)
    {
        cout<<num<<" ";
    }
    system("pause");
    return 0;
}
//0605