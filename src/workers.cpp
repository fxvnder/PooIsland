#include "island.h"
#include "buildings.h"
#include "tile.h"

// ===== Class Worker ===== //
Worker::Worker(Tile &tile) : tile(tile) {
    identifier[0] = tile.island().workerIDCounter();
    identifier[1] = tile.island().day();
}
std::string Worker::type() {
    return type_var;
}

int* Worker::giveIdentifier(){
    return identifier;
}

// ===== Class operative ===== //
operative::operative(class Tile &tile) : Worker(tile){ // oper
    tile.island().workerIDCounter()++;
    identifier[0] = tile.island().workerIDCounter();
    identifier[1] = tile.island().day();
    type_var = "oper";
}
//char operative::workerChar(){
//}

// ===== Class miner ===== //
miner::miner(class Tile &tile) : Worker(tile){ // miner
    tile.island().workerIDCounter()++;
    identifier[0] = tile.island().workerIDCounter();
    identifier[1] = tile.island().day();
    type_var = "miner";
}

// ===== Class lumberjack ===== //
lumberjack::lumberjack(class Tile &tile) : Worker(tile){ // len
    tile.island().workerIDCounter()++;
    identifier[0] = tile.island().workerIDCounter();
    identifier[1] = tile.island().day();
    type_var = "len";
}
