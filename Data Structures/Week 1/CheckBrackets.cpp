#include <iostream>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;

/*struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};*/

int main() {
    //std::string text;
    //getline(std::cin, text);
    string text;
    cin>>text;
    std::stack <char> opening_brackets_stack;
    int balance = true;
    int i=0,a;
    char top;
    

    while(i<text.length())
		{
		    if (opening_brackets_stack.empty())
		    	a=i;
			if(text[i]=='['||text[i]=='{'||text[i]=='(')
				opening_brackets_stack.push(text[i]);
			else
			{
				if((text[i]==']'||text[i]=='}'||text[i]==')'))
				{
				 if(opening_brackets_stack.empty())
				{
					balance=false;
					break;
				}
				else
				{
					top=opening_brackets_stack.top();
					opening_brackets_stack.pop();
				    if(( top =='[' && text[i]!=']')||( top=='{' && text[i]!='}')||( top=='(' && text[i]!=')'))
				    {
				    	balance=false;
						break;
				    }
				}
				}
			}
				i+=1;
		}
    // Printing answer, write your code here

	if(balance && opening_brackets_stack.empty())
		cout<<"Success";
	else
	{
		if((i>=text.size()) &&!opening_brackets_stack.empty())
			cout<<a+1;
		else
			cout<<i+1;
	}
    return 0;
}
