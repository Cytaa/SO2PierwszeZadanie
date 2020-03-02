//
// Created by cyta on 02.03.2020.
//

#ifndef SO2_BALL_H
#define SO2_BALL_H


class Ball {
    private:
        int xPosition;
        int yPosition;
        int speed;

        int direction();
public:
    int getXPosition() const;

    void setXPosition(int xPosition);

    int getYPosition() const;

    void setYPosition(int yPosition);

    int getSpeed() const;

    void setSpeed(int speed);

public:

        Ball(int xPosition, int yPosition, int speed);

        void move();

};


#endif //SO2_BALL_H
