#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct student
{
    string firstname;
    string lastname;
    int age;
    string gender;
    string course;
    string year;
    string section;
    int studno;
};

int menu(int &menuChoice);
void userInfo(student user[], int size, int const track);
void listUser(student user[], int size, int const track);

int main(int argc, char** argv) {

int menuChoice;
int static track = 0;
student user[30];
do {
menu(menuChoice);
switch(menuChoice) {
case 3:
userInfo(user, 30, track);
track++;
break;
case 4:
listUser(user, 30, track);
break;
}
} while(menuChoice != 5);

return 0;
}
    int menu(int &menuChoice)
    {
    do {
    cout<< "\n\t\t==========================================="
        << "\n\t\t|\tSimple Student Record Program\t  |"
        << "\n\t\t==========================================="
        << "\n\n\t\t\t\t [MAIN MENU]"
        << "\n\n\n[1] - Search Student\n[2] - Best Students\n[3] - Add New Student\n[4] - View Students\n[5] - Delete Student"
        << "\n\nEnter a choice: ";
    cin>> menuChoice;

    if (menuChoice>5||menuChoice<1)
    {
        cout<< "Please select an existing option!";
    }
    }
    while (menuChoice>5||menuChoice<1);

    return menuChoice;
    }

void userInfo(student user[], int size, int const track)
{
    cout<< "\n\n\t\t\t\t[Add a student]";
    cout<< "\n\nEnter student's first name: ";
    cin>> user[track].firstname;
    cout<< "\nEnter student's last name: ";
    cin>> user[track].lastname;
    cout<< "\nAge: ";
    cin>> user[track].age;
    cout<< "\nGender: ";
    cin>> user[track].gender;
    cout<< "\nCourse: ";
    cin>> user[track].course;
    cout<< "\nYear: ";
    cin>> user[track].year;
    cout<< "\nSection: ";
    cin>> user[track].section;
    cout<< "\nStudent No.: ";
    cin>> user[track].studno;
    return;
}

void listUser(student user[], int size, int const track)
{
    int list;
    cout<< "\n\tName|||Age|||Gender|||Course|||Year|||Section|||Student No.\n";
    for (list=0; list<track; list++)
    {
        cout<< "\n\n" << user[list].firstname <<" " << user[list].lastname <<"\t\t" << user[list].age <<"\t" << user[list].gender << "\t" << user[list].course << "\t" << user[list].year << "\t" << user[list].section << "    " << user[list].studno <<"\n";
    }
    return;
}
