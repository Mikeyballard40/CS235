//**** YOU MAY NOT MODIFY THIS DOCUMENT ****/
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <vector>
#include "ExpressionManagerInterface.h"

using namespace std;

#define default_cap 100

class ExpressionManager : public ExpressionManagerInterface
{
private:
    string *expression;
    int first;
    int last;
    string *pp;
    vector<string> inFix;
    vector<string> postFix;
    vector<string> preFix;
    vector<string> priority;
    const string operators = "([{ -+  */% ";

public:
    ExpressionManager() :
        expression(new string[default_cap]), 
        pp(new string[default_cap]),
        inFix(), 
        first(0),
        last(0),
        postFix(), 
        preFix(), 
        priority() { }
    ~ExpressionManager() { 
        delete[] expression;
     }

    virtual void push_back(string item){
        cout << "last: " << last << "item: " << item << endl;
        expression[last] = item;
        cout << "expression[last]: " << expression[last] << endl;
        last++;
        cout << last << endl;
    }


	/** Return the integer value of the infix expression */
	virtual int value(void){

    };

	/** Return the infix items from the expression
		Throw an error if not a valid infix expression as follows:
		First check to see if the expression is balanced ("Unbalanced"),
		then throw the appropriate error immediately when an error is found
		(ie., "Missing Operand", "Illegal Operator", "Missing Operator") */
	virtual string infix(void){
        stringstream ss;
        int s1 = 0; //s1 = (, s2 = {, s3 = [;
        for (int i = 0; i < last; i++){
            cout << expression[i] << endl;

            if (expression[i] == "("){
                pp[s1] = "(";
                s1++;
            }else if (expression[i] == "{"){
                pp[s1] = "{";
                s1++;
            }else if (expression[i] == "["){
                pp[s1] = "[";
                s1++;
            }

            if(expression[i] == ")"){
                if(pp[s1] == "("){
                    s1--;
                }else if(pp[s1] == "{" || pp[s1] == "["){
                    return "Unbalanced";
                }
            }
            else if(expression[i] == "}"){
                if(pp[s1] == "{"){
                    s1--;
                }else if(pp[s1] == "(" || pp[s1] == "["){
                    return "Unbalanced";
                }
            }
            else if(expression[i] == "]"){
                if(pp[s1] == "["){
                    s1--;
                }else if(pp[s1] == "{" || pp[s1] == "("){
                    return "Unbalanced";
                }
            }
            else{
                ss << expression[i] << " ";
            }


        }
        last = 0;
        return ss.str();

    };

	/** Return a postfix representation of the infix expression */
	virtual string postfix(void){

    };

	/** Return a prefix representation of the infix expression */
	virtual string prefix(void){

    };

	/** Return the infix vector'd expression items */
	virtual string toString(void) const{
        stringstream iss;
        string item;
        for(int i = 0; i < last; i ++){
            iss << expression[i] << " ";

        }
        return iss.str();

    };
};
#endif	// EXPRESSION_INTERFACE_H