#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;
int redo();
int main(){
    int cardone, cardtwo, cardthr, cardfor, cardfiv;
    int num_of_hits = 0;
    char h_or_s, doag, o_or_e;
    bool a = true;
    bool b;
    srand( (unsigned)time(0) );
    cout << "Welcome to Console Blackjack 1.1! You can hit three times total. ";
    do{
    num_of_hits = 0;
    cardone = (rand()%13) + 1;
    cardtwo = (rand()%13) + 1;
    cardthr = (rand()%13) + 1;
    cardfor = (rand()%13) + 1;
    cardfiv = (rand()%13) + 1;
    if(cardone > 10)
    cardone = 10;
    if(cardtwo > 10)
    cardtwo = 10;
    if(cardthr > 10)
    cardthr = 10;
    if(cardfor > 10)
    cardfor = 10;
    if(cardfiv > 10)
    cardfiv = 10;
    cout << "Your card values are: " << cardone << " and " << cardtwo << ".\n";
    if(cardone == 1)
    cout << "Is your ace a one or eleven? [o/e] ";
    tolower(o_or_e);
    if(o_or_e == 'e')
    cardone = 11;
    else
    cardone = 1;
    if(cardtwo == 1)
    cout << "Is your ace a one or eleven? [o/e] ";
    tolower(o_or_e);
    if(o_or_e == 'e')
    cardtwo = 11;
    else
    cardtwo = 1;
    if(cardone+cardtwo==21){
    cout << "21!!!!!!\n";
    b = redo();
    system("pause");
    return 0;}
    else if(cardone + cardtwo > 21){
    cout << "BUST!\n";
    b = redo();
    system("pause");
    return 0;
}else
    cout << "Hit or stay? [h/s] ";
    do{
    cin >> h_or_s;
    switch(h_or_s){
         case 'h':case 'H':
              num_of_hits++;
              if(num_of_hits == 1){
              cout << "Your next card is " << cardthr << ". ";
              if(cardthr == 1)
              cout << "Is your ace a one or eleven? [o/e] ";
              tolower(o_or_e);
              if(o_or_e == 'e')
              cardthr = 11;
              else
              cardthr = 1;
              cout << ". Your total value is " << cardone+cardtwo+cardthr;
              if(cardone+cardtwo+cardthr==21){
              cout << ". You win!!!!\n";
              b = redo();
              system("pause");
              return 0;
              }else if(cardone+cardtwo+cardthr>21){
              cout << ". BUST!\n";
              b = redo();
              system("pause");
              return 0;
              }else{
              cout << ". Hit or stay? ";
              continue;}}
              if(num_of_hits == 2){
              cout << "Your next card is " << cardfor << ". ";
              if(cardfor == 1)
              cout << "Is your ace a one or eleven? [o/e] ";
              tolower(o_or_e);
              if(o_or_e == 'e')
              cardfor = 11;
              else
              cardfor = 1;
              cout << "Your total value is " << cardone+cardtwo+cardthr+cardfor;
              if(cardone+cardtwo+cardthr+cardfor==21){
              cout << ". You win!!!!\n";
              b = redo();
              system("pause");
              return 0; 
              }else if(cardone+cardtwo+cardthr+cardfor>21){
              cout << ". BUST!\n";
              b = redo();
              system("pause");
              return 0;
              }else{
              cout << ". Hit or stay? ";
              continue;}}
              if(num_of_hits == 3){
              a = false;
              cout << "Your next card is " << cardfiv << " and your total value is " << cardone+cardtwo+cardthr+cardfor+cardfiv;
              if(cardfiv == 1)
              cout << "Is your ace a one or eleven? [o/e] ";
              tolower(o_or_e);
              if(o_or_e == 'e')
              cardfiv = 11;
              else
              cardfiv = 1;
              cout << "Your total value is " << cardone+cardtwo+cardthr+cardfor+cardfiv;
              if(cardone+cardtwo+cardthr+cardfor+cardfiv==21){
              cout << ". You win!!!!\n";
              b = redo();
              system("pause");
              return 0;
              }else if(cardone+cardtwo+cardthr+cardfor+cardfiv>21){
              cout << ". BUST!\n";
              b = redo();  
              system("pause");
              return 0;
              }else
              cout << ".\nYour cards were worth " << cardone+cardtwo+cardthr+cardfor+cardfiv << ". Thanks for playing! ";
              }break;
              
              case 's':case 'S':
              a = false;
              if(num_of_hits == 0)
              cout << "Your cards in total were worth " << cardone+cardtwo << ". Thanks for playing! ";
              else if(num_of_hits == 1)
              cout << "Your cards in total were worth " << cardone+cardtwo+cardthr << ". Thanks for playing! ";
              else if(num_of_hits == 2)
              cout << "Your cards in total were worth " << cardone+cardtwo+cardthr+cardfor << ". Thanks for playing! ";
              break;
         }}while(a);
    b = redo();
    }while(b);
    system("pause");
    return 0;
}
     int redo(){
         char doag;
         cout << "Restart? [y/n] ";
         cin >> doag;
         switch(doag){
         case 'y':case 'Y':
         main();
         break;
         case 'n':case 'N':
         return 0;
         break;
         }}