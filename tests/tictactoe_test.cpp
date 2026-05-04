#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/tictactoe.hpp"

TEST_CASE( "First player (x) begins" ) {
    TTTMechanics tictactoe;
    REQUIRE(tictactoe.getplayer() == 'X' );
}

TEST_CASE("Good move reshapes the board") {
    TTTMechanics tictactoe;
    REQUIRE(tictactoe.makemove(1) == true);
    REQUIRE(tictactoe.retrievecell(0)== 'X');

}

TEST_CASE( "After game restarts, the numbers and board restores successfully" ) {
    TTTMechanics tictactoe;
    tictactoe.makemove(1);
    tictactoe.switchcurrentplayer();
    tictactoe.makemove(2);
    tictactoe.resetgame();

    REQUIRE(tictactoe.getplayer() == 'X' );
    REQUIRE(tictactoe.retrievecell(0)== '1');
    REQUIRE(tictactoe.retrievecell(1) == '2');
    REQUIRE(tictactoe.retrievecell(2) == '3');
    REQUIRE(tictactoe.retrievecell(3)=='4');
    REQUIRE(tictactoe.retrievecell(4)=='5');
    REQUIRE(tictactoe.retrievecell(5)=='6');
    REQUIRE(tictactoe.retrievecell(6)=='7');
    REQUIRE(tictactoe.retrievecell(7)=='8');
    REQUIRE(tictactoe.retrievecell(8)=='9');
}



TEST_CASE("Once a cell is used, the user sees an error if reattempting to place their mark on it") {
    TTTMechanics tictactoe;
    REQUIRE(tictactoe.makemove(1)==true);
    REQUIRE(tictactoe.makemove(1)==false);
}


//new code


TEST_CASE("Cpu selects first spot that is untaken") {
TTTMechanics tictactoe;

    REQUIRE(tictactoe.firstavailableselectionongrid()==1);
    tictactoe.makemove(1);

    REQUIRE(tictactoe.firstavailableselectionongrid()==2);
    tictactoe.switchcurrentplayer();
    tictactoe.makemove(2);
    REQUIRE(tictactoe.firstavailableselectionongrid()==3);



};


TEST_CASE("Restart game works") {

  TTTMechanics tictactoe;
    REQUIRE(tictactoe.makemove(1)==true);
    REQUIRE(tictactoe.firstavailableselectionongrid()==2);
    tictactoe.resetgame();
    REQUIRE(tictactoe.firstavailableselectionongrid()==1);

};



// WORK ON GETTING MORE TESTS


// new code for portfolio 3

TEST_CASE("trap feature begins again after game") {
    TTTMechanics tictactoe;
    tictactoe.placetrapcelltest(2);
    tictactoe.resetgame();
    REQUIRE(tictactoe.checkiftrapactivated() == false);
    REQUIRE(tictactoe.trapcelltest() == -1);
};


TEST_CASE("gameplay functions as is if the user selects to use trap feature") {
    TTTMechanics tictactoe;
    tictactoe.placetrapcelltest(8);
    REQUIRE(tictactoe.makemove(1)==true);
    REQUIRE(tictactoe.lastdecisionoftrapcell() == false);
    REQUIRE(tictactoe.retrievecell(0)=='X');

};
// end code for portfolio 3
