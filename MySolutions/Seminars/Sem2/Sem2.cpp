#include <iostream>
#include <fstream>

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
    Point a_;
    Point b_;
	Point c_;

public:
    const Point& getA() const { return a_; }
	const Point& getB() const { return b_; }
	const Point& getC() const { return c_; }

	void setA(const Point& a) { a_ = a; }
	void setA(int x, int y) { a_ = Point(x, y); }

	void setB(const Point& b) { b_ = b; }
	void setC(const Point& c) { c_ = c; }

    Triangle(const Point& a, const Point& b, const Point& c) : a_(a), b_(b), c_(c) {}

    double getSide(const Point& a, const Point& b) const {
		return a.calculateDistance(b);
    }

    double calculatePerimeter() const {
        double sideA = getSide(b_,c_);
		double sideB = getSide(a_, c_);
		double sideC = getSide(a_, b_);

        return sideA + sideB + sideC;
    }

    double calculateArea() const {
        // Calculating area with Heron's formula
        /*double sideA = getSide(b_, c_);
        double sideB = getSide(a_, c_);
        double sideC = getSide(a_, b_);

        double halfPerimeter = (sideA + sideB + sideC) / 2.0;

        return sqrt(halfPerimeter * (halfPerimeter - sideA) * (halfPerimeter - sideB) * (halfPerimeter - sideC));*/

		int x1 = a_.getX(), y1 = a_.getY();
        int x2 = b_.getX(), y2 = b_.getY();
        int x3 = c_.getX(), y3 = c_.getY();

		double doubledArea = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
		return doubledArea / 2;
	}

    Point::Quadrant getCenterPosition() const {
        double centerX = (a_.getX() + b_.getX() + c_.getX()) / 3.0;
        double centerY = (a_.getY() + b_.getY() + c_.getY()) / 3.0;

        return Point(static_cast<int>(centerX), static_cast<int>(centerY)).getQuadrant();
	}
};

int main()
{
    std::cout << "Hello World!\n";
}
