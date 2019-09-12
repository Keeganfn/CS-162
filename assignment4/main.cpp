#include "main.h"

/*********************************************************************
 * ** Function:main.cpp
 * ** Description:main function for program calls everythign
 * ** Parameters:command line args num and bool
 * ** Pre-Conditions:command line args
 * ** Post-Conditions:program run
 * *********************************************************************/ 

using namespace std;


int main(int argc, char **argv){
        int play_again;

        bool debug;
        int size = 0;
        if(command_line_check(argc, debug, size, argv) == 1){
                return 1;
        }

        Map r1(size,debug);
        r1.game();

        do{
        play_again = int_check("Would you like to go again with the same sized prison? 1 = yes 2 = no", '1', '2');
        if(play_again == 1){
                r1.game();
        }

        }while(play_again == 1);
}


