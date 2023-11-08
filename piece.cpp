#include "piece.h"

sf::Texture Piece::whiteKing;
sf::Texture Piece::blackKing;
sf::Texture Piece::whiteQueen;
sf::Texture Piece::blackQueen;
sf::Texture Piece::whiteRook;
sf::Texture Piece::blackRook;
sf::Texture Piece::whiteBishop;
sf::Texture Piece::blackBishop;
sf::Texture Piece::whiteKnight;
sf::Texture Piece::blackKnight;
sf::Texture Piece::whitePawn;
sf::Texture Piece::blackPawn;

void Piece::setPiece(char type, bool player, int pos, bool moved){
    setType(type);
    setPlayer(player);
    setPosition(pos); //m_moved true
    setMoved(moved); // m_moved false
    //en el argumento bool player---> true(blanco) -  false(negro)
}

std::string Piece::toString(){
    std::string str;

    str += m_player?"White ":"Black ";

    switch (m_type)
    {
        case 'K':
            str += "King ";
            break;
        case 'Q':
            str += "Queen ";
            break;
        case 'R':
            str += "Rook ";
            break;
        case 'B':
            str += "Bishop ";
            break;
        case 'N':
            str += "Knight ";
            break;
        case 'P':
            str += "Pawn ";
            break;
        default:
            str += "??? ";
            break;
    }

    str += "\nto position\nX: ";
    str += std::to_string((m_position%8)+1);
    str += "  Y: ";
    str += std::to_string((m_position/8)+1);
    str += '\n';


    return str;

}

void Piece::move(){
    if(m_position<=-1 || 64<=m_position){
        m_position = -1;
        m_sprite.setColor(sf::Color(0x00000000));
        m_sprite.setPosition(sf::Vector2f((m_position % 8) * 64.f + 32.f, (m_position / 8) * 64.f + 32.f));
        possibleMoves.clear();
        m_moved = true;
    }
    else{
        m_sprite.setPosition(sf::Vector2f((m_position % 8) * 64.f + 32.f, (m_position / 8) * 64.f + 32.f));
        m_moved = true;
    }
    return;
}

void Piece::loadTextures(){
    whiteKing.loadFromFile("D:/PruebaCLion/Textures/w_king.png");
    blackKing.loadFromFile("D:/PruebaCLion/Textures/b_king.png");
    whiteQueen.loadFromFile("D:/PruebaCLion/Textures/w_queen.png");
    blackQueen.loadFromFile("D:/PruebaCLion/Textures/b_queen.png");
    whiteRook.loadFromFile("D:/PruebaCLion/Textures/w_rook.png");
    blackRook.loadFromFile("D:/PruebaCLion/Textures/b_rook.png");
    whiteBishop.loadFromFile("D:/PruebaCLion/Textures/w_bishop.png");
    blackBishop.loadFromFile("D:/PruebaCLion/Textures/b_bishop.png");
    whiteKnight.loadFromFile("D:/PruebaCLion/Textures/w_knight.png");
    blackKnight.loadFromFile("D:/PruebaCLion/Textures/b_knight.png");
    whitePawn.loadFromFile("D:/PruebaCLion/Textures/w_pawn.png");
    blackPawn.loadFromFile("D:/PruebaCLion/Textures/b_pawn.png");

}

void Piece::setTexture(){
    // ELIMINAR : m_sprite = sf::Sprite();creando una nueva instancia de sf::sprite, es el constructor
    switch (m_type)
    {
        case 'K':
            m_sprite.setTexture(m_player ? whiteKing : blackKing);
            break;
        case 'Q':
            m_sprite.setTexture(m_player ? whiteQueen : blackQueen);
            break;
        case 'R':
            m_sprite.setTexture(m_player ? whiteRook : blackRook);
            break;
        case 'B':
            m_sprite.setTexture(m_player ? whiteBishop : blackBishop);
            break;
        case 'N':
            m_sprite.setTexture(m_player ? whiteKnight : blackKnight);
            break;
        case 'P':
            m_sprite.setTexture(m_player ? whitePawn : blackPawn);
            break;
        default:
            std::cerr << "Error piece type does not exist.\n";
            break;
    }
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x/2 , m_sprite.getTexture()->getSize().y/2));//definimos el centro de la textura, el origen donde se realizaran transformaciones
    m_sprite.setScale(sf::Vector2f(0.150f,0.150)); //la sprite se escala a 0.375 veces su tamaño original, se hace mas pequeña
}