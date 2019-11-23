//we take from user 3 inputs The first line contains the length of the key L(0 < L ≤ 104) L is guaranteed to be a perfect square
//The second line contains L numbers X(0 ≤ X ≤ 109) 
//which represent the key. You can use these numbers to form the key matrix of Hill Cipher.
//The last line contains the plaintext to encrypt. It is a single string that consists of at most 100 characters.
//Each character is a capital English alphabetical character
//output is the result of hill cipher encryption


#include <iostream>
#include<math.h>
using namespace std;
 
int main() {
	long long l;
	cin>>l;
	long long e= sqrt(l);
	long long** mat= new long long*[e];
	for(int i = 0; i < e; i++){
    	mat[i] = new long long[e];
	}
	
	for(int i=0;i<e;i++){
		for(int j=0; j<e; j++){
			cin>>mat[i][j];
		}
	}
	string s;
	cin>>s;
	if(s.length()%e==0) s=s;
	else{
		while (s.length()% e !=0){
			s=s+'X';
		}
	}
 
	long long** ansm= new long long*[e];
	for(int i = 0; i < e; i++){
    	ansm[i] = new long long[s.length()/e];
	}
	long long** ans= new long long*[e];
	for(int i = 0; i <e; i++){
    	ans[i] = new long long[s.length()/e];
	}
	long long c=0;
	for(int i=0;i<s.length()/e;i++){
		for(int j=0; j<e; j++){
			ansm[j][i]=(s[c])%26+65;
			c++;
		}
	}
	for(int i=0; i<e; i++){
		for(int j=0; j<s.length()/e; j++){
		long long sum=0;
		long long f=0;
		for(int p=0; p<e; p++){
			f=(mat[i][p]%26)*(ansm[p][j]%26);
			sum=(sum)+f; 
		}
		ans[i][j]=sum%26;
		}
	}
    	
	for(int i=0; i<s.length()/e; i++){
		for(int j=0; j<e; j++){
			cout<<char(ans[j][i]+65);
		}
	}
	return 0;
}
