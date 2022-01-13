#ifndef POOISLAND_RESOURCES_H
#define POOISLAND_RESOURCES_H

struct resourcesStr {
    int iron; // Ferro
    int steel_bar; // Barra de aço
    int coal; // Carvão
    int wood; // Madeira
    int wood_plaques; // Vigas de Madeira
    int electricity; // Eletricidade

    resourcesStr(int iron=0, int steel=0, int coal=0, int wood=0, int wood_plaques=0, int electricity=0);
};

#endif //POOISLAND_RESOURCES_H
