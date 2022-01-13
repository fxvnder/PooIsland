#include "island.h"
#include "buildings.h"
#include "tile.h"

// ===== Class Worker ===== //
Worker::Worker(Tile &tile) : tile(tile) { }
std::string Worker::type() {
    return type_var;
}

// ===== Class operative ===== //
operative::operative(class Tile &tile) : Worker(tile){ // oper
    type_var = "oper";
}

// ===== Class miner ===== //
miner::miner(class Tile &tile) : Worker(tile){ // miner
    type_var = "miner";
}

// ===== Class lumberjack ===== //
lumberjack::lumberjack(class Tile &tile) : Worker(tile){ // len
    type_var = "len";
}
