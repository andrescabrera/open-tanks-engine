///@brief Online *nix tanks game engine using UDP Sockets and POSIX Threads.
///@author Andrés Cabrera

#include <stdio.h>
#include <stdlib.h>

#define USERNAME_SIZE 64
#define NICK_SIZE 48
#define STATE_NAME_SIZE 128

#define TANK_MODEL_NAME_SIZE 16

#define MAX_PLAYERS_PER_TEAM 16
#define MAX_TANK_MODEL_CANNON_MODELS 8;

#define MAP_NAME_SIZE 16;

typedef struct Player *Player;
typedef struct Connection *Connection;
typedef struct Game *Game;
typedef struct TankCannon *TankCannon;
typedef struct TankModule *TankModule;
typedef struct TankTurret *TankTurret;
typedef struct TankMotor *TankMotor;
typedef struct TankModel *TankModel;
typedef struct Tank *Tank;
typedef struct Garage *Garage;
typedef struct Map *Map;

struct Player {
    long int id;
    char email[USERNAME_SIZE];
    char nick[NICK_SIZE];
    Connection activeConnection;
    Team activeGameTeam;
    Garage garages;
};

struct Connection {
    char state[STATE_NAME_SIZE];
    int socketDescriptor;
    Player player;
};

struct Game {
    char state[STATE_NAME_SIZE];
    long int id;
    Team teamOne;
    Team teamTwo;
};

struct Team {
    long int id;
    Game game;
    Player players[MAX_PLAYERS_PER_TEAM];
    Platoon plattons[MAX_PLAYERS_PER_TEAM/2];
};

struct Platoon {
    long int id;
    char state[STATE_NAME_SIZE]; //Ready for play or not
    Player platoons[MAX_PLAYER_PER_PLATOON];
};

struct Tank {
    long int id;
    char state[STATE_NAME_SIZE]; //Game state, playable or not
    Garage garage; //Tank location - user garage
    double damage;
    //Crew crewList;
};

struct Cannon {
    long int id;
    char state[STATE_NAME_SIZE]; ///Game state, disabled or enabled
};

struct TankModel {
    long int id;
    char name[TANK_MODEL_NAME_SIZE];
    char state[STATE_NAME_SIZE]; ///Game state, disabled or enabled
    int version;
    int maxHitPoints;
    TankCannon compatibleCannons[MAX_TANK_MODEL_CANNON_MODELS];
    //Modules compatibleModules
    //Turret compatibleTurrets
};

///Player garage
struct Garage {
    long int id;
    Tank tank;
    Garage nextGarage;
};

///Scene - Battlefield
struct Map {
    long int id;
    char name[MAP_NAME_SIZE];
    char state[STATE_NAME_SIZE]; ///Test purpose. Disabled or enabled for play
    //Object objectList;
    int version;
};

struct TankCannon {
    long int id;
    double millimeters;
    double penetration;
    double damageFactor;
    //TankAmmunition compatibleAmmunitionTypes[MAX_CANNON_AMMUNITION_TYPES]
    char name[MAP_NAME_SIZE];
    char state[STATE_NAME_SIZE]; ///Test purpose: Disabled or enabled for play
    int version;
}

int main()
{
    printf("Hello wot!\n");
    return 0;
}
