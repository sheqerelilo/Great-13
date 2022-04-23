// ----------------------------------------------------------------------

/* ----------------------------------------------------------------------
    Program 2: Great 13
        Peg puzzle. Jump pegs to try and leave only a single peg.

    Course: CS 141, Fall 2021
    System: Windows using CLion
    Author: Sheqere Lilo

    Running the program looks like:
        . . .
   ----------------------------------------------------------------------
*/
#include <iostream>
#include <cctype>   // for toupper()
using namespace std;

char pA='#',pB='#',pC='#',pD='#',pE='#',pF='#',pH='#',pI='#',pJ='#',pK='#',pL='#',pM='#', pG='.'; // global variables are set using char.


void displayInstructions()
{
    cout << "Class: CS 141             \n"
         << "Program: #2 Great 13      \n"
         << "  \n"
         << "Make a series of jumps until there is a single piece left in the   \n"
         << "middle. On each move you must jump an adjacent piece into an empty \n"
         << "square, jumping horizontally, vertically, or diagonally.           \n"
         << "Input of 'R' resets the board back to the beginning, and input of  \n"
         << "'X' exits the game.'   \n"
         << endl << endl;
}
int spacesRemaining=12;



void restart()
{pA='#',pB='#',pC='#',pD='#',pE='#',pF='#',pH='#',pI='#',pJ='#',pK='#',pL='#',pM='#',pG='.';
    spacesRemaining=12;  //Variable used to keeo track of the numbers displayed in the board.


}



void displayBoard()
{
    cout <<""
         <<                 "     Board   " <<            " Position \n"
         <<"       "             << pA <<             "          A    \n"
         <<"     " <<      pB<<" "<<pC<<" "<<pD<<       "      B C D  \n"
         <<"   "<<pE<<" "<<pF<<" "<<pG<<" "<<pH<<" "<<pI<<"  E F G H I\n"
         <<"     " <<      pJ<<" "<<pK<<" "<<pL<<       "      J K L  \n"
         <<"       "             << pM <<             "          M    \n"
         << endl;
} //end displayBoard()
bool checkMove = false;
//the bool variable is int for keeping track of the moves being made.

void start(char& w){ //sets and flips the # sign with the (.) sign.
    if (w=='#'){w='.';}
}



void end(char& t){
    if (t=='.'){t='#';} //same fuction just the opposite.
}

bool correctSymbol(char x, char y, char z){ //this variables checks to see if the right symbol is being placed in the correct spot.

    for(int i=0; i<=3; i++) {
        char l = '&';
        if (i == 1) { l = x; }
        if (i == 2) { l = y; }
        if (i == 3) { l = z; }
        switch (l) {
            case 'A':
                l= pA;
                break;
            case 'B':
                l = pB ;
                break;
            case 'C':
                l = pC;
                break;
            case 'D':
                l= pD;
                break;
            case 'E':
                l = pE;
                break;
            case 'F':
                l= pF;
                break;
            case 'G':
                l=pG;
                break;
            case 'H':
                l = pH;
                break;
            case 'I':
                l = pI;
                break;
            case 'J':
                l = pJ;
                break;
            case 'K':
                l = pK;
                break;
            case 'L':
                l = pL;
                break;
            case 'M':
                l = pM;
                break;
        }
        if (i == 1) { x = l; }


        if (i == 2) { y = l; }


        if (i == 3) { z = l; }
    }
    if (x=='#' && y=='#' && z=='.'){
        checkMove=true;}


    else {checkMove=false;}
    if (x=='.'){cout<<"   *** Source must have a piece. Please retry"<<endl<<endl;}
    else if(y=='.'){cout<<"   *** Must jump a piece. Please retry"<<endl<<endl;}
    else if(z=='#'){cout<<"   *** Destination must be blank. Retry"<<endl<<endl;}

    return checkMove;
}
bool topToBottom(char s,char e){ //variable checks the relation  between the top and bottom of the board.


    checkMove=false;
    int is = s;
    s = s - 64;
    int ie = e;
    e = e - 64; 

    if(s==1||s==13){
        if(e==5||e==7||e==9){
            checkMove=true; //checks to see if s = 1 and e =5 and so forth. same concept for the below variables.
        }
    }
    if(s==7){

        if(e==1||e==5||e==9||e==13){
            //end position can only be 1 5 9 or 13
            checkMove=true;
        }
    }
    if(s==9||s==5){
        if(e==1||e==7||e==13){
            checkMove=true;
        }
    }
    if(s==3||s==11){
        if(e==11||e==3){
            checkMove=true;
        }
    }
    if(s==8||s==6){
        if(e==8||e==6){
            checkMove=true;
        }
    }
    if(s==12||s==2){
        if(e==4||e==10||e==2||e==12){
            checkMove=true;
        }
    }
    if(s==4||s==10){
        if(e==2||e==12||e==4||e==10){
            checkMove=true;
        }
    }
    return checkMove;
}
bool JumpCheck(char s, char m) { //relation between middle and top positon.
    int is = s;
    s = s - 64;
    int im = m;
    m = m - 64;
    //s initializes start and m initializes middle.

    checkMove=false;
    if (m != 1 && m != 5 && m != 9 && m != 13 && s!=m) {

        if (s == 1) { //is s == 1 then m is <=4. same for the values below.
            if (m <= 4) {
                
                checkMove = true;
            }
        }

        if (s == 13) {
            if (m >= 10) {
                checkMove = true;
            }
        }
        int top;
        int end;
        if (s > 1 && s < 13 && s != 9 && s != 5) {
            top = s - 4;
            end = s + 4;

            for (int i = -1; i < 2; i++) {
                int tempTop;
                int tempEnd;
                int tempCenter;
                tempTop = top + i;
                tempEnd = end + i;
                tempCenter = s + i;

                if (m == tempTop || m == tempEnd || m == tempCenter) {
                    checkMove = true;
                    break;
                }
            }
        }
        if (s == 9) {
            if (m == 8 || m == 4 || m == 12) {
                checkMove = true;
            }
        }
        if (s == 5) {
            if (m == 2 || m == 6 || m == 10) {
                checkMove = true;
            }
        }
    }

    return (checkMove);
}

bool centerToEnd(char s, char m) { //value shows the realtion between center and end of the board.

    int is = s;
    s = s - 64;
    int im = m;
    m = m - 64;

    checkMove=false;
    if (s!=m) {

        if (s == 1) {
            if (m <= 4) {
                checkMove = true;
            }
        }

        if (s == 13) {
            if (m >= 10) {
                checkMove = true;
            }
        }

        int top;
        int end;
        if (s > 1 && s < 13 && s != 9 && s != 5) {
            top = s - 4;
            end = s + 4;

            for (int j = 0; j < 2; j++) {
                if (s == 2 + j && m == 1) {
                    checkMove = true;
                }
                if (s == 12 - j && m == 13) {
                    checkMove = true;
                }

                for (int i = -1; i < 2; i++) {
                    int tempTop;
                    int tempEnd;
                    int tempCenter;
                    tempTop = top + i;
                    tempEnd = end + i;
                    tempCenter = s + i;

                    if (s == 4 && m == 5) { break; }
                    if (s == 6 && m == 1) { break; }
                    if (s == 6 && m == 9) { break; }
                    if (s == 8 && m == 5) { break; }
                    if (s == 8 && m == 13) { break; }


                    if (m == tempTop || m == tempEnd || m == tempCenter) {
                        checkMove = true;
                        break;
                    }
                }
            }

        }
        if (s == 9) {
            if (m == 8 || m == 4 || m == 12) {
                checkMove = true;
            }
        }
        if (s == 5) {
            if (m == 2 || m == 6 || m == 10) {
                checkMove = true;
            }


        }
        if (m==7&&(s==2||s==4||s==10||s==12)){checkMove=false;}
        if (m==3&&(s==2||s==4)){checkMove=false;}
        if (m==6&&(s==2||s==10)){checkMove=false;}
        if (m==11&&(s==10||s==12)){checkMove=false;}
        if (m==8&&(s==4||s==12)){checkMove=false;}

        if ((s==3||s==11)&&(m==6||m==8)){checkMove=false;}
        if ((s==8||s==6)&&(m==3||m==11)){checkMove=false;}

    }


    return (checkMove);
}





int main()
{


    displayInstructions();

    displayBoard();
    int numToMove = 1;
    char moveFrom;
    char Jump;
    char location;

    while(true) {
        if (spacesRemaining==1){
            cout<<endl<<"Congratulations, you did it!"<<endl;
            break;
        }

        cout<<numToMove<<". "<<"Enter positions from, jump, and to (e.g. EFG): ";
        cin >> moveFrom;
        moveFrom=toupper(moveFrom);
        if (moveFrom =='X'){
            cout<<"Exiting"<<endl;
            if (spacesRemaining!=1){cout<<endl<<"Better luck next time."<<endl;}
            break;
        }
        if (moveFrom =='R'){
            restart();
            numToMove = 1;
            cout<<endl<<"   *** Restarting"<<endl<<endl;
            displayBoard();
            continue;
        }

        cin>>Jump;
        Jump=toupper(Jump);
        if (Jump=='X'){
            cout<<" Exiting"<<endl<<endl<<"Better luck next time. "<<endl;
            //  if (spacesRemaining!=1)
            //  {cout<<endl<<"Better luck next time. "<<endl;}
            break;
        }
        if (Jump =='R'){
            restart();
            numToMove = 1;
            cout<<endl<<"   *** Restarting"<<endl;
            displayBoard();
            continue;
        }
        //  cout<<endl;
        cin>>location;
        cout<< endl;
        location=toupper(location);
        if (location =='X'){
            cout<<" Exiting"<<endl;
            if (spacesRemaining!=1){cout<<endl<<"Better luck next time. ";}
            break;
        }
        if (location =='R'){
            numToMove = 1;
            cout<<endl<<"   *** Restarting";
            displayBoard();
            continue;
        }


        if (!correctSymbol(moveFrom, Jump, location))
        { }
        else if ( !JumpCheck(moveFrom, Jump) || !centerToEnd(Jump, location) ||
                  !topToBottom(moveFrom, location) )
        {cout<<"   *** Pieces must be adjacent. Please retry"<<endl<<endl;}

            else {
            for (int i = 1; i < 3; i++) {
                int l = 0;
                if (i == 1) { l = moveFrom; }
                if (i == 2) { l = Jump; }
                switch (l) {
                    case 'A':
                        start(pA);
                        break;
                    case 'B':
                        start(pB);
                        break;
                    case 'C':
                        start(pC);
                        break;
                    case 'D':
                        start(pD);
                        break;
                    case 'E':
                        start(pE);
                        break;
                    case 'F':
                        start(pF);
                        break;
                    case 'G':
                        start(pG);
                        break;
                    case 'H':
                        start(pH);
                        break;
                    case 'I':
                        start(pI);
                        break;
                    case 'J':
                        start(pJ);
                        break;
                    case 'K':
                        start(pK);
                        break;
                    case 'L':
                        start(pL);
                        break;
                    case 'M':
                        start(pM);
                        break;
                }
            }
            switch (location) {
                case 'A':
                    end(pA);
                    break;
                case 'B':
                    end(pB);
                    break;
                case 'C':
                    end(pC);
                    break;
                case 'D':
                    end(pD);
                    break;
                case 'E':
                    end(pE);
                    break;
                case 'F':
                    end(pF);
                    break;
                case 'G':
                    end(pG);
                    break;
                case 'H':
                    end(pH);
                    break;
                case 'I':
                    end(pI);
                    break;
                case 'J':
                    end(pJ);
                    break;
                case 'K':
                    end(pK);
                    break;
                case 'L':
                    end(pL);
                    break;
                case 'M':
                    end(pM);
                    break;
            }
            displayBoard();
            spacesRemaining=spacesRemaining-1;
            numToMove++;

        }
    }
    cout << "Done." << endl;
    return 0;
}