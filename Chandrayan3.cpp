#include <iostream>
#include <string>

class Spacecraft {
private:
    int x;
    int y;
    int z;
    std::string direction;
    std::string prevDirection;

public:
    Spacecraft(int x, int y, int z, const std::string& direction) :
        x(x), y(y), z(z), direction(direction), prevDirection("") {}

    void moveForward() {
        if (direction == "N") {
            y++;
        } else if (direction == "S") {
            y--;
        } else if (direction == "E") {
            x++;
        } else if (direction == "W") {
            x--;
        } else if (direction == "Up") {
            z++;
        } else if (direction == "Down") {
            z--;
        }
    }

    void moveBackward() {
        if (direction == "N") {
            y--;
        } else if (direction == "S") {
            y++;
        } else if (direction == "E") {
            x--;
        } else if (direction == "W") {
            x++;
        } else if (direction == "Up") {
            z--;
        } else if (direction == "Down") {
            z++;
        }
    }

    void turnLeft() {
        if (direction == "N") {
            direction = "W";
        } else if (direction == "S") {
            direction = "E";
        } else if (direction == "E") {
            direction = "N";
        } else if (direction == "W") {
            direction = "S";
        } else if (direction == "Up" || direction == "Down") {
            direction = prevDirection == "N" ? "W" : prevDirection == "S" ? "E" : prevDirection == "E" ? "N" : "S";
        }
    }

    void turnRight() {
        if (direction == "N") {
            direction = "E";
        } else if (direction == "S") {
            direction = "W";
        } else if (direction == "E") {
            direction = "S";
        } else if (direction == "W") {
            direction = "N";
        } else if (direction == "Up" || direction == "Down") {
            direction = prevDirection == "N" ? "E" : prevDirection == "S" ? "W" : prevDirection == "E" ? "S" : "N";
        }
    }

    void turnUp() {
        prevDirection = direction;
        if (direction == "N") {
            direction = "Up";
        } else if (direction == "S") {
            direction = "Down";
        } else if (direction == "E") {
            direction = "Up";
        } else if (direction == "W") {
            direction = "Up";
        } else if (direction == "Up" || direction == "Down") {
            direction = "Up";
        }
    }

    void turnDown() {
        prevDirection = direction;
        if (direction == "N") {
            direction = "Down";
        } else if (direction == "S") {
            direction = "Down";
        } else if (direction == "E") {
            direction = "Down";
        } else if (direction == "W") {
            direction = "Down";
        } else if (direction == "Up" || direction == "Down") {
            direction = "Down";
        }
    }

    void executeCommands(const std::string& commands) {
        for (char command : commands) {
            switch (command) {
                case 'f':
                    moveForward();
                    break;
                case 'b':
                    moveBackward();
                    break;
                case 'l':
                    turnLeft();
                    break;
                case 'r':
                    turnRight();
                    break;
                case 'u':
                    turnUp();
                    break;
                case 'd':
                    turnDown();
                    break;
                default:
                    // Ignore invalid commands
                    break;
            }
        }
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    int getZ() const {
        return z;
    }

    std::string getDirection() const {
        return direction;
    }
};

int main() {
    Spacecraft spacecraft(0, 0, 0, "N");
    std::string commands = "frubl";

    spacecraft.executeCommands(commands);

    std::cout << "Final Position: (" << spacecraft.getX() << ", " << spacecraft.getY() << ", " << spacecraft.getZ() << ")\n";
    std::cout << "Final Direction: " << spacecraft.getDirection() << "\n";

    return 0;
}
