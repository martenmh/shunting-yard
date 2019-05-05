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
       int addedPresedence = 0;
        for(char& c : formulaString){
            
            switch(c){


                case '+':
                    presedenceCheck(2 + addedPresedence);
                    operatorStack.push(operatorStruct('+', 2 + addedPresedence));
                    break;


                case '-':
                    presedenceCheck(2  + addedPresedence);
                    operatorStack.push(operatorStruct('-', 2 + addedPresedence));
                    break;


                case '/':
                    presedenceCheck(3 + addedPresedence);
                    operatorStack.push(operatorStruct('/', 3 + addedPresedence));
                    break;

                case '*':
                    presedenceCheck(3 + addedPresedence);
                    operatorStack.push(operatorStruct('*', 3 + addedPresedence));
                    break;
                    

                case '^':
                    operatorStack.push(operatorStruct('^', 4 + addedPresedence));
                    break;
                
                case '(':
                    operatorStack.push(operatorStruct('(', 5));
                    addedPresedence = 4;
                    break;
                case ')':
                
                    while(!operatorStack.empty() && operatorStack.top().operatorChar != '('){
                        output.push(operatorStack.top().operatorChar);
                        operatorStack.pop();
                    }
                    
                    operatorStack.pop();

                    
                    addedPresedence = 0;
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
    cout << "Formula: ";
    string formulass;
    cin >> formulass;
    formula userFormula = formula(formulass);
    
    cout << "You entered: " << userFormula.formulaString << endl;
    cout << "Result: ";
    while(!userFormula.output.empty()){
        cout << userFormula.output.front();    
        userFormula.output.pop();
    }
    cout << endl;
    


}
