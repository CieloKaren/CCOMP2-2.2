/*
    This code file contains static member initialisations
    of pieceTextures.h
*/

#include "pieceTextures.h"

sf::Texture PieceTextures::loadTexture(std::string str){
    sf::Texture tmp;
    if (!tmp.loadFromFile(str))
        std::cout << "Error loading file\n";
    return tmp;
}

sf::Texture PieceTextures::blackKing = PieceTextures::loadTexture("D:/PruebaCLion/Textures/b_king.png");
sf::Texture PieceTextures::blackQueen = PieceTextures::loadTexture("D:/PruebaCLion/Textures/b_queen.png");
sf::Texture PieceTextures::blackRook = PieceTextures::loadTexture("D:/PruebaCLion/Textures/b_rook.png");
sf::Texture PieceTextures::blackKnight = PieceTextures::loadTexture("D:/PruebaCLion/Textures/b_knight.png");
sf::Texture PieceTextures::blackBishop = PieceTextures::loadTexture("D:/PruebaCLion/Textures/b_bishop.png");
sf::Texture PieceTextures::blackPawn = PieceTextures::loadTexture("D:/PruebaCLion/Textures/b_pawn.png");

sf::Texture PieceTextures::whiteKing = PieceTextures::loadTexture("D:/PruebaCLion/Textures/w_king.png");
sf::Texture PieceTextures::whiteQueen = PieceTextures::loadTexture("D:/PruebaCLion/Textures/w_queen.png");
sf::Texture PieceTextures::whiteRook = PieceTextures::loadTexture("D:/PruebaCLion/Textures/w_rook.png");
sf::Texture PieceTextures::whiteKnight = PieceTextures::loadTexture("D:/PruebaCLion/Textures/w_knight.png");
sf::Texture PieceTextures::whiteBishop = PieceTextures::loadTexture("D:/PruebaCLion/Textures/w_bishop.png");
sf::Texture PieceTextures::whitePawn = PieceTextures::loadTexture("D:/PruebaCLion/Textures/w_pawn.png");