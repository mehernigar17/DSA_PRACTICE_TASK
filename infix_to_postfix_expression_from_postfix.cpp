
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
    getline(cin, infix);

    for(int i = 0; i < infix.size(); i++){
        char symbol = infix[i];


        if(symbol == ' ')
            continue;

        if (isdigit(symbol)){
            while(i < infix.size() && isdigit(infix[i])){
                postfix += infix[i];
                i++;
            }
            postfix += ' ';
            i--;
        }

        else if (symbol == '(')
            s.push(symbol);

        else if (symbol == ')'){
            while(!s.empty() && s.top() != '('){
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.pop();
        }

        else{
            while(!s.empty() && priority(s.top()) >= priority(symbol)){
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(symbol);
        }
    }

    while (!s.empty()){
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }

    cout << "Postfix: " << postfix << endl;


    stack<int> val;

    for(int i = 0; i < postfix.size(); i++){

        if(isdigit(postfix[i])){
            int num = 0;
            while(i < postfix.size() && isdigit(postfix[i])){
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            val.push(num);
        }

        else if(postfix[i] == ' ')
            continue;

        else{
            int b = val.top(); val.pop();
            int a = val.top(); val.pop();
            int result;

            if(postfix[i] == '+') result = a + b;
            else if(postfix[i] == '-') result = a - b;
            else if(postfix[i] == '*') result = a * b;
            else if(postfix[i] == '/') result = a / b;

            val.push(result);
        }
    }

    cout << "Result: " << val.top() << endl;

    return 0;
}
