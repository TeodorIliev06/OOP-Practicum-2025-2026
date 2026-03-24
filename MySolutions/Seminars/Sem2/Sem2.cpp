#include <iostream>
#include <fstream>
#include <print>

class Point {
private:
    int x_;
    int y_;

	mutable int counter_;

    void setX(int x) {
        x_ = x;
		counter_++;
    }

    void setY(int y) {
        y_ = y;
		counter_++;
    }

public:
    enum class Quadrant {
        First,
        Second,
        Third,
        Fourth,
        XAxis,
        YAxis,
        Center
	};

    Point() : x_(0), y_(0) { 
        counter_++;
    }
    Point(int x, int y) : x_(x), y_(y) { 
        counter_++;
    }
    ~Point() { 
		std::print("Point at (%d, %d) is being destroyed.\n", x_, y_);
	}

    int getX() const {
		counter_++;
        return this->x_;
	}
    int getY() const {
		counter_++;
        return this->y_;
    }

    double calculateDistance(const Point& otherPoint) const {
        int distanceX = this->x_ - otherPoint.x_;
        int distanceY = this->y_ - otherPoint.y_;

		counter_++;
        return sqrt(distanceX * distanceX + distanceY * distanceY);
	}

    Quadrant getQuadrant() const {
        if (x_ == 0 && y_ == 0) {
            return Quadrant::Center;
		}
		else if (x_ == 0) {
            return Quadrant::YAxis;
        } else if (y_ == 0) {
            return Quadrant::XAxis;
		} else if (x_ > 0 && y_ > 0) {
            return Quadrant::First;
        } else if (x_ < 0 && y_ > 0) {
            return Quadrant::Second;
        } else if (x_ < 0 && y_ < 0) {
            return Quadrant::Third;
        } else {
            return Quadrant::Fourth;
        }

		counter_++;
	}

    void saveToFile(const std::string& filename) const {
		counter_++;
        if (filename.empty()) return;

        std::ofstream file(filename);

        if (file.is_open()) {
            file << x_ << " " << y_ << std::endl;
            file.close();
        }
        else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

    void saveToStream(std::ostream& out) const {
		counter_++;
        if (!out) return;

        out << x_ << " " << y_ << std::endl;
    }

    void readFromFile(const std::string& filename) {
		counter_++;
		if (filename.empty()) return;

        std::ifstream file(filename);

        if (file.is_open()) {
            file >> x_ >> y_;
            file.close();
        }
        else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

    void saveToStream(std::istream& in) {
		counter_++;
		if (!in) return;

        in >> x_ >> y_;
	}

    void nullifyCounter() {
        counter_ = 0;
	}

    int getCounter() const {
        return counter_;
	}
};

class Triangle {
private:
	mutable int counter_;
    Point points_[3];

public:
    const Point& getA() const { return points_[0]; }
	const Point& getB() const { return points_[1]; }
	const Point& getC() const { return points_[2]; }

	void setA(const Point& a) { points_[0] = a; }
	void setA(int x, int y) { points_[0] = Point(x, y); }

	void setB(const Point& b) { points_[1] = b; }
	void setC(const Point& c) { points_[2] = c; }

    Triangle() = default;

    Triangle(const Point& a, const Point& b, const Point& c) {
        points_[0] = a;
        points_[1] = b;
        points_[2] = c;
    }

    double getSide(const Point& a, const Point& b) const {
		return a.calculateDistance(b);
    }

    double calculatePerimeter() const {
        double sideA = getSide(points_[1], points_[2]);
		double sideB = getSide(points_[0], points_[2]);
		double sideC = getSide(points_[0], points_[1]);

        return sideA + sideB + sideC;
    }

    double calculateArea() const {
		int x1 = points_[0].getX(), y1 = points_[0].getY();
        int x2 = points_[1].getX(), y2 = points_[1].getY();
        int x3 = points_[2].getX(), y3 = points_[2].getY();

		double doubledArea = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
		return doubledArea / 2;
	}

    Point::Quadrant getCenterPosition() const {
        double centerX = (points_[0].getX() + points_[1].getX() + points_[2].getX()) / 3.0;
        double centerY = (points_[0].getY() + points_[1].getY() + points_[2].getY()) / 3.0;

        return Point(static_cast<int>(centerX), static_cast<int>(centerY)).getQuadrant();
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
