/*Given 2 numbers in Hex format that represent 2 polynomials in GF(28) with m(x) = x8 + x4 + x3 + x + 1. Find the result of Adding and Multiplying those numbers. Note: Result of addition is the same as the result of subtraction.

Input
The input consists of 1 line that has 2 numbers, each of which consists of 2 Hex digits that represent the 2 given numbers as described above.

Output
In a single line print 2 numbers in Hex format(All characters must be capital), the first one should be the result of the addition of the given 2 numbers and the second is the result of multiplying them. These operations should be done in GF(28) with m(x) = x8 + x4 + x3 + x + 1.*/


#include <iostream>
#include <sstream>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
string HexToBin(string hexdec) 
{ 
    long int i = 0; 
	string Ans="";
    while (hexdec[i]) { 
  
        switch (hexdec[i]) { 
        case '0': 
            Ans += "0000"; 
            break; 
        case '1': 
            Ans += "0001"; 
            break; 
        case '2': 
            Ans += "0010"; 
            break; 
        case '3': 
            Ans += "0011"; 
            break; 
        case '4': 
            Ans += "0100"; 
            break; 
        case '5': 
            Ans += "0101"; 
            break; 
        case '6': 
            Ans += "0110"; 
            break; 
        case '7': 
            Ans += "0111"; 
            break; 
        case '8': 
            Ans += "1000"; 
            break; 
        case '9': 
            Ans += "1001"; 
            break; 
        case 'A': 
        case 'a': 
            Ans += "1010"; 
            break; 
        case 'B': 
        case 'b': 
            Ans += "1011"; 
            break; 
        case 'C': 
        case 'c': 
            Ans += "1100"; 
            break; 
        case 'D': 
        case 'd': 
            Ans += "1101"; 
            break; 
        case 'E': 
        case 'e': 
            Ans += "1110"; 
            break; 
        case 'F': 
        case 'f': 
            Ans += "1111"; 
            break; 
        default: 
            Ans="";
        } 
        i++; 
    } 
    
    return Ans;
} 
void createMap(unordered_map<string, char> *um) 
{ 
    (*um)["0000"] = '0'; 
    (*um)["0001"] = '1'; 
    (*um)["0010"] = '2'; 
    (*um)["0011"] = '3'; 
    (*um)["0100"] = '4'; 
    (*um)["0101"] = '5'; 
    (*um)["0110"] = '6'; 
    (*um)["0111"] = '7'; 
    (*um)["1000"] = '8'; 
    (*um)["1001"] = '9'; 
    (*um)["1010"] = 'A'; 
    (*um)["1011"] = 'B'; 
    (*um)["1100"] = 'C'; 
    (*um)["1101"] = 'D'; 
    (*um)["1110"] = 'E'; 
    (*um)["1111"] = 'F'; 
} 
string convertBinToHex(string bin) 
{ 
    int l = bin.size(); 
    int t = bin.find_first_of('.'); 
    int len_left = t != -1 ? t : l; 

    for (int i = 1; i <= (4 - len_left % 4) % 4; i++) 
        bin = '0' + bin; 
   
    if (t != -1)     
    { 

        int len_right = l - len_left - 1; 

        for (int i = 1; i <= (4 - len_right % 4) % 4; i++) 
            bin = bin + '0'; 
    } 

    unordered_map<string, char> bin_hex_map; 
    createMap(&bin_hex_map); 
      
    int i = 0; 
    string hex = ""; 
      
    while (1) 
    { 

        hex += bin_hex_map[bin.substr(i, 4)]; 
        i += 4; 
        if (i == bin.size()) 
            break; 

        if (bin.at(i) == '.')     
        { 
            hex += '.'; 
            i++; 
        } 
    } 

    return hex;     
} 
void shiftStringLeft(string &str){
	for(int i=0;i<str.length()-1;i++){
		str[i]=str[i+1];
	}
	str[str.length()-1]='0';
}
int main() {
	string s1,s2;
	cin>>s1>>s2;
	
	string dec1=HexToBin(s1);
	string dec2=HexToBin(s2);
	
	string sumString="33335555";
	for(int i=0; i<8;i++){
		sumString[i]=((dec1[i]-'0')^(dec2[i]-'0'))+'0';
	}
	
	sumString=convertBinToHex(sumString);
	string temps[8];
	string toAns[8]={};
	temps[0]=dec1;
	string multAns="";
	string toXor="00011011";
	string mm="55557777";
	int h=0;
	for(int i=1;i<8;i++){
		if(dec1[0]=='0'){
			shiftStringLeft(dec1);
			temps[i]=dec1;
		}
		else{
			shiftStringLeft(dec1);
			for(int i=0; i<8;i++){
				mm[i]= ((dec1[i]-'0')^(toXor[i]-'0'))+'0';
			}
			temps[i]=mm;
			dec1=mm;
			//mm="";
		}
	}
	//cout<<dec2<<" ";
	for(int i=i;i<8;i++){
		if(dec2[i]=='1'){
			toAns[h]=temps[7-i];
			h++;
			//cout<<temps[i]<<" ";
		}
	}
	multAns=toAns[0];
	if(h>0){
		for(int j=1;j<h;j++){
			for(int i=0; i<8;i++){
				multAns[i]= ((toAns[j][i]-'0')^(multAns[i]-'0'))+'0';
			}
			//cout<<j;
		}
	}
	//cout<<multAns;
	multAns=convertBinToHex(multAns);
	cout<<sumString<<" "<<multAns;
	return 0;
}
