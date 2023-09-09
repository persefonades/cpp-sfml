// #include <SFML/Audio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>

std::string get_assets(std::string filename)
{
    std::filesystem::path cwd = std::filesystem::current_path().parent_path() / "assets" / filename;
    return cwd.string();
}

class Point
{
public:
    int _x, _y;

    Point(int x = 0, int y = 0) : _x(x), _y(y) {}
};

const int M = 20;
const int N = 10;

int field[M][N] = {0};

int figures[7][4] = {
    1, 2, 5, 7, // I
    2, 4, 5, 7, // Z
    3, 5, 4, 6, // S
    3, 5, 4, 7, // T
    2, 3, 5, 7, // L
    3, 5, 7, 6, // J
    2, 3, 4, 5, // O
};

Point a[4], b[4];

class TetrisApp
{
private:
    std::string title;
    int left, top, width, height;

public:
    TetrisApp(int, int, int, int, std::string);
    ~TetrisApp();
    void initUI();
};

TetrisApp::TetrisApp(int left = 10, int top = 10, int width = 640, int height = 960, std::string title = "Tetris")
{
    this->title = title;
    this->left = left;
    this->top = top;
    this->width = width;
    this->height = height;
}

void TetrisApp::initUI()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(this->width, this->height), this->title);

    sf::Texture t;
    t.loadFromFile(get_assets("tiles.png"));

    sf::Sprite s(t);
    s.setTextureRect(sf::IntRect(0, 0, 18, 18));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        int n = 2;
        for (int i = 0; i < 4; i++)
        {
            a[i]._x = figures[n][i] % 2;
            a[i]._y = figures[n][i] / 2;
        }

        window.clear(sf::Color::White);

        for (int i = 0; i < 4; i++)
        {
            s.setPosition(a[i]._x * 18, a[i]._y * 18);
            window.draw(s);
        }
        window.display();
    }
}

TetrisApp::~TetrisApp()
{
}

int main(int argc, char const *argv[])
{
    TetrisApp *app = new TetrisApp();
    app->initUI();

    return 0;
}
