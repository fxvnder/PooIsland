#ifndef POOISLAND_WORKERS_H
#define POOISLAND_WORKERS_H

class worker {
private:
    int indentificador[2], custo;
public:

};

class operario : private worker {
    int custo = 15;
    // 5% probab. de se despedir a partir do dia 10
};

class lenhador : private worker {
    int custo = 20;
    // trabalha 4 dias e descansa 1
};

class mineiro : private worker {
    int custo = 10;
    // 10% probab. de se despedir a partir do dia 2
};

#endif //POOISLAND_WORKERS_H
