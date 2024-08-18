#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

int main()
{
    // Criação da janela SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML + ImGui");
    window.setFramerateLimit(60);

    // Inicialização do ImGui para SFML
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;

    // Loop principal
    while (window.isOpen())
    {
        sf::Time deltaTime = deltaClock.restart();

        // Processamento de eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Início do novo frame ImGui
        ImGui::SFML::Update(window, deltaTime);

        // Limpeza da tela
        window.clear(sf::Color::Black);

        // Renderização da interface gráfica com ImGui
        ImGui::Begin("Hello, ImGui!");
        ImGui::Text("SFML + ImGui is working!");
        ImGui::End();

        // Renderiza o conteúdo do ImGui
        ImGui::SFML::Render(window);

        // Apresentação da janela
        window.display();
    }

    // Finalização do ImGui para SFML
    ImGui::SFML::Shutdown();

    return 0;
}
