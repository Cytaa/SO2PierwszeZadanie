#include <ncurses.h>
#include <unistd.h>
#include "Ball.h"
#include <iostream>
#include <thread>
#include <vector>


void run(WINDOW *win, Ball *ball){
    while(true){
            usleep(50000 * ball->getSpeed());
            if(ball->getYPosition() == 0)ball->setGoingUp(false);
            if(ball->getYPosition() == win->_maxy)ball->setGoingUp(true);
            if(ball->getXPosition() == 0) ball->setCanLeft(false);
            if(ball->getXPosition() == win->_maxx)ball->setCanRight(false);   
            ball->move();
    }

}

void refr(WINDOW *win, std::vector<Ball*> *balls){
   
    while(true){    
        wclear(win);
        box(win,0,0);

        for(int i = 0; i < balls->size(); i++){
            mvwprintw(win, balls->at(i)->getYPosition(), balls->at(i)->getXPosition(),"o");
        }
        wrefresh(win);
        refresh();
    }
}

int main(){



    std::vector<Ball*> *balls = new std::vector<Ball*>();

    initscr();
    noecho();
    cbreak();

    int height, width, startingY, startingX;
    height = 40;
    width = 120;
    startingX = startingY = 2;


    WINDOW *win = newwin(height, width, startingX, startingY);
    
    Ball *ball = new Ball(win->_maxx / 2, win->_maxy - 1, 1 );
    Ball *ball2 = new Ball(win->_maxx / 2, win->_maxy - 1, 2 );

    balls->push_back(ball);
    balls->push_back(ball2);

    
    std::thread refresher(refr, win, balls);
    std::thread t1(run, win, ball);
    std::thread t2(run, win, ball2);
    
    


    t1.join();
    t2.join();    

    refresher.join();

    endwin();
    return 0;
}

