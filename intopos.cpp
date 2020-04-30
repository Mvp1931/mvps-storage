#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
class intpos{

public:
	void intopos(string S);
	int prece(char K);
};

int prece(char K){

	if(K=='/')
		{return 4;}
	else if(K=='*')
		{return 3;}
	else if(K=='+')
		{return 2;}
	else if(K=='-')
		{return 1;}
	else
		{return -1;}

}

void intopos(string S){

	stack<char> ST;

	ST.push('N');
	int LEN=S.length();

	string NS;
//input the INorder Expression: one by one character!
	for(int J=0;J<LEN;J++){

		if((S[J]>='a' && S[J]<='z') || (S[J]>='A' && S[J]<='Z'))
		{
			NS=NS+S[J];
		}
		else{
			while(ST.top() != 'N' && prece(S[J])<=prece(ST.top())){

				char CH= ST.top();
				ST.pop();
				NS=NS+CH;
			}
			ST.push(S[J]);
		}
	}
//pop all expression elements one by one//print Postorder!
	while(ST.top() != 'N'){

		char CH = ST.top();
		ST.pop();
		NS=NS+CH;
	}

	cout<<NS<<endl;
}

int main(){

	string EXPR;

	cout<<"Enter your Inorder Expression!"<<endl;
	getline(cin,EXPR);

		cout<<"Your Postorder Expression is:";
	intopos(EXPR);
}
 5