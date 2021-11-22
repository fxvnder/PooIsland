#ifndef POOISLAND_FILES_H
#define POOISLAND_FILES_H

#include <vector>
#include "objects.h"

bool saveFile(const std::string& filename, std::vector<std::string> commands);
bool openFile(const std::string& filename, const island& world);

#endif //POOISLAND_FILES_H
