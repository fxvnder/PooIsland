#ifndef POOISLAND_WORKERS_H
#define POOISLAND_WORKERS_H

#include <iostream>

class Tile;

class Worker {
protected:
    std::string type_var;
    Tile & tile;
    int identifier[2];
public:
    std::string type();
    Worker(class Tile & tile);
    virtual char workerChar() = 0;
    virtual ~Worker(){};
    int* giveIdentifier();
    //Worker(const Worker &old); // const por cópia
    //Worker & operator=( /*const*/ Worker /*&*/ old);
    virtual bool checkrestday() = 0;
    virtual void togglerestday(bool rest) = 0;
    Worker & dup(Worker *old, Tile & tile);
};

class operative : public Worker {
    //int givesUp[2];
    // 5% probab. de se despedir a partir do dia 10
public:
    operative(class Tile &tile);
    ~operative();
    char workerChar() override;
    bool checkrestday() override { return false; }
    void togglerestday(bool rest) override { }
};

class lumberjack : public Worker {
    // trabalha 4 dias e descansa 1
    //bool isHeResting;
    bool restday;
public:
    lumberjack(class Tile &tile);
    ~lumberjack();
    char workerChar() override;
    bool checkrestday() override { return restday; };
    void togglerestday(bool rest) override { if (rest) restday = true; else restday = false; };
};

class miner : public Worker {
    //int givesUp[2];
    // 10% probab. de se despedir a partir do dia 2
public:
    miner(class Tile &tile);
    ~miner();
    char workerChar() override;
    bool checkrestday() override { return false; }
    void togglerestday(bool rest) override { }
};

#endif //POOISLAND_WORKERS_H
