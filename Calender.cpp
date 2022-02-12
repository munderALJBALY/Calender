/* this program display a monthly calendar of year 2022 month by month
   and allow the user to browse the calendar forward and backward.
*/
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
//#include<dos.h>
#include<windows.h>
using namespace std;
//=====================================================

//EDIT EDIT EDIT EDIT EDIT EDIT EDIT EDIT EDIT EDIT EDIT 
void gotoxy(short x, short y)
{
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clrscr() {
    system("cls");
}
void short_test(){
    Beep (555,100);
    // system("pause>nul");
}
void beb(){
    for (int i=0; i<3000; i+=50){
    Beep (i,100);
    }
    //descending pitch beep
    for (int i=3000; i>0; i-=50){
    Beep (i,100);
    }
}
void bob(){
int x;
    // Loop for sound Jingle
    for (x = 0; x < 2; x++) {
        Beep(523, 500);
    }
 
    // sound Bell
    Beep(523, 800);
 
    Sleep(200);
 
    // Loop for sound Jingle
    for (x = 0; x < 2; x++) {
        Beep(523, 500);
    }
 
    // sound Bell
    Beep(523, 800);
 
    // Sound for rest of the tone
    Sleep(200);
 
    Beep(523, 500);
 
    Sleep(50);
 
    Beep(659, 400);
 
    Sleep(50);
 
    Beep(440, 400);
 
    Sleep(50);
 
    Beep(494, 400);
 
    Sleep(50);
 
    Beep(523, 750);
 
    Sleep(400);
 
    Beep(600, 400);
 
    Sleep(100);
 
    Beep(600, 350);
 
    Sleep(200);
 
    Beep(600, 300);
 
    Sleep(150);
 
    Beep(600, 250);
 
    Sleep(150);
 
    Beep(600, 150);
 
    Sleep(150);
 
    Beep(550, 250);
 
    Sleep(150);
 
    Beep(555, 350);
 
    Sleep(50);
 
    Beep(555, 200);
    Sleep(150);
 
    Beep(555, 200);
 
    Sleep(150);
 
    Beep(690, 200);
 
    Sleep(150);
 
    Beep(690, 200);
 
    Sleep(150);
 
    Beep(610, 200);
 
    Sleep(150);
 
    Beep(535, 160);
 
    Sleep(100);
 
    Beep(500, 150);
 
    Beep(500, 50);
 
    Sleep(200);
 
    Beep(700, 200);
    // system("pause>nul");
    }

void printHeader(int y, int m)
{
    gotoxy(30, 5); cout << y << " - ";
    gotoxy(38, 5);
    switch (m){
    case 1: cout << m << " January"; break;
    case 2: cout << m << " Febreuary"; break;
    case 3: cout << m << " March"; break;
    case 4: cout << m << " April"; break;
    case 5: cout << m << " May"; break;
    case 6: cout << m << " June"; break;
    case 7: cout << m << " July"; break;
    case 8: cout << m << " Aougust"; break;
    case 9: cout << m << " Sebtember"; break;
    case 10:cout << m << " October"; break;
    case 11:cout << m << " November"; break;
    case 12:cout << m << " December"; break;
    };
    //gotoxy(20, 7); cout << "-----------------------------------------\n";
    //gotoxy(20, 8); cout << "mon   tue   wed   thu   fri   sat   sun" << endl;
    //gotoxy(20, 9); cout << "------------------------------------------\n";

    gotoxy(20, 7); cout << "-----------------------------------------\n";
    gotoxy(20, 8); cout << "sat   sun   mon   tue   wed   thu   fri " << endl;
    gotoxy(20, 9); cout << "------------------------------------------\n";

} // end of function print_Header;
//===============================================================

int findMonthDays(int month, int y)
{
    int days = 0;
    switch (month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:  days = 31; break;
    case 4:
    case 6:
    case 9:
    case 11:  days = 30; break;
    case 2: { if (y % 4 == 0) days = 29;
          else days = 28;
        break;
    };
    };
    return days;
} // end of function findMonthDays

// ===================================================
int main()
{
    clrscr();
    int month, year, startday, maxdays, week_position,daycount,h,last_position,last;
    char choice;
    bool on;
    year = 2022;
    month = 1;
    startday = 1;
    week_position = startday;
    // positin = in which day the month starts.
    // to go forward or backward to display next month

    do { // stop by inter 'S' charactar
        clrscr();
        on = false;
        printHeader(year, month);
        maxdays = findMonthDays(month, year);

        week_position = startday; // startday is change output  
        last_position = week_position;
gotoxy(2,2);
cout << "maxdays = " << maxdays << "| last_pos = " << week_position <<" startday : " << startday << " Count_Space is : " << (week_position - 1);

       gotoxy(20, 10);//is last position
        for (int k = 1; k <= startday - 2 ; k++){ 
            cout << "      ";
           }//if startday == 3 print one 'space' AND 5 print three space meaning (startday - 2) = num of spaces
        daycount = 1,h = 0; 

        while (daycount <= maxdays){
            gotoxy(20 + (week_position - 1) * 6 , 10 + h );
            // w = 01 | 02 | 03 | 04 | 05 | 06 | 07
            // x = 20 | 26 | 32 | 38 | 44 | 50 | 56

            if( daycount < 10 ){cout << " " << daycount++ << "      ";}else{cout << daycount++ << "      ";}
            if ((week_position % 7) == 0)  // start sequence of days in new line
            {
                h = h + 2; week_position = 1;
            }
            else
                week_position++;

        }// to locate the right position of days sequence

        gotoxy(20 , 10+h+1);
        cout << "------------------------------------------\n";
        gotoxy(70, 13); cout << "  --> ";
        gotoxy(68, 14); cout << "next month ";
        gotoxy(3, 13); cout << "  <-- ";
        gotoxy(1, 14); cout << "prev month ";
        gotoxy(35, 22); cout << " to stop press any button else Right and Left: ";
        //gotoxy(5, 22); cin >> choice; // chice F : B : S

        system("pause>nul");
        
        if (GetAsyncKeyState(VK_RIGHT)){
            on = GetAsyncKeyState(VK_RIGHT);
            cout << on;
            month++;
            if (month > 12){
                month=1; year++;
                bob();
                // short_test();
            }
        }else if (GetAsyncKeyState(VK_LEFT)){ //choice == 'B' || choice == 'b'
                on = GetAsyncKeyState(VK_LEFT);
                cout << on;
                month--;
                if (month < 1){
                    month=12; year--;
                    beb();
                    // short_test();
                }
                last = last_position; // 1
                last_position = last - (findMonthDays(month, year) % 7);
                if(last_position == 0){last_position = 7;}
                else if(last_position < 0){
                   last_position = last - ((findMonthDays(month, year) % 7) - 7);
                }
                
                week_position = last_position;
            }
        startday = week_position;
   
    } while (on); // end of do while

return 0;
} // end of main program
/* ==============================================================================

1- STUDY THE ABOVE CODE.

2- IMPLEMENT IT INTO YOUR COMPUTER.

3- There is some bugs in this program .. test it and try to find the bugs.

4- TRY TO IMPROVE THIS CODE BY MINIMIZING EXTRA UN-NESSESARY STATEMENTS AND BY
   DESIGNING MORE FUNCTIONS.

5- TRY TO IMPROVE THE ABOVE CODE TO DO CALENDAR BROWSING USING LEFT & RIGHT ARROWES DIRECTLY.
 */

