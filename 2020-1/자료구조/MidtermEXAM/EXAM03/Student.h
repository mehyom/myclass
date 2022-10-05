#pragma once

struct Student {
	int id;
	const char* sex;
	const char* name;

	Student(int tArr = 0, const char* studentSex="", const char* studentName = "")
		:id(tArr), sex(studentSex), name(studentName) {}
	~Student() {}
};