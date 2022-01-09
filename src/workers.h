#ifndef POOISLAND_WORKERS_H
#define POOISLAND_WORKERS_H

#include <iostream>

class worker {
private:
    int indentificador[2], custo;
public:
protected:
    std::string type;
};

class operative : public worker {
    int custo = 15;
    // 5% probab. de se despedir a partir do dia 10
public:
    operative();
};

class lumberjack : public worker {
    int custo = 20;
    // trabalha 4 dias e descansa 1
public:
    lumberjack();
};

class miner : public worker {
    int custo = 10;
    // 10% probab. de se despedir a partir do dia 2
public:
    miner();
};

#endif //POOISLAND_WORKERS_H
