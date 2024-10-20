#pragma once
#include "TrajectoryManager.h"
#include "IMenuItem.h"
#include <memory>

class SplineSequence: public IMenuItem {
private:
    std::shared_ptr<TrajectoryManager> manager;
public:
    SplineSequence(const std::shared_ptr<TrajectoryManager>& manager): manager{manager}{}
    void render() override;
};