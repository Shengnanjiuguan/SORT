#include<iostream>
#include<vector>
using namespace std;

void selectSort(vector<int>&vec)//不稳定排序
{
    int lens = vec.size();
    int minIndex = 0;
    
    for(int i = 0;i<lens;i++)
    {
       minIndex = i;
       for(int j = i+1;j<lens;j++)
       {
           if(vec[j]<vec[minIndex])
           {
               minIndex = j;
           }
       }
       swap(vec[i],vec[minIndex]);
    }
}

void print(vector<int>& nums)
 {
      for (auto i : nums) 
    {
       cout << i << " ";
    }
      cout << endl;
}

int main()
{
 vector<int>vec = { 10,9,1,4,2,3,6,7,5,5 };
 selectSort(vec);
 print(vec);
 system("pause");
 return 0; 
}