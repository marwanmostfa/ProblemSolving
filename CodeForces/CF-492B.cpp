#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

void swap(long* a, long* b)  
{  
    long t = *a;  
    *a = *b;  
    *b = t;  
}  
long partition (long arr[], long low, long high)  
{  
    long pivot = arr[high]; // pivot  
    long i = (low - 1); // Index of smaller element  
  
    for (long j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
void quickSort(long arr[], long low, long high)  
{  
    if (low < high)  
    {  
        long pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
} 
long maxSortedAdjacentDiff(long* arr, long n) 
{ 
    // Find maximum and minimum in arr[] 
    long maxVal = arr[0], minVal = arr[0]; 
    for (long i = 1; i < n; i++) { 
        maxVal = max(maxVal, arr[i]); 
        minVal = min(minVal, arr[i]); 
    } 
  
    // Arrays to store maximum and minimum values 
    // in n-1 buckets of differences. 
    long maxBucket[n - 1]; 
    long minBucket[n - 1]; 
    fill_n(maxBucket, n - 1,INT_MIN); 
    fill_n(minBucket, n - 1,INT_MAX); 
  
    // Expected gap for every bucket. 
    float delta = (float)(maxVal - minVal) / (float)(n - 1); 
  
    // Traversing through array elements and 
    // filling in appropriate bucket if bucket 
    // is empty. Else updating bucket values.  
    for (long i = 0; i < n; i++) { 
        if (arr[i] == maxVal || arr[i] == minVal) 
            continue; 
  
        // Finding index of bucket. 
        long index = (float)(floor(arr[i] - minVal) / delta); 
  
        // Filling/Updating maximum value of bucket 
        if (maxBucket[index] == INT_MIN) 
            maxBucket[index] = arr[i]; 
        else
            maxBucket[index] = max(maxBucket[index], arr[i]); 
  
        // Filling/Updating minimutm value of bucket 
        if (minBucket[index] == INT_MAX) 
            minBucket[index] = arr[i]; 
        else
            minBucket[index] = min(minBucket[index], arr[i]); 
    } 
  
    // Finding maximum difference between maximum value 
    // of previous bucket minus minimum of current bucket. 
    long prev_val = minVal; 
    long max_gap = 0; 
    for (long i = 0; i < n - 1; i++) { 
        if (minBucket[i] == INT_MAX) 
            continue; 
        max_gap = max(max_gap, minBucket[i] - prev_val); 
        prev_val = maxBucket[i]; 
    } 
    max_gap = max(max_gap, maxVal - prev_val); 
  
    return max_gap; 
} 
int main() {
	long arr[2];
	for(int i=0;i<2;i++){
		cin>>arr[i];
	}
	long n=arr[0];
	long l=arr[1];
	
	long* array=new long[n];
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
	
	quickSort(array,0,n-1);
	//long x = sizeof(array) / sizeof(array[0]); 
	long diff= maxSortedAdjacentDiff(array,n);
	double d=0.0;

	if(array[0]==0 && array[n-1]==l) d=(double)diff/2;
	else if(array[0] !=0 && array[n-1]==l){
		if(diff/2>=array[0]) d=(double)diff/2;
		else d=(double)array[0];
	}
	else if(array[0] ==0 && array[n-1]!=l){
		if(diff/2 >=(l-array[n-1])) d=(double)diff/2;
		else d=(double)(l-array[n-1]);
	}
	else{
		if((double)diff/2 >=array[0] && (double)diff/2>=(l-array[n-1])) d=(double)diff/2;
		else if((double)diff/2 >=array[0] && (double)diff/2 <(l-array[n-1]))  d=(double)(l-array[n-1]);
		else if((double)diff/2 <array[0] && (double)diff/2 >=(l-array[n-1]))  d=(double)array[0];
		else{
			if(array[0] >= (l-array[n-1])) d=(double)array[0];
			else d=(double)(l-array[n-1]);
		}
	}
	cout<<setprecision(16);
	cout<<d;
	return 0;
}
