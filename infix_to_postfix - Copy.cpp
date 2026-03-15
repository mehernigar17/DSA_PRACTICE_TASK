
#include <bits/stdc++.h>

using namespace std;

stack<char> s;

int priority(char s){
    if(s == '^'){
        return 100;
    }
    else if (s == '*'|| s == '/'){
        return 50;
    }
    else if (s == '+'|| s == '-'){
        return 20;
    }
    else return 0;
}



int main(){



string infix, postfix = "";
    cin>>infix;
    for(int i =0; i < infix.size(); i++){
        char symbol = infix[i];
        //operand
        if (symbol >= 'A' && symbol <= 'Z')
            postfix = postfix + symbol;
            //left parenthesis
        else if (symbol == '(')
                    s.push(symbol);
                    //right parenthesis
        else if (symbol == ')')
        {
            while(!s.empty() && s.top() != '('){
                    postfix = postfix + s.top();
                    s.pop();
                  }
            s.push(symbol);
        }

        //operator
        else{
            while(!s.empty() && priority(s.top())>= priority(symbol)){
                postfix = postfix + s.top();
                    s.pop();
            }
            s.push(symbol);
        }
    }
        while (!s.empty()){
            postfix = postfix + s.top();
                    s.pop();
        }
        cout<<postfix<<endl;













return 0;
}
