
//#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include "ExpressionManager.h"


using namespace std;




bool noparentheses(string top) {
	if (top == "[" || top == "(" || top == "{") {
		return false;
	}
	else {
		return true;
	}
}


bool isOperator(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
		return true;
	}
	else {
		return false;
	}
}


int getWeight(char ch) {
	switch(ch) {
		case '/': return 2;
		case '%': return 2;
		case '*': return 2;
		case '+': return 1;
		case '-': return 1;
		case ')': return 0;
		default: return 0;
	}
}



/*
	* Checks whether an expression is balanced on its parentheses
	*
	* - The given expression will have a space between every number or operator
	*
	* @return true if expression is balanced
	* @return false otherwise
	*/
bool ExpressionManager::isBalanced(string expression) {
	stack<char> mystack;

	for (int i = 0; i < expression.length(); i++) {
		if (expression.at(i) == '(' || expression.at(i) == '{' || expression.at(i) == '[') {
			mystack.push(expression.at(i));
		}

		else if (expression.at(i) == ')' || expression.at(i) == '}' || expression.at(i) == ']') {
			if (mystack.empty()) {
				return false;
			}
			else if (expression.at(i) == ')' && mystack.top() == '(') {
				mystack.pop();
			}
			else if (expression.at(i) == '}' && mystack.top() == '{') {
				mystack.pop();
			}
			else if (expression.at(i) == ']' && mystack.top() == '[') {
				mystack.pop();
			}
			else {
				return false;
			}
		}
	}


	if (!mystack.empty()) {
		return false;
	}

	return true;
}


	/**
	* Converts a postfix expression into an infix expression
	* and returns the infix expression.
	*
	* - The given postfix expression will have a space between every number or operator.
	* - The returned infix expression must have a space between every number or operator.
	* - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
	* - Check lab requirements for what will be considered invalid.
	*
	* return the string "invalid" if postfixExpression is not a valid postfix expression.
	* otherwise, return the correct infix expression as a string.
	*/
string ExpressionManager::postfixToInfix(string postfixExpression) {

	stack<string> mystack;
	stringstream ss;
	string s1;
	string s2;
	string s3;
	string result;
	string invalid = "invalid";
	string answer;

	if (!isBalanced(postfixExpression)) {
		return invalid;
	}


	else {

		for (int i = 0; i < postfixExpression.length(); i++) {
			
			result = "";
			ss.clear();

			if (postfixExpression.at(i) == ' ') {
				continue;
			}
			else if (isalpha(postfixExpression.at(i)) || postfixExpression.at(i) == '.') {
				return invalid;
			}

			else if (isdigit(postfixExpression.at(i))) {
				if (i < postfixExpression.length()-1) {
					if (isdigit(postfixExpression.at(i + 1))) {
						if (i < postfixExpression.length()-2) {
							if (isdigit(postfixExpression.at(i+2))) {
								s1 = postfixExpression.at(i);
								s2 = postfixExpression.at(i+1);
								s3 = postfixExpression.at(i+2);

								s1.append(s2);
								s1.append(s3);
								ss.clear();
								ss << s1;
								ss >> result;
								mystack.push(result);
								i+=2;
							}
							else {
								s1 = postfixExpression.at(i);
								s2 = postfixExpression.at(i+1);

								s1.append(s2);
								ss.clear();
								ss << s1;
								ss >> result;
								mystack.push(result);
								i++;
							}
						}
						else {
						s1 = postfixExpression.at(i);
						s2 = postfixExpression.at(i+1);

						s1.append(s2);
						ss.clear();
						ss << s1;
						ss >> result;
						mystack.push(result);
						i++;
						}
					}
					else {
						s1 = postfixExpression.at(i);
						ss.clear();
						ss << s1;
						ss >> result;
						mystack.push(result);
					}
				}
				else {
					ss.clear();
					ss << postfixExpression.at(i);
					ss >> result;
					mystack.push(result);
				}
				
			}

			else if (isOperator(postfixExpression.at(i))) {
				if (mystack.size() < 2) {
					return invalid;
				}

				else if (postfixExpression.at(i) == '+') {
					s2 = mystack.top();
					mystack.pop();
					s1 = mystack.top();
					mystack.pop();

					result.append("( ");
					result.append(s1);
					result.append(" + ");
					result.append(s2);
					result.append(" )");
					mystack.push(result);
				}
				else if (postfixExpression.at(i) == '-') {
					s2 = mystack.top();
					mystack.pop();
					s1 = mystack.top();
					mystack.pop();

					result.append("( ");
					result.append(s1);
					result.append(" - ");
					result.append(s2);
					result.append(" )");
					mystack.push(result);
				}
				else if (postfixExpression.at(i) == '*') {
					s2 = mystack.top();
					mystack.pop();
					s1 = mystack.top();
					mystack.pop();

					result.append("( ");
					result.append(s1);
					result.append(" * ");
					result.append(s2);
					result.append(" )");
					mystack.push(result);
				}
				else if (postfixExpression.at(i) == '/') {
					s2 = mystack.top();
					mystack.pop();
					s1 = mystack.top();
					mystack.pop();

					if (s2 == "0") {
						return invalid;
					}
					else {
						result.append("( ");
						result.append(s1);
						result.append(" / ");
						result.append(s2);
						result.append(" )");
						mystack.push(result);
					}
				}
				else if (postfixExpression.at(i) == '%') {
					s2 = mystack.top();
					mystack.pop();
					s1 = mystack.top();
					mystack.pop();

					result.append("( ");
					result.append(s1);
					result.append(" % ");
					result.append(s2);
					result.append(" )");
					mystack.push(result);
				}
			}		


	}
}

	if (mystack.size() == 1) {
		answer = mystack.top();
	}
	else {
		return invalid;
	}

	while (!mystack.empty()) {
		mystack.pop();
	}

	return answer;
}


	/*
	* Evaluates a postfix expression returns the result as a string
	*
	* - The given postfix expression will have a space between every number or operator.
	* - Check lab requirements for what will be considered invalid.
	*
	* return the string "invalid" if postfixExpression is not a valid postfix Expression
	* otherwise, return the correct evaluation as a string
	*/
string ExpressionManager::postfixEvaluate(string postfixExpression) {
	stack<int> mystack;
	string invalid = "invalid";
	int numOne;
	int numTwo;
	int result;
	stringstream ss;
	string answer;
	string charone = "";
	string chartwo = "";
	string charthree = "";


	while (!mystack.empty()) {
		mystack.pop();
	}

	if (!isBalanced(postfixExpression)) {
		return invalid;
	}

	for (int i = 0; i < postfixExpression.length(); i++) {
		numOne = 0;
		numTwo = 1;
		result = 0;
		ss.clear();

		if (postfixExpression.at(i) == ' ') {
			continue;
		}
		else if (isalpha(postfixExpression.at(i)) || postfixExpression.at(i) == '.') {
			return invalid;
		}

		else if (isdigit(postfixExpression.at(i))) {
			if (i < postfixExpression.length()-1) {
				if (isdigit(postfixExpression.at(i + 1))) {
					if (i < postfixExpression.length()-2) {
						if (isdigit(postfixExpression.at(i+2))) {
							charone = postfixExpression.at(i);
							chartwo = postfixExpression.at(i+1);
							charthree = postfixExpression.at(i+2);

							charone.append(chartwo);
							charone.append(charthree);
							ss.clear();
							ss << charone;
							ss >> result;
							mystack.push(result);
							i+=2;
						}
						else {
							charone = postfixExpression.at(i);
							chartwo = postfixExpression.at(i+1);

							charone.append(chartwo);
							ss.clear();
							ss << charone;
							ss >> result;
							mystack.push(result);
							i++;
						}
					}
					else {
					charone = postfixExpression.at(i);
					chartwo = postfixExpression.at(i+1);

					charone.append(chartwo);
					ss.clear();
					ss << charone;
					ss >> result;
					mystack.push(result);
					i++;
					}
				}
				else {
					charone = postfixExpression.at(i);
					ss.clear();
					ss << charone;
					ss >> result;
					mystack.push(result);
				}
			}
			else {
				ss.clear();
				ss << postfixExpression.at(i);
				ss >> result;
				mystack.push(result);
			}
			
		}

		else if (postfixExpression.at(i) == '+' || postfixExpression.at(i) == '-' || postfixExpression.at(i) == '*' || 
					postfixExpression.at(i) == '/' || postfixExpression.at(i) == '%') {
			if (mystack.size() < 2) {
				return invalid;
			}

			else if (postfixExpression.at(i) == '+') {
				numTwo = mystack.top();
				mystack.pop();
				numOne = mystack.top();
				mystack.pop();

				result = numOne + numTwo;
				mystack.push(result);
			}
			else if (postfixExpression.at(i) == '-') {
				numTwo = mystack.top();
				mystack.pop();
				numOne = mystack.top();
				mystack.pop();

				result = numOne - numTwo;
				mystack.push(result);
			}
			else if (postfixExpression.at(i) == '*') {
				numTwo = mystack.top();
				mystack.pop();
				numOne = mystack.top();
				mystack.pop();

				result = numOne * numTwo;
				mystack.push(result);
			}
			else if (postfixExpression.at(i) == '/') {
				numTwo = mystack.top();
				mystack.pop();
				numOne = mystack.top();
				mystack.pop();

				if (numTwo == 0) {
					return invalid;
				}
				else {
					result = numOne / numTwo;
					mystack.push(result);
				}
			}
			else if (postfixExpression.at(i) == '%') {
				numTwo = mystack.top();
				mystack.pop();
				numOne = mystack.top();
				mystack.pop();

				result = numOne % numTwo;
				mystack.push(result);
			}
		}

	}

	answer = to_string(mystack.top());

	if (mystack.size() > 1) {
		return invalid;
	}
	else {

		while (!mystack.empty()) {
			mystack.pop();
		}

		return answer;
	}

}




	/*
	* Converts an infix expression into a postfix expression
	* and returns the postfix expression
	*
	* - The given infix expression will have a space between every number or operator.
	* - The returned postfix expression must have a space between every number or operator.
	* - Check lab requirements for what will be considered invalid.
	*
	* return the string "invalid" if infixExpression is not a valid infix expression.
	* otherwise, return the correct postfix expression as a string.
	*/
string ExpressionManager::infixToPostfix(string infixExpression) {

	stack<char> mystack;
	stringstream ss;
	string invalid = "invalid";
	string postfix;
	string s1;
	string s2;
	string s3;
	string result;
	char ch;

/*	ss.clear();
	ss << infixExpression;
	ss >> ch;
	ss.clear();*/

	if (!isBalanced(infixExpression)) {
		return invalid;
	}

	else if (infixExpression.length() == 1 && !isdigit(infixExpression.at(0))) {
		return invalid;
	}


	else {

		for (int i = 0; i < infixExpression.length(); i++) {
			s1 = "";
			s2 = "";
			s3 = "";
			result = "";
			
			ss.clear();
			if (infixExpression.at(i) == ' ') {
				continue;
			}
			else if (isalpha(infixExpression.at(i)) || infixExpression.at(i) == '.') {
				return invalid;
			}


			else if (isdigit(infixExpression.at(i))) {
				if (i < infixExpression.length()-1) {
					if (isdigit(infixExpression.at(i + 1))) {
						if (i < infixExpression.length()-2) {
							if (isdigit(infixExpression.at(i+2))) {
								s1 = infixExpression.at(i);
								s2 = infixExpression.at(i+1);
								s3 = infixExpression.at(i+2);

								s1.append(s2);
								s1.append(s3);
								ss.clear();
								ss << s1;
								ss >> result;
								cout << "triple" << result << endl;

								postfix.append(result);
								postfix.append(" ");
								i+=2;
							}
							else {
								s1 = infixExpression.at(i);
								s2 = infixExpression.at(i+1);

								s1.append(s2);
								ss.clear();
								ss << s1;
								ss >> result;
								cout << "double" << result << endl;

								postfix.append(result);
								postfix.append(" ");
								i++;
							}
						}
						else {
						s1 = infixExpression.at(i);
						s2 = infixExpression.at(i+1);

						s1.append(s2);
						ss.clear();
						ss << s1;
						ss >> result;
						postfix.append(result);
						postfix.append(" ");
						i++;
						}
					}
					else {
						s1 = infixExpression.at(i);
						ss.clear();
						ss << s1;
						ss >> result;
						cout << "single1" << result << endl;

						postfix.append(result);
						postfix.append(" ");
					}
				}
				else {
					ss.clear();
					ss << infixExpression.at(i);
					ss >> result;
					cout << "single2" << result << endl;

					postfix.append(result);
					postfix.append(" ");
				}
				
			}

			else if (infixExpression.at(i) == '[' || infixExpression.at(i) == '(' || infixExpression.at(i) == '{') {
				mystack.push(infixExpression.at(i));
			}

			else if (infixExpression.at(i) == ']') {
				if (mystack.empty()) {
					return invalid;
				}
				else if (mystack.top() == '[') {
					mystack.pop();
				}				
				else {
					while (mystack.top() != '[') {
						ss.clear();
						ss << mystack.top();
						ss >> result;
						cout << "]" << result << endl;

						if (noparentheses(result)) {
							postfix.append(result);
							postfix.append(" ");
						}
						mystack.pop();
					}
					if (mystack.top() == '[') {
						mystack.pop();
					}
					else {
						return invalid;
					}
				}
			}
			else if (infixExpression.at(i) == ')') {
				if (mystack.empty()) {
					return invalid;
				}
				else if (mystack.top() == '(') {
					mystack.pop();
				}				
				else {
					while (mystack.top() != '(') {
						ss.clear();
						ss << mystack.top();
						ss >> result;
						cout << ")" << result << endl;

						if (noparentheses(result)) {
							postfix.append(result);
							postfix.append(" ");
						}
						mystack.pop();
					}
					if (mystack.top() == '(') {
						mystack.pop();
					}
					else {
						return invalid;
					}
				}
			}
			else if (infixExpression.at(i) == '}') {
				if (mystack.empty()) {
					return invalid;
				}
				else if (mystack.top() == '{') {
					mystack.pop();
				}
				else {
					while (mystack.top() != '{') {
						ss.clear();
						ss << mystack.top();
						ss >> result;
						cout << "}" << result << endl;

						if (noparentheses(result)) {
							postfix.append(result);
							postfix.append(" ");
						}
						mystack.pop();
					}
					if (mystack.top() == '{') {
						mystack.pop();
					}
					else {
						return invalid;
					}
				}
			}


			else if (mystack.empty() && isOperator(infixExpression.at(i))) {
				mystack.push(infixExpression.at(i));
			}
			else if (i < infixExpression.length() - 1 && isOperator(infixExpression.at(i)) &&
						 (isOperator(infixExpression.at(i + 2)) || infixExpression.at(i+2) == ')' ||
						  infixExpression.at(i+2) == '}' || infixExpression.at(i+2) == ']')){
				return invalid;
			}


			else if (!mystack.empty() && isOperator(infixExpression.at(i))) {
				while (!mystack.empty() && getWeight(infixExpression.at(i)) <= getWeight(mystack.top())) {
					result = "";
					ss.clear();
					ss << mystack.top();
					ss >> result;

					if (noparentheses(result)) {
						postfix.append(result);
						postfix.append(" ");
					}
					mystack.pop();
				}
				mystack.push(infixExpression.at(i));
			}

			else {
				return invalid;
			}
		}		
	}
	result = "";

	while (!mystack.empty()) {
		ss.clear();
		ss << mystack.top();
		ss >> result;

		if (noparentheses(result)) {
			postfix.append(result);
			postfix.append(" ");
		}
		mystack.pop();
	}

	if (!isBalanced(postfix)) {
		return invalid;
	}

	postfix = postfix.substr(0, postfix.length()-1);

	return postfix;
}














