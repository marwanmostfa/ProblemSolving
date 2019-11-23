#include <iostream>
#include <sstream>
#include <bitset>
#include <bits/stdc++.h>
#include <string>
#include<vector>
#include <cmath> 
#define ull unsigned long long int 
 
using namespace std;
int decimalToBinary(int N) 
{ 
  
    // To store the binary number 
    ull B_Number = 0; 
    int cnt = 0; 
    while (N != 0) { 
        int rem = N % 2; 
        ull c = pow(10, cnt); 
        B_Number += rem * c; 
        N /= 2; 
  
        // Count used to store exponent value 
        cnt++; 
    } 
  
    return B_Number; 
} 
void createMap(unordered_map<string, char>* um)
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
 
	// length of string before '.' 
	int len_left = t != -1 ? t : l; 
	for (int i = 1; i <= (4 - len_left % 4) % 4; i++)
		bin = '0' + bin;
 
	// if decimal point exists     
	if (t != -1)
	{
		// length of string after '.' 
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
		// one by one extract from left, substring 
		// of size 4 and add its hex code 
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
string rotl(string str, int n) {
	string temp = str.substr(0, n);
	string news = "";
	for (int i = n; i < str.length(); i++) {
		news += str[i];
	}
	news += temp;
	return news;
}
int getRow(string str) {
	if (str == "00") return 0;
	else if (str == "01") return 1;
	else if (str == "10") return 2;
	else if (str == "11") return 3;
	else return -1;
}
int getCol(string str) {
	if (str == "0000") return 0;
	else if (str == "0001") return 1;
	else if (str == "0010") return 2;
	else if (str == "0011") return 3;
	else if (str == "0100") return 4;
	else if (str == "0101") return 5;
	else if (str == "0110") return 6;
	else if (str == "0111") return 7;
	else if (str == "1000") return 8;
	else if (str == "1001") return 9;
	else if (str == "1010") return 10;
	else if (str == "1011") return 11;
	else if (str == "1100") return 12;
	else if (str == "1101") return 13;
	else if (str == "1110") return 14;
	else if (str == "1111") return 15;
	else return -2;
}
int main() {
	vector<vector<int> > S1{ {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
							{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
							{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
							{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13} };
 
	vector<vector<int> > S2{ {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
							{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
							{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
							{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9} };
 
	vector<vector<int> > S3{ {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
 
							{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
 
							{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
 
							{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12} };
 
	vector<vector<int> > S4{ {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
 
							{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
 
							{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
 
							{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14} };
 
	vector<vector<int> > S5{ {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
 
							{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
 
							{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
 
							{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3} };
 
	vector<vector<int> > S6{ {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
 
							{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
 
							{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
 
							{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13} };
 
	vector<vector<int> > S7{ {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
 
							{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
 
							{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
 
							{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12} };
 
	vector<vector<int> > S8{ {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
 
							{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
 
							{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
 
							{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11} };
 
	int ePerm[48] = { 32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1 };
	int sPerm[32] = { 16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25 };
	int PC1[56] = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
	int PC2[48] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
	int rot[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
	int IP[64]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};
	int inverse[64]={40,8,48,16,56,24,64,32,39, 7 ,  47 ,   15  ,  55,   23  ,  63 ,  31,
            38,     6,   46,    14 ,   54 ,  22,    62,   30,
            37,     5,   45,    13,    53,   21,    61,   29,
            36,     4 ,  44 ,   12,   52 ,  20 ,   60 ,  28,
            35 ,    3  , 43  ,  11 ,   51  , 19  ,  59  , 27,
            34  ,   2   ,42   , 10  ,  50   ,18  ,  58   ,26,
            33   ,  1  , 41   ,  9   , 49  , 17   , 57  , 25};
	string key;
	cin >> key;
	string text;
	cin >> text;
	int nn;
	cin>>nn;
	if(nn==0){
		cout<<text;
	}
	else{
		for(int j=0; j<nn; j++){
	//convert text to binary
	string btext = "";
	for (int i = 0; i < text.length(); i++) {
		stringstream ss;
		ss << hex << text[i];
		unsigned tt;
		ss >> tt;
		bitset<4> b(tt);
		btext += b.to_string();
	}
 
	// permutate text initial permutation
	string temptext = "";
	for (int i = 0; i < 64; i++) {
		char c = btext[IP[i] - 1];
		temptext += c;
	}
	string bkey = "";
	for (int i = 0; i < key.length(); i++) {
		stringstream ss;
		ss << hex << key[i];
		unsigned tt;
		ss >> tt;
		bitset<4> b(tt);
		bkey += b.to_string();
	}
 
	// permutate key permutation choice 1
	string tempkey = "";
	for (int i = 0; i < 56; i++) {
		char c = bkey[PC1[i] - 1];
		tempkey += c;
	}
	string roundkey = "";
	string lperm = "";
	string rperm = "";
	string xorOp1 = "";
	string xorOp2 = "";
	
	string ltext = temptext.substr(0,32);
	string rtext = temptext.substr(32, 32);
	string rounds[16];
	for (int i = 0; i < 16; i++) {
		string lkey = tempkey.substr(0, 28);
		string rkey = tempkey.substr(28, 28);
		lkey = rotl(lkey, rot[i]);
		rkey = rotl(rkey, rot[i]);
		tempkey = lkey;
		tempkey += rkey;
		for (int k = 0; k < 48; k++) {
			char f = tempkey[PC2[k] - 1];
			roundkey += f;
		}
		rounds[i]=roundkey;
		roundkey="";
	}
	
	for (int i = 0; i < 16; i++) {
	
		// pass right half of text to expansion perm.
		for (int k = 0; k < 48; k++) {
			char c = rtext[ePerm[k] - 1];
			rperm += c;
		}
		//XORing key with output of expansion perm.
		for (int k = 0; k < 48; k++) {
			int l = rperm[k] - '0';
			int r = rounds[15-i][k] - '0';
			int val = l ^ r;
			char c = val + '0';
			xorOp1 += c;
		}
		//S-Box
		string sbits1[8] = { "" };
		sbits1[0]=xorOp1.substr(0,6);
		sbits1[1]=xorOp1.substr(6,6);
		sbits1[2]=xorOp1.substr(12,6);
		sbits1[3]=xorOp1.substr(18,6);
		sbits1[4]=xorOp1.substr(24,6);
		sbits1[5]=xorOp1.substr(30,6);
		sbits1[6]=xorOp1.substr(36,6);
		sbits1[7]=xorOp1.substr(42,6);
		string rbox = "";
 
		for (int w = 0; w <8; w++) {
			string row = "";
			string col = "";
			row += sbits1[w][0];
			row += sbits1[w][5];
			col += sbits1[w][1];
			col += sbits1[w][2];
			col += sbits1[w][3];
			col += sbits1[w][4];
			stringstream ss;
			int r = getRow(row);
			int c = getCol(col);
			if(w==0){
				int te=decimalToBinary(S1[r][c]);
			    ss<<setfill ('0') <<setw (4)<<te;
				rbox += ss.str();
			
			}
			else if(w==1){
				int te=decimalToBinary(S2[r][c]);
				ss<<setfill ('0') <<setw (4)<<te;
				rbox += ss.str();
				
			}
			else if(w==2){
				int te=decimalToBinary(S3[r][c]);
				ss<<setfill ('0') <<setw (4)<<te;
				rbox += ss.str();
			}
			else if(w==3){
				int te=decimalToBinary(S4[r][c]);
				ss<<setfill ('0') <<setw (4)<<te;
				rbox += ss.str();
				
			}
			else if(w==4){
				int te=decimalToBinary(S5[r][c]);
				ss<<setfill ('0') <<setw (4)<<te;
				rbox += ss.str();
				
			}
			else if(w==5){
				int te=decimalToBinary(S6[r][c]);
				ss<<setfill ('0') <<setw (4)<<te;
				rbox += ss.str();
			}
			else if(w==6){
				int te=decimalToBinary(S7[r][c]);
				ss<<setfill ('0') <<setw (4)<<te;
				rbox += ss.str();
			}
			else if(w==7){
				int te=decimalToBinary(S8[r][c]);
			    ss<<setfill ('0') <<setw (4)<<te;
				rbox += ss.str();
 
			}
			
		}
	
		//S_perm
		string op2 = "";
		for (int k = 0; k < 32; k++) {
			char c = rbox[sPerm[k] - 1];
			op2 += c;
		}
		//XORing output of S-perm with left half of text
		for (int k = 0; k <32; k++) {
			int l = ltext[k] - '0';
			int r = op2[k] - '0';
			int val = l ^ r;
			char c = val + '0';
			xorOp2 += c;
		}
 
		temptext = rtext;
		temptext += xorOp2;
		ltext = temptext.substr(0,32);
		rtext = temptext.substr(32,32);
		lperm = "";
		rperm = "";
		xorOp1 = "";
		xorOp2 = "";
		roundkey = "";
		rbox="";
	}
	ltext = temptext.substr(32,32);
	rtext = temptext.substr(0,32);
	temptext = ltext;
	temptext +=rtext;
	string fans = "";
	for (int i = 0; i < 64; i++) {
		char c = temptext[inverse[i] - 1];
		fans += c;
	}
	text=convertBinToHex(fans);
		}
	cout<<text;
	}
 	return 0;
  }
