// Static stack implementation using arrays 

#include<iostream>

using namespace std;

const int max_size = 100;

class stack{
    private:
        int top;
        int item[max_size];
    
    public:
        // Give top an inatial value -1
        stack(){ top = -1; }

        // Check if the stack is empty
        bool is_empty()
        {
            if (top == -1)           
                return true;
            
            else            
                return false;
        }    

       int get_top()
        {            
            // Return the top element    
            return item[top];           
        }

        void push(int element)
        {
            // Check if the stack is overflow
            if (top > max_size - 1)
                cout<<"Stack is overflow"<<endl;
            else
                // If it's not overflow add the element and update the top counter
                top ++;
                item[top] = element;     
        }
        
        // Return the top element
        int pop()
        {
            // Check if the stack is underflow
            if (is_empty())
                cout<<"Stack is underflow"<<endl;
            else
                // Return the top and update the top counter
                top --;
                return item[top + 1];
        }

        void print()
        {
            // Check if the stack is overflow
            if(is_empty())
                cout<<"Stack is overflow"<<endl;
            else
                // print all element in the stack from top to bottom
                for(int i = top; i >= 0; i --)
                {
                    cout<< item[i]<< " ";
                }
            cout <<endl;
        }
};

int main()
{
    // Inatialize a stack struck called s
    stack s;

    // Push the the values 5 10 15 20 25 using the push method
    s.push(5);
    s.push(15);
    s.push(20);
    s.push(25);

    // Print the top value 
    cout<<"The value of the top is: "<<s.get_top()<<endl;

    // Print all the stack out 
    s.print();

    // Pop all the stack elements 
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    // Try to pop when the stack is overflow 
    cout<<s.pop()<<endl;
    
    return 0;
}