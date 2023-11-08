/*
    This code file contains member functions of chessGame.h
*/

#include "chessGame.h"
 

ChessGame::ChessGame(sf::Color bordL_col = sf::Color::White, sf::Color bordD_col = sf::Color::Black)
: board(bordL_col,bordD_col)
{   
    Piece::loadTextures();
    restart();
}


void ChessGame::restart(){

    selected = false;
    playerTurn = true;
    playerTurnCheck = false;
    mate = false;
    turn = 1;
    //PIEZAS DE LAS FILAS INFERIOR Y SUPERIOR DEL TABLERO
    blackPieces[0].setPiece('R', false, 7);
    blackPieces[1].setPiece('N', false, 6);
    blackPieces[2].setPiece('B', false, 5);
    blackPieces[3].setPiece('K', false, 4);
    blackPieces[4].setPiece('Q', false, 3);
    blackPieces[5].setPiece('B', false, 2);
    blackPieces[6].setPiece('N', false, 1);
    blackPieces[7].setPiece('R', false, 0);

    whitePieces[0].setPiece('R', true, 56); 
    whitePieces[1].setPiece('N', true, 57); 
    whitePieces[2].setPiece('B', true, 58); 
    whitePieces[3].setPiece('Q', true, 59); 
    whitePieces[4].setPiece('K', true, 60); 
    whitePieces[5].setPiece('B', true, 61); 
    whitePieces[6].setPiece('N', true, 62); 
    whitePieces[7].setPiece('R', true, 63); 

    //PEONES
    for(int i=8;i<16;i++){
        whitePieces[i].setPiece('P', true, 48 +(i-8));
        blackPieces[i].setPiece('P', false, 15 - (i-8) );
    }

    textLastMove.setString(" ");

}

void ChessGame::updateInfo(){
    textTurn.setString("Turn: " + std::to_string(turn));
    textLastMove.setString(lastMove);

    if(!mate){
        if(playerTurn)
            textSituation.setString("White's Turn");
        else
            textSituation.setString("Blacks's Turn");

        if(playerTurnCheck)
            textSituation.setString(textSituation.getString() + "\nCheck");
    }
    else{
        if(playerTurnCheck){
            if(playerTurn)
                textSituation.setString("CHECKMATE\nBlack Wins");
            else
                textSituation.setString("CHECKMATE\nWhite Wins");
        }
        else{
            textSituation.setString("STALEMATE\nIts a DRAW");
        }

    }
}


/*void ChessGame::setTarget(sf::RenderTarget& target) {
    this->target = &target;
}
*/

void ChessGame::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.clear(sf::Color::Black);

    target.draw(board); //funcion draw de board


    for(int i=0;i<16;i++){
        target.draw(whitePieces[i]);
        target.draw(blackPieces[i]);
    }
}

void ChessGame::createMovesSquares() {
    if(selectedPiece == NULL)
        return;

    sf::RectangleShape tmp;
    tmp.setPosition(sf::Vector2f((selectedPiece->getPosition() % 8) * 64.f , (selectedPiece->getPosition() / 8) * 64.f));
    tmp.setSize(sf::Vector2f(64.f, 64.f));
    tmp.setFillColor(sf::Color(0x00000000));
    tmp.setOutlineColor(sf::Color::Red);
    tmp.setOutlineThickness(-3.f);
    window->draw(tmp);
    return;
}


bool ChessGame::selectPiece(int pos){

    for(int i=0; i<16; i++){
        if(playerTurn){ // If white turn
            if(whitePieces[i].getPosition() == pos){
                selectedPiece = &whitePieces[i];
                selected = true;
                break;
            }
        }
        else{ // If black turn
            if(blackPieces[i].getPosition() == pos){
                selectedPiece = &blackPieces[i];
                selected = true;
                break;
            }
        }
        selected = false;
    }

    if(!selected){
        selectedPiece = NULL;
        return selected;
    }
    createMovesSquares();

    return selected;
}

void ChessGame::moveSelected(int pos){
    selectedPiece->setPosition(pos);
    for(int i=0; i<16;i++){
        if(selectedPiece->getPlayer()){
            if(blackPieces[i].getPosition()==pos){
                blackPieces[i].setPosition(-1);
                break;
            }
        }
        else{
            if(whitePieces[i].getPosition()==pos){
                whitePieces[i].setPosition(-1);
                break;
            }
        }
    }
    playerTurn=!playerTurn;
    selectedPiece=NULL;
    selected=false;
}

void ChessGame::calcKingMoves(Piece* tmpPiece){

    int piecePos{tmpPiece->getPosition()};
    tmpPiece->getPossibleMoves().clear();

    if((piecePos / 8) != 0){
        tmpPiece->getPossibleMoves().push_back(piecePos - 8);
        if((piecePos % 8) != 0)
            tmpPiece->getPossibleMoves().push_back(piecePos - 9);
        if((piecePos % 8) != 7)
            tmpPiece->getPossibleMoves().push_back(piecePos - 7);
    }
    if((piecePos / 8) != 7){
        tmpPiece->getPossibleMoves().push_back(piecePos + 8);
        if((piecePos % 8) != 0)
            tmpPiece->getPossibleMoves().push_back(piecePos + 7);
        if((piecePos % 8) != 7)
            tmpPiece->getPossibleMoves().push_back(piecePos + 9);
    }
    if((piecePos % 8) != 0)
        tmpPiece->getPossibleMoves().push_back(piecePos - 1);
    if((piecePos % 8) != 7)
        tmpPiece->getPossibleMoves().push_back(piecePos + 1);

}

void ChessGame::calcKnightMoves(Piece* tmpPiece){

    tmpPiece->getPossibleMoves().clear();

    int piecePos{tmpPiece->getPosition()};

    if((piecePos / 8) != 0 ){
        if((piecePos % 8) >= 2 )
            tmpPiece->getPossibleMoves().push_back(piecePos - 10);
        if( (piecePos % 8) <= 5 )
            tmpPiece->getPossibleMoves().push_back(piecePos - 6);
        if((piecePos / 8) != 1){
            if((piecePos % 8) >= 1 )
                tmpPiece->getPossibleMoves().push_back(piecePos - 17);
            if((piecePos % 8) <= 6 )
                tmpPiece->getPossibleMoves().push_back(piecePos - 15);
        }
    }
    if((piecePos / 8) != 7){
        if((piecePos % 8) >= 2 )
            tmpPiece->getPossibleMoves().push_back(piecePos + 6);
        if( (piecePos % 8) <= 5 )
            tmpPiece->getPossibleMoves().push_back(piecePos + 10);
        if((piecePos / 8) != 6){
            if((piecePos % 8) >= 1 )
                tmpPiece->getPossibleMoves().push_back(piecePos + 15);
            if((piecePos % 8) <= 6 )
                tmpPiece->getPossibleMoves().push_back(piecePos + 17);
        }
    }

    tmpPiece->getDangerMoves().clear();

    for(int i = 0; i < tmpPiece->getPossibleMoves().size(); i++){

        if(!playerTurn){
            if( (tmpPiece->getPossibleMoves().at(i)) == blackPieces[3].getPosition() )
                tmpPiece->getDangerMoves().push_back( tmpPiece->getPossibleMoves().at(i) );
        }
        else{
            if( (tmpPiece->getPossibleMoves().at(i)) == whitePieces[4].getPosition() )
                tmpPiece->getDangerMoves().push_back( tmpPiece->getPossibleMoves().at(i) );
        }

    }

    tmpPiece->getDangerMoves().push_back( tmpPiece->getPosition() );

}

