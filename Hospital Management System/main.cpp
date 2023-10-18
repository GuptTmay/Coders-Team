#include "departmentmenu.cpp"

#include <iostream>
#include <string>
#include <cstring>

int main() {
    linkedqueue department[4];
    strcpy(department[0].departmentname, "General Health Clinic");
    strcpy(department[1].departmentname, "Heart Clinic");
    strcpy(department[2].departmentname, "Dentist Clinic");
    strcpy(department[3].departmentname, "Lung Clinic");

    again:
    int choice = 0;
    while (choice != 5) {
        for (int i = 0; i < 4; i++) {
            cout << "[" << (i + 1) << "]" << " " << department[i].departmentname << endl; 
        }
        cout << "[5] Exit";
        cout << "\n Enter your choice: ";
        cin >> choice;
        system("cls");
        
        switch (choice) {
            case 1:
                departmentMenu(&department[0]);
                break;
            case 2:
                departmentMenu(&department[1]);
                break;
            case 3:
                departmentMenu(&department[2]);
                break;
            case 4:
                departmentMenu(&department[3]);
                break;
            case 5:
                break;
            default:
                cout << "Entered invaild Value, Reinitializing process.";
                goto again;
                break;
        }
    }
    cout << "\n Thank you visiting us!";
    cout << "\n We hope for your better health in future.";
    return 0;
}