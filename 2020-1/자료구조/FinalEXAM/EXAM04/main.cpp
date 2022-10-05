#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BST.h"
using namespace std;
const char* guide_msg =
"\ni: 예약 요청\n\
d: 예약 취소\n\
c: 예약 변경\n\
w: 비행기명 검색\n\
n: 파일럿명 검색\n\
p: 예약 목록 출력\n\n";

void reqReserve(BinSrchTree& tree) {
	printf("\n입력: 비행기명,파일럿명,착륙 예약 시간\n\n");

	vector<string> result;
	string token;
	string line;
	getline(cin, line);
	stringstream ss(line);

	while (getline(ss, token, ',')) {
		result.push_back(token);
	}
	if (result.size() != 3) {
		printf("\n 입력값을 다시 확인하세요\n\n");
		return;
	}
	Reservation* newRev = new Reservation(result[0], result[1], atoi(result[2].c_str()));
	BinaryNode* node = new BinaryNode(newRev);

	BinaryNode* prev = tree.search(newRev, CompareTypeLandingAvaliableTime1);
	BinaryNode* next = tree.search(newRev, CompareTypeLandingAvaliableTime2);
	if (prev == NULL && next == NULL) {
		tree.insert(node);
		printf("\n 비행기 %s는 %d분에\n 착륙 예약 완료 되었습니다!\n\n",
			node->getData()->getPlane().c_str(), node->getData()->getLandTime());
	}
	else if (prev != NULL && next == NULL) {
		printf("\n 비행기 %s는 착륙 요청이 거부 되었습니다!\n 현재 %d분에 비행기 %s 착륙 예약이 있습니다\n\n",
			node->getData()->getPlane().c_str(), prev->getData()->getLandTime(), prev->getData()->getPlane().c_str());
		delete node;
	}
	else if (prev == NULL && next != NULL) {
		printf("\n 비행기 %s는 착륙 요청이 거부 되었습니다!\n 현재 %d분에 비행기 %s 착륙 예약이 있습니다\n\n",
			node->getData()->getPlane().c_str(), next->getData()->getLandTime(), next->getData()->getPlane().c_str());
		delete node;
	}
	else {
		printf("\n 비행기 %s는 착륙 요청이 거부 되었습니다!\n 현재 %d분에 비행기 %s, %d분에 비행기 %s 착륙 예약이 있습니다\n\n", 
			node->getData()->getPlane().c_str(), prev->getData()->getLandTime(), prev->getData()->getPlane().c_str(),
			next->getData()->getLandTime(), next->getData()->getPlane().c_str());
		delete node;
	}
}

void printReserve(BinSrchTree& tree) {
	tree.displayTree();
}

void delReserve(BinSrchTree& tree) {
	printf("\n입력: 비행기명\n\n");
	std::string myplane;
	getline(cin, myplane);

	Reservation key(myplane, std::string(""), -1);

	Reservation* prev = tree.inorderSearch(&key, CompareTypePlaneName);
	if (prev != NULL) {
		printf("\n 비행기 %s의 %d분 예약 정보가 삭제되었습니다!\n\n",
			prev->getPlane().c_str(), prev->getLandTime());
		tree.remove(prev);
	}
	else {
		printf("\n 비행기 %s의 예약 정보를 찾지 못했습니다!\n\n", key.getPlane().c_str());
	}

}

void srchPlane(BinSrchTree& tree) {
	printf("\n입력: 비행기명\n\n");
	std::string myplane;
	getline(cin, myplane);

	Reservation key(myplane, std::string(""), -1);

	Reservation* prev = tree.inorderSearch(&key, CompareTypePlaneName);
	if (prev != NULL) {
		printf("\n 비행기 %s의 예약 정보입니다\n 비행사 %s의 비행기 %s 착륙 예약 시간은 %d분입니다\n\n",
			prev->getPlane().c_str(), prev->getPilot().c_str(),
			prev->getPlane().c_str(), prev->getLandTime());
	}
	else {
		printf("\n 비행기 %s의 예약 정보를 찾지 못했습니다!\n\n", key.getPlane().c_str());
	}
}

void srchPilot(BinSrchTree& tree) {
	printf("\n입력: 파일럿명\n\n");
	std::string mypilot;
	getline(cin, mypilot);

	Reservation key(std::string(""), mypilot, -1);

	Reservation* prev = tree.inorderSearch(&key, CompareTypePilotName);
	if (prev != NULL) {
		printf("\n 비행사 %s의 예약 정보입니다\n 비행사 %s의 비행기 %s 착륙 예약 시간은 %d분입니다\n\n",
			prev->getPilot().c_str(), prev->getPlane().c_str(),
			prev->getPilot().c_str(), prev->getLandTime());
	}
	else {
		printf("\n 비행사 %s의 예약 정보를 찾지 못했습니다!\n\n", key.getPilot().c_str());
	}
}

void modifyTime(BinSrchTree& tree) {
	printf("\n입력: 비행기명,변경시간\n\n");
	vector<string> result;
	string token;
	string line;
	getline(cin, line);
	stringstream ss(line);

	while (getline(ss, token, ',')) {
		result.push_back(token);
	}
	if (result.size() != 2) {
		printf("\n 입력값을 다시 확인하세요\n\n");
		return;
	}
	Reservation key(result[0], std::string(""), atoi(result[1].c_str()));
	Reservation* prev = tree.inorderSearch(&key, CompareTypePlaneName);
	if (prev == NULL) {
		printf("\n 비행기 %s의 예약 정보를 찾지 못했습니다!\n\n", key.getPlane().c_str());
		return;
	}

	Reservation save(prev->getPlane(), prev->getPilot(), prev->getLandTime());
	
	tree.remove(prev);

	BinaryNode* prevNode = tree.search(&key, CompareTypeLandingAvaliableTime1);
	BinaryNode* nextNode = tree.search(&key, CompareTypeLandingAvaliableTime2);
	if (prevNode == NULL && nextNode == NULL) {
		//tree.setCompareMethod(0);
		Reservation* newRev = new Reservation(save.getPlane(), save.getPilot(), key.getLandTime());
		BinaryNode* afterNode = new BinaryNode(newRev);
		tree.insert(afterNode);
		printf("\n 비행기 %s는 %d분에서 %d분으로 착륙 예약이 변경되었습니다!\n\n",
			newRev->getPlane().c_str(), save.getLandTime(), newRev->getLandTime());
	}
	else if (prevNode != NULL && nextNode == NULL) {
		printf("\n 비행기 %s는 예약 변경이 거부 되었습니다!\n 현재 %d분에 비행기 %s 착륙 예약이 있습니다\n\n",
			save.getPlane().c_str(), prevNode->getData()->getLandTime(), prevNode->getData()->getPlane().c_str());
		// 복구
		Reservation* myRev = new Reservation(save.getPlane(), save.getPilot(), save.getLandTime());
		BinaryNode* myNode = new BinaryNode(myRev);
		tree.insert(myNode);
	}
	else if(prevNode == NULL && nextNode != NULL) {
		printf("\n 비행기 %s는 예약 변경이 거부 되었습니다!\n 현재 %d분에 비행기 %s 착륙 예약이 있습니다\n\n",
			save.getPlane().c_str(), nextNode->getData()->getLandTime(), nextNode->getData()->getPlane().c_str());
		// 복구
		Reservation* myRev = new Reservation(save.getPlane(), save.getPilot(), save.getLandTime());
		BinaryNode* myNode = new BinaryNode(myRev);
		tree.insert(myNode);
	}
	else {
		printf("\n 비행기 %s는 예약 변경이 거부 되었습니다!\n 현재 %d분에 비행기 %s, %d분에 비행기 %s 착륙 예약이 있습니다\n\n",
			save.getPlane().c_str(), prevNode->getData()->getLandTime(), prevNode->getData()->getPlane().c_str(),
			nextNode->getData()->getLandTime(), nextNode->getData()->getPlane().c_str());
		// 복구
		Reservation* myRev = new Reservation(save.getPlane(), save.getPilot(), save.getLandTime());
		BinaryNode* myNode = new BinaryNode(myRev);
		tree.insert(myNode);
	}
}

void main() {
	std::string strTime;
	printf(" 항공기 청소 소요 시간을 입력하세요\n");
	getline(cin, strTime);
	BinSrchTree tree;
	char line[100];
	tree.setDetaK(atoi(strTime.c_str()));

	printf(guide_msg);
	while (fgets(line, sizeof(line), stdin)) {
		switch (line[0]) {
		case 'i':
			reqReserve(tree);
			break;
		case 'd':
			delReserve(tree);
			break;
		case 'c':
			modifyTime(tree);
			break;
		case 'w':
			srchPlane(tree);
			break;
		case 'n':
			srchPilot(tree);
			break;
		case 'p':
			printReserve(tree);
			break;
		default:
			printf("\nunknown command\n\n");
		}
		printf(guide_msg);
	}
}