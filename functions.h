#pragma once
#include <string>
#include <stack>
using namespace std;

bool checkParenthesis(string expression);
//Use this to make sure parenthesis are even and match up
string inToPost(stack <char> x, string exp);
//does conversion, something funny happening with parenthesis
bool isOp (char x);
//checks to see if the character is an operator or not
int prec(char x);
//checks precedence of operator
char queueMenu();