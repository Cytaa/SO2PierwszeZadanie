//
// Created by cyta on 02.03.2020.
//
#include <time.h>
#include <cstdlib>
#include "Ball.h"

Ball::Ball(int xPosition, int yPosition, int speed){
    this->xPosition = xPosition;
    this->yPosition = yPosition;
    this->speed = speed;

}

int Ball::direction() {
    srand(time(NULL));

    return rand() % 3 - 1;
}


void Ball::move() {
    this->yPosition--;
    this->setXPosition(this->getXPosition() + this->direction());
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

