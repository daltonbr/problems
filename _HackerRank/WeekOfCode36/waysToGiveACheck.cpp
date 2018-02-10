/*
https://www.hackerrank.com/contests/w36/challenges/ways-to-give-a-check
*/

#include <vector>
#include <iostream>
#include <typeinfo>
using namespace std;

class vector2
{
    public:
        int x;
        int y;
        vector2(){};
        vector2(int _x, int _y)
        {
            x = _x;
            y = _y;
        }

        vector2(vector2 anotherVector, int _x, int _y)
        {            
            x = anotherVector.x + _x;
            y = anotherVector.y + _y;
        }

        bool operator== (vector2 &rhs)
        {
            if (typeid(*this) != typeid(rhs))
            {
                return false;
            }

            return ( (*this).x == rhs.x && (*this).y == rhs.y );
        }

        vector2 operator+ (vector2 &rhs)
        {        
            vector2 output;
            output.x = (*this).x + rhs.x;
            output.y = (*this).y + rhs.y;
            return output;
        }

        vector2 translate (int _x, int _y)
        {        
            vector2 output;
            output.x = (*this).x + _x;
            output.y = (*this).y + _y;
            return output;
        }

        vector2 operator- (vector2 &rhs)
        {
            vector2 output;
            output.x = (*this).x - rhs.x;
            output.y = (*this).y - rhs.y;
            return output;
        }

        void toString()
        {
            cout << "(" << (*this).x << ", " << (*this).y << ")" << endl;
        }    

};

class board
{      
    private:
        vector2 enemyKing;
        vector2 pawnToPromote;
        vector2 promotePlace;

        void findEnemyKing() // enemy (black) king "k"
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                if (position[i][j] == 'k')
                {
                    enemyKing.x = i;
                    enemyKing.y = j;
                    //cout << "enemy king at: " << enemyKing.x << ", " << enemyKing.y << endl;
                }                
            }
        }

        // we only have just one "promotable pawn"
        void findPawnToPromote() // Paws "P"
        {
            for (int j = 0; j < 8; j++) // no need to traverse other row
            {                
                if (position[1][j] == 'P' && position[0][j] == '#')
                {
                    pawnToPromote.x = 1;
                    pawnToPromote.y = j;
                    //cout << "pawnToPromote at: " << pawnToPromote.x << ", " << pawnToPromote.y << endl;
                    promotePlace.x = 0;
                    promotePlace.y = j;
                    //cout << "promotePlace at: " << promotePlace.x << ", " << promotePlace.y << endl;
                }                
            }
        }

        bool knightCheck(vector2 pos)
        {
            vector<vector2> positionsToCheck;
            if (pos.y - 1 >= 0) positionsToCheck.push_back(vector2(pos, 2, -1));
            if (pos.y - 2 >= 0) positionsToCheck.push_back(vector2(pos, 1, -2));
            if (pos.y + 1 >= 0) positionsToCheck.push_back(vector2(pos, 2, 1));
            if (pos.y + 2 >= 0) positionsToCheck.push_back(vector2(pos, 1, 2));

            for (int i = 0; i < positionsToCheck.size(); i++)
            {                
                if (positionsToCheck[i] == enemyKing) return true;                
            }
            return false;
        }

        bool bishopCheck(vector2 pos)
        {          
            int _x, _y;

            for (int i = 1; i < 8; i++)
            {
                // top left
                _x = pos.x-i;
                _y = pos.y-i;
                
                if (IsValidPosition(_x,_y) && !IsEmpty(_x,_y))
                {
                    if (position[_x][_y] == 'k') return true;
                }

                // bottom left
                _x = pos.x+i;
                _y = pos.y-i;
                
                if (IsValidPosition(_x,_y) && !IsEmpty(_x,_y))
                {
                    if (position[_x][_y] == 'k') return true;
                }

                // top right
                _x = pos.x-i;
                _y = pos.y+i;
                
                if (IsValidPosition(_x,_y) && !IsEmpty(_x,_y))
                {
                    if (position[_x][_y] == 'k') return true;
                }

                // bottom right
                _x = pos.x+i;
                _y = pos.y+i;
                
                if (IsValidPosition(_x,_y) && !IsEmpty(_x,_y))
                {
                    if (position[_x][_y] == 'k') return true;
                }
            }
            return false;
        }

        bool rookCheck(vector2 pos)
        {            
            vector<vector2> positionsToCheck;

            // rook down vertical
            for (int _x = 1; _x < 8; _x++)
            {                            
                if (IsValidPosition(_x,pos.y) && IsEmpty(_x,pos.y))
                {
                    if (position[_x][pos.y] == 'k') return true;
                }
            }
            
            // rook right horizontal
            for (int _y = pos.y+1; _y < 8; _y++)
            {
                if (!IsEmpty(pos.x,_y))
                {
                    if (position[pos.x][_y] == 'k') return true;
                }
            }

            // rook left horizontal
            for (int _y = pos.y-1; _y >= 0; _y--)
            {
                if (!IsEmpty(pos.x,_y))
                {
                    if (position[pos.x][_y] == 'k') return true;
                }
            }

            return false;
        }

        int findAnotherRooks(vector<vector2> &rooks)
        {   
            int counter = 0;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                if (position[i][j] == 'R')
                {
                    vector2 newVector = vector2(i, j);
                    rooks.push_back(newVector);
                    counter++;
                    //cout << "another rook at: " << rooks[counter-1].x << ", " << rooks[counter-1].y << endl;                    
                }                
            }
            return counter;
        }

        int findAnotherBishops(vector<vector2> &bishops)
        {
            int counter = 0;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                if (position[i][j] == 'B')
                {
                    vector2 newVector = vector2(i, j);
                    bishops.push_back(newVector);
                    counter++;
                    //cout << "another bishop at: " << bishops[counter-1].x << ", " << bishops[counter-1].y << endl;                    
                }                
            }            
            return counter;
        }

        int findAnotherQueens(vector<vector2> &queens)
        {
            int counter = 0;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                if (position[i][j] == 'Q')
                {
                    vector2 newVector = vector2(i, j);
                    queens.push_back(newVector);
                    counter++;
                    //cout << "another queen at: " << queens[counter-1].x << ", " << queens[counter-1].y << endl;                    
                }                
            }            
            return counter;
        }

    public:
        board() {};
        char position[8][8];
        
        bool IsValidPosition(int x, int y)
        {
            return ((x >= 0 && x < 8) && (y >= 0 && y < 8));
        }

        bool IsEmpty(int x, int y)
        {
            return (position[x][y] == '#');
        }

        int waysToGiveACheck()        
        {
            int checkCount = 0;
            findEnemyKing();
            findPawnToPromote();
            bool queenFlag = false;
            if (knightCheck(promotePlace))  { /*cout << "knight check " << endl;*/ checkCount++; }
            if (bishopCheck(promotePlace)) { /*cout << "bishop check " << endl;*/ checkCount++; queenFlag = true; }
            if (rookCheck(promotePlace)) { /*cout << "rook check " << endl;*/ checkCount++; queenFlag = true; }

            if (queenFlag)
            {
                checkCount++;
            }

            vector<vector2> anotherRooks, anotherQueens, anotherBishops;
            if (int rooks = findAnotherRooks(anotherRooks))
            {
                while (rooks--)
                {
                    if (rookCheck(anotherRooks[rooks])) {/* cout << "another rook check " << rooks << endl; */checkCount=4;}
                }
            }

            if (int bishops = findAnotherBishops(anotherBishops))
            {   
                while (bishops--)
                {
                    if (bishopCheck(anotherBishops[bishops])) {/* cout << "another bishop check " << endl;*/ checkCount=4;}
                }
            }

            if (int queens = findAnotherQueens(anotherQueens))
            {   
                while (queens--)
                {
                    if (bishopCheck(anotherQueens[queens])) {/* cout << "another queen (bishop) check " << endl;*/ checkCount=4;}
                    if (rookCheck(anotherQueens[queens])) {/* cout << "another queen (rook) check " << endl;*/ checkCount=4;}

                }
            }

            return checkCount;
        }

        void printBoard()
        {
            cout << "--== Board ==--" << endl;
            for (int i = 0; i < 8; i++)
            {
                cout << "row " << i << " ";
                for (int j = 0; j < 8; j++)
                {
                    cout << position[i][j];
                }
                cout << endl;
            }
            cout << endl;
        }

};


int main()
{
    int t; cin >> t;  

    vector<board> boards;

    for (int count = 0; count < t; count++)
    {
        board newBoard = board();
        // input
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> newBoard.position[i][j];             
            }            
        }
        boards.push_back(newBoard);
    }

    for (int count = 0; count < t; count++)
    {
    //    boards[count].printBoard();        
        cout << boards[count].waysToGiveACheck() << endl;
        //cout << "----------------------" << endl;
    }    

    return 0;
}
