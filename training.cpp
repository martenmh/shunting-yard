#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct operatorStruct{
    
    int presedence;
    char operatorChar;
    operatorStruct(char operatorCharIn, int presedenceIn){
        
        operatorChar = operatorCharIn;
        presedence = presedenceIn;
       
    }
};
struct formula{
    string formulaString;
    //string output;
    queue<char> output;
    stack<operatorStruct> operatorStack;

    void presedenceCheck(int presedenceIn){
        if(operatorStack.size() > 0){
            while(!operatorStack.empty() && operatorStack.top().presedence >= presedenceIn){
                output.push(operatorStack.top().operatorChar);
                operatorStack.pop();
            }
        }
    }

    formula(string formulaStr){
        
        formulaString = formulaStr;

        /* 
            Foreach character in the formula check what type of operator it is and push it in the operatorStack, 
            if it is an operand push it in the operandStack.
        */

        for(char& c : formulaString){
            
            switch(c){


                case '+':
                    presedenceCheck(2);
                    operatorStack.push(operatorStruct('+', 2));
                    break;


                case '-':
                    presedenceCheck(2);
                    operatorStack.push(operatorStruct('-', 2));
                    break;


                case '/':
                    presedenceCheck(3);
                    operatorStack.push(operatorStruct('/', 3));
                    break;


                case '*':
                    presedenceCheck(3);
                    operatorStack.push(operatorStruct('*', 3));
                    break;
                    

                case '^':
                    operatorStack.push(operatorStruct('^', 4));
                    break;
                    
                default:
                    output.push(c);
                    break;
            }
            
        }

        
        while(!operatorStack.empty()){
            output.push(operatorStack.top().operatorChar);
            operatorStack.pop();
        }

    }
    

};

int main(){
    
    formula userFormula = formula("3+4*2/4^2^3-5");
    
    cout << userFormula.formulaString << endl;
    while(!userFormula.output.empty()){
        cout << userFormula.output.front();    
        userFormula.output.pop();
    }
    cout << endl;
    


}
