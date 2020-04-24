#include <ncurses.h>
#include <unistd.h>
#include "Ball.h"
#include <iostream>
#include <thread>
#include <vector>
#include <time.h>
#include <random>
int ch;

void run(WINDOW *win, Ball *ball){
    while(ball->getEnd() == false){
        usleep(5000 * ball->getSpeed());
        if(ball->getYPosition() == 0)ball->setGoingUp(false);
        if(ball->getYPosition() == win->_maxy)ball->setGoingUp(true);
        if(ball->getXPosition() == 0)ball->setCanLeft(false);
        if(ball->getXPosition() == win->_maxx)ball->setCanRight(false);   
        ball->move();
    }

}

void refr(WINDOW *win, std::vector<Ball*> *balls){
   
    while(ch != 'q'){    
        wclear(win);
        for(int i = 0; i < balls->size(); i++){
            if(balls->at(i)->getPrint() == true) mvwprintw(win, balls->at(i)->getYPosition(), balls->at(i)->getXPosition(),"o");
        }
        wrefresh(win);
        usleep(400);
    }
}

void newBall(std::vector<Ball*> *balls, std::vector<std::thread> *threads,WINDOW *win){
    srand(time(NULL));
    
    while(ch != 'q'){

        Ball *ball = new Ball(rand() % win->_maxx, rand() % win->_maxy, rand() % 3 + 1);
        std::thread movement(run, win, ball);
        balls->push_back(ball);
        threads->push_back(std::move(movement));
        sleep(1);
    
    }
}

void stopProgramm( std::vector<Ball*> *balls){
    ch = getch();
    if(ch == 'q'){
        for(int i = 0; i < balls->size(); i++){
            balls->at(i)->setEnd(true);
        }
    }
}

void canMerge (std::vector<Ball*> *balls){
    while(ch != 'q'){
        for(int i = 0; i < balls->size(); i++){
            for(int y = 0; y < balls->size(); y++){
                if(i != y){
                    if((balls->at(i)->getXPosition() - balls->at(y)->getXPosition() == 0) && (balls->at(i)->getYPosition() - balls->at(y)->getYPosition() ==0)){
                        balls->at(y)->setPrint(false);
                    }
                }
            }
        }
    }
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
    std::thread end(stopProgramm, balls);
   // std::thread merg(canMerge,balls);

    


    for(int i = 0; i < threads->size(); i++){
        threads->at(i).join();
    }


    refresher.join();
    creator.join();
    //merg.join();
    end.join();
    

    endwin();
    return 0;
}

