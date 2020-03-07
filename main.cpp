#include <ncurses.h>
#include <unistd.h>
#include "Ball.h"
#include <iostream>
#include <thread>


void run(WINDOW *win, Ball *ball){
    while(true){
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
    }

}

void refresh(WINDOW *win){
    
}

int main(){

    initscr();

    int height, width, startingY, startingX;
    height = 40;
    width = 120;
    startingX = startingY = 2;


    WINDOW *win = newwin(height, width, startingX, startingY);
    
    Ball *ball = new Ball(win->_maxx / 2, win->_maxy - 1, 1 );
    Ball *ball2 = new Ball(win->_maxx / 2, win->_maxy - 1, 2 );
    Ball *ball3 = new Ball(win->_maxx / 2, win->_maxy - 1, 3 );

    std::thread t1(run, win, ball);
    std::thread t2(run, win, ball2);
    std::thread t3(run, win, ball3);


    t1.join();
    t2.join();

    endwin();
    return 0;
}

