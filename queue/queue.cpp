#include<iostream>

using namespace std;

const int max_size = 5;

class queue
{
    private:
        int first;
        int last;
        int list[max_size];  

    public:

        queue(){ first = -1; last = -1; }

        void enqueue(int element)
        {
            // Check if the queue is overflow
            if (last >= max_size - 1)
                cout<<"Queue is overflow"<<endl;
            else{
                if (first == -1)
                    first = 0;
                // Add the element to the queue and update the last  counter    
                last ++;
                list[last] = element; 
            }
        }

        void dequeue()
        {
            // Check if the queue is empty
            if (first == -1 || first > last)
                cout<<"Queue is underflow"<<endl;
            
            else{
                // Print the first element and update the first counter
                first ++;
                cout<<list[first - 1]<<endl;
            }
        }

        void print()
        {
            // Check if the queue is empty
            if (first == -1 || first > last)
                cout<<"Queue is empty"<<endl;
            
            else{
                for( int i = first; i <= last; i ++)
                    cout<<list[i];
                }
            cout<<endl;
        }
};

int main()
{
    queue q;

    q.print();
    
    cout<< "Add number 1 to the queue" <<endl;
    q.enqueue(1);

    cout<< "Add number 2 to the queue" <<endl;
    q.enqueue(2);

    cout<< "Add number 3 to the queue" <<endl;
    q.enqueue(3);

    cout<< "Add number 4 to the queue" <<endl;
    q.enqueue(4);

    cout<< "Add number 5 to the queue" <<endl;
    q.enqueue(5);

    // Try to add more than the queue list max_size
    q.enqueue(6);
    q.enqueue(7);


    q.print();
    // Dequeue the queue
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    // Try to print while the queue is empty
    q.print();

    return 0;    
}