#include "IMenuItem.h"
#include "MutationListener.h"
#include <algorithm>

void IMenuItem::notifyListeners() {
    std::for_each(listeners.begin(), listeners.end(), [](MutationListener* listener){listener->onMutate();});
}