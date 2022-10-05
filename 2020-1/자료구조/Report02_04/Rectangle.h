#pragma once
class Rectangle {
private:
	int w;
	int h;

protected:
	int area() {
		return w * h;
	}
	int perimeter() {
		return 2 * (w + h);
	}

public:
	Rectangle() : w(0), h(0) {}
	~Rectangle() {}

	void input(){
		scanf("%d", &w);
		scanf("%d", &h);
	}

	void output() {
		printf("%d\n", area());
		printf("%d\n", perimeter());
	}
};

