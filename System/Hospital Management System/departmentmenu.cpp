#include "linkedqueue.cpp"

#include <iostream>

void departmentMenu (linkedqueue *q) {
    again:
    int choice = 0;
    while (choice != 5) {
        cout<<"\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout<<"\n-------------------Hospital Management System--------------------|";
        
        cout<<"\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout<<"\n-------------------Welcome to "<< q->departmentname << "--------|";
        cout<<"\n [1] Add a normal patient.";
        cout<<"\n [2] Add a critically ill patient.";
        cout<<"\n [3] Take Patient to Doctor.";
        cout<<"\n [4] Display List of Patient.";
        cout<<"\n [5] Change Department or Exit.";
        cout<<"\n Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: q->insertEnd();
                break;
            case 2: q->insertStart();
                break;
            case 3: q->firstPatientOut();
                break;
            case 4: q->listOfPatients();
                break;
            case 5:
                cout << "\n Exiting " << q->departmentname; 
                q->wait();          
                break;
            default:
                cout << "\n\n Invaild choice Entered, Reinitializing process.";
                q->wait();
                goto again;
                break;
        }

    }
}