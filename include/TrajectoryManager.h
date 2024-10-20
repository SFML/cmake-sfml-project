#pragma once
#include "common/Pose2d.h"
#include "pathing/Trajectory.h"
#include <memory>

struct TrajectoryManager {
    std::vector<Pose2d> points;
    std::shared_ptr<Trajectory> getTrajectory();
    void remove(int index);
    void swap(int a, int b);
    void add(int index);
};