#include <ncurses.h>
#include <unistd.h>
#include "Ball.h"
#include <iostream>


int main(){

    initscr();

    int height, width, startingY, startingX;
    height = 20;
    width = 70;
    startingX = startingY = 2;


    WINDOW * win = newwin(height, width, startingX, startingY);
    refresh();
    box(win,0,0);
    wrefresh(win);
    Ball *ball = new Ball(win->_maxx / 2,win->_maxy, 1 );

        for(int i = 0; i <= win->_maxy; i++){
            wclear(win);
            box(win,0,0);
            mvwprintw(win, ball->getYPosition(), ball->getXPosition(),"*");
            wrefresh(win);
            refresh();
            usleep(100000 * ball->getSpeed());
            ball->move();

        }






    getch();
    endwin();
    return 0;
}

