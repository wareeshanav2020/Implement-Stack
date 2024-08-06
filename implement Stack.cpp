#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks;
    Student* next;

    Student(string n, int m) : name(n), marks(m), next(nullptr) {}
};

class Stack {
private:
    Student* topStudent;

public:
    Stack() : topStudent(nullptr) {}

    void push(string name, int marks) {
        Student* newStudent = new Student(name, marks);
        newStudent->next = topStudent;
        topStudent = newStudent;
        cout << "Student " << name << " with marks " << marks << " added to the stack." << endl;
    }

    void pop() {
        if (topStudent == nullptr) {
            cout << "Stack is empty. No student to remove." << endl;
            return;
        }
        Student* temp = topStudent;
        topStudent = topStudent->next;
        cout << "Student " << temp->name << " removed from the stack." << endl;
        delete temp;
    }

    void display() {
        if (topStudent == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        Student* temp = topStudent;
        cout << "Students in the stack:" << endl;
        while (temp != nullptr) {
            cout << "Name: " << temp->name << ", Marks: " << temp->marks << endl;
            temp = temp->next;
        }
    }

    void displayTop3() {
        if (topStudent == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }

        Stack secondaryStack;
        Student* temp = topStudent;

        while (temp != nullptr) {
            secondaryStack.push(temp->name, temp->marks);
            temp = temp->next;
        }

        cout << "Top 3 students based on marks:" << endl;
        for (int i = 0; i < 3 && !secondaryStack.isEmpty(); ++i) {
            cout << "Name: " << secondaryStack.topStudent->name << ", Marks: " << secondaryStack.topStudent->marks << endl;
            secondaryStack.pop();
        }
    }

    bool isEmpty() {
        return topStudent == nullptr;
    }
};

int main() {
    Stack mainStack;
    int choice;
    string name;
    int marks;

    while (true) {
        cout << "Enter your choice of the activity:" << endl;
        cout << "1. Add a student in Stack" << endl;
        cout << "2. Remove a Student from Stack" << endl;
        cout << "3. Display all students of Stack" << endl;
        cout << "4. Display top 3 positions of students" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student's name: ";
                cin >> name;
                cout << "Enter student's marks: ";
                cin >> marks;
                mainStack.push(name, marks);
                break;
            case 2:
                mainStack.pop();
                break;
            case 3:
                mainStack.display();
                break;
            case 4:
                mainStack.displayTop3();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

