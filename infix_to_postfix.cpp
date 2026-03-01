
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
    //getline(cin, infix);
    for(int i =0; i < infix.size(); i++){
        char symbol = infix[i];
        if (symbol >= '0' && symbol <= '9')
            postfix = postfix + symbol;
        else if (symbol == '(')
                    s.push(symbol);
        else if (symbol == ')')
        {
            while(!s.empty() && s.top() != '('){
                    postfix = postfix + s.top();
                    s.pop();
                  }
            s.pop();
        }
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
}
