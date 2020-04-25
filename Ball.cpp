#include <time.h>
#include <cstdlib>
#include "Ball.h"

Ball::Ball(int xPosition, int yPosition, int speed){
    this->xPosition = xPosition;
    this->yPosition = yPosition;
    this->speed = speed;
    this->goingUp = true;
    this->canLeft = true;
    this->canRight = true;
    this->end = false;
    this->print = true;
    srand(time(NULL));

}

int Ball::direction(){    
    if(canLeft == false && canRight == true)return random() % 2;
    if(canLeft == true && canRight == false)return random() % 2 - 1;
    return rand() % 3 - 1;
}


void Ball::move(){    
    if(this->goingUp == true){
        this->yPosition--;
        this->setXPosition(this->getXPosition() + this->direction());
    }
    else{
        this->yPosition++;
    this->setXPosition(this->getXPosition() + this->direction());
    }
    this->canLeft = true;
    this->canRight = true;
    
}

int Ball::getXPosition() const {
    return xPosition;
}

void Ball::setXPosition(int xPosition) {
    Ball::xPosition = xPosition;
}

int Ball::getYPosition() const {
    return yPosition;
}

void Ball::setYPosition(int yPosition) {
    Ball::yPosition = yPosition;
}

int Ball::getSpeed() const {
    return speed;
}

void Ball::setSpeed(int speed) {
    Ball::speed = speed;
}

void Ball::setGoingUp(bool goingUp) {
    this->goingUp = goingUp;
}

bool Ball::getGoingUp(){
    return this->goingUp;
}

bool Ball::getCanLeft(){
    return this->canLeft;
}

void Ball::setCanLeft(bool canLeft){
    this->canLeft = canLeft;
}

bool Ball::getCanRight(){
    return this->canRight;
}

void Ball::setCanRight(bool canRight){
    this->canRight = canRight;
}

void Ball::setEnd(bool end){
    this->end = end;
}

bool Ball::getEnd(){
    return this->end;
}

void Ball::setPrint(bool print){
    this->print = print;
}

bool Ball::getPrint(){
    return this->print;
}