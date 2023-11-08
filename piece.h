/*
    This header file contains the Piece class.
*/

#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
//#include "pieceTextures.h"
using namespace std;
class Piece : public sf::Drawable{

public:

    Piece(char type='P', bool player=true, int pos=-1, bool moved=false)
    : m_type{type}, m_player{player},
    m_position{-1}, m_moved{true}, enPassant{-1}{ 

    }

    void setPiece(char type, bool player, int pos, bool moved=false);

    void setType(char ch){m_type = ch; setTexture();}
    char getType()       {return m_type;}

    void setPlayer(bool bl){m_player = bl; setTexture();}
    bool getPlayer()       {return m_player;}

    void setPosition(int pos){m_position = pos; move();}
    int getPosition()        {return m_position;}

    void setMoved(bool moved){m_moved = moved;}
    bool getMoved()           {return m_moved;}

    void setEnPassant(int x){enPassant = x;} //En Passant=capturar las piezas
    int getEnPassant()      {return enPassant;}




    std::vector<int>& getPossibleMoves(){return possibleMoves;}
    std::vector<int>& getDangerMoves(){return dangerMoves;}
    std::string toString();


    static void loadTextures();
    
    //en toda la aplicación, independientemente de cuántas instancias de Piece se creen.
    

private:
    sf::Sprite m_sprite;


    std::vector<int> possibleMoves;
    std::vector<int> dangerMoves; 


    char m_type; //'K'=King , 'Q' = Queen , 'R' = Rook , 'B' = Bishop , 'N' = Knight , 'P' = Pawn
    bool m_player; // true == White , false == Black
    int m_position; // 0-63 board, -1 dead
    int enPassant; // chess rule for pawn 
    bool m_moved;

   //texture pieces//  static Esto significa que solo habrá una copia de cada textura 
    static sf::Texture whiteKing;
    static sf::Texture blackKing;
    static sf::Texture whiteQueen;
    static sf::Texture blackQueen;
    static sf::Texture whiteRook;
    static sf::Texture blackRook;
    static sf::Texture whiteBishop;
    static sf::Texture blackBishop;
    static sf::Texture whiteKnight;
    static sf::Texture blackKnight;
    static sf::Texture whitePawn;
    static sf::Texture blackPawn;

    void setTexture();

    void move();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  
    }
};

#endif