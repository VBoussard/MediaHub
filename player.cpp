#include "player.h"
#include "iostream"
using namespace std;

Player::Player() : QWidget()
{
    int ID_fen = (int) this->winId();
    cout<<"real IDWin player : "<< ID_fen<<endl;
}

