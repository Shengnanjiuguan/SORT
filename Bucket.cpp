#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
using namespace std;

class Bucket
{
    public:
    void mysort(vector<int> &nums)
   {
       //（1）初始化桶
     int n = nums.size();
     vector<list<int>> buckets(n);
     
     //（2）数据放入桶并完成排序
     for (int num : nums)
    {
      int index = getBucketIndex(num);
      insertSort(buckets[index], num);
    }

    //（3）从桶取数据，放入nums
     int index = 0;
     for (list<int> bucket : buckets) 
    {
        for (int num : bucket)
      {
          nums[index] = num;
          index++;
      }
    }
    }

     //辅助函数一：获得桶的序号
    int getBucketIndex(int num)
   {
      return num / 3;
    }

    //辅助函数二：把数据插入对应桶(这里用的插入排序)
    void insertSort(list<int> &bucket, int num)
   {
     int n = bucket.size();
     bool flag = true;
     for (auto it = bucket.begin(); it != bucket.end(); it++)
    {
      if (num <= *it)
     {
        bucket.insert(it, num);
        flag = false;
        break;
      }
    }
   
      if (flag)
      bucket.push_back(num);
   }
};

int main()
{
vector<int> nums = {9, 7, 5, 3, 1, 0, 8, 4, 6, 2};
Bucket b;
b.mysort(nums);
for (int num : nums)
{
cout << num << " ";
}
system("pause");
return 0;
}