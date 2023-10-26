#include<iostream>
#include<vector>
using namespace std;
void sortArray(vector<int>arr)
{
    vector<int>ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]==0)
        {
            ans.push_back(arr[i]);
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]==1)
        {
            ans.push_back(arr[i]);
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]==2)
        {
            ans.push_back(arr[i]);
        }
    }
    
    for(auto x: ans)
    {
        cout<<x<<" ";
    }
    
}

int main()
{
    int n ;
    cin>>n;
    vector<int>arr{0,1,1,1,0,0,0,0,1,2,0,2,0,2,0,1,0,2,1};

    sortArray(arr);
    return 0;
}