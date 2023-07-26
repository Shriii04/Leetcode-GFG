//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int a[], int N, int parent)  
    {
      // Your Code Here
      
      int largest,left,right;
    largest = parent;
    left = 2*parent+1;
    right =2*parent+2;

    if(left<N && a[left]>a[largest]){
        largest=left;
    }

    if(right<N && a[right]>a[largest]){
        largest=right;
    }

    if(parent!=largest){
        int temp =a[parent];
        a[parent]=a[largest];
        a[largest]=temp;
        heapify(a,N,largest);
      
    }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int a[], int N)  
    { 
    // Your Code Here
    
     for(int i=N/2-1;i>=0;i--){
        heapify(a,N,i);
    }
    }
    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int a[], int N)
    {
        //code here
        buildHeap(a,N);
        
        for(int i=N-1;i>=0;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }

        
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends