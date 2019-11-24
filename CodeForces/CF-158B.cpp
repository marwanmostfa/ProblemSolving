//Taxi
#include <iostream>
using namespace std;
 
int main() {
	long long n;
	cin>>n;
	int* arr=new int[n];
	int sum=0;
	int fours=0;
	int threes=0;
	int twos=0;
	int ones=0;
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==4) fours++;
		else if(arr[i]==3) threes++;
		else if(arr[i]==2) twos++;
		else ones++;
	}
	sum=sum+fours;
	if(twos ==1) twos=1;
	else{
		if(twos%2==0){
			sum=sum+twos/2;
			twos=0;
		}
		else{
			sum=sum+(twos-1)/2;
			twos=1;
		}
	}
	
	if(threes==ones){
		sum=sum+threes+twos;
		threes=0;
		ones=0;
	}
	else if(threes>ones){
		sum=sum+ones;
		threes=threes-ones;
		sum=sum+threes+twos;
		threes=0;
		ones=0;
	}
	else{
		sum=sum+threes;
		ones=ones-threes;
		if(twos==1){
			if(ones<=2){
				sum=sum+1;
				ones=0;
				twos=0;
			}
			else{
				sum=sum+1;
				ones=ones-2;
				twos=0;
				if(ones<=4){
				sum=sum+1;
				ones=0;
			}
			else{
				if(ones%4==0){
					sum=sum+ones/4;
					ones=0;
				}
				else{
					sum=sum+1+ones/4;
					ones=0;
				}
			}
			}
			
		}
		else{
			if(ones<=4){
				sum=sum+1;
				ones=0;
			}
			else{
				if(ones%4==0){
					sum=sum+ones/4;
					ones=0;
				}
				else{
					sum=sum+1+ones/4;
					ones=0;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
