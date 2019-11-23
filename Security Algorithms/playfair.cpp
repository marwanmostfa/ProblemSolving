//This is an Algorithm For playfair Encryption
//1-it handles J as I
//When two characters are in the same row, you take the one on the right.
//When two characters are in the same column, you take the one below.
//If you end up with one letter, you append 'X' since it is slightly used in all languages and almost never coupled with another 'X'.
//When two characters are the same, You separate them with 'X'
//If you get two consecutive 'X' ('XX') you separate them by the second least used character which is 'Q'


#include <iostream>
using namespace std;
 
int main() {
	//get key and plaintext from User
	string key;
	cin>>key;
	string ptext;
	cin>>ptext;
	
	string ktmp="";
 
	//Initializing the Playfair Alphabetical Matrix
	int mat [5][5];
	int ind=0;
	for(int i=0;i<key.length();i++){
		int j;
		if(key[i]=='J'){
			key[i]='I';
		}
		for ( j=0; j<i; j++){  
	        if (key[i] == key[j]){ 
	           break;} 
		}
		if (j == i){
			ktmp += key[i];
        	   } 
	}
 
	string all="ABCDEFGHIKLMNOPQRSTUVWXYZ";
	
	ktmp += all;
	string mtr="";
	int it=0;
	for(int i=0;i<ktmp.length();i++){
		int j;
		for ( j=0; j<i; j++){  
	        if (ktmp[i] == ktmp[j]){ 
	           break;} 
		}
		if (j == i){
			mtr += ktmp[i];
        	   } 
	}
 
	for(int i=0; i<ptext.length();i++){
		if(ptext[i]=='J'){
 
			ptext[i]='I';
		}
	
	}
	
	int index=0;
	for(int i=0;i<5;i++){
		for(int j=0; j<5; j++){
			if(ktmp[index] != 'J'){
					mat[i][j]=int(mtr[index]);
			}
			index++;
		}
	}
 
	string temp= "";
	temp=temp+ptext[0];
	if(ptext.length()==1){
		if(ptext[0]=='X'){
			temp +='Q';
		}
		else{
			temp += 'X';
			}
	}
	if(ptext[0]==ptext[1] && ptext[0]=='X'){
		temp +='Q';
	}
	else if(ptext[0]==ptext[1] && ptext[0] !='X'){
		temp += 'X';
	}
	for(int i=1; i<ptext.length();i++){
		if(ptext[i]==ptext[i+1] && ptext[i] != 'X' && temp.length()%2==0){
			temp +=ptext[i] ;
			temp += 'X';
		}
		else if(ptext[i]==ptext[i+1] && ptext[i] == 'X' && temp.length()%2==0){
			temp +=ptext[i] ;
			temp += 'Q';
		}
		else{
			temp += ptext[i];
		}
		if((i+1) ==ptext.length() && temp.length() %2 !=0 && ptext[i] !='X'){
				temp += 'X';
		}
		else if((i+1) ==ptext.length() && temp.length() %2 !=0 && ptext[i] =='X'){
			temp += 'Q';
		}
	
	}
 
	string ans="";
	int itr=0;
	while (itr <temp.length()-1){
		int newl=0;
		int newu=0;
		int li;
		int ri;
		int lj;
		int rj;
		for(int i=0;i<5;i++){
			for(int j=0; j<5; j++){
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
			if(lj==4){
				newl=mat[li][0];
				newu=mat[li][rj+1];
			}
			else if(rj==4){
				newl=mat[li][lj+1];
				newu=mat[li][0];
			}
			else{
				newl=mat[li][lj+1];
				newu=mat[li][rj+1];
			}
		}
		else if(rj==lj){
			if(li==4){
				newl=mat[0][rj];
				newu=mat[ri+1][rj];
			}
			else if(ri==4){
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
	cout<<ans;
	return 0;
}
