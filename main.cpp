#include <ncurses.h>
#include <unistd.h>
#include "Ball.h"
#include <iostream>
#include <thread>
#include <vector>
#include <time.h>
#include <random>


void run(WINDOW *win, Ball *ball){
    
    while(true){
        usleep(5000 * ball->getSpeed());
        if(ball->getYPosition() == 0)ball->setGoingUp(false);
        if(ball->getYPosition() == win->_maxy)ball->setGoingUp(true);
        if(ball->getXPosition() == 0)ball->setCanLeft(false);
        if(ball->getXPosition() == win->_maxx)ball->setCanRight(false);   
        ball->move();

    }

}

void refr(WINDOW *win, std::vector<Ball*> *balls){
   
    while(true){    
        wclear(win);
        for(int i = 0; i < balls->size(); i++){
            mvwprintw(win, balls->at(i)->getYPosition(), balls->at(i)->getXPosition(),"o");
        }
        wrefresh(win);
    }
}

void newBall(std::vector<Ball*> *balls, std::vector<std::thread> *threads,WINDOW *win){
    srand(time(NULL));

    while(true){

        Ball *ball = new Ball(rand() % win->_maxx, rand() % win->_maxy, rand() % 5 + 1);
        std::thread movement(run, win, ball);
        balls->push_back(ball);
        threads->push_back(std::move(movement));
        sleep(1);
    
    }
}

void closeProgram(std::vector<std::thread> *threads){
    
}

int main(){



    std::vector<Ball*> *balls = new std::vector<Ball*>();
    std::vector<std::thread> *threads = new std::vector<std::thread>();

    initscr();
    noecho();
    cbreak();
    curs_set(0);

    int height, width, startingY, startingX;
    height = 40;
    width = 120;
    startingX = startingY = 2;


    WINDOW *win = newwin(height, width, startingX, startingY);
    
    std::thread creator(newBall, balls, threads, win);
    std::thread refresher(refr, win, balls);
    std::thread close(closeProgram,threads);
    
    refresher.join();
    creator.join();
    close.join();

    endwin();
    return 0;
}

