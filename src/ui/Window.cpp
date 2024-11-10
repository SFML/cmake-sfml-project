#include "ui/Window.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "implot.h"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include "IconsFontAwesome6.h"


Window::Window() {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    window = glfwCreateWindow(1500, 900, "RoboOp Visualizer", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;


    float baseFontSize = 16.0f;
    float iconFontSize = baseFontSize * 2.0f / 3.0f;

    ImFontConfig config;
    config.SizePixels = baseFontSize;
    io.Fonts->AddFontDefault(&config);

    static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_16_FA, 0 };
    ImFontConfig icons_config; 
    icons_config.MergeMode = true; 
    icons_config.PixelSnapH = true; 
    icons_config.GlyphMinAdvanceX = iconFontSize;
    io.Fonts->AddFontFromFileTTF( FONT_ICON_FILE_NAME_FAS, iconFontSize, &icons_config, icons_ranges );

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    ImPlot::CreateContext();
}

Window::~Window() {
    glfwTerminate();
    glfwDestroyWindow(window);
}

bool Window::render() {
    if (glfwWindowShouldClose(window)) {
        return false;
    }

    glfwPollEvents();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("Tools", true)) {
            for (const auto& pair: tools) {
                if (ImGui::MenuItem(pair.first.c_str())) {
                    activated[pair.first] = not activated[pair.first];
                }
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    for (const auto& pair: tools) {
        if (activated[pair.first]) {
            pair.second->render();
        }
    }

    ImGui::EndFrame();
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(50./255, 125./255, 175./255, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
    return true;
}

void Window::addTool(const std::string& name, const std::shared_ptr<ITool>& tool) {
    tools[name] = tool;
    activated[name] = false;
}