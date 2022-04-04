#include "Snake.h"

Snake::Snake(COORD pos, int vel)
{
    this->pos = pos;
    this->vel = vel;

    dir = 'n';
    len = 1;

    body.push_back(pos);
}

void Snake::direction(char dir) { this->dir = dir; }
void Snake::grow() { len++; }
COORD Snake::get_pos() { return pos; }

vector<COORD> Snake::get_body() { return body; }

void Snake::move_snake()
{
    switch(dir)
    {
        case 'u': pos.Y -= vel; break;
        case 'd': pos.Y += vel; break;
        case 'l': pos.X -= vel; break;
        case 'r': pos.X += vel; break;
    }

    body.push_back(pos);
    if(body.size() > len) body.erase(body.begin());
}



bool Snake::eaten(COORD food)
{
    if(pos.X == food.X && pos.Y == food.Y) return true;
    return false;
}
