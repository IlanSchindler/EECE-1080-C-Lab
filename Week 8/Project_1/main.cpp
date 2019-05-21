#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

struct cell{
    int val;
    bool checked;
    bool flagged;
};

const int
    gridCorner = 197, // Intersection ┼
    gridWallV = 179, // Runs vertically │
    gridWallH = 196, // Runs Horizontally ─

    zero  = static_cast<int>(' '), // All cases that a covered space can be
    one   = static_cast<int>('1'),
    two   = static_cast<int>('2'),
    three = static_cast<int>('3'),
    four  = static_cast<int>('4'),
    five  = static_cast<int>('5'),
    six   = static_cast<int>('6'),
    seven = static_cast<int>('7'),
    eight = static_cast<int>('8'),
    mine  = static_cast<int>('*'),
    flag  = 177,// ▒
    quest = static_cast<int>('?'),

    hidden = 219,// █

    maxSize = 100;

bool boardMade = false;

cell board[maxSize][maxSize];

int mineVals[] = {zero, one, two, three, four, five, six, seven, eight, mine, flag, quest};



void makeBoard(int w, int l, int desiredMines){

    for(int i = 0; i < w; i ++){ // Creates the "empty" board
        for(int j = 0; j < l; j++){
            board[i][j].val = zero;//            board[i][j].numMines = 0;
        }
    }

    for(int i = 0; i < desiredMines; i++){ // Places 10 mines in the board at random
        int y = rand()%w;
        int x = rand()%l;
        if(board[y][x].val == mine){ // Restarts that iteration of the loop if it selects a pre-existing mine
            i--;
        }
        else {
            board[y][x].val = mine; // Places a mine
        }
    }

    int numMines = 0;
    for (int i = 0; i < w; i++){
        for (int j = 0; j < l; j++){
            numMines = 0;
            if (board[i][j].val == mine) continue;
            for (int localI = -1; localI < 2; localI++){
                for (int localJ = -1; localJ < 2; localJ++){
                    if (i+localI < 0 || j + localJ < 0 || i + localI >= w || j+localJ >= l){
                        continue;
                    }
                    else {
                        if (board[i+localI][j+localJ].val == mine){
                            numMines++;
                        }
                    }
                }
            }
            board[i][j].val = mineVals[numMines];
        }
    }
    boardMade = true;
}

void makeBoardSafeStart(int w, int l, int desiredMines, int row, int col){
    for(int i = 0; i < w; i ++){ // Creates the "empty" board
        for(int j = 0; j < l; j++){
            board[i][j].val = zero;//            board[i][j].numMines = 0;
        }
    }

    for(int i = 0; i < desiredMines; i++){ // Places 10 mines in the board at random
        int y = rand()%w;
        int x = rand()%l;
        if(y == row and x == col){
            i--;
        } else if(board[y][x].val == mine){ // Restarts that iteration of the loop if it selects a pre-existing mine
            i--;
        }
        else {
            board[y][x].val = mine; // Places a mine
        }
    }

    int numMines = 0;
    for (int i = 0; i < w; i++){
        for (int j = 0; j < l; j++){
            numMines = 0;
            if (board[i][j].val == mine) continue;
            for (int localI = -1; localI < 2; localI++){
                for (int localJ = -1; localJ < 2; localJ++){
                    if (i+localI < 0 || j + localJ < 0 || i + localI >= w || j+localJ >= l){
                        continue;
                    }
                    else {
                        if (board[i+localI][j+localJ].val == mine){
                            numMines++;
                        }
                    }
                }
            }
            board[i][j].val = mineVals[numMines];
        }
    }
    boardMade = true;
}

void printBoardDebug(int w, int l){
    for(int i = -1; i < w; i ++){
        for(int j = -1; j < l; j++){
            if(i < 0 && j < 0)cout<<setw(2)<<' ';
            else if(i < 0)cout<<setw(2)<<j;
            else if(j < 0)cout<<setw(2)<<i;
            else cout<<setw(2)<<static_cast<char>(board[i][j].val);
        }
        cout << endl;
    }
}

void printBoard(int w, int l){
    system("CLS");

    for(int j = 0; j < 2; j++){
        cout<<"  ";
        for(int i = 0; i < 2*l+1; i++){
            if(i%2==0) cout<<static_cast<char>(gridWallV);
            else if ((j < 1) && ((i-1)/2) < 10) cout <<" ";
            else if (j < 1) cout << static_cast<int>(((i-1)/2)/10);
            else cout << static_cast<int>(((i-1)/2)%10);
        }
        cout<<endl;
    }
    for(int i = 0; i < 2 * w + 1; i++){
        if(i%2==0) cout << static_cast<char>(gridWallH) << static_cast<char>(gridWallH);
        else cout<<setw(2)<<((i-1)/2);
        for(int j = 0; j < 2 * l + 1; j++){
            if(i % 2 == 0 && j % 2 == 0){
                cout << static_cast<char>(gridCorner);
            } else if (i % 2 == 0){
                cout << static_cast<char>(gridWallH);
            } else if (j % 2 == 0){
                cout << static_cast<char>(gridWallV);
            } else {
                cell valToPrint = board[(i - 1) / 2][(j - 1) / 2];
                if(valToPrint.flagged){
                    cout << static_cast<char>(flag);
                } else if(!valToPrint.checked){
                    cout << static_cast<char>(hidden);
                } else {
                    cout << static_cast<char>(valToPrint.val);
                }
            }
        }
        cout << endl;
    }
   // printBoardDebug(w, l);
}



void lostGame(int w, int l){
    for(int i = 0; i < w; i++){
        for(int j = 0; j < l; j++){
            board[i][j].checked = true;
        }
    }
}

void wonGame(int w, int l){
    for(int i = 0; i < w; i++){
        for(int j = 0; j < l; j++){
            if(board[i][j].val != mine) board[i][j].checked = false;
            else board[i][j].flagged = true;
        }
    }
}

bool openCellRecursion(int w, int l, int row, int col, int &openCells){
    cell &selectedVal = board[row][col];
    selectedVal.checked = true;
    if(selectedVal.val == zero){
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                if (row + i < 0 || col + j < 0 || row + i >= w || col + j >= l){
                    continue;
                } else {
                    cell &checkVal = board[row + i][col + j];
                    //If
                    //the next cell to be checked isn't a mine
                    //AND the next cell isnt already checked
                    //AND the next cell isnt already flagged
                    //AND the next cell isnt the current cell
                    //THEN open it
                    if(checkVal.val != mine && !(checkVal.checked) && !(checkVal.flagged) && (i != 0 || j != 0)){
                        openCellRecursion(w, l, row + i, col + j, openCells);
                    }

                }
            }
        }
    }
    openCells++;
    return true;
}


bool openCell(int w, int l, int row, int col, int &openCells){
    cell &selectedVal = board[row][col];
    if(selectedVal.checked){
        return true;
    } else if(selectedVal.flagged){
        return true;
    } else if(board[row][col].val == mine){
        lostGame(w,l);
        return false;
    } else {
        selectedVal.checked = true;
        if(selectedVal.val == zero){
            for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++){
                    if (row + i < 0 || col + j < 0 || row + i >= w || col + j >= l){
                        continue;
                    } else {
                        cell &checkVal = board[row + i][col + j];
                        //If
                        //the next cell to be checked isn't a mine
                        //AND the next cell isnt already checked
                        //AND the next cell isnt already flagged
                        //AND the next cell isnt the current chell
                        //THEN open it
                        if(checkVal.val != mine && !(checkVal.checked) && !(checkVal.flagged) && (i != 0 || j != 0)){
                            openCellRecursion(w, l, row + i, col + j, openCells);
                        }

                    }
                }
            }
        }
        openCells++;
    }
    return true;
}

void flagCell(int row, int col){
    board[row][col].flagged = !board[row][col].flagged;
}



void setupGame(int &width, int &length, int &mineNum){
    system("CLS");
    bool allValid = true; //Checks number of mines can fit in grid
    int x = 0;
    const int y = 3;


    do{
        allValid = true;

        //input and validate length
        cout << "Input length of the grid: ";
        cin >> length;   // Size input
        if (length > maxSize){
            cout << "length too large. Please try again." << endl;
            allValid = false;
            continue;
        }

        //input and validate width
        cout << "Input width of the grid: ";
        cin >> width;
        if(width > maxSize){
            cout << "width too large. Please try again." << endl;
            allValid = false;
            continue;
        }

        // input and validate desired number of mines
        // invalid if number exceeds or equals number of spaces on board
        cout << "Input number of desired mines: ";
        cin >> mineNum;   // Number of mines input
        if(mineNum >= (length * width)){
            cout << "Too many mines. Please try again." << endl;
            allValid = false;
            continue;
        }
    }while(!allValid);
}

void printOutside(){
    string outsideArray[10]
    {"a 12 foot tall chocolate Easter bunny",
        "bread",
        "an item of great value. Wait, it's just an Xbox ONE...",
        "2 boxen of donuts. You look inside and find 2 moosen",
        "that this man LOVES LARGE BANANAS",
        "a whiteboard and some markers. You draw a pretty picture. Nice",
        "a slinky. You let it drop down some stairs. Good job slinky",
        "a broken down Tesla Roadster with a man inside. He probably lived a full and happy life... Probably.",
        "a brand new 2018 iPhone X. Unfortunately, it is now 2019, so the phone no longer works",
        "Schaudenfreud. It hurts...Funny"};
    cout << "You have found " << outsideArray[rand() % 10] << endl;
}

void playGame(){
    int w, l, minesToFind, flagCount = 0;
    setupGame(w,l,minesToFind);
    bool alive = true;
    int row, col,
        revealedCells,
        numCells;
    char choice;
    printBoard(w,l);
    revealedCells = 0;
    numCells = w * l - minesToFind;

    do{
        cout<<"You have found " << flagCount << "/" << minesToFind << " mines."<<endl;

        cout<<"Enter row: ";
        cin >> row;
        cout<<"Enter column: ";
        cin>>col;
        cout<<"Enter Action O (open) / F (flag): ";
        cin>>choice;
        choice = tolower(choice);
        if(row >= w || col >= l){
            printBoard(w,l);
            printOutside();
            continue;
        }
        switch(choice){
        case 'o':
            if(!boardMade){
                makeBoardSafeStart(w, l, minesToFind, row, col);
            }
            if(board[row][col].checked){
                printBoard(w, l);
                cout<<"You have already checked that space." << endl;
            } else if (board[row][col].flagged){
                printBoard(w,l);
                cout<<"That cell is flagged and cannot be opened." << endl;
            }else {
                alive = openCell(w, l, row, col, revealedCells);
                printBoard(w,l);
            }
            break;
        case 'f':
            flagCell(row, col);
            flagCount = flagCount + (board[row][col].flagged) ? 1 : -1;
            printBoard(w,l);
            break;
        default:
            cout<<"You select cell ("<<row<<","<<col<<"), but decide to neither open it nor flag it."<<endl;
            cout<<"You lightly stroke cell ("<<row<<","<<col<<")'s cheek passionately."<<endl;
            printBoard(w,l);
            break;
        }
        //cout<<"Butts";
    }while(alive && (revealedCells < numCells));
    if(alive){
        cout << "You located all the mines! \nGame Over. You win!" << endl;
    } else {
        cout << "You found a mine! \nGame Over. You lose." << endl;
    }

}

int main(){
    srand(time(NULL));
    char again = 'y';
    do{
        playGame();
        cout << "Would you like to play again (Y/N)?" << endl;
        cin >> again;
        again = tolower(again);
    }while(again == 'y');

    return 0;
}





