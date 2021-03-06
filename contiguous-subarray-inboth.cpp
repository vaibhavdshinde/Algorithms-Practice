// CPP program to find longest contiguous
// subset in binary representation of given
// two numbers n and m
#include <bits/stdc++.h>
using namespace std;

int mx = -INT_MAX; // maximum length
string res; // final resultant string

// utility function which convert
// decimal number to its binary representation
string convertToBinary(int n){
	string temp;
	while(n>0){
		int rem = n%2;
		temp.push_back(48+rem);
		n=n/2;
	}
	reverse(temp.begin(),temp.end());
	return temp;
}

// utility function to check all the
// substrings and get the longest substring
void getString(string s1, string s2){
	int len = s1.length();
	int n = len;

	// for every substring of s1, 
	// check if its length is greater than
	// previously found string 	
	// and also it is present in string s2
	while(len > 0){
		for(int i=0; i<n-len+1; i++){
			string temp = s1.substr(i,len);
			// cout<<"temp :: "<<temp<<endl;
			int tlen = temp.length();
			if(tlen > mx && s2.find(temp) != string::npos){
				 res = temp;
				 mx = tlen;
			}
		}
		len = len - 1;
	}
}

// utility function which returns 
// decimal value of binary representation
int getDecimal(string s){
	int len = s.length();
	int ans = 0;
	int j = 0;
	for(int i = len-1; i>=0; i--){
		if(s[i] == '1') ans += pow(2,j);
		j+=1; 
	}
	return ans;
}

// driver program
int main(){
	int n,m;
	n = 8;
	m = 16;
	string s1 = convertToBinary(n);
	string s2 = convertToBinary(m);
	if(n == 0)s1.push_back('0');
	if(m == 0) s2.push_back('0');
	getString(s1,s2);
	 cout<<"longest string :: "<<res<<endl;
	 int ans = getDecimal(res);
	if(res != "")cout<<"decimal value  :: "<<ans<<endl;
	return 0;
}