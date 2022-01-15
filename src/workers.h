#ifndef POOISLAND_WORKERS_H
#define POOISLAND_WORKERS_H

#include <iostream>

class Tile;

class Worker {
private:
    int custo = 0;
protected:
    std::string type_var;
    Tile & tile;
    int identifier[2];
public:
    std::string type();
    Worker(class Tile & tile);
    virtual char workerChar() = 0;
    int* giveIdentifier();
};

class operative : public Worker {
    int custo = 15;
    // 5% probab. de se despedir a partir do dia 10
public:
    operative(class Tile &tile);
    virtual char workerChar() override { return 'O'; };
};

class lumberjack : public Worker {
    int custo = 20;
    // trabalha 4 dias e descansa 1
public:
    lumberjack(class Tile &tile);
    virtual char workerChar() override { return 'L'; };
};

class miner : public Worker {
    int custo = 10;
    // 10% probab. de se despedir a partir do dia 2
public:
    miner(class Tile &tile);
    virtual char workerChar() override { return 'M'; };
};

#endif //POOISLAND_WORKERS_H
