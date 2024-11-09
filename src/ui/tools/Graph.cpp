#include "ui/tools/Graph.h"
#include "common/calc.h"
#include "implot.h"
#include "pathing/Spline.h"
#include "pathing/Trajectory.h"
#include <format>

void Graph::render() {
    auto trajectory = manager->generateTrajectory();

    ImGui::Begin("Graph");
    ImPlot::BeginPlot("Splines");
    for (int i = 0; i < trajectory->splines.size(); i++) {
        const auto& spline = trajectory->splines[i];
        double xStart = spline.start.position.x();
        double xEnd = spline.end.position.x();
        if (xStart > xEnd) {
            std::swap(xStart, xEnd);
        }
        int count = (xEnd - xStart) / H_STEP;
        double x_values[count];
        double y_values[count];

        for (int ii = 0; ii < count; ii++) {
            double x = xStart + ii * H_STEP;
            x_values[ii] = x;
            y_values[ii] = getY(spline.coefficients, x);
        }

        ImPlot::PlotLine(std::format("Spline {}", i).c_str(), x_values, y_values, count);
    }
    ImPlot::EndPlot();
    ImGui::End();
}