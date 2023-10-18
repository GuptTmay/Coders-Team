#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct patient {
    long ID;
    string firstName;
    string surName;
    int age;
    char blood_group[5];
    char gender;
    patient* next;
};


class linkedqueue {
    private:
        patient *head, *tail;
    
    public:
        linkedqueue() {
            head = NULL;
            tail = NULL;
        }

        bool search(int);  
        patient input();
        void insertStart();
        void insertEnd();
        void firstPatientOut();
        void listOfPatients();
        char departmentname[50];
        // Other Util functions
        // Stops the program for sometime
        void wait() {
            cout << "\n\nPress Enter to continue...";
            cin.ignore(); 
            getchar(); 
            system("cls");
        }

        // Output the details of the patient
        void output(patient *p)
        {
            cout<<"\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
            cout<<"\n Patient data:\n";
            cout<<"\n First Name : "<<p->firstName;
            cout<<"\n Last Name : "<<p->surName;
            cout<<"\n Gender : "<<p->gender;
            cout<<"\n Age : "<<p->age;
            cout<<"\n Blood Group : "<<p->blood_group;
            cout<<"\n Mobile Number : "<<p->ID;
            cout<<"\n\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
            wait();
        }
};

// Searchs through the linked list to find the id
bool linkedqueue :: search(int id_Number) {
    if (head == NULL) {
        return false;
    }

    patient* p = new patient();
    p = head;

    while (p->next != NULL && p->ID != id_Number) 
    {
        p = p->next;
    }

    if (p->ID == id_Number) {
        return true;
    }
    
    return false;
}

patient linkedqueue :: input() {
    patient* p = new patient();
    bool checker = false;
    getline(cin, p->firstName);

    cout << "Enter your First Name: ";
    getline(cin, p->firstName);

    cout << "Enter your Surname: ";
    getline(cin, p->surName);

    cout << "Enter your Age: ";
    cin >> p->age;

    char gen;
    cout << "Enter your Gender(m/f): ";
    cin >> gen;
    p->gender = toupper(gen);
    
    again:
    const char* bloodTypes[] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O+", "a+", "a-", "b+", "b-", "ab+", "ab-", "o+", "o-"};
    
    cout << "Enter your blood type: ";
    cin >> p->blood_group;
    
    for (int i = 0; i < 16; i++) {
        if (strcmp(bloodTypes[i], p->blood_group) == 0) {
            checker = true;
            break;
        }
    }

    if (checker == false) {
        cout << "Invaild Blood Group Type";
        goto again;
    }

    cout << "Enter your Phone Number: ";
    cin >> p->ID;

    if (search(p->ID)) {
        p->ID = 0;
        cout << "You have already Registed!, Data not Invaild, Operation Cancelled.";
    } 
    return *p;
}

void linkedqueue :: insertStart() {
    patient *p = new patient();
    *p = input();

    if (p->ID == 0) {
        return;
    }

    if (head == NULL) {
        head = p;
        tail = p;
        p->next = NULL;
    } else {
        p->next = head;
        head = p;
    }

    cout << "Process Successfully Completed!" << endl;
    output(p);
    wait();
    return;
}

void linkedqueue :: insertEnd() {
    patient *p = new patient();
    *p = input();
    if (p->ID == 0) {
        return;
    } 

    if (tail == NULL) {
        head = p;
        tail = p;
        p->next = NULL;
    } else {
        tail->next = p;
        tail = tail->next;
        p->next = NULL;
    }

    cout << "Process Successfully Completed!" << endl;
    output(p);
    wait();
    return;
}

void linkedqueue::firstPatientOut() {
    if (head == NULL) {
        cout << "No Patient to Operate";
    } else {
        patient *p = new patient();
        p = head;
        head = head->next;
        cout << "\n Patient to Operate";
        output(p);
    }
}

void linkedqueue::listOfPatients() {
    patient *p = new patient();
    p = head;

    if (p == NULL) {
        cout << "Patient List is Empty!";
    } else {
        cout<<"\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout<<"\n-------------------Hospital Data--------------------|";
        cout<<"\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout<<"\n-------------------Patient List---------------------|";
        while (p != NULL) {
            cout<<"\n Patient data:\n";
            cout<<"\n First Name : "<<p->firstName;
            cout<<"\n Last Name : "<<p->surName;
            cout<<"\n Gender : "<<p->gender;
            cout<<"\n Age : "<<p->age;
            cout<<"\n Blood Group : "<<p->blood_group;
            cout<<"\n Mobile Number : "<<p->ID;
            cout<<"\n\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
            p = p->next;
        }
    }
}