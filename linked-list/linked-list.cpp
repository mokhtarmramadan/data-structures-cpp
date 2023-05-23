// Operation on Linked List:
// Creation
// Insertion (At the Beginning , At the End , At any specified position in between)
// Deletion
// Traversing
// Searching


#include<iostream>

using namespace std;

// Create a node structure 
struct node{
    int data;
    node *next;
};


class list{

    // Inatialize a pointer for a node and put the start value of it as NULL 
    private:
        node *start;
    public:
        list() { start = NULL; }

        // Add a new node from the start 
        void add_start(int data)
        {   
            // Create a pointer called newnode to point at an empty node and then give it some data 
            node *newnode = new node;
            newnode -> data = data;

            // Check if the list is empty
            if (start ==  NULL)
            {
                // Make the newnode pointer points at NULL
                newnode -> next = NULL;
            }
            // If the list is not empty 
            else
            {
                // Make the newnode pointer points at the start of the linked list 
                newnode -> next = start;
            }

            // Make the start pointer points at the newnode
            start = newnode;

        }
    
        void add_end(int data)
        {
            // Create a pointer called newnode to point at an empty node and then give it some data and an NULL pointer
            // (because it will be added at the end of the list)
            node *newnode = new node;
            newnode -> data = data;
            newnode -> next = NULL;

            // Check if the list is empty
            if (start == NULL)
            {
                start = newnode;
            }
            else
            {
                // Create a temporary pointer to inatially points at the start of the list
                node *temp = start;

                // Go through all the list till we get the address of the last node
                while (temp -> next != NULL)
                {
                    
                    temp = temp -> next;
                }
                // Make the last node in the list points at the new node
                temp -> next = newnode;
            }
            
        }

        void add_mid(int data, int position)
        {
            node *newnode = new node;
            newnode -> data = data;

            if (position == 1)
            {
                // add_start(data); is correct but not efficient because we alread create a new node in the heep and it will
                // stay allocated but useless 
                // Check if the list is empty
            if (start ==  NULL)
            {
                // Make the newnode pointer points at NULL
                newnode -> next = NULL;
            }
            // If the list is not empty 
            else
            {
                // Make the newnode pointer points at the start of the linked list 
                newnode -> next = start;
            }

            // Make the start pointer points at the newnode
            start = newnode;

            }

            else
            {
                // Create a temp pointer to point at the position
                node *temp = start;
                for (int i = 0; i < position - 1; i ++)
                {
                    temp = temp -> next;

                }

                // Make the pointer or the new node points at the node passed next
                newnode -> next = temp -> next;

                // Make temp points at the new node
                temp -> next =  newnode;
            }
        }

        // Delete a node function 
        void Delete(int data)
        {
            // A node pointer to hold the address of the node we want to delete
            node *hold;

            // Check if it's the first node 
            if( start -> data == data)
            {
                // Hold the start node
                hold = start;
                // Update the start pointer to the next node
                start = start -> next;
                //  Delete the held node
                delete hold;
                return;
            }

            // If the element we want o delete is in between
            node *temp = start;

            // Iterate till we find the data
            while(temp -> next -> next != NULL)
            {
                // Check if the node we're on has the data we're searching
                if(temp -> next -> data == data)
                {
                    // Hold the node past the temp node
                    hold = temp -> next;
                    // Make temp points at the node past the held node 
                    temp -> next = hold -> next;
                    delete hold;
                    return;

                }
                // Move temp pointer to next if it doesn't meet the condition
                temp = temp -> next;
            }
        }

        // Display linked list function 
        void dispaly()
        {
            // Check if the list was empty 
            if (start == NULL)
            {
                cout <<"List is empty\n";
                return;
            }

            cout <<"List is: ";
            
            node *temp = start;
            while(temp -> next != NULL)
            {
                cout<< temp ->data << " ";
                temp = temp -> next;
            }

            cout<<endl;
        }

        // Count nodes function 
        int count()
        {
            int count = 0;
            node *temp = start;

            while(temp -> next != NULL)
            {
                count ++;
                temp = temp -> next;

            }

            return count;
            

        }

        // Search data function 
        bool search(int data)
        {
            node *temp = start;
            
            while(temp -> next != NULL)
            {
                if (temp -> data = data)
                {
                    return true;
                }

            }
            return false;
        }

        // Concatenate two linked lists 
        list operator+(list &m){

			node *temp = this->start;
			while ( temp->next != NULL ){
				temp = temp->next;
			}
			temp->next=m.start;
			return *this;
		}
    
};

int main()
{
    list list;
    list.dispaly(); // List is empty
    list.add_start(1);
    list.add_end(2);
    list.add_start(1);
    list.dispaly(); // List is: 1 1 2
    cout<< "The list contains "<< list.count()<<endl; // 3
    cout << "Enter item to search in the list \n";
    int item;
    cin >> item; // 2
    if (list.search(item))
        cout<< "Item found\n"<<endl;
    else
        cout<< "Item not found\n"<<endl;

    list.add_mid(50, 4);
    list.dispaly(); // List is: 1 1 2 50
    list.Delete(50);
    list.dispaly(); // List is: 1 1 2 
    list.Delete(100); // Element 100 was not found
    list.dispaly(); // List is: 1 1 2 


    return 0;
}