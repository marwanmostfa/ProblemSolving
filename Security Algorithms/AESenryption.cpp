/*Given a 128-bit key and a 128-bit plaintext. Perform AES Encryption for N times.

Input
The input consists of 3 lines. The first line contains 32 Hex characters which represent the 128-bit key. The second line contains 32 Hex characters which represent the 128-bit plaintext. The third line contains a single number N(0 ≤ N ≤ 50).

Output
The output should consist of a single line that contains 32 Hex characters(use capital letters) which represent the ciphertext obtained by applying AES encryption N times using the given key and plaintext.*/


#include <iostream>
#include <sstream>
#include <bitset>
#include <bits/stdc++.h>
#include<string.h>
using namespace std;
int hexaToDec(string hexVal) 
{    
    int len = hexVal.length();
    int base = 1; 
    int dec_val = 0; 
    for (int i=len-1; i>=0; i--) 
    {    
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        { 
            dec_val += (hexVal[i] - 48)*base; 
            base = base * 16; 
        } 
        else if (hexVal[i]>='A' && hexVal[i]<='F') 
        { 
            dec_val += (hexVal[i] - 55)*base; 
            base = base*16; 
        } 
    } 
      
    return dec_val; 
} 
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
void subByte(string text[],string**sbox,int size){
	for(int j=0;j<size;j++){
			string c="";
			string u="";
			c+=text[j][0];
			int x=hexaToDec(c);
			u +=text[j][1];
			int y=hexaToDec(u);
			text[j]=sbox[x][y];
	}
}
void keyExpansion(string key[],string w[],string rconj[],string **sbox){
	string temp="........,,,,,,,,";
	for(int i=0;i<4;i++){
		w[i]="";
		w[i]+=key[4*i];
		w[i]+=key[4*i+1];
		w[i]+=key[4*i+2];
		w[i]+=key[4*i+3];
	}
	for(int i=4;i<44;i++){
		temp=w[i-1];
		string ss[4]={};
		ss[0]+=temp[0];
		ss[0]+=temp[1];
		ss[1]+=temp[2];
		ss[1]+=temp[3];
		ss[2]+=temp[4];
		ss[2]+=temp[5];
		ss[3]+=temp[6];
		ss[3]+=temp[7];
		if(i%4==0){
			string sad[4]={};
			sad[0]=ss[1];
			sad[1]=ss[2];
			sad[2]=ss[3];
			sad[3]=ss[0];
			string tt=ss[0];
			ss[0]=ss[1];
			ss[1]=ss[2];
			ss[2]=ss[3];
			ss[3]=tt;
			subByte(sad,sbox,4);
			temp="";
			temp+=sad[0];
			temp+=sad[1];
			temp+=sad[2];
			temp+=sad[3];
			temp=HexToBin(temp);
			rconj[(i/4)-1]=HexToBin(rconj[(i/4)-1]);
			for(int o=0; o<32;o++){
				temp[o]= ((temp[o]-'0')^(rconj[(i/4)-1][o]-'0'))+'0';
			}
			temp=convertBinToHex(temp);
			rconj[(i/4)-1]=convertBinToHex(rconj[(i/4)-1]);
		}
		w[i-4]=HexToBin(w[i-4]);
		temp=HexToBin(temp);
		w[i]="";
		for(int k=0; k<32;k++){
				w[i] += (((w[i-4][k]-'0')^(temp[k]-'0'))+'0');
		}
		temp=convertBinToHex(temp);
		w[i-4]=convertBinToHex(w[i-4]);
		w[i]=convertBinToHex(w[i]);
			
	}
}
void shiftRows(string (&text)[16] ){
	string tmp=text[7];
	text[7]=text[4];
	text[4]=text[5];
	text[5]=text[6];
	text[6]=tmp;
	string tmp2=text[11];
	text[11]=text[9];
	text[9]=tmp2;
	tmp=text[10];
	text[10]=text[8];
	text[8]=tmp;
	string tmp3=text[12];
	text[12]=text[15];
	text[15]=text[14];
	text[14]=text[13];
	text[13]=tmp3;
}
void shiftStringLeft(string &str){
	for(int i=0;i<str.length()-1;i++){
		str[i]=str[i+1];
	}
	str[str.length()-1]='0';
}
string mult(string t,string c){
	string s1,s2;
				s1=HexToBin(t);
				s2=HexToBin(c);
				string temps[8];
				string toAns[8]={};
				temps[0]=s1;
				string multAns="";
				string toXor="00011011";
				string mm="55557777";
				int h=0;
				for(int j=1;j<8;j++){
					if(s1[0]=='0'){
						shiftStringLeft(s1);
						temps[j]=s1;
					}
				else{
					shiftStringLeft(s1);
					for(int k=0; k<8;k++){
							mm[k]= ((s1[k]-'0')^(toXor[k]-'0'))+'0';
						}
						temps[j]=mm;
						s1=mm;
					}
				}
				for(int j=0;j<8;j++){
					if(s2[j]=='1'){
						toAns[h]=temps[7-j];
						h++;
					}
				}
				if(h==0) multAns="00000000";
				else multAns=toAns[0];
				if(h>0){
					for(int j=1;j<h;j++){
						for(int k=0; k<8;k++){
							multAns[k]= ((toAns[j][k]-'0')^(multAns[k]-'0'))+'0';
						}
					}
				}
			return	multAns=convertBinToHex(multAns);
 
}
void mixCol(string (&text)[16]){
	string mat[16];
	string temp[16];
	mat[0]="02";
	mat[4]="01";
	mat[8]="01";
	mat[12]="03";
	mat[1]="03";
	mat[5]="02";
	mat[9]="01";
	mat[13]="01";
	mat[2]="01";
	mat[6]="03";
	mat[10]="02";
	mat[14]="01";
	mat[3]="01";
	mat[7]="01";
	mat[11]="03";
	mat[15]="02";
	
	string op1,op2,op3,op4;
	op1=HexToBin(mult(mat[0],text[0]));
	op2=HexToBin(mult(mat[1],text[4]));
	op3=HexToBin(text[8]);
	op4=HexToBin(text[12]);
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[0]=convertBinToHex(op1);
	
	op1=HexToBin(mult(mat[0],text[1]));
	op2=HexToBin(mult(mat[1],text[5]));
	op3=HexToBin(text[9]);
	op4=HexToBin(text[13]);
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[1]=convertBinToHex(op1);
	
	op1=HexToBin(mult(mat[0],text[2]));
	op2=HexToBin(mult(mat[1],text[6]));
	op3=HexToBin(text[10]);
	op4=HexToBin(text[14]);
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[2]=convertBinToHex(op1);
	
	op1=HexToBin(mult(mat[0],text[3]));
	op2=HexToBin(mult(mat[1],text[7]));
	op3=HexToBin(text[11]);
	op4=HexToBin(text[15]);
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[3]=convertBinToHex(op1);
	
	op1=HexToBin(text[0]);
	op2=HexToBin(mult(mat[0],text[4]));
	op3=HexToBin(mult(mat[1],text[8]));
	op4=HexToBin(text[12]);
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[4]=convertBinToHex(op1);
	
	op1=HexToBin(text[1]);
	op2=HexToBin(mult(mat[0],text[5]));
	op3=HexToBin(mult(mat[1],text[9]));
	op4=HexToBin(text[13]);
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[5]=convertBinToHex(op1);
	
	op1=HexToBin(text[2]);
	op2=HexToBin(mult(mat[0],text[6]));
	op3=HexToBin(mult(mat[1],text[10]));
	op4=HexToBin(text[14]);
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[6]=convertBinToHex(op1);
	
	op1=HexToBin(text[3]);
	op2=HexToBin(mult(mat[0],text[7]));
	op3=HexToBin(mult(mat[1],text[11]));
	op4=HexToBin(text[15]);
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[7]=convertBinToHex(op1);
	
	op1=HexToBin(text[0]);
	op2=HexToBin(text[4]);
	op3=HexToBin(mult(mat[0],text[8]));
	op4=HexToBin(mult(mat[1],text[12]));
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[8]=convertBinToHex(op1);
	
	op1=HexToBin(text[1]);
	op2=HexToBin(text[5]);
	op3=HexToBin(mult(mat[0],text[9]));
	op4=HexToBin(mult(mat[1],text[13]));
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[9]=convertBinToHex(op1);
	
	op1=HexToBin(text[2]);
	op2=HexToBin(text[6]);
	op3=HexToBin(mult(mat[0],text[10]));
	op4=HexToBin(mult(mat[1],text[14]));
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[10]=convertBinToHex(op1);
	
	op1=HexToBin(text[3]);
	op2=HexToBin(text[7]);
	op3=HexToBin(mult(mat[0],text[11]));
	op4=HexToBin(mult(mat[1],text[15]));
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[11]=convertBinToHex(op1);
	
	op1=HexToBin(mult(mat[1],text[0]));
	op2=HexToBin(text[4]);
	op3=HexToBin(text[8]);
	op4=HexToBin(mult(mat[0],text[12]));
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[12]=convertBinToHex(op1);
	
	op1=HexToBin(mult(mat[1],text[1]));
	op2=HexToBin(text[5]);
	op3=HexToBin(text[9]);
	op4=HexToBin(mult(mat[0],text[13]));
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[13]=convertBinToHex(op1);
	
	op1=HexToBin(mult(mat[1],text[2]));
	op2=HexToBin(text[6]);
	op3=HexToBin(text[10]);
	op4=HexToBin(mult(mat[0],text[14]));
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[14]=convertBinToHex(op1);
	
	op1=HexToBin(mult(mat[1],text[3]));
	op2=HexToBin(text[7]);
	op3=HexToBin(text[11]);
	op4=HexToBin(mult(mat[0],text[15]));
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op2[k]-'0'))+'0';
	}
	for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op3[k]-'0'))+'0';
	}
    for(int k=0; k<8;k++){
		op1[k]= ((op1[k]-'0')^(op4[k]-'0'))+'0';
	}
	temp[15]=convertBinToHex(op1);
	
	for(int t=0;t<16;t++){
		text[t]=temp[t];
	}
}
void addKey(string (&text)[16], string w[16]){
	for(int i=0;i<16;i++){
		string s1,s2;
		s1=HexToBin(text[i]);
		s2=HexToBin((w[i]));
		for(int j=0; j<8;j++){
			s1[j]=((s1[j]-'0')^(s2[j]-'0'))+'0';
		}
		text[i]=convertBinToHex(s1);
	}
}
 
int main() {
	string s1,s2;
	cin>>s2>>s1;
	int n;
	cin>>n;
	string ptext[16]={};
	string key[16]={};
	string Rconj[10];
	Rconj[0]="01000000";
	Rconj[1]="02000000";
	Rconj[2]="04000000";
	Rconj[3]="08000000";
	Rconj[4]="10000000";
	Rconj[5]="20000000";
	Rconj[6]="40000000";
	Rconj[7]="80000000";
	Rconj[8]="1B000000";
	Rconj[9]="36000000";
	int j=0;
	string** sbox = new string*[16];
	for (int i = 0; i < 16; ++i) 
	{
	     sbox[i] = new string[16];
	}
	sbox[0][0]="63";sbox[0][1]="7C";sbox[0][2]="77";sbox[0][3]="7B";
	sbox[0][4]="F2";sbox[0][5]="6B";sbox[0][6]="6F";sbox[0][7]="C5";
	sbox[0][8]="30";sbox[0][9]="01";sbox[0][10]="67";sbox[0][11]="2B";
	sbox[0][12]="FE";sbox[0][13]="D7";sbox[0][14]="AB";sbox[0][15]="76";
	
	sbox[1][0]="CA";sbox[1][1]="82";sbox[1][2]="C9";sbox[1][3]="7D";
	sbox[1][4]="FA";sbox[1][5]="59";sbox[1][6]="47";sbox[1][7]="F0";
	sbox[1][8]="AD";sbox[1][9]="D4";sbox[1][10]="A2";sbox[1][11]="AF";
	sbox[1][12]="9C";sbox[1][13]="A4";sbox[1][14]="72";sbox[1][15]="C0";
	
	sbox[2][0]="B7";sbox[2][1]="FD";sbox[2][2]="93";sbox[2][3]="26";
	sbox[2][4]="36";sbox[2][5]="3F";sbox[2][6]="F7";sbox[2][7]="CC";
	sbox[2][8]="34";sbox[2][9]="A5";sbox[2][10]="E5";sbox[2][11]="F1";
	sbox[2][12]="71";sbox[2][13]="D8";sbox[2][14]="31";sbox[2][15]="15";
	
	sbox[3][0]="04";sbox[3][1]="C7";sbox[3][2]="23";sbox[3][3]="C3";
	sbox[3][4]="18";sbox[3][5]="96";sbox[3][6]="05";sbox[3][7]="9A";
	sbox[3][8]="07";sbox[3][9]="12";sbox[3][10]="80";sbox[3][11]="E2";
	sbox[3][12]="EB";sbox[3][13]="27";sbox[3][14]="B2";sbox[3][15]="75";
	
	sbox[4][0]="09";sbox[4][1]="83";sbox[4][2]="2C";sbox[4][3]="1A";
	sbox[4][4]="1B";sbox[4][5]="6E";sbox[4][6]="5A";sbox[4][7]="A0";
	sbox[4][8]="52";sbox[4][9]="3B";sbox[4][10]="D6";sbox[4][11]="B3";
	sbox[4][12]="29";sbox[4][13]="E3";sbox[4][14]="2F";sbox[4][15]="84";
	
	sbox[5][0]="53";sbox[5][1]="D1";sbox[5][2]="00";sbox[5][3]="ED";
	sbox[5][4]="20";sbox[5][5]="FC";sbox[5][6]="B1";sbox[5][7]="5B";
	sbox[5][8]="6A";sbox[5][9]="CB";sbox[5][10]="BE";sbox[5][11]="39";
	sbox[5][12]="4A";sbox[5][13]="4C";sbox[5][14]="58";sbox[5][15]="CF";
	
	sbox[6][0]="D0";sbox[6][1]="EF";sbox[6][2]="AA";sbox[6][3]="FB";
	sbox[6][4]="43";sbox[6][5]="4D";sbox[6][6]="33";sbox[6][7]="85";
	sbox[6][8]="45";sbox[6][9]="F9";sbox[6][10]="02";sbox[6][11]="7F";
	sbox[6][12]="50";sbox[6][13]="3C";sbox[6][14]="9F";sbox[6][15]="A8";
	
	sbox[7][0]="51";sbox[7][1]="A3";sbox[7][2]="40";sbox[7][3]="8F";
	sbox[7][4]="92";sbox[7][5]="9D";sbox[7][6]="38";sbox[7][7]="F5";
	sbox[7][8]="BC";sbox[7][9]="B6";sbox[7][10]="DA";sbox[7][11]="21";
	sbox[7][12]="10";sbox[7][13]="FF";sbox[7][14]="F3";sbox[7][15]="D2";
	
	sbox[8][0]="CD";sbox[8][1]="0C";sbox[8][2]="13";sbox[8][3]="EC";
	sbox[8][4]="5F";sbox[8][5]="97";sbox[8][6]="44";sbox[8][7]="17";
	sbox[8][8]="C4";sbox[8][9]="A7";sbox[8][10]="7E";sbox[8][11]="3D";
	sbox[8][12]="64";sbox[8][13]="5D";sbox[8][14]="19";sbox[8][15]="73";
	 
	sbox[9][0]="60";sbox[9][1]="81";sbox[9][2]="4F";sbox[9][3]="DC";
	sbox[9][4]="22";sbox[9][5]="2A";sbox[9][6]="90";sbox[9][7]="88";
	sbox[9][8]="46";sbox[9][9]="EE";sbox[9][10]="B8";sbox[9][11]="14";
	sbox[9][12]="DE";sbox[9][13]="5E";sbox[9][14]="0B";sbox[9][15]="DB";
	  
	sbox[10][0]="E0";sbox[10][1]="32";sbox[10][2]="3A";sbox[10][3]="0A";
	sbox[10][4]="49";sbox[10][5]="06";sbox[10][6]="24";sbox[10][7]="5C";
	sbox[10][8]="C2";sbox[10][9]="D3";sbox[10][10]="AC";sbox[10][11]="62";
	sbox[10][12]="91";sbox[10][13]="95";sbox[10][14]="E4";sbox[10][15]="79";
	
	sbox[11][0]="E7";sbox[11][1]="C8";sbox[11][2]="37";sbox[11][3]="6D";
	sbox[11][4]="8D";sbox[11][5]="D5";sbox[11][6]="4E";sbox[11][7]="A9";
	sbox[11][8]="6C";sbox[11][9]="56";sbox[11][10]="F4";sbox[11][11]="EA";
	sbox[11][12]="65";sbox[11][13]="7A";sbox[11][14]="AE";sbox[11][15]="08";
	
	sbox[12][0]="BA";sbox[12][1]="78";sbox[12][2]="25";sbox[12][3]="2E";
	sbox[12][4]="1C";sbox[12][5]="A6";sbox[12][6]="B4";sbox[12][7]="C6";
	sbox[12][8]="E8";sbox[12][9]="DD";sbox[12][10]="74";sbox[12][11]="1F";
	sbox[12][12]="4B";sbox[12][13]="BD";sbox[12][14]="8B";sbox[12][15]="8A";
	
	sbox[13][0]="70";sbox[13][1]="3E";sbox[13][2]="B5";sbox[13][3]="66";
	sbox[13][4]="48";sbox[13][5]="03";sbox[13][6]="F6";sbox[13][7]="0E";
	sbox[13][8]="61";sbox[13][9]="35";sbox[13][10]="57";sbox[13][11]="B9";
	sbox[13][12]="86";sbox[13][13]="C1";sbox[13][14]="1D";sbox[13][15]="9E";
	
	sbox[14][0]="E1";sbox[14][1]="F8";sbox[14][2]="98";sbox[14][3]="11";
	sbox[14][4]="69";sbox[14][5]="D9";sbox[14][6]="8E";sbox[14][7]="94";
	sbox[14][8]="9B";sbox[14][9]="1E";sbox[14][10]="87";sbox[14][11]="E9";
	sbox[14][12]="CE";sbox[14][13]="55";sbox[14][14]="28";sbox[14][15]="DF";
	
	sbox[15][0]="8C";sbox[15][1]="A1";sbox[15][2]="89";sbox[15][3]="0D";
	sbox[15][4]="BF";sbox[15][5]="E6";sbox[15][6]="42";sbox[15][7]="68";
	sbox[15][8]="41";sbox[15][9]="99";sbox[15][10]="2D";sbox[15][11]="0F";
	sbox[15][12]="B0";sbox[15][13]="54";sbox[15][14]="BB";sbox[15][15]="16";
	
	string tp[16]={};
	string kp[16]={};
	
	for(int i=0;i<16;i++){
		tp[i]="";
		tp[i] +=s1[j];
		tp[i] +=s1[j+1];
		key[i]+=s2[j];
		key[i]+=s2[j+1];
		kp[i]+=s2[j];
		kp[i]+=s2[j+1];
		j=j+2;
	}
	 ptext[1]=tp[4]; ptext[2]=tp[8];
	 ptext[3]=tp[12]; ptext[4]=tp[1];
	 ptext[6]=tp[9]; ptext[7]=tp[13];
   	 ptext[8]=tp[2]; ptext[9]=tp[6];
	 ptext[11]=tp[14]; ptext[12]=tp[3];
	 ptext[13]=tp[7]; ptext[14]=tp[11];
	 ptext[0]=tp[0];
	 ptext[5]=tp[5];
	 ptext[10]=tp[10];
	 ptext[15]=tp[15];
	string words[44];
	keyExpansion(key,words,Rconj,sbox);
	key[1]=kp[4]; key[2]=kp[8];
	 key[3]=kp[12]; key[4]=kp[1];
	 key[6]=kp[9]; key[7]=kp[13];
   	 key[8]=kp[2]; key[9]=kp[6];
	 key[11]=kp[14]; key[12]=kp[3];
	 key[13]=kp[7]; key[14]=kp[11];
	 key[0]=kp[0];
	 key[5]=kp[5];
	 key[10]=kp[10];
	 key[15]=kp[15];
	
	if(n==0){
		cout<<s1;
	}
	else{
		string tempkey2[16]={};
		for(int j=0; j<n;j++){
			if(j>0){
				string hello[16]={};
				hello[1]=ptext[4]; hello[2]=ptext[8];
				 hello[3]=ptext[12]; hello[4]=ptext[1];
				 hello[6]=ptext[9]; hello[7]=ptext[13];
			   	 hello[8]=ptext[2]; hello[9]=ptext[6];
				 hello[11]=ptext[14]; hello[12]=ptext[3];
				 hello[13]=ptext[7]; hello[14]=ptext[11];
				 hello[0]=ptext[0];
				 hello[5]=ptext[5];
				 hello[10]=ptext[10];
				 hello[15]=ptext[15];
				 for(int yy=0; yy<16;yy++) ptext[yy]=hello[yy];
			}
			addKey(ptext, key);
			for(int i=0; i<9;i++){
				string t1=words[(i+1)*4];
				string t2=words[(i+1)*4+1];
				string t3=words[(i+1)*4+2];
				string t4=words[(i+1)*4+3];
				subByte(ptext,sbox,16);
				
				shiftRows(ptext);
			
				mixCol(ptext);
				
				string tempKey[16]={};
					tempKey[0] +=t1[0];
					tempKey[0] +=t1[1];
					
					tempKey[1] +=t2[0];
					tempKey[1] +=t2[1];
					
					tempKey[2] +=t3[0];
					tempKey[2] +=t3[1];
				
					tempKey[3] +=t4[0];
					tempKey[3] +=t4[1];
					
					tempKey[4] +=t1[2];
					tempKey[4] +=t1[3];
					
					tempKey[5] +=t2[2];
					tempKey[5] +=t2[3];
					
					tempKey[6] +=t3[2];
					tempKey[6] +=t3[3];
					
					tempKey[7] +=t4[2];
					tempKey[7] +=t4[3];
					
					tempKey[8] +=t1[4];
					tempKey[8] +=t1[5];
				
					tempKey[9] +=t2[4];
					tempKey[9] +=t2[5];
				
					tempKey[10] +=t3[4];
					tempKey[10] +=t3[5];
					
					tempKey[11] +=t4[4];
					tempKey[11] +=t4[5];
					
					tempKey[12] +=t1[6];
					tempKey[12] +=t1[7];
				
					tempKey[13] +=t2[6];
					tempKey[13] +=t2[7];
					
					tempKey[14] +=t3[6];
					tempKey[14] +=t3[7];
					
					tempKey[15] +=t4[6];
					tempKey[15] +=t4[7];
					
				addKey(ptext, tempKey);
					
			}
			string t1=words[40];
				string t2=words[41];
				string t3=words[42];
				string t4=words[43];
				string tempKey[16]={};
				tempKey[0] +=t1[0];
					tempKey[0] +=t1[1];
					
					tempKey[1] +=t2[0];
					tempKey[1] +=t2[1];
					
					tempKey[2] +=t3[0];
					tempKey[2] +=t3[1];
				
					tempKey[3] +=t4[0];
					tempKey[3] +=t4[1];
					
					tempKey[4] +=t1[2];
					tempKey[4] +=t1[3];
					
					tempKey[5] +=t2[2];
					tempKey[5] +=t2[3];
					
					tempKey[6] +=t3[2];
					tempKey[6] +=t3[3];
					
					tempKey[7] +=t4[2];
					tempKey[7] +=t4[3];
					
					tempKey[8] +=t1[4];
					tempKey[8] +=t1[5];
				
					tempKey[9] +=t2[4];
					tempKey[9] +=t2[5];
				
					tempKey[10] +=t3[4];
					tempKey[10] +=t3[5];
					
					tempKey[11] +=t4[4];
					tempKey[11] +=t4[5];
					
					tempKey[12] +=t1[6];
					tempKey[12] +=t1[7];
				
					tempKey[13] +=t2[6];
					tempKey[13] +=t2[7];
					
					tempKey[14] +=t3[6];
					tempKey[14] +=t3[7];
					
					tempKey[15] +=t4[6];
					tempKey[15] +=t4[7];
				subByte(ptext,sbox,16);
				shiftRows(ptext);
				addKey(ptext, tempKey);
				string op[16]={};
				op[1]=ptext[4]; op[2]=ptext[8];
	 op[3]=ptext[12]; op[4]=ptext[1];
	 op[6]=ptext[9]; op[7]=ptext[13];
   	 op[8]=ptext[2]; op[9]=ptext[6];
	 op[11]=ptext[14]; op[12]=ptext[3];
	 op[13]=ptext[7]; op[14]=ptext[11];
	 op[0]=ptext[0];
	 op[5]=ptext[5];
	 op[10]=ptext[10];
	 op[15]=ptext[15];
	 
	 for(int mm=0;mm<16;mm++) ptext[mm]=op[mm];
		}
		for(int mm=0;mm<16;mm++) cout<<ptext[mm];
	}
	return 0;
}  
