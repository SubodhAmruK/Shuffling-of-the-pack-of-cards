#include<iostream>
#include <bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>
#include <windows.h>
/*The string a[m] has all the cards 

colors of the cards
B -> BLUE
G -> GREEN
R -> RED
Y -> YELLOW

type of cards
A -> ACE
J -> JACK
K -> KING
Q -> QUEEN
2,3,4,5,6,7,8,9,10 -> NUMBER CARDS

*/
#define m 52
#define m2 13
using namespace std;

void menu();

int n = 13,ch,cc=0;
int x,i,j=1,k=0;
string c,cf,ci,ck; // For game 1
string d,df,di,da;
int p1,p2,s=0;// For game 2
/*This a array That contains all the cards, B -> BLUE*/
string a[m] =    {  "B-A", "B-J", "B-K", "B-Q", "B10", "B2", "B3", "B4", "B5", "B6", "B7","B8", "B9",
                    "G-A", "G-J", "G-K", "G-Q", "G10", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9",
                    "R-A", "R-J", "R-K", "R-Q", "R10", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9",
                    "Y-A", "Y-J", "Y-K", "Y-Q", "Y10", "Y2", "Y3", "Y4", "Y5", "Y6", "Y7", "Y8", "Y9"};

string b[m2] = {  "B-A", "B-J", "B-K", "B-Q", "B10", "B2", "B3", "B4", "B5", "B6", "B7","B8", "B9"};
string r[m2] = {  "R-A", "R-J", "R-K", "R-Q", "R10", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9"};
string y[m2] = {  "Y-A", "Y-J", "Y-K", "Y-Q", "Y10", "Y2", "Y3", "Y4", "Y5", "Y6", "Y7", "Y8", "Y9"};
string g[m2] = {  "G-A", "G-J", "G-K", "G-Q", "G10", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9"};
string a1[13];

void pos()
{
    int row = 3;
    int col = 0;
    printf("\033[%d;%dH", row, col);
}
bool comparator(string a,string b)
{
    return a<b; //returns true if string a is less than b and vice-versa
}

void shuffle() //This function when called shuffles the pack
        {
            srand(time(0));

            for (int i=0; i<m ;i++)
            {
                // Random for remaining positions.
                int r = i + (rand() % m -i); // helps in randomly choose a position

                swap(a[i], a[r]); //swaps the i value positon with random positon
            }
        }

void display() //This Function displays the shuffled pack of cards
{                
    pos();
    //system("cls");

    //sort(a,a+m,comparator); //Helps in sorting of strings in an array
    string a2[m] = {  "B-A", "B-K", "B-Q", "B-J", "B10", "B9", "B8" , "B7" , "B6", "B5", "B4", "B3", "B2",
                    "G-A", "G-K", "G-Q", "G-J", "G10", "G9", "G8" , "G7" , "G6", "G5", "G4", "G3", "G2",
                    "R-A", "R-K", "R-Q", "R-J", "R10", "R9", "R8" , "R7" , "R6", "R5", "R4", "R3", "R2",
                    "Y-A", "Y-K", "Y-Q", "Y-J", "Y10", "Y9", "Y8" , "Y7" , "Y6", "Y5", "Y4", "Y3", "Y2",
                    };
                    
    for (i=0;i<m;i++)
    {
        if(i % 13 == 0) // Prints only 13 cards in a row
        {
            cout<<"\n";
        }
        cout<<"\t"<<a2[i]<<"  ";

    }
    fflush(stdin);
    getchar();
}


void multishuf()
{
    //system("cls");
    pos();
    int ms;
    cout<<"Number of Shuffles : ";
    cin>>ms;
    fstream new_file; 
    new_file.open("new_file_write.txt",ios::out);  
    if(!new_file) 
    {
        cout<<"File creation failed";
    }
    else
    {
        cout<<"Shuffled cards will be stored into a file"<<"\n";
        //new_file<<"Learning File handling"<<"\n";    //Writing to file
        
    }   
    while(ms)
    {
        shuffle(); // shuffle the pack

            for (i=0;i<m;i++)
            {
                if(i % 13 == 0) // Prints only 13 cards in a row
                {
                    cout<<"\n";
                    //new_file<<"\n";
                }
                cout<<"\t"<<a[i]<<"  ";
                new_file<<"\t"<<a[i]<<"  ";
                
                //new_file<<"Learning File handling"<<"\n";
                

            }
            new_file<<"\n\n\n";
            cout<<"\n";
            ms--;

    }
    new_file.close(); 

    fflush(stdin);
    getchar();
            
}
void shufdisp() //This functions displays packs of cards used to play in real time
{
    //system("cls");
    pos();
    cout<<"\nCards Shuffled Successfully!!!";
    
    cout<<"\n\n\n\nNumber of Players(2-4): "; //
    cin>>x; //This is for only 2 to 4 player games

    if(x>=2 && x<=4)
    {
        for (i=0; i<m - (m-(x*13)); i++)
        {
            if(i % 13 == 0)
            {

                cout<<"\n\n"<<"Player "<<j<<": ";
                j++;
            }
            cout<<"\t"<<a[i]<<"  ";
        }
    }
    else
    {
        cout<<"Error!";
    }
    cout << endl;
    
    fflush(stdin);
    getchar();

}


void game1() // Pick a Card
{
    //system("cls");
    pos();
    shuffle(); //Shuffle the deck
    cout<<"\n  ";
    for(i=0;i<5;i++)
    {
        cout<<a[i]<<"  "; // Displays 5 cards
    }
    srand(time(0));

    ci = a[rand()%4]; // Computer choose one from 5 cards

    do
    {
        cout<<"\n  Choose one from above 5 : ";
        cin>>c; //Your choice
        cout<<"\n  Lock your choice? (y/n) : ";
        cin>>cf; // Can proceed only when you press y for locking the choice
    }
    while(cf == "n" || cf == "N");

        if (c == ci) // If your choice matches computer's choice
        {
            cout<<"\n  You Won!"
                <<"\n  Computer    : "<<ci
                <<"\n  Your choice : "<<c;
        }
        else // If your choice doesn't matche computer's choice
        {
            cout<<"\n  You Lost!"
                <<"\n  Computer    : "<<ci
                <<"\n  Your choice : "<<c;
        }
        fflush(stdin);
        getchar();
}


bool areEqual(string arr1[], string arr2[]) //Function for comparing array of strings
{
    
    // Linearly compare elements
    for (int i = 0; i <= m2-1; i++)
        if (arr1[i] != arr2[i])
            return false; // If all elements are not same

    // If all elements were same.
    return true;
}
void game2()
{
    //system("cls");
    pos();
    shuffle(); // Shuffle the deck
    cout<<"\nSwaps:"<<s; //No.of Swaps
    do
    {
        cout<<"\n\n   DECK: ";
        cout<<"\n     ";
        cout<<"____________________________________________________________________________________\n     |";
        for(i=40;i<=m;i++)
        {
            cout<<" "<<a[i]<<" | "; // Display 13 Cards randomly
        }
        cout<<"\n     ------------------------------------------------------------------------------------\n     ";
        srand(time(0));
        p1 = rand() % 38; //Computer chooses one card randomly from the reaming 38 cards
        d = a[p1];

        do
        {
            cout<<"\n    \tEnter the card you want to swap from deck: ";
            cin>>di; //Input the card which you want to swap

            cout<<"\n    \tLock your choice? (y/n) : ";
            cin>>df; //Proceeds further only when you lock your choice with Y
        }
        while(df == "n" || df == "N" || di == "0");
        cc=0;
        for(i=39;i<=m;i++) // find the location of the input element from the deck.
        {
            if (a[i] == di)
            {
                cc=1;
                p2 = i;
            }
        }

        if(cc==1)
        {
            swap(a[p2],a[p1]); // Swaps the computer choice and your choice
            s++; // Swap in incremented
            cout<<"\nSwaps:"<<s;
            cout<<"\n"<<a[p1]<<" is replaced with "<<a[p2]<<" successfully!";
            cout<<"\n     ____________________________________________________________________________________\n     |";
            for(i=40;i<=m;i++)
            {
                cout<<" "<<a[i]<<" | ";
            }
            cout<<"\n     ------------------------------------------------------------------------------------\n     ";

        }
        else
        {
            cout<<di<<" is not found in the pack!"; //If the input element is not there
        }

        cout<<"\nDo you want to Continue swapping? (y/n): ";
        cin>>da;
    }
    while(da == "y" || da == "Y"); // Stop swapping to further proceed.
    cout<<" \n---------------";
    cout<<" \n| "<<"Swaps:"<<s<<"     | ";

        for(i=40,k=0;i<=m;i++,k++)
        {
            a1[k] = a[i]; // Every element of array a are copied into array a1 
        }
        //cout<<"\n     ----------------------------------------------------------------------\n     ";
        sort(a1,a1+n,comparator); // sorts the array of strings
        if (areEqual(a1, b)) //If the array a1 elements match with Blue color deck
            cout << "\n| BLUE MATCHES! | "; 
        else if(areEqual(a1,r))
            cout <<"\n| RED MATCHES! | "; //If the array a1 elements match with Red color deck
        else if(areEqual(a1,g))
        {
            cout <<"\n| GREEN MATCHES! | "; //If the array a1 elements match with Green color deck
        }
        else if(areEqual(a1,y))
        {
            cout << "\n| YELLOW MATCHES! | "; //If the array a1 elements match with Yellow color deck
        }
        else
        {
            cout << "\n| No matches! | ";
        }
        cout<<" \n---------------";
        fflush(stdin);
    getchar();
}

void menu()
{
    system("cls");
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t____________________\n"
        <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|                  |"
        <<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|   Shuffle Game!  |\n"
        <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|                  |\n"
        <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|------------------|\n"
        <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| 1. Display Cards |\n"
        <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| 2. Shuffle Cards |\n"
        <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| 3. Multi Shuffle |\n"
        <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| 4. Play Game 1   |\n"
        <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| 5. Play Game 2   |\n"
        <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| 6. Exit          |\n"
        <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|__________________|"
        <<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: display();
                    break;
            case 2: shufdisp();
                    break;
            case 3: multishuf();
                    break;
            case 4: game1();
                    break;
            case 5: game2();
                    break;
            case 6: exit(0);
                    break;

            default: cout<<"Error! Wrong Input";
                     break;
        }
}
int main()
{
    
    while(1)
    {
        menu();
    }

}
