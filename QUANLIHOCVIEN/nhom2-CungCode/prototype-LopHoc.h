﻿#ifndef _quanLiLopHoc_h
#define _quanLiLopHoc_h
struct Date {
	int year;
	int month;
	int day;
};
struct classroom {
	char maLop[11];
	char tenLop[30];
	int lichHoc; //dùng khoá 1: sáng, 2: Chiều, 3: Tối
	long hocPhi;
	Date startDay;
	Date endDay;
	Date realEndDay;
};
struct roomNode {
	classroom value;
	roomNode* next;
};
struct roomList {
	roomNode* headNode;
	roomNode* tailNode;
};
int insertHead(roomList &room, roomNode* p);
int insertTail(roomList &room, roomNode* p);
void readListRoom(char fileRoom[], roomList &room);
void read1RoomOnFile(FILE* fi, classroom& x);
void printInfoClass(classroom x);
void showRoomList(roomList sl);
int isEmpty(roomList room);
void showRoomNode(roomNode* p);
void initRoomList(roomList &room);
const char* keyLichHoc(classroom room);
const char* keyTenMon(const char* nameRoom); //ép chó thành mèo
const char* findLopHocChuaTenMonCanTim(roomList room);
#endif _quanLiLopHoc_h