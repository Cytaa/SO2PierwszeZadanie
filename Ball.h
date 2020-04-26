#ifndef SO2_BALL_H
#define SO2_BALL_H
#include <atomic>


class Ball {
    private:
        int xPosition;
        int yPosition;
        int speed;
        bool goingUp;
        bool canLeft;
        bool canRight;
        bool end;
        std::atomic<bool> print;

        int direction();
    public:
        int getXPosition();

        void setXPosition(int xPosition);

        int getYPosition();

        void setYPosition(int yPosition);

        int getSpeed();

        void setSpeed(int speed);

        Ball(int xPosition, int yPosition, int speed);

        void move();

        void setGoingUp(bool goingUp);

        bool getGoingUp();

        void setCanLeft(bool canLeft);

        bool getCanLeft();

        void setCanRight(bool canRight);

        bool getCanRight();

        void setEnd(bool end);
        
        bool getEnd();

        void setPrint(bool print);

        bool getPrint();

};


#endif //SO2_BALL_H
