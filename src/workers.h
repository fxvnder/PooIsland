#ifndef POOISLAND_WORKERS_H
#define POOISLAND_WORKERS_H

#include <iostream>

class Tile;

class Worker {
private:
protected:
    int indentificador[2], custo;
    std::string type_var;
    Tile & tile;
public:
    std::string type();
    Worker(class Tile & tile);
};

class operative : public Worker {
    int custo = 15;
    // 5% probab. de se despedir a partir do dia 10
public:
    operative(class Tile &tile);
};

class lumberjack : public Worker {
    int custo = 20;
    // trabalha 4 dias e descansa 1
public:
    lumberjack(class Tile &tile);
};

class miner : public Worker {
    int custo = 10;
    // 10% probab. de se despedir a partir do dia 2
public:
    miner(class Tile &tile);
};

#endif //POOISLAND_WORKERS_H
