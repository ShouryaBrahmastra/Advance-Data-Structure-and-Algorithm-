/**
 * 
 * Write a program multiply two polynomials using LinkedList.
 * 
 * Author: Shourya Gupta 
 * Copyright: ShouryaBrahmastra
 * 
 * **/
#include <iostream>
using namespace std;

struct Node {
    int coeff, power;
    Node* next;
};

class Solution {
public:
    Node* createPolynomial(int degree) {
        Node* poly = NULL;
        for (int i = degree; i >= 0; --i) {
            int coeff;
            cout << "Enter coefficient for x^" << i << ": ";
            cin >> coeff;
            poly = addNode(poly, coeff, i);
        }
        return poly;
    }


    Node* addNode(Node* start, int coeff, int power) {
        Node* newNode = new Node{coeff, power, NULL};
        if (!start)
            return newNode;

        Node* ptr = start;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        return start;
    }

    Node* multiply(Node* poly1, Node* poly2) {
        Node* poly3 = NULL;
        for (Node* ptr1 = poly1; ptr1; ptr1 = ptr1->next) {
            for (Node* ptr2 = poly2; ptr2; ptr2 = ptr2->next) {
                int coeff = ptr1->coeff * ptr2->coeff;
                int power = ptr1->power + ptr2->power;
                poly3 = addNode(poly3, coeff, power);
            }
        }
        removeDuplicates(poly3);
        return poly3;
    }


    void removeDuplicates(Node* start) {
        Node *ptr1 = start, *ptr2, *dup;
        while (ptr1 && ptr1->next) {
            ptr2 = ptr1;
            while (ptr2->next) {
                if (ptr1->power == ptr2->next->power) {
                    ptr1->coeff += ptr2->next->coeff;
                    dup = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    delete dup;
                } else {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
    }

    void printList(Node* ptr) {
        while (ptr) {
            cout << (ptr->coeff > 0 && ptr != ptr->next ? "+" : "") << ptr->coeff << "x^" << ptr->power;
            ptr = ptr->next;
        }
        cout << endl;
    }

};

// Driver code
int main() {
    Solution solution;
    char choice;
    do {
        int degree1, degree2;

        cout << endl;
        cout << "Enter the degree of the first polynomial: ";
        cin >> degree1;
        Node* poly1 = solution.createPolynomial(degree1);

        cout << endl;
        cout << "Enter the degree of the second polynomial: ";
        cin >> degree2;
        Node* poly2 = solution.createPolynomial(degree2);

        cout << endl;
        cout << "First Polynomial: ";
        solution.printList(poly1);

        cout << "Second Polynomial: ";
        solution.printList(poly2);

        cout << endl;
        Node* poly3 = solution.multiply(poly1, poly2);
        cout << "Resultant Polynomial: ";
        solution.printList(poly3);

        cout << endl;
        cout << "Do you want to multiply another pair of polynomials? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
