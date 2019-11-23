#include <iostream>
//#include <bits/stdc++.h>
#include <vector>
#include <sstream>
#include <bitset>
#include <string>
using namespace std;
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
 
 
	string s;
	cin >> s;
	string binput = "";
	for (int i = 0; i < s.length(); i++) {
		stringstream ss;
		ss << hex << s[i];
		unsigned n;
		ss >> n;
		bitset<4> b(n);
		binput += b.to_string();
	}
	//1- divide binput to 8 blocks of 6 bits each
	//2- each block is passed to Sn in order
	//3- first and last bits of the 6 bits are the offset to the row of Sn vector
	//4- the 4 middle bits are the offset to the columns in Sn vector
	//5- get the element in the(row,column) position in hexadecimal for each block of binput
	//6- concatenate the 8 hexadecimals
	string sbits[8] = { "" };
	int values[8];
	for (int i = 0; i < 8; i++) {
		string row = "";
		string col = "";
		for (int j = i * 6; j < (i * 6 + 6); j++) {
			sbits[i] += binput[j];
		}
		
		row += sbits[i][0];
		row += sbits[i][5];
		col += sbits[i][1];
		col += sbits[i][2];
		col += sbits[i][3];
		col += sbits[i][4];
		
		int r = getRow(row);
		int c = getCol(col);
		
		if (i == 0) {
			values[0] = S1[r][c];
		}
		else if (i == 1) values[1] = S2[r][c];
		else if (i == 2) values[2] = S3[r][c];
		else if (i == 3) values[3] = S4[r][c];
		else if (i == 4) values[4] = S5[r][c];
		else if (i == 5) values[5] = S6[r][c];
		else if (i == 6) values[6] = S7[r][c];
		else if (i == 7) values[7] = S8[r][c];
	}
	string ans = "";
	for (int i = 0; i < 8; i++) {
		stringstream ss;
 
		ss << hex << uppercase << values[i];
		
		ans += ss.str();
	}
	cout << ans;
	return 0;
}
