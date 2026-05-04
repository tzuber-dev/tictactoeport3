#include <string>

#include "tictactoe.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;


TTTMechanics::TTTMechanics() {
    resetgame();
}




void TTTMechanics::resetgame() {
    board[0] = '1';
    board[1] = '2';
    board[2] = '3';
    board[3] = '4';
    board[4] = '5';
    board[5] = '6';
    board[6] = '7';
    board[7] = '8';
    board[8] = '9';


    //new code for portfolio 3


    activatedtrapcell = false;
    currenttrap = -1;
    placedtrapcell = false;

    currentplayerid = 'X';
}


void TTTMechanics::showboard() const {

    cout<<"\n";
    cout<<" "<<board[0]<<" | "<<board[1]<< " | "<<board[2]<<"\n";
    cout<<"---+---+---\n";
    cout<<" "<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<"\n";
    cout<<"---+---+---\n";
    cout<<" "<<board[6]<<" | "<<board[7]<< " | "<<board[8]<<"\n";
    cout<<"\n";
}

char TTTMechanics::getplayer() const {
    return currentplayerid;
}

char TTTMechanics::retrievecell(int ind) const {
    if (ind < 0 || ind > 8) {
        return '?';
    }
    return board[ind];
}


bool TTTMechanics::checkifcelltaken(int pos) const {
    if (pos < 1 || pos > 9) {
        return true;
    }
    if (board[pos-1] =='X' || board[pos-1] =='O') {
        return true;
    }
    return false;
}

//new code

int TTTMechanics::firstavailableselectionongrid() const {
    for (int x=0; x<=9; x++) {
        if (!checkifcelltaken(x)) {
            return x;
        }
    }
    return -1;
}


//new code for portfolio 3



void TTTMechanics::activatetrapcellwhenever() {
    activatedtrapcell = true;
    currenttrap = (rand()%9) +1;
    placedtrapcell = false;
};


void TTTMechanics::deactivatetrapcell() {
    activatedtrapcell = false;
    currenttrap=-1;
    placedtrapcell=false;

};


bool TTTMechanics::lastdecisionoftrapcell() const {
return placedtrapcell;
};


bool TTTMechanics::checkiftrapactivated() const {
    return activatedtrapcell;
};


int TTTMechanics::trapcelltest() const{
    return currenttrap;
};


void TTTMechanics::placetrapcelltest(int var1) {
    if (var1 >= 1 &&var1 <= 9) {
        activatedtrapcell = true;
        currenttrap = var1;
        placedtrapcell = false;
    }
};


int TTTMechanics::randomtrapcellselection() const {
    int selections[9];
    int possibilityofselections = 0;


    for (int x=1; x<=9; x++) {
        if (!checkifcelltaken(x)) {
            selections[possibilityofselections] = x;
            possibilityofselections++;
        };
    }


    if (possibilityofselections == 0) {
         return -1;
    };


    int randomness = rand() % possibilityofselections;
    return selections[randomness];
};





//end code for portfolo 3

bool TTTMechanics::makemove(int pos) {

    // new code for portfolio 3

    placedtrapcell = false;

    // end code for portfolio 3

    if (pos < 1 || pos > 9) {
        return false;
    }

    if (checkifcelltaken((pos))) {
        return false;
    }

    // new code for portfolio 3

    if (activatedtrapcell && pos == currenttrap) {
        placedtrapcell = true;
        return true;
    };
    // end code for portfolio 3

    board[pos-1] = currentplayerid;
    return true;

}

void TTTMechanics::switchcurrentplayer() {
    if (currentplayerid == 'X') {
        currentplayerid = 'O';
    } else {
        currentplayerid = 'X';

    }
}


bool TTTMechanics::winnerofgame() const {
    if (board[0]==board[1] && board[1]==board[2]) {
        return true;
    }
    if (board[3] == board[4] && board[4]==board[5]) {
        return true;
    }
    if (board[6] == board[7] && board[7]==board[8]) {
        return true;
    }

    if (board[0]==board[3] && board[3]==board[6]) {
        return true;
    }

    if (board[1] == board[4] && board[4]==board[7]) {
        return true;
    }

    if (board[2] == board[5] && board[5]==board[8]) {
        return true;
    }

    if (board[0] == board[4] && board[4]==board[8]) {
        return true;
    }

    if (board[2] == board[4] && board[4]==board[6]) {
        return true;


    }
  return false;
}

bool TTTMechanics::draw() const {
    if (winnerofgame()) {
        return false;
    };

    int a;
    for (a=0; a<9;a++) {



        // new code for portfolio 3
         if (activatedtrapcell&& a == placedtrapcell - 1) {
             continue;
         }

        //end code for portfolio 3
        if (board[a] != 'X' && board[a]!= 'O') {
            return false;
        }
    }

    return true;
};
