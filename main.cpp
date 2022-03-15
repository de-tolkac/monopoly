#include <iostream>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

#include "random.h"
#include "Field.h"
#include "GoToCard.h"

struct Color {
    int r, g, b;
    
    Color()
        : r(255)
        , g(255)
        , b(255)
    {}

    Color(int _r, int _g, int _b)
        : r(_r)
        , g(_g)
        , b(_b)
    {}

    friend std::ostream& operator<<(std::ostream& out, const Color& c) {
        out << ' ' << c.r << ' ' << c.g << ' ' << c.b;
        return out;
    }
};

bool printLog = false;

void gameLogging(std::ostream& out) {}

template <typename Head, typename ... Tail>
void gameLogging(std::ostream& out, const Head& data, const Tail&... rest) {
    if (printLog) { 
        out << data;
        gameLogging(out, rest...);
    }
}

void drawLine(std::vector<Color>& field, Color color, int MapWidth, int StartX, int StartY, int EndX, int EndY) {
    if (StartX == EndX) {
        if (StartY > EndY) {
            std::swap(StartY, EndY);
        }
        for (int y = StartY; y <= EndY; ++y) {
            field[y + StartX*MapWidth] = color;
        }
    } else if (StartY == EndY) {
        if (StartX > EndX) {
            std::swap(StartX, EndX);
        }
        for (int x = StartX; x <= EndX; ++x) {
            field[StartY + x*MapWidth] = color;
        }
    } else {
        if (StartX > EndX) {
            std::swap(StartX, EndX);
            std::swap(StartY, EndY);
        }
        int kx = EndX - StartX;
        int ky = EndY - StartY;

        for (int x = StartX; x <= EndX; ++x) {
            int y = ((x - StartX) * ky) / kx + StartY;
            field[y + x*MapWidth] = color;
        }
    }
}

void drawRectangle(std::vector<Color>& picture, Color color, int MapWidth, int X, int Y, int RectHeight, int RectWidth) {
    drawLine(picture, color, MapWidth, X, Y, X + RectHeight, Y);
    drawLine(picture, color, MapWidth, X, Y, X, Y + RectWidth);
    drawLine(picture, color, MapWidth, X + RectHeight, Y, X + RectHeight, Y + RectWidth);
    drawLine(picture, color, MapWidth, X, Y + RectWidth, X + RectHeight, Y + RectWidth);
}

void drawRectangle(std::vector<Color>& picture, Color borderColor, Color backgroundColor, int MapWidth, int X, int Y, int RectHeight, int RectWidth) {
    drawLine(picture, borderColor, MapWidth, X, Y, X + RectHeight, Y);
    drawLine(picture, borderColor, MapWidth, X, Y, X, Y + RectWidth);
    drawLine(picture, borderColor, MapWidth, X + RectHeight, Y, X + RectHeight, Y + RectWidth);
    drawLine(picture, borderColor, MapWidth, X, Y + RectWidth, X + RectHeight, Y + RectWidth);
    for (int x = X + 1; x <= X + RectHeight - 1; ++x) {
        for (int y = Y + 1; y <= Y + RectWidth - 1; ++y) {
            picture[y + x*MapWidth] = backgroundColor;
        }
    }
}

void drawMonopolyField(Field (&map)[41], std::vector<Color>& picture, int MapWidth) {
    std::sort(std::begin(map), std::end(map), [](const Field& lhs, const Field& rhs) {
        return lhs.counter < rhs.counter;
    });
    
    drawLine(picture, Color(0, 0, 0), MapWidth, 80, 120, 80, 180);
    drawLine(picture, Color(0, 0, 0), MapWidth, 75, 170, 80, 180);
    drawLine(picture, Color(0, 0, 0), MapWidth, 85, 170, 80, 180);
    drawLine(picture, Color(0, 0, 0), MapWidth, 75, 170, 85, 170);

    for (int i = 0; i < 41; ++i) {
        drawRectangle(picture, Color(0, 0, 0), Color(255, 225 - 5*i, 225 - 5*i), MapWidth, map[i].x, map[i].y, map[i].height, map[i].width);
    }
}

int main(int argc, char** argv) {
    if (argc == 2 && strcmp(argv[1], "-l") == 0) {
        printLog = true;
    }

    Field map[41];
    initField(map);

    GoToCard chances[16];
    initChances(chances);

    GoToCard publicTreasury[16];
    initTreasury(publicTreasury);

    srand(time(0));
    std::random_shuffle(std::begin(chances), std::end(chances));
    std::random_shuffle(std::begin(publicTreasury), std::end(publicTreasury));

    int chancePointer = 0;
    int publicTreasuryPointer = 0;
    int positionPointer = 0;

    RandGenerator random;
    
    constexpr size_t ITERATIONS = 300000000;
    
    for (size_t i = 0; i < ITERATIONS; ++i) {
        int cubes = random.generate();
        positionPointer = (map[positionPointer].position + cubes) % 40;
        map[positionPointer].counter += 1;
        
        gameLogging(std::cout, positionPointer, "\n");

        switch (map[positionPointer].type) {
            case Field::Chance:
                gameLogging(std::cout, "Chance: ");
                if (chances[chancePointer].needJump) {
                    if (chances[chancePointer].jumpTo < 0) {
                        positionPointer += chances[chancePointer].jumpTo;
                        if (positionPointer < 0) {
                            positionPointer = 40 + positionPointer;
                        }
                    } else {
                        positionPointer = chances[chancePointer].jumpTo;
                    }
                    gameLogging(std::cout, "go to ", positionPointer,  "\n");
                    map[positionPointer].counter += 1;
                } else {
                    gameLogging(std::cout, "stay\n");
                }
                chancePointer = (chancePointer + 1) % 16;
                break;
            case Field::Treasury:
                gameLogging(std::cout, "Treasury: ");
                if (publicTreasury[publicTreasuryPointer].needJump) {
                    if (publicTreasury[publicTreasuryPointer].jumpTo < 0) {
                        positionPointer += publicTreasury[publicTreasuryPointer].jumpTo;
                        if (positionPointer < 0) {
                            positionPointer = 40 + positionPointer;
                        }
                    } else {
                        positionPointer = publicTreasury[publicTreasuryPointer].jumpTo;
                    }
                    gameLogging(std::cout, "go to ", positionPointer, "\n");
                    map[positionPointer].counter += 1;
                } else {
                    gameLogging(std::cout, "stay\n");
                }
                publicTreasuryPointer = (publicTreasuryPointer + 1) % 16;
                break;
            case Field::GoToJail:
                gameLogging(std::cout, "Go to jail!\n");
                positionPointer = 40;
                map[positionPointer].counter += 1;
                break;
            default:
                break;
        }
    }
   
    constexpr int WIDTH = 1156;
    constexpr int HEIGHT = 1024;
   
    std::vector<Color> picture(WIDTH * HEIGHT);
    drawMonopolyField(map, picture, WIDTH);

    std::ofstream image;
    image.open("./result.ppm");
    image << "P3\n" << WIDTH << ' ' << HEIGHT << "\n255\n";
    for (int i = 0; i < HEIGHT * WIDTH; ++i) {
        image << picture[i];
    }
    image.close();
    return 0;
}