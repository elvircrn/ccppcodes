#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

    int qnum, frnum;
    int rnum = rand();
    string cchoice;
    int i = 0;
    int range2;
    int range1;
int W(){

return 0;

}

void MM(){

    cout << "Welcome to 'Quess a Number !'\n (S)tart Game \n (C)redits\n (E)xit\n";
    cin >> cchoice;

}

void SG(){

    cout << "Choose the range: ";
    cin >> range1; cout << " - "; cin >> range2;
    cout << "You have chosen the numbers between " << range1 << " and " << range2 << ", good luck !" << endl;
    srand (time (0 ));
    (int (rand()) % range2) + range1;
    cin >> qnum;
        while (qnum != rnum){
        cin >> qnum;

            if (qnum == frnum){cout << "Correct, you win ! \n";  W(); }
            else if (qnum < frnum){cout << "Higher ! \n";}
            else if (qnum > frnum) {cout << "Lower ! \n";}
        }

}

void C(){

string cchoiceif;

    cout << "Made by: Vex A.K.A. Vedad Fejazgic :P\n (R)eturn\n";
        if (cchoiceif == "R" || cchoiceif == "r") {
        MM();

        }

}

int main()
{
    srand (time (0));

    MM();

    if (cchoice == "S" || cchoice == "s"){
    SG();
    }

    else if (cchoice == "C" || cchoice == "c"){
    C();
    }

    else if(cchoice == "E" || cchoice == "e"){
    return 0;
    }

   return 0;
}
