#include <string>



class TTTMechanics {
private:
    //new code for portfolio 3
    bool placedtrapcell;
    bool activatedtrapcell;
    int currenttrap;

    // end code for portfolio 3
    char board[9];
    char currentplayerid;


public:
    TTTMechanics();

    void resetgame();
    void showboard() const;

    char getplayer() const;
    char retrievecell(int ind) const;

    bool makemove(int pos);
    bool checkifcelltaken(int pos) const;

    bool winnerofgame() const;

    bool draw() const;

    void switchcurrentplayer();

    //new code

    int firstavailableselectionongrid() const;


    //new code for portfolio 3


    void activatetrapcellwhenever();
    void deactivatetrapcell();
    bool lastdecisionoftrapcell() const;
    bool checkiftrapactivated() const;
    int trapcelltest() const;
    void placetrapcelltest(int var1);
    int randomtrapcellselection() const;



    //end code for portfolio 3





};
