#include <iostream>
#include <fstream>
#include "Board.h"
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

Board enemy;
Board player;
int enemyHP = 5;
int playerHP = 5;

/// This Function Reads CSV FIlE AND PUT IT INTO THE GRID
void PlayerInit(){

    player.SetGrid();
    ifstream ip;

    ip.open("ship_placement.csv",ios::in);

    if(!ip.is_open())cout << "ERROR: File Open" << endl;


    string ShipType;
    string StartPos;
    string Direction;

    if (ip.good()){
        for(int i =0; i<5 ; i++){
            getline(ip,ShipType,',');
            getline(ip,StartPos,',');
            getline(ip,Direction,'\n');
            player.deployShip(ShipType,StartPos,Direction);
        }

    }else  ip.close();


}

/// START PLAYER'S TURN AND GET RETURN VALUE FOR POINTS
int PlayerTurn(){
    string atkCoor; /// Grid Coordinates
    int points;
    int x = 0;
    cout << "Enemy's Base" << endl;
    enemy.GridLayoutHidden();
    cout << "Your Base" << endl;
    player.GridLayout();
    cout << "--------------------------------" << endl;
    cout << "|  Enemy's Ships Remaining:  " << enemyHP <<" |" <<endl;
    cout << "|  Player's Ships Remaining: " << playerHP << " |" <<endl;
    cout << "--------------------------------" << endl;
    cout << "Enter Coordinates:" << endl;
    cout << "All Letters Should Be UPPERCASE !!!" << endl;
    cout << "Press X to Quit." << endl;
    cin >> atkCoor ;

    x = enemy.GetPosition(atkCoor);

    if (atkCoor == "x" || atkCoor == "X"){
        x = 101;
    }

    while (x > 101 ){
        cout << "You Entered a Wrong Value. Please Try Again." << endl;
        cout << "Press X to Quit." << endl;
        cin >> atkCoor ;
        x = enemy.GetPosition(atkCoor);
    }
    if (atkCoor == "X" || atkCoor == "x"){
        cout << "Final Enemy's Base" << endl;
        enemy.GridLayout();
        cout << "Final Your Base" << endl;
        player.GridLayout();
        exit(42);
    }else{
        points = enemy.StartAttack(atkCoor);
        cout << endl;
    }

    return points;
}

/// START ENEMY'S TURN AND GET RETURN VALUE FOR POINTS
int EnemyTurn(){
    vector <int> enemyPick = {0};
    srand(time(NULL));
    int attackCoordinates;
    int points;
    cout << "Enemy's Turn" << endl;
    std::this_thread::sleep_for(std::chrono::seconds (2));
    attackCoordinates = 1+ (rand() % 100);

    enemyPick.push_back(attackCoordinates);

    for (int i =0;i <enemyPick.size() ;i++){
        if(enemyPick[i] == attackCoordinates){
            attackCoordinates = 1+ (rand() % 100);
        }
        else{
            break;
        }
    }

    //  cout << attackCoordinates << endl;
    points = player.StartAttackEnemy(attackCoordinates);
    return points;
}

/// START THE GAME AND WAIT UNTIL EITHER PLAYER OR ENEMY POINTS IS ZERO
void startGame(){
    int enemyPoint = 5;
    int playerPoint = 5;
    int select;

    select = rand() % 2 +1;

    if(select == 1){
        while (enemyHP != 0 || playerHP !=0){
////////////////// Your Turn
            playerPoint = PlayerTurn();
            enemyHP = enemyHP - playerPoint;
//////////////// Enemy's Turn
            enemyPoint = EnemyTurn();
            playerHP = playerHP - enemyPoint;

            if (enemyHP == 0){
                cout << "Player Wins !!" << endl;
                cout << "Final Enemy's Base" << endl;
                enemy.GridLayout();
                cout << "Final Your Base" << endl;
                player.GridLayout();
                exit(42);
            }else if (playerHP == 0){
                cout << "Enemy Wins !!" << endl;
                cout << "Final Enemy's Base" << endl;
                enemy.GridLayout();
                cout << "Final Your Base" << endl;
                player.GridLayout();
                exit(42);
            }
        }

    }else{
        while (enemyHP != 0 || playerHP !=0){
//////////////// Enemy's Turn
        enemyPoint = EnemyTurn();
        playerHP = playerHP - enemyPoint;
////////////////// Your Turn
        playerPoint = PlayerTurn();
        enemyHP = enemyHP - playerPoint;
        if (enemyHP == 0){
            cout << "Player Wins !!" << endl;
            cout << "Final Enemy's Base" << endl;
            enemy.GridLayout();
            cout << "Final Your Base" << endl;
            player.GridLayout();
            exit(42);
        }else if (playerHP == 0){
            cout << "Enemy Wins !!" << endl;
            cout << "Final Enemy's Base" << endl;
            enemy.GridLayout();
            cout << "Final Your Base" << endl;
            player.GridLayout();
            exit(42);
        }
      }
    }


    while (enemyHP != 0 || playerHP !=0){


////////////////// Your Turn




        playerPoint = PlayerTurn();
        enemyHP = enemyHP - playerPoint;
//////////////// Enemy's Turn
        enemyPoint = EnemyTurn();
        playerHP = playerHP - enemyPoint;



        if (enemyHP == 0){
            cout << "Player Wins !!" << endl;
            cout << "Final Enemy's Base" << endl;
            enemy.GridLayout();
            cout << "Final Your Base" << endl;
            player.GridLayout();
            exit(42);
        }else if (playerHP == 0){
            cout << "Enemy Wins !!" << endl;
            cout << "Final Enemy's Base" << endl;
            enemy.GridLayout();
            cout << "Final Your Base" << endl;
            player.GridLayout();
            exit(42);
        }
    }
}

/// MAIN FUNCTION CALLS THE PLAYERINIT AND SETUP THE ENEMY GRID
int main() {
    srand(time(NULL));
    string optionKey = "0";


    enemy.SetGrid();
    enemy.SetEnemy();
    PlayerInit();
  // player.GridLayout();
  //  enemy.GridLayout();

    cout << "-------------------------------" << endl;
    cout << "|    WELCOME TO BATTLEGRID    |" << endl;
    cout << "-------------------------------" << endl;
    while (optionKey != "1" || optionKey != "2"){

        cout << endl;
        cout <<"1. Start The Game " << endl;
        cout <<"2. Quit" << endl;
        cin >> optionKey;

        if(optionKey == "1"){
            startGame();
        }else if (optionKey == "2"){
            exit(42);
        }else{
            cout << "You entered wrong value. Please Try Again." << endl;

        }

    }


///////////////////////////////////////////////////////////////////////////



    return 0;
}
