#ifndef _quanLiLopHoc_h
#define _quanLiLopHoc_h
struct Date {
	int year;
	int month;
	int day;
};
//PHẦN 1: Phước
//1. Xây dựng danh sách liên kết đơn phù hợp để tổ chức lưu trữ lớp học và học viên tại trung tâm.
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
//tìm lớp học có học phí lớn nhất
roomNode* getMaxFee(roomList list);

#endif _quanLiLopHoc_h