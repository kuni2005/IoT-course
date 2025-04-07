#include "UsableResource.h"
#include <stdexcept>
#include <iostream>

UsableResource::UsableResource(const std::string &name, int capacity)
    : Resource (name, Type::Usable), capacity (capacity) {
        if (capacity <= 0)
            throw std::invalid_argument("Capacity for resource" + name + " must be positive");
}

bool UsableResource::isAvailableForUse() const {
    return isAvailable;
}

void UsableResource::allocate() {
    if (!isAvailable)
        throw std::invalid_argument("Usable resource " + getName() + " is already allocated");
    isAvailable = false;
}

void UsableResource::use() {
    std::cout << "Using resource " << getName() << "'(capacity: " << capacity << "GHz" << std::endl;
}


void UsableResource::release() {
    if (isAvailable)
        std::cerr<<"Warning: Attempting to release an already available resource " + getName() + "\n";
    isAvailable = true;
}

