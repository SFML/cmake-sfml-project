#pragma once
#include "pathing/Trajectory.h"
#include <common/Pose2d.h>
#include <memory>

struct TrajectoryManager {
    std::vector<Pose2d> poses{Pose2d::Zero()};
    std::shared_ptr<Trajectory> generateTrajectory();
};