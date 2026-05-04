

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include "src/tictactoe.hpp"


bool validinputformovement(const std::string& inputuser) {
    if (inputuser.length() !=1) {

        return false;

    }

    if (inputuser[0] < '1' || inputuser[0] > '9') {
        return false;
    }
    return true;
}


bool validinputformovementplayagain(const std::string inputuser) {
    if (inputuser.length() !=1) {
        return false;
    }
    if (inputuser[0] == 'Y' || inputuser[0] == 'y' || inputuser[0] == 'N' || inputuser[0] == 'n' ) {
        return true;
    }
    return false;
};

//new code

bool menuselectionverification(const std::string inputuser) {
    if (inputuser.length() !=1) {
        return false;
    }
    return (inputuser[0] == '1' || inputuser[0] == '2' || inputuser[0] == '3' );
}



//new code for portfolio 3


bool selectnewtrapfunction(const std::string inputuser) {
    if (inputuser.length() !=1) {
        return false;
    };


    return (inputuser[0] == '1' || inputuser[0] == '2' );
}


//end code for portfolio 3





int main() {


    // new code for portfolio 3

    srand(time(0));
    //end code for portfolio 3
    TTTMechanics tictactoe;
    std::string inputuserfield;
    bool playonemoretime = true;

    std::cout<<"~Welcome to the Tic-Tac-Toe game!~";
    std::cout<<"\n";
    std::cout<<"A Player is letter X and B Player is letter O";


    while (playonemoretime) {


        tictactoe.resetgame();

        //new code

        int versionofmatch = 0;

        while (true) {
            std::cout<<"\n";
            std::cout<<"\n";

            std::cout<<"+------------------------------------------+";
            std::cout<<"\n";
            std::cout<<"\n";
            std::cout<<"[Select game mode]: "<<"\n";

            std::cout<<"\n";
            std::cout<<"\n";

            std::cout<<"\n";
            std::cout<<"1. Human against human"<<"\n";
            std::cout<<"2. Human against computer"<<"\n";
            std::cout<<"3. Computer against human"<<"\n";
            std::cout<<"\n";
            std::cout<<"\n";
            std::cout<<"+------------------------------------------+";
            std::cout<<"\n";
            std::cout<<"\n";
            std::cout<<"Enter number: ";


            std::getline(std::cin,inputuserfield);

            if (!menuselectionverification(inputuserfield)) {
                std::cout<<"! INVALID INPUT, RETRY !"<<"\n";
                continue;
            }
            versionofmatch = inputuserfield[0] - '0';
            break;
        };


        // new code for portfolio 3
        while (true) {
            std::cout<<"Would you like to include trap cell in your game?"<<std::endl;
            std::cout<<"1. Yes"<<std::endl;
            std::cout<<"2. No"<<std::endl;


            std::getline(std::cin, inputuserfield);


            if (!selectnewtrapfunction(inputuserfield)) {
                std::cout<<"! INVALID INPUT, RETRY !"<<"\n";
                continue;
            };


            if (inputuserfield[0] =='1') {
                tictactoe.activatetrapcellwhenever();
            } else {
                tictactoe.deactivatetrapcell();
                std::cout<<"Trap cell is not activated this round!"<<std::endl;
            }


            break;



        }

        //end code for portfolio 3

        if (versionofmatch == 2) {
            std::cout<<"Computer goes second."<<"\n";
        }else if (versionofmatch == 3) {
            std::cout<<"Computer goes first."<<"\n";
        };

        tictactoe.showboard();


        while (true){

            //new code

            bool computerchoice = false;

            if (versionofmatch ==2 && tictactoe.getplayer() == 'O') {
                computerchoice = true;
            };

            if (versionofmatch ==3 && tictactoe.getplayer() == 'X') {
                computerchoice = true;
            };

            if (computerchoice) {


                //new code for portfolio 3


                int turnforcomputernewfunc = tictactoe.randomtrapcellselection();



                //end code for portfolio 3
                int computerstep = tictactoe.firstavailableselectionongrid();
                std::cout<<"Computer selected: "<<computerstep<<"\n";
                tictactoe.makemove(computerstep);
            } else {

                std::cout<<"Player"<<tictactoe.getplayer()<<" enter a move (1-9): ";
                std::getline(std::cin,inputuserfield);

                if (!validinputformovement(inputuserfield)) {
                    std::cout<<"Invalid input. Retry."<<"\n";
                    continue;
                }
                int userstep = inputuserfield[0] - '0';

                if (!tictactoe.makemove(userstep)) {
                    std::cout<<"Uh oh! Not correct input. Please retry. \n";
                    continue;
                };


                //new code for portfolio 3




                if (tictactoe.lastdecisionoftrapcell()) {
                    std::cout<<"Oh no! You set off the trap! Player "<<tictactoe.getplayer()<<" loses their turn.";
                }



                //end code for portfolio 3


            }



            //if (invalidinput)
            int usermove = inputuserfield[0] - '0';


            tictactoe.showboard();
            if (tictactoe.winnerofgame()) {
                tictactoe.showboard();
                std::cout<<"Player "<<tictactoe.getplayer()<<" wins the match!\n";
                break;
            }
            if (tictactoe.draw()) {
                tictactoe.showboard();
                std::cout<<"Draw! \n";
                break;
            }
            tictactoe.switchcurrentplayer();
        }


        while (true){
            std::cout<<"Play again? (y/n): ";
            std::getline(std::cin,inputuserfield);

            ///add anms
            ///

            if (inputuserfield.length() != 1) {
                std::cout<<"Invalid input. Retry."<<"\n";
                continue;
            }

            if (inputuserfield[0] == 'y' || inputuserfield[0] == 'Y') {

                playonemoretime = true;
                break;



            } else if (inputuserfield[0] == 'n' || inputuserfield[0] == 'N') {
                playonemoretime = false;
                break;
            } else {
                std::cout<<"Wrong input. Retry."<<"\n";
            }
            //break;
        }


        }
    std::cout<<"Thanks for playing the game!";
    return 0;

};
