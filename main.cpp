#include <ncurses.h>
#include <unistd.h>
#include "Ball.h"
#include <iostream>
#include <thread>
#include <vector>
#include <time.h>
#include <random>


void run(WINDOW *win, std::vector<Ball*> *balls){
    
    while(true){
        for(int i = 0; i < balls->size(); i++){
            usleep(50000 * balls->at(i)->getSpeed());
            if(balls->at(i)->getYPosition() == 0)balls->at(i)->setGoingUp(false);
            if(balls->at(i)->getYPosition() == win->_maxy)balls->at(i)->setGoingUp(true);
            if(balls->at(i)->getXPosition() == 0)balls->at(i)->setCanLeft(false);
            if(balls->at(i)->getXPosition() == win->_maxx)balls->at(i)->setCanRight(false);   
            balls->at(i)->move();
        }
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

void newBall(std::vector<Ball*> *balls, WINDOW *win){
    srand(time(NULL));
    
    while(true){
        Ball *ball = new Ball(rand() % win->_maxx, rand() % win->_maxy, rand() % 5);
        balls->push_back(ball);  
        sleep(2);
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
    
    std::thread creator(newBall, balls, win);
    std::thread move(run, win, balls);
    std::thread refresher(refr, win, balls);
    
    refresher.join();
    move.join();
    creator.join();

    endwin();
    return 0;
}

