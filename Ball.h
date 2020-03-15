#ifndef SO2_BALL_H
#define SO2_BALL_H


class Ball {
    private:
        int xPosition;
        int yPosition;
        int speed;
        bool goingUp;
        bool canLeft;
        bool canRight;
        bool end;

        int direction();
    public:
        int getXPosition() const;

        void setXPosition(int xPosition);

        int getYPosition() const;

        void setYPosition(int yPosition);

        int getSpeed() const;

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

};


#endif //SO2_BALL_H
