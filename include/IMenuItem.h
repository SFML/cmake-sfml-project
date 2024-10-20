#pragma once

#include "MutationListener.h"
#include <vector>

class IMenuItem {
public:
    std::vector<MutationListener*> listeners;
    void notifyListeners();
    virtual ~IMenuItem() = default;
    virtual void render() = 0;
};