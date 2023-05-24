// Program for a Queue Using Linked list.

#include<iostream>

using namespace std;

struct node {
    int data;
    node *next;
};


class queue
{
    private:
        node *first;
        node *last;
    public:
        // Set first and last node pointers to NULL 
        queue() { first = NULL; last = NULL; }

        // Function to check if the queue is empty or not
        bool is_empty()
        {
            if(first == NULL || last == NULL)
                return true;
            else 
                return false;
        }   

        // Function to enqueue node to the queue 
        void enqueue(int data)
        {
            node *newnode = new node;
            newnode -> data =  data;
            newnode -> next  = NULL;

            // Check if we are on an empty queue
            if(is_empty())
            {
                first = last = newnode;

            }
            else
            {
                last -> next = newnode;
                last = newnode;

            }
        }


        // Function to dequeue and print the front element 
        void dequeue()
        {
            // If the queue is empty 
            if(is_empty())
            {
                cout<<"The queue is empty\n";
            }
            // If the queue contains only one node 
            else if (first == last)
            {
                delete first;
                first = last = NULL;
            }
            // If there are more than one node in the queue 
            else
            {
                node *temp = first;
                first = first -> next;
                delete temp;

            }
        }

        // Function to get the first node's data in the queue 
        int peek()
        {
            // Check if the queue is empty 
            if (is_empty())
            {
                cout<<"Queue is empty\n";
                return -1;
            }
            else
            {
                return first -> data;
            }

        }

        // Function to display the elements of the queue 
        void display()
        {
            // Check if the queue is empty
            if(is_empty())
            {
                cout << "Queue is empty" << endl;
                return;
            }
            else
            {
                node *temp = first;
                while(temp -> next != NULL)
                {
                    cout << temp -> data << " ";
                    temp = temp -> next;
                }
                
                if (temp -> next == NULL)
                {
                    cout << temp -> data << " ";
                }
                cout << endl;
    
            }
        }
};

int main()
{
    queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(10);

    cout << "Queue elements: ";
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();
    cout << "Front element after dequeuing: " << q.peek() << endl;

    return 0;
    
    
}
