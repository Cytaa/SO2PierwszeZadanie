#include <ncurses.h>
#include <unistd.h>
#include "Ball.h"
#include <iostream>
#include <thread>


void run(Ball *ball, WINDOW *win){
    int i = 100;
    while(i != 0){
            noecho();
            wclear(win);
            box(win,0,0);
            mvwprintw(win, ball->getYPosition(), ball->getXPosition(),"*");
            wrefresh(win);
            refresh();
            usleep(50000 * ball->getSpeed());
            if(ball->getYPosition() == 0)ball->setGoingUp(false);
            if(ball->getYPosition() == win->_maxy)ball->setGoingUp(true);
            if(ball->getXPosition() == 0) ball->setCanLeft(false);
            if(ball->getXPosition() == win->_maxx)ball->setCanRight(false);   
            ball->move();
            i--;

        }
};

int main(){

    initscr();

    int height, width, startingY, startingX;
    height = 40;
    width = 120;
    startingX = startingY = 2;


    WINDOW *win = newwin(height, width, startingX, startingY);
    refresh();
    box(win,0,0);
    wrefresh(win);
    Ball *ball = new Ball(win->_maxx / 2, win->_maxy - 1, 1 );
    Ball *ball2 = new Ball(win->_maxx / 2, win->_maxy - 1, 2 );
    
    std::thread t1(run,ball,win);
    std::thread t2(run,ball2,win);


    t1.join();
    t2.join();    

    getch();
    endwin();
    return 0;
}

