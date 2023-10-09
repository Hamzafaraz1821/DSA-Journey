//
// Created by hamza on 06/10/2023.
//


#include<iostream>
#include<variant>
#include<string>
#include<cmath>
using namespace std;

//
class stack{
private:
    struct node{
        variant<double,char> data;
        node* next;
        node* prev;

        node(){
            next = nullptr;
            prev = nullptr;
        }
    };

    node* headPtr;
    node* tailPtr;
public:
    stack(){
        headPtr = nullptr;
        tailPtr = nullptr;
    }

    node* getHeadPtr(){
        return headPtr;
    }
    bool isEmpty();
    void push(variant<double,char>);
    variant<double,char> pop();
    variant<double,char> popFromTail();
    void displayAll();

};

void stack::push(variant<double,char> val){

    node* newNode = new node;
    if(headPtr == nullptr){
        headPtr = newNode;
        tailPtr = newNode;
    }

    newNode->data = val;
    newNode->next = headPtr;
    newNode->prev = tailPtr;

    headPtr->prev = newNode;
    tailPtr->next = newNode;

    headPtr = newNode;
}

variant<double,char> stack::pop(){
        node* temp =  headPtr;

        if(headPtr == nullptr){
            cout << endl << "UnderFlow";
        }

        variant<double,char> data = temp->data;

        if(headPtr == tailPtr){
            headPtr = nullptr;
            tailPtr = nullptr;

        }else{
            headPtr = temp->next;
            headPtr->prev = tailPtr;
            tailPtr->next = headPtr;
        }

        delete temp;
        return data;
}

variant<double,char> stack::popFromTail(){
        node* temp =  tailPtr;

        if(headPtr == nullptr){
            cout << endl << "UnderFlow";
        }

        variant<double,char> data = temp->data;

        if(headPtr == tailPtr){
            headPtr = nullptr;
            tailPtr = nullptr;

        }else{
            tailPtr = temp->prev;
            tailPtr->next = headPtr;
            headPtr->prev = tailPtr;
        }

        delete temp;
        return data;
}

bool stack::isEmpty() {
    if(headPtr == nullptr){
        return true;
    }
    return false;
}

void stack::displayAll() {
    node* current = tailPtr;


    if(headPtr == nullptr){
        cout << endl << "The stack is empty";
        return;
    }

    do {
        visit([](const auto& value) {
            cout << value << " ";
        }, current->data);

        current = current->prev;
    }while(current!=tailPtr);
}

class infixToPostfixConvertor : public stack{


public:

    void infixToPostfix(string expression){
        push('(');
        expression+=')';
        string number;

        for(char i: expression) {

            if (isOperand(i)) {
                number += i;

            } else if (isOperator(i)) {
                try {
                    double value = stod(number);
                    number = "";
                    stack1.push(value);
                } catch (const std::invalid_argument& e) {}
                variant<double, char> value1 = getHeadPtr()->data;
                while (checkPrecedence(get<char>(value1), i)) {
                    stack1.push(pop());

                    value1 = getHeadPtr()->data;
                }
                push(i);

            } else {
                if (i == '(') {
                    push(i);
                }
                else if (i == ')') {
                    try{
                        double num = stod(number);
                        number = "";
                        stack1.push(num);
                    }catch(const std::invalid_argument& e){}
                    variant<double, char> value1 = getHeadPtr()->data;
                    while (get<char>(value1) != '(') {
                        stack1.push(pop());
                        value1 = getHeadPtr()->data;
                    }
                    pop();
                }
            }

        }
    }

    double calculate(){

        variant<double,char> i = stack1.popFromTail();

        do{

            if(holds_alternative<double>(i)){
                push(get<double>(i));
            }else if(holds_alternative<char>(i)){
                variant<double,char> value2 = pop();
                variant<double,char> value1 = pop();

                double afterOperation = applyOperation( get<double>(value1) ,get<double>(value2) , get<char>(i));


                cout << endl << get<double>(value1) << " " << get<double>(value2) << " After Operation "<< afterOperation << " operator " << get<char>(i);

                push(afterOperation);
                cout << endl;
                displayAll();
            }

            if(stack1.isEmpty()){
                break;
            }
            i = stack1.popFromTail();


        }while(stack1.isEmpty() || holds_alternative<char>(i) || holds_alternative<double>(i));

        variant<double,char> result = pop();
        return get<double>(result);
    }



    void displayInfixtoPostfix() {
        stack1.displayAll();
    }

private:
    string postfix;
    stack stack1;


    // function to check if it is operand or not
    static bool isOperand(char i){
        if(i == '(' || i == ')' || i == '+' || i == '-' || i =='*' || i == '/' || i == '^'){
            return false;
        }
        return true;
    }

    static bool isOperator(char i){
        if(i != '+' && i != '-' && i !='*' && i != '/' && i != '^'){
            return false;
        }
        return true;
    }

    static int getOperatorPrecedence(char op) {
        if (op == '+' || op == '-') {
            return 1;
        } else if (op == '*' || op == '/') {
            return 2;
        } else if (op == '^') {
            return 3;
        } else {
            return 0;  // Default precedence for unknown operators
        }
    }

    static bool checkPrecedence(char val, char i) {
        int precedenceVal = getOperatorPrecedence(val);
        int precedenceI = getOperatorPrecedence(i);

        return precedenceVal >= precedenceI;
    }

    static double add(double num1 , double num2){
        return num1+num2;
    }

    static double subtract(double num1 , double num2){
        return num1-num2;
    }

    static double multiply(double num1 , double num2){
        return num1*num2;
    }

    static double divide(double num1 , double num2){
        return num1/num2;
    }

    static double power(double num1 , double num2){
            return pow(num1,num2);
    }

    static double applyOperation(double firstOperand , double secondOperand , char Operator){
        if(Operator == '+'){
            return add(firstOperand,secondOperand);

        }else if(Operator == '-'){
            return subtract(firstOperand,secondOperand);
        }else if(Operator == '*'){
            return multiply(firstOperand,secondOperand);
        }else if(Operator == '/'){
            return divide(firstOperand,secondOperand);
        }else{
            return power(firstOperand,secondOperand);
        }
    }

};


int main(){

    infixToPostfixConvertor infixToPostfix;
    infixToPostfix.infixToPostfix("12+(13*14-(15/16^17)*18)*19");
    infixToPostfix.displayInfixtoPostfix();
    double value = infixToPostfix.calculate();
    cout << endl << value;
    return 0;
}

