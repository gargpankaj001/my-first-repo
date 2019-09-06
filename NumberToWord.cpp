#include<iostream>
#include<string>
#include<vector>
using namespace std;

string getNumberName(int digit) {
	switch(digit) {
		case 1: return "one";
		case 2: return "two";
		case 3: return "three";
		case 4: return "four";
		case 5: return "five";
		case 6: return "six";
		case 7: return "seven";
		case 8: return "eight";
		case 9: return "nine";
		case 0: return "";
		default: return "";
			 break;
	}
}
string getNumberName(int dig1,int dig2) {
	if(dig1==1) {
		int num=dig1*10+dig2;
		switch(num) {
		case 10: return "ten";
		case 11: return "eleven";
		case 12: return "twelve";
		case 13: return "thirteen";
		case 14: return "fourteen";
		case 15: return "fifteen";
		case 16: return "sixteen";
		case 17: return "seventeen";
		case 18: return "eighteen";
		case 19: return "nineteen";
		default: return "";
			 break;
			}
	} else {
		string str="";
		switch(dig1) {
		case 2: str= "twenty"; break;
		case 3: str= "thirty"; break;
		case 4: str= "forty"; break;
		case 5: str= "fifty"; break;
		case 6: str= "sixty"; break;
		case 7: str= "seventy"; break;
		case 8: str= "eighty"; break;
		case 9: str= "ninety"; break;
		case 0: str= ""; break;
		default: str=""; break;
		}
		str=str+" "+getNumberName(dig2);
		return str;
	}
}
int main() {
	long int number,n,count=0;
	cout<<"Enter Number :";
	cin>>number;
	n=number;
	vector<int> v;
	while(n!=0) { v.push_back(n%10); count++; n=n/10; }
	string name[count+1];
	string words[]={"","","hundred","thousand","thousand","lack","lack","crore","crore","arab"};
	for(int i=0;i<count;i++) {
		if(i==1||i==4||i==6||i==8)
			name[i]=getNumberName(v[i],v[i-1]);
		else if(i==0 && count==1 || i==2 || i==3 && count==4 || i==5 && count==6 || i==7 && count==8 || i==9)
			name[i]=getNumberName(v[i]);

	}

	for(int j=count-1;j>-1;j--) {
		if(name[j]!="" && name[j]!=" ")
			cout<<" "<<name[j]<<" "<<words[j]<<" ";
	}

	return 0;
}
