//Given the plaintext and the ciphertext produced using Playfair Cipher.Deduce the key
//consider that the English alphabets start with A and end with I.

#include<string>
#include<algorithm>
#include <iostream>
#include <bits/stdc++.h> 
 
using namespace std;
void permute(string str,string* s) 
{ 
    sort(str.begin(), str.end()); 
 
    long mn=0;
    do { 
       s[mn]=str;
       mn++;
    } while (next_permutation(str.begin(), str.end())); 
}  
 
int main() {
	string temp;
	cin>>temp;
	string c;
	cin>>c;
	string norm="ABCDEFGHI";
	string ans="";
	string finalans="";
	string* strarr=new string[362880];
	int mat[3][3];
	
	permute(norm,strarr);
 
	for(int u=0;u<362880;u++){
		int val=(int)strarr[u][0];
		int fu=0;
		// filling the key matrix
		for(int j=0;j<3;j++){
			for(int k=0; k<3; k++){
				mat[j][k]=(int)strarr[u][fu];
				fu++;
			}
		}
		ans="";
		int itr=0;
		while (itr <temp.length()-1){
			int newl=0;
			int newu=0;
			int li;
			int ri;
			int lj;
			int rj;
	
			for(int i=0;i<3;i++){
				for(int j=0; j<3; j++){
					if(int(temp[itr]) == mat[i][j]){
						li=i;
						lj=j;
					}
					if(int(temp[itr+1]) == mat[i][j]){
						ri=i;
						rj=j;
					}
				}
			}
			if(ri==li){
				if(lj==2){
					newl=mat[li][0];
					newu=mat[li][rj+1];
				}
				else if(rj==2){
					newl=mat[li][lj+1];
					newu=mat[li][0];
				}
				else{
					newl=mat[li][lj+1];
					newu=mat[li][rj+1];
				}
			}
			else if(rj==lj){
				if(li==2){
					newl=mat[0][rj];
					newu=mat[ri+1][rj];
				}
				else if(ri==2){
					newl=mat[li+1][rj];
					newu=mat[0][rj];
				}
				else{
					newl=mat[li+1][lj];
					newu=mat[ri+1][lj];
				}
			}
			else{
			if(rj>lj){
				newu=mat[ri][rj-(rj-lj)];
				newl=mat[li][lj+(rj-lj)];
			}
			else{
				newu=mat[ri][rj+(lj-rj)];
				newl=mat[li][lj-(lj-rj)];
			}
			}
		ans += char(newl);
		ans += char(newu);
		itr  +=2;
		newl=0;
		newu=0;
}
	
		if(ans==c){
			
			for(int w=0; w<3;w++){
				for(int o=0; o<3;o++){
					finalans += (char)mat[w][o];
				}
			}
			break;
		
		}
}
	cout<<finalans;	
	return 0;
