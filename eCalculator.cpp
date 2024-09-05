#include <iostream>
using namespace std;


void displayMenu(){
    cout<< "welcome to eCalculator! What can I calculate for you? "<<endl;
    cout << "for addition press  + " << endl;
    cout << "for subtraction press  - " << endl;
    cout << "for multiplication press  * " << endl;
    cout << "for division press  / " << endl;
}

double calculate(double num1, double num2, char operatorSymbol){
    double result;
    
    switch(operatorSymbol){
        case '+':
            result = num1+num2;
            break;
            
        case '-':
            result = num1-num2;
            break;
        case '*':
            result = num1*num2;
            break;
        case '/':
            if(num2==0){
                cout<<"error: division by zero is not allowed."<< endl;
                return 1;
            }
            result = num1/num2;
            break;
            
        default:
            cout<<"error: invalid operator"<<endl;
    }
    
    return 0;    
}

bool askContinue(){
    string response;
     while(true){
        cout<< "do you want to perform another calculation? y/n: ";
        cin>>response;
        
        if (response== "y"){
            return true;
        } else if (response == "n" ) {
            return false;
        } else {
            cout << "Invalid response. Please enter 'y' for yes or 'n' for no." << endl;
        }
        
     }
}

void runCalculator(){
    char operatorSymbol;
    double num1,num2, result;
    bool keep = true;
    
    while(keep){
        displayMenu();
        
        cout<<"enter operator: ";
        cin>>operatorSymbol;
        
        cout<<"enter numbers: ";
        cin>>num1>>num2;
        
        result= calculate(num1, num2, operatorSymbol);
    if(operatorSymbol== '+' || operatorSymbol== '-' || operatorSymbol== '*' || (operatorSymbol== '/' && num2!= 0)) {
        cout<< "result: "<< result<<endl;
    }
    
    keep= askContinue();
    }
    
    cout<< "thanks for using eCalculator! see you next time."<<endl;
    
}

int main(){
    runCalculator();
    
    return 0;
}



