#ifndef POOISLAND_RESOURCES_H
#define POOISLAND_RESOURCES_H

struct resourcesStr {
    double iron; // Ferro
    double steel_bar; // Barra de aço
    double coal; // Carvão
    double wood; // Madeira
    double wood_plaques; // Vigas de Madeira
    double electricity; // Eletricidade
    double money; // Cash

    resourcesStr(double iron = 0, double steel = 0, double coal = 0, double wood = 0, double wood_plaques = 0, double electricity = 0, double money = 0);
};

#endif //POOISLAND_RESOURCES_H
