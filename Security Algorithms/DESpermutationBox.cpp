//4 lines of input
//1-The first line consists of a single number S that represents the size of the output of the permutation box (4 ≤ S ≤ 256) 
//also S is a multiple of 4.
//2-S numbers in decimal format separated by spaces which represent the values inside the permutation box that represent the order i
//n which the output should be with respect to the input The values will be always within the size of the input (From 1 to N)
//3- single number N that represents the size of the input of the permutation box (4 ≤ N ≤ 64) also N is a multiple of 4
//4- contains N / 4 Hex characters that represent the input to the permutation box.

#include <iostream>
#include <sstream>
#include <bitset>
#include <string>
using namespace std;
 
int main() {
	int s;
	cin >> s;
	int* permutation = new int[s];
	for (int i = 0; i < s; i++) {
		cin >> permutation[i];
	}
	int n;
	cin >> n;
	string input;
	cin >> input;
	string binput = "";
	for (int i = 0; i < input.length(); i++) {
		stringstream ss;
		ss << hex << input[i];
		unsigned tt;
		ss >> tt;
		bitset<4> b(tt);
		binput += b.to_string();
	}
 
	int* out = new int[s];
	string op = "";
	for (int i = 0; i < s; i++) {
		out[i] = binput[permutation[i] - 1];
		char c = out[i];
		op += c;
	}
	stringstream ans;
	bitset<256> set(op);
	
	ans << hex << uppercase << set.to_ulong();
	cout << ans.str();
	return 0;
}
