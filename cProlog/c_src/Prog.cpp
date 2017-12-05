//
// Created by Bidbip on 12/3/2017.
//

#include "Prog.h"


template<typename T>
bool Prog::isListCons(T name) {
    return ((name.compare(".") == 0) || (name.compare("[|]") == 0) || (name.compare("list") == 0));
}