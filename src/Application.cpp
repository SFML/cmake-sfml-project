#include "Application.h"
#include "tools/CodeGenerator.h"
#include "tools/TrajectoryManager.h"
#include "ui/Window.h"
#include "ui/tools/Editor.h"
#include "ui/tools/Graph.h"
#include <memory>

void Application::run() {
    auto manager = std::make_shared<TrajectoryManager>();
    auto generator = std::make_shared<CodeGenerator>();

    auto editor = std::make_shared<Editor>(manager);
    auto graph = std::make_shared<Graph>(manager);

    Window window;

    window.addTool("Editor", editor);
    window.addTool("Graph", graph);

    while (window.render()) {

    }
}