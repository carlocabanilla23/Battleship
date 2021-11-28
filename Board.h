//
// Created by John Carlo Cabanilla on 11/14/2021.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H
#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

class Board {
    public:
/// THIS FUNCTION PUSH A 100 OBJECT IN THE GRID VECTOR TO REPRESENT EACH BOX IN WITHIN THE GRID
    void SetGrid(){
        for(int i=0;i <= 100;i++){
            grid.push_back(" ");
            grid2.push_back(" ");
        }
    }
/// THIS FUNCTION PRINTS THE GRID WITH ALL THE SHIPS ON IT.
    void GridLayout(){
        // 1.) To setup the column header

        cout <<"    ";
        for (int xLoc = 1; xLoc < xLocation.size() ; xLoc++){
            cout << "  " << xLocation[xLoc] << "   ";
        }
        cout << endl;
        cout <<"    ";
        for(int j = 0 ; j < 10 ; j++){
            cout << "_____ ";
        }

        cout << endl;

// 2.) To setup the Grid
        for (int i = 1 ; i <= 100 ; i++){

//            if(grid.at(i) == "1"){
//                SetConsoleTextAttribute(h,13);
//            }

// 2.) To setup the row 1
            if(i == 1 | i == 11 || i == 21 ||i == 31 ||i == 41 ||i == 51 ||i == 61 ||i == 71 ||i == 81 ||i == 91){
                int x = 0;
                if (i > 80 && i < 90){
                    x = 9;
                }else if (i > 90){
                    x = 10;
                }else{
                    x = i%9;
                }
// 3.) To setup the left side grid and vertical lines
                if (x == 10){

                    cout << x << " |" << "  " << grid[i] << "  |";
                }
                else{
                    cout << x << "  |" << "  " << grid[i] << "  |";
                }

            }
// 4.) To setup the Horizontal Line
            else if( i == 10 || i == 20 || i == 30 || i == 40 || i == 50 || i == 60 || i == 70 || i == 80 || i == 90 || i == 100){


                cout << "  " << grid[i] << "  |";
                cout << endl;

                cout <<"    ";
                for(int j = 0 ; j < 9 ; j++){
                    cout << "_____ ";
                }
                cout << "_____ ";
                cout << endl;
            }

// 5.) To setup inside grid
            else{
                cout << "  " << grid[i] << "  |";
            }
        }
        cout << endl;
    }
/// THIS SHIPS PRINTS THE GRID WITHOUT SHOWING THE LOCATION OF ALL THE SHIPS
    void GridLayoutHidden(){
        // 1.) To setup the column header

        cout <<"    ";
        for (int xLoc = 1; xLoc < xLocation.size() ; xLoc++){
            cout << "  " << xLocation[xLoc] << "   ";
        }
        cout << endl;
        cout <<"    ";
        for(int j = 0 ; j < 10 ; j++){
            cout << "_____ ";
        }

        cout << endl;

// 2.) To setup the Grid
        for (int i = 1 ; i <= 100 ; i++){

//            if(grid.at(i) == "1"){
//                SetConsoleTextAttribute(h,13);
//            }

// 2.) To setup the row 1
            if(i == 1 | i == 11 || i == 21 ||i == 31 ||i == 41 ||i == 51 ||i == 61 ||i == 71 ||i == 81 ||i == 91){
                int x = 0;
                if (i > 80 && i < 90){
                    x = 9;
                }else if (i > 90){
                    x = 10;
                }else{
                    x = i%9;
                }
// 3.) To setup the left side grid and vertical lines
                if (x == 10){

                    cout << x << " |" << "  " << grid2[i] << "  |";
                }
                else{
                    cout << x << "  |" << "  " << grid2[i] << "  |";
                }

            }
// 4.) To setup the Horizontal Line
            else if( i == 10 || i == 20 || i == 30 || i == 40 || i == 50 || i == 60 || i == 70 || i == 80 || i == 90 || i == 100){


                cout << "  " << grid2[i] << "  |";
                cout << endl;

                cout <<"    ";
                for(int j = 0 ; j < 9 ; j++){
                    cout << "_____ ";
                }
                cout << "_____ ";
                cout << endl;
            }

// 5.) To setup inside grid
            else{
                cout << "  " << grid2[i] << "  |";
            }
        }
        cout << endl;
    }
/// THIS FUNCTION DEPLOYS THE SHIPS ONTO THE GRID
    int deployShip(string shipType,string startPos,string direction){
       // SetGrid();
       //   GridLayout2();
       //  char dir1 = direction[0];
       //  char dir2 = direction[1];
        int shipLength =   ShipType(shipType);
        int exactPosition = GetPosition(startPos);
        string spaceChar = " ";

        if (direction[0] == 'V'){
            if(direction[1] == 'U'){
                for(int i = 0 ;i <shipLength; i++){
                    if(grid[exactPosition] != spaceChar){
                        cout << "ERROR : Cannot Overlap Ships. Please Try Again" << endl;
                        exit(42);
                    }else{
                        grid[exactPosition] = to_string(shipLength);
                        exactPosition = exactPosition-10;
                    }


                }


            }else if (direction[1] == 'D'){
                for(int i = 0 ;i <shipLength; i++){
                    if(grid[exactPosition] != spaceChar){
                        cout << "ERROR : Cannot Overlap Ships. Please Try Again" << endl;
                        exit(42);
                    }else {
                        grid[exactPosition] = to_string(shipLength);
                        exactPosition = exactPosition + 10;
                    }
                }
            }
        }

// Horizontal Conditions
        else if (direction[0] == 'H'){
            if(direction[1] == 'L'){
                for(int i = 0 ;i <shipLength; i++){
                    if(grid[exactPosition] != spaceChar){
                        cout << "ERROR : Cannot Overlap Ships. Please Try Again" << endl;
                        exit(42);
                    }else {
                        grid[exactPosition] = to_string(shipLength);
                        exactPosition = exactPosition - 1;
                    }
                }


            }else if (direction[1] == 'R'){
                for(int i = 0 ;i <shipLength; i++){
                    if(grid[exactPosition] != spaceChar){
                        cout << "ERROR : Cannot Overlap Ships. Please Try Again" << endl;
                        exit(42);
                    }else {
                        grid[exactPosition] = to_string(shipLength);
                        exactPosition = exactPosition + 1;
                    }
                }
            }
        }

        return 0;
    }
    int ShipType (string shipType){

        if (shipType == "Carrier") return 5;
        else if (shipType == "Battleship") return 4;
        else if (shipType == "Cruiser") return 3;
        else if (shipType == "Submarine") return 2;
        else if (shipType == "Destroyer") return 1;
        else {
            cout << "ERROR : Ship not found" << endl;
            cout << "Please Make Sure all the inputs are correct" << endl;
            cout << "1. Only First Letter Of The Ship is Uppercase" << endl;
            cout << "2. There should be no space" << endl;
            cout << "3. Only 2 Commas" << endl;
            cout << "Please Edit your Grid and Restart The Game" << endl;
            exit(42);
        }

    }
/// THIS FUNCTION DETERMINE WHAT KIND OF SHIP AND ITS VALUE
    int GetPosition (string startPos){
        string xValue,yValue,zValue;
        int x,y;
        int z = 0;

        xValue = startPos[0];
        yValue = startPos[1];
        zValue = startPos[2];

        if (startPos.size() > 2){
            if(zValue == "0"){
                yValue = "10";
            }else{
                z = 100;
            }
        }


        for (int i = 0 ; i <xLocation.size() ; i++){
            if(xValue == xLocation[i])x=i;

        }
        for (int j = 0 ; j <yLocation.size() ; j++){
            if(yValue == yLocation[j]) y = 10*(j-1);

        }
        return x+y+z;
    }
/// THIS GENERATES RANDOM SHIP POSITIONS FOR THE ENEMY GRID
    void SetEnemy(){
        int x = rand() % 5 + 1;
        switch (x) {
            case 1:{
                deployShip("Carrier","B8","VU");
                deployShip("Battleship","E10","HL");
                deployShip("Cruiser","H5","VD");
                deployShip("Submarine","E3","HR");
                deployShip("Destroyer","E6","HL");
                break;
            }
            case 2:{
                deployShip("Carrier","C4","HR");
                deployShip("Battleship","C10","VU");
                deployShip("Cruiser","F8","HL");
                deployShip("Submarine","B6","HR");
                deployShip("Destroyer","H6","HL");
                break;
            }
            case 3:{
                deployShip("Carrier","E3","HL");
                deployShip("Battleship","B7","HR");
                deployShip("Cruiser","H5","HR");
                deployShip("Submarine","D10","HL");
                deployShip("Destroyer","G8","HR");
                break;
            }
            case 4:{
                deployShip("Carrier","B6","VU");
                deployShip("Battleship","D3","VD");
                deployShip("Cruiser","F7","VU");
                deployShip("Submarine","H8","VD");
                deployShip("Destroyer","J10","VU");
                break;
            }
            case 5:{
                deployShip("Carrier","G8","HR");
                deployShip("Battleship","D3","VD");
                deployShip("Cruiser","B7","HR");
                deployShip("Submarine","F6","HR");
                deployShip("Destroyer","B3","HL");
                break;
            }
            default:{
                break;
            }



        }

    }
/// THIS FUNCTIONS INITIATE AN ATTACK TO THE ENEMY'S BASE BASE ON USERS OUTPUT
    int StartAttack(string coordinates){
        int coor = GetPosition(coordinates);
        string shipType;
        if (grid[coor] == " "){
            cout << "You missed" << endl;
            grid2[coor] = "O";
            grid[coor] = "O";
            return 0;
        }
        else if (grid[coor] == "X" || grid[coor] == "O"){
            cout << "You missed. You already Attacked this Grid" << endl;
            return 0;
        }
        else{
            cout << "You Got A Hit !!!" << endl;
            shipType = grid[coor];
            for (int i = 0 ; i < 100 ; i++){
                if(grid[i] == shipType){
                    grid[i] = "X";
                    grid2[i] = "X";
                }
            }
            return 1;
        }

    }
/// THIS FUNCTION GENERATE RANDOM ATTACK FOR THE ENEMY
    int StartAttackEnemy(int coordinates){
        string shipType;
        if (grid[coordinates] == " "){
            cout << "Enemy missed" << endl;
            grid[coordinates] = "O";
            return 0;
        }
        else{
            cout << "Enemy Got A Hit !!!" << endl;
            shipType = grid[coordinates];
            for (int i = 0 ; i < 100 ; i++){
                if(grid[i] == shipType){
                    grid[i] = "X";
                }
            }
            return 1;
        }

    }

private:

    vector <string> grid;  /// THIS VECTOR IS USE FOR THE GRID LAYOUT AND GAME INITIALIZATION
    vector<string>  grid2; /// THIS VECTOR IS USE FOR THE  GRID HIDDEN LAYOUT
    vector <string> xLocation = {" ","A","B","C","D","E","F","G","H","I","J"}; /// THIS VECTOR IS USED FOR X-AXIS
    vector <string> yLocation = {" ","1","2","3","4","5","6","7","8","9","10"}; /// THIS VECTOR IS USED FOR Y-AXIS



};


#endif //BATTLESHIP_BOARD_H
