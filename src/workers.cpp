#include "island.h"
#include "buildings.h"
#include "tile.h"

// ===== Class Worker ===== //
Worker::Worker(Tile &tile) : tile(tile) {
    identifier[0] = tile.island().workerIDCounter();
    identifier[1] = tile.island().day();
}
/*
Worker::Worker(const Worker &old) // const por cópia
:   type_var(old.type_var),
    tile(old.tile) {
    identifier[0] = old.identifier[0];
    identifier[1] = old.identifier[1];
}*/

//Worker & Worker::operator=( /*const*/ Worker /*&*/ old) { // idioma swap
//    // este objeto outro vai morrer aqui
//    std::swap (type_var, old.type_var);
//    std::swap (identifier[0], old.identifier[0]);
//    std::swap (identifier[1], old.identifier[1]);
//    return *this; // pensar no quê que (a = b) retorna, para casos do tipo a = (b = c)
//}

Worker & Worker::dup(Worker *old, Tile & tilezz){
    type_var=old->type_var;
    tile = tilezz;
    identifier[0] = old->identifier[0];
    identifier[1] = old->identifier[1];
    return *this;
}

std::string Worker::type() {
    return type_var;
}

int* Worker::giveIdentifier(){
    return identifier;
}

// ===== Class operative ===== //
operative::operative(class Tile &tile) : Worker(tile){ // oper
//    givesUp[0] = 5;
//    givesUp[1] = 10;
    tile.island().workerIDCounter()++;
    identifier[0] = tile.island().workerIDCounter();
    identifier[1] = tile.island().day();
    type_var = "oper";
}
char operative::workerChar(){
    return 'O';
};
operative::~operative() { }
//char operative::workerChar(){
//}

// ===== Class miner ===== //
miner::miner(class Tile &tile) : Worker(tile){ // miner
//    givesUp[0] = 10;
//    givesUp[1] = 2;
    tile.island().workerIDCounter()++;
    identifier[0] = tile.island().workerIDCounter();
    identifier[1] = tile.island().day();
    type_var = "miner";
}
char miner::workerChar() {
    return 'M';
};
miner::~miner() { }

// ===== Class lumberjack ===== //
lumberjack::lumberjack(class Tile &tile) : Worker(tile){ // len
    restday = false;
    tile.island().workerIDCounter()++;
    identifier[0] = tile.island().workerIDCounter();
    identifier[1] = tile.island().day();
    type_var = "len";
}
char lumberjack::workerChar() {
    return 'L';
};
lumberjack::~lumberjack() { }