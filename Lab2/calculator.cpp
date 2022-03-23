#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;



struct Calculator{
    double num1;
    double num2;
    int operation;
    string opName;

    enum  Operation {Add = 1, Subtract = 2, Multiply =3, Divide=4, Sqrt=5 };
    Operation op;

    Calculator(double a, double b , int op){
        num1 = a;
        num2 = b;
        operation = op;

    }

    int calculate(double a, double b) {
        switch (operation) {
            case Add:
            opName = " plus "; 
            return a + b;
            break;

            case Subtract:
            opName = " minus ";
            return a-b;
            break;

            case Multiply:
            opName = " times ";
            return a*b;
            break;

            case Divide:
            opName = " divided by ";
            return a/b;
            break;

            case Sqrt:
            opName = "Sqrt of ";
            return sqrt(a);
            break;
            
            default:
            return -3;
            }
        }

 };


int main() {
    double num1, num2;
    int operation;
    int killSwitch = 0;
    ofstream out_stream;
    out_stream.open("output.txt"); // opening output file


    cout << "Choose an operation,\n for Add type 1, Subtract type 2, Multiply type 3, Divide type 4, Sqrt type 5 or 0 to Quit\n";
cin >> operation;
while ( operation != killSwitch){

    while (operation >5 || operation < 1 || cin.fail()){
        cin.clear();
        cin.ignore(256,'\n');

         cout << "invalid operation please choose again"<<endl;
        cin >> operation;
    }
    cout << "Please provide a number.\n";
    cin >> num1;
    while(cin.fail()){
        cout << "Please enter a number"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> num1;
    }
    if (operation != 5){
        cout << "Please provide another number.\n";
        cin >> num2;
        while(cin.fail()){
        cout << "Please enter a number"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> num2;
     }
     }

    Calculator calc(num1,num2,operation);
    float answer = calc.calculate(num1, num2);
    if (operation >= 1 && operation < 5){
        cout << num1 <<calc.opName << num2 << " is " << answer << endl;
    }
    if(operation >5 && operation < 1){
        cout << "You have submitted an invalid operation" <<endl;
    }
    if(operation == 5){
        cout << calc.opName << num1 << " is " << answer << endl;
    }

    cout << "Choose an operation,\n for Add type 1, Subtract type 2, Multiply type 3, Divide type 4, Sqrt type 5 or 0 to Quit\n";
    cin >> operation;



}

cout << "Goodbye"<<endl;
    

    
}

