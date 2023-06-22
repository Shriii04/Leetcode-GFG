class Solution {
public:
    int inversions=0;
    int find_index_where_just_greater(int left,int right,vector<int>&arr,int target)
    {
        while(left<=right)
        {
            int mid=(left+right)/2;
            long long x=arr[mid];
            x*=2;
            if(x>=target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return (left-1);
    }
    void merge(vector<int>&arr,int l,int m,int r)
    {
        vector<int>Arr(r-l+1);
        int ptr1=l,ptr2=m+1,ptr3=0;
        while(ptr3<=(r-l))
        {
            if(ptr1==(m+1))
            {
                Arr[ptr3]=arr[ptr2];
                ptr2++;
                ptr3++;
                continue;
            }
            if(ptr2==(r+1))
            {
                int idx=find_index_where_just_greater(m+1,r,arr,arr[ptr1]);
                inversions+=idx-m;
                Arr[ptr3]=arr[ptr1];
                ptr1++;
                ptr3++;
                continue;
            }
            if(arr[ptr1]<=arr[ptr2])
            {
                int idx=find_index_where_just_greater(m+1,r,arr,arr[ptr1]);
                inversions+=idx-m;
                Arr[ptr3]=arr[ptr1];
                ptr1++;
                ptr3++;
            }
            else
            {
                Arr[ptr3]=arr[ptr2];
                ptr2++;
                ptr3++;
            }
        }
        for(int i=l;i<=r;i++)
        {
            arr[i]=Arr[i-l];
        }
        return;
    }
    void mergeSort(vector<int>&arr,int l,int r)
    {
        if(l==r)
        {
            return;
        }
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        return;
    }
    int reversePairs(vector<int>&nums) 
    {
        mergeSort(nums,0,nums.size()-1);
        return inversions;
    }
};