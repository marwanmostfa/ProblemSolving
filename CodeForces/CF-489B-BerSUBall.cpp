#include <iostream>
#include <bits/stdc++.h> 
using namespace std;  
  
// A utility function to swap two elements  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
 
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
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
 
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  
  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
int main() {
	int n;
	cin>>n;
	int* boys=new int[n];
	for(int i=0;i<n;i++){
		cin>>boys[i];
	}
	
	int m;
	cin>>m;
	int* girls=new int[m];
	for(int i=0;i<m;i++){
		cin>>girls[i];
	}
	
	quickSort(boys,0,n-1);
	quickSort(girls,0,m-1);
	int counter =0;
	
	if(n>m){
		int ind=0;
			for(int i=0; i<m;i++){
				for(int j=ind; j<n;j++){
					if(boys[j] ==girls[i] || abs(boys[j]-girls[i]) ==1 ){
						counter++;
						ind=j+1;
						break;
						}
					
						}
					}
			}
	else if(n<m) {
		int index=0;
		for(int i=0; i<n;i++){
				for(int j=index; j<m;j++){
					if(boys[i] ==girls[j] || abs(boys[i]-girls[j]) ==1 ){
						counter++;
						index=j+1;
						break;
					}
					
	}
		}
	
	}
	else{ 
		int v=0;
		for(int i=0; i<m;i++){
			for(int j=v; j<m;j++){
				if(boys[i] ==girls[j] || abs(boys[i]-girls[j]) ==1 ){
					counter++;
					v=j+1;
					break;
					}
	
				}
		}
		
	}
	cout<<counter;
	return 0;
}
