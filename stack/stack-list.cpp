// Stack Dynamic Implementation Using Pointers (linked lists )

#include<iostream>
using namespace std;


struct node {
    int data;
    node *next;
};

class stack{
    private:
        node *top;
    public:
        stack() {top == NULL; }

    void push(int data){
        // Create a new node with a next pointer equals NULL
        node *newnode = new node;
        newnode -> data = data;

        // Check if the stack is underflow or not
        if(top == NULL)
        {
            newnode -> next = NULL;
        }
        else
        {
            newnode -> next = top;
        }
        
        top = newnode;
        
    }

    void pop(){
        // Check if the stack is underflow 
        if (top == NULL)
        {
            cout << "Stack is underflow\n";
            return;
        }
        else{
            node *temp = top;
            top = top -> next;
            cout << temp -> data << " Was deleted\n";
            delete temp;
            
        }
        
    }

    // Print stack function 
    void display(){
        node *temp = top;

        // Check if the stack is empty 
        if (top == NULL)
        {
            cout << "Stack is underflow\n";
            return;
        }
        while(temp != NULL)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }


        cout << endl;

    }


};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    s.pop();

    s.display();

}
