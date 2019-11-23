//given a permutation box, print its inverse
include <iostream>
using namespace std;
int isRepeating(int arr[], int size) 
{ 
    int i, j; 
    int cnt=0; 
    for(i = 0; i < size; i++) {
        for(j = i + 1; j < size; j++) {
        if(arr[i] == arr[j]){ 
            cnt++ ;
            break;
        }
        }
    }
    return cnt;    
}  
int main() {
	int s;
	cin>>s;
	int* arr=new int[s];
	for(int i=0;i<s;i++){
		cin>>arr[i];
	}
	if(isRepeating(arr,s) != 0){
		cout<<"IMPOSSIBLE";
	}
	else{
	int* res=new int[s];
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			if(i+1==arr[j]){
				res[i]=j+1;
			}
		}
		cout<<res[i]<<" ";
	}
	}
	return 0;
}
