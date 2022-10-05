#pragma once
#include <string>

class Reservation
{
private:
	std::string plane;
	std::string pilot;
	int tLand;

public:
	Reservation(const std::string& pln, const std::string & plt, int tLnd)
		:plane(pln), pilot(plt), tLand(tLnd) {}
	~Reservation() { }

	const std::string& getPlane() {
		return plane;
	}
	const std::string& getPilot() {
		return pilot;
	}
	int getLandTime() {
		return tLand;
	}
};