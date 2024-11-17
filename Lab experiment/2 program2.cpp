/**
 * 
 * Design a code to perform given below operations in LinkedList.
 *
 * (a) Insertion and deletion at any position
 * (b) Searching a given element and finds its location.
 * (c) Count the number of nodes in the linked list.
 * (d) Perform reverse operation in linked list.
 * 
 * Author: Shourya Gupta
 * Copyright: ShouryaBrahmastra
 * 
 * **/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LL 
{
    Node* head;

    public: 

    LL() : head(NULL) {}
    
    void insertAtBeginning(int value) 
    {
        Node* new_node = new Node(); 
        new_node->data = value;      
        new_node->next = head;      
        head = new_node;            
    }

    
    void insertAtEnd(int value) 
    {
        Node* new_node = new Node(); 
        new_node->data = value;      
        new_node->next = NULL;       

        
        if (!head) 
        {
            head = new_node;
            return;
        }

        
        Node* ptr = head;
        while (ptr->next) 
        {
            ptr = ptr->next;
        }

        ptr->next = new_node;
    }

    
    void insertAtPosition(int value, int pos) 
    {
        Node* new_node = new Node(); 
        new_node->data = value; 
        new_node->next=NULL;

        if (pos < 1) 
        {
            cout << "Location must be greater or equal to 1." << endl;
            return;
        }

        if (pos == 1) 
        {
            insertAtBeginning(value);
            return;
        }            

        Node* temp = head;
        for (int i = 1; i < pos - 1; ++i) 
        {
            temp = temp->next;
        }  

        new_node->next = temp->next;
        temp->next = new_node;
    }

    void deletefrombegin() 
    {
        Node* temp = head; 
        if (!head) 
        {
            cout << "List is empty." << endl;
            return;
        }
       
        head = head->next; 
        free(temp);      
    }

    void deletefromend() 
    {
        Node* temp = head;
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (!head->next) 
        {
            free(head);
            head = NULL;   
            return;
        }      
        
        while (temp->next->next) {
            temp = temp->next;
        }
        
        free(temp->next); 
        temp->next = NULL; 
    }

    void deleteFromPosition(int pos) 
    {
        Node* temp = head;
        if (pos < 1) 
        {
            cout << "Position should be greater or equal to 1." << endl;
            return;
        }

        if (pos == 1) 
        {
            deletefrombegin();
            return;
        }
        
        for (int i = 1; i < pos - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl;
            return;
        }
        // Save the node to be deleted
        Node* nodeToDelete = temp->next; 
        // Update the next pointer
        temp->next = temp->next->next;   
         // Delete the node
        delete nodeToDelete;            
    }
    
    int search(int key) 
    {
        Node* current = head;
        int index = 0;

        while (current) 
        {
            if (current->data == key) 
            {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; 
    }
    int count() 
    {
        Node* current = head;
        int count = 0;
        while (current) 
        {
            count++;
            current = current->next;
        }
        return count;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;

        while (current) 
        {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }

    void printList() 
    {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

};


int main() {
    LL list;
    int choice, value, position;

    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search for an Element\n";
        cout << "8. Count Nodes\n";
        cout << "9. Reverse List\n";
        cout << "10. Print List\n";
        cout << "0. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert and position: ";
                cin >> value >> position;
                list.insertAtPosition(value, position);
                break;
            case 4:
                list.deletefrombegin();
                break;
            case 5:
                list.deletefromend();
                break;
            case 6:
                cout << "Enter position to delete from: ";
                cin >> position;
                list.deleteFromPosition(position);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                position = list.search(value);
                if (position != -1) {
                    cout << "Element found at position: " << position << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 8:
                cout << "Number of nodes: " << list.count() << endl;
                break;
            case 9:
                list.reverse();
                cout << "List reversed." << endl;
                break;
            case 10:
                list.printList();
                break;
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}