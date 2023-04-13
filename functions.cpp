#include "functions.h"
#include <iostream>
#include "queue.h"

int prec(char x){
  if (x == '^')
        return 3;
    else if (x == '/' || x == '*')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return -1;
}

bool checkParenthesis(string expression){
int p = 0;
int x = 0;
   for(int i = 0; i < expression.length(); i++){
     if (expression.at(i) == '('||expression.at(i) == '{'||expression.at(i) == '[') {p =p+1;}
     if (expression.at(i) == ')'||expression.at(i) == '}'||expression.at(i) == ']') {x =x+1;}
   }
  if (p==x){return true;}
  else {return false;}
}

bool isOp (char x){
  if (x == '-'|| x=='+' || x=='*' || x=='/'|| x== '^') return true;
else {return false;}
}

string inToPost(stack <char> x, string exp) {
string post;
  for(int i=0; i < exp.length(); i++) {

    //check if it's a variable (operand)
    if(((exp.at(i)>='a') && (exp.at(i)<='z'))||((exp.at(i)>='A')&&(exp.at(i)<='Z'))||( (exp.at(i) >= '0' && exp.at(i) <= '9'))) {post = post + exp.at(i);}
     

      //parenthesis checks 2 - error before here, before cout<<"here"
    
   if((exp.at(i)=='(')||(exp.at(i)=='{')||(exp.at(i)=='[')) {x.push(exp.at(i)); 
                                                             cout<<"here in paranthesis check"<<endl; }
    
  if((exp.at(i)==')')||(exp.at(i)=='}')||(exp.at(i)==']')){
     
      while(((x.top()!='(')||(x.top()!='{')||(x.top()!='['))&&(!x.empty())){
        char c = x.top();
        post = post + c; 
        x.pop();  
        
      }
   
      if ((!x.empty())&&((x.top() == '(') || (x.top()== '{') || (x.top()== '['))) {
         post = post + x.top();
        x.pop(); 
      
      }
      
    }
      
      //operator checks - working
    else if(isOp(exp.at(i))){
      if(x.empty()){
        x.push(exp.at(i));
      }
      else {
        if (prec(exp.at(i))> prec(x.top())){x.push(exp.at(i));}
        else if(prec(exp.at(i))==prec(x.top())&&(exp.at(i)=='^')){x.push(exp.at(i));}
        else {
          while ((!x.empty()) && (prec(exp.at(i))<= prec(x.top()))){
            char temp = x.top();
            post = post + temp;
            x.pop();
          }
          x.push(exp.at(i));
        }


        
      }
    
    
  }}//end of for loop
    //add operators onto postfix expression
  while (!x.empty()){
    post = post + x.top();
    x.pop();
  }
  
return post;
  }

char queueMenu(){
  cout<< "Pick a Queue option: "<<endl;
  cout<< "Enter 'A' to add an integer to the queue;"<<endl;
  cout<< "Enter 'E' to check if the queue is empty;"<<endl;
  cout<< "Enter 'D' to delete the next integer in the queue;"<<endl;
  cout<< "Enter 'V' to get the value of the first integer in the queue;"<<endl;
  cout<< "Enter 'N' to get the number of items in the queue;"<<endl;
  cout<< "Enter 'Q' to end the queue check"<<endl;
  char x;
  cin>>x;
  return toupper(x); }