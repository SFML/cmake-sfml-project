#include <SFML/Graphics.hpp>
#include <unordered_set> 
#include <queue>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace sf;

const int PIXEL_SIZE = 16;
const int MAX_HEIGHT = 30;
const int MAX_WIDTH = 30;


// Sprite snake_body()
struct Position {
    int x,y;
    Position(){};
    Position(int a, int b) {
        x = a;
        y = b;
    }
    bool operator== (const Position& other) const{
        return (x==other.x && y ==other.y);
    }

};

enum class DIRECTIONS {
    UP,
    RIGHT,
    DOWN,
    LEFT,
};

const int DIR_COORD[4][2] = {{0,-1}, {1,0}, {0,1}, {-1,0}};

class Snake {
    private:
        int snake_size;
        // std::unordered_set<Position> snake_set;
        std::deque<Position> snake_queue;
        Sprite snake_body, food_icon;
        DIRECTIONS cur_directions = DIRECTIONS::RIGHT;
        Position food_pos;
    public:             
        Snake(Sprite &snake_sp, Sprite &food_sp) {
            snake_size = 1;
            Position center{MAX_WIDTH/2, MAX_HEIGHT/2};
            snake_queue.emplace_back(center);
            // snake_set.emplace(CENTER);
            snake_body = snake_sp;
            food_icon = food_sp; 
            generate_food();
        }

        void displaySnake(RenderWindow &window) {
            for (Position p: snake_queue ) {
                snake_body.setPosition(p.x*PIXEL_SIZE, p.y*PIXEL_SIZE);
                window.draw(snake_body);
            }
            food_icon.setPosition(food_pos.x*PIXEL_SIZE, food_pos.y*PIXEL_SIZE);
            window.draw(food_icon);

        }
        void changeDirection(DIRECTIONS d) {
            if (d == cur_directions || (int)d == ((int)cur_directions + 2)%4) {
                return;
            }
            cur_directions = d;
        }

        void move() {
            auto dmove = DIR_COORD[(int)cur_directions];
            int dx = dmove[0];
            int dy = dmove[1];
            Position snake_head = snake_queue.back();
            Position next_pos(snake_head.x+dx, snake_head.y+dy);
            Position snake_tail = snake_queue.front();
            if (next_pos.x < 0 || next_pos.x >= MAX_WIDTH || next_pos.y < 0 || next_pos.y >= MAX_WIDTH) {
                return;
            }
            if (snake_head == food_pos) {
                snake_queue.emplace_back(next_pos);
                ++snake_size;
                generate_food();
                return;
            }
            snake_queue.pop_front();
            snake_queue.emplace_back(next_pos);
            std::cout<<food_pos.x<<' '<<food_pos.y<<'\n';
            std::cout<<snake_head.x<<' '<<snake_head.y<<'\n';

        }

        void generate_food() {
            Position food{(rand()%MAX_WIDTH), (rand()%MAX_HEIGHT)};
            for (Position p: snake_queue)  {
                if (p == food) {
                    generate_food();
                    return;
                }
            }
            food_pos = food;
        }

};



int main()
{
    RenderWindow window(VideoMode(MAX_WIDTH*PIXEL_SIZE, MAX_HEIGHT*PIXEL_SIZE), "Snake Game");
    Texture white, red, green;
    white.loadFromFile("../../src/images/white.png");
    red.loadFromFile("../../src/images/red.png");
    green.loadFromFile("../../src/images/green.png");
    Sprite background(white);
    Sprite snake_body(red);
    Sprite food(green);
    Clock clock;
    float timer = 0, delay = 0.1;
    srand(time(0));
    Snake snake{snake_body, food};
    while (window.isOpen())
    {
        Event e;
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;  
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                window.close();
            }


        }

        if (Keyboard::isKeyPressed(Keyboard::Up)) snake.changeDirection(DIRECTIONS::UP);
        else if (Keyboard::isKeyPressed(Keyboard::Down)) snake.changeDirection(DIRECTIONS::DOWN);
        else if (Keyboard::isKeyPressed(Keyboard::Left)) snake.changeDirection(DIRECTIONS::LEFT);
        else if (Keyboard::isKeyPressed(Keyboard::Right)) snake.changeDirection(DIRECTIONS::RIGHT);

        if (timer>delay) {timer = 0; snake.move();}
        window.clear();
        snake.displaySnake(window);
        window.display();
    }
}