#include "prototype-HocVien.h"		//	1in2 2in1
									//	đã khai báo thư viện prototype-LopHoc.h bên trong thư viện này nên không cần khai báo lại


//========================================================================
//etc
roomNode* findNodeExistTenLopForTrue(roomList room, char tenLop[]) {
	roomNode* currNode = room.headNode;
	while(currNode!=NULL) {
		if(strcmpi(currNode->value.tenLop, tenLop))
			return currNode;	//đã tìm thấy node chứa tên lớp
		currNode = currNode->next;
	}
	return NULL;
}
//Xuất thông tin lop hoc
void printInfoClass(classroom x) {
	printf("|%-14s|%-21s|%15s| %10ld|%d/%02d/%02d| %d/%02d/%02d| %d/%02d/%02d|\n", x.maLop
														   , x.tenLop
														   , keyLichHoc(x)
														   , x.hocPhi
														   , x.startDay.year, x.startDay.month, x.startDay.day
														   , x.endDay.year, x.endDay.month, x.endDay.day
														   , x.realEndDay.year, x.realEndDay.month, x.realEndDay.day
														   
														   );
}
void showRoomList(roomList sl) {
	if (isEmpty(sl)) {
		printf("Linked roomList is Empty\n");
		return;
	}
	printf("Noi dung danh sach lien ket:\n");
	printf("|%-s|%-14s|%-21s|%15s| %s|%-10s|%-10s|%-10s|\n", "STT", "Ma lop hoc", "Ten mon", "Lich hoc", "   Hoc phi", "yyyy/mm/dd", "yyyy/mm/dd ", "yyyy/mm/dd ");
	printf("---------------------------------------------------------------------------------------\n");
	roomNode* p = sl.headNode;
	int i = 0;
	while (p != NULL) {
		printf("  %02d", i + 1);
		showRoomNode(p);
		i++;
		p = p->next;
	}

}
//========================================================================
//xử lí file
void readListRoom(char fileRoom[], roomList &room) {
	int n;
	FILE* fi = fopen(fileRoom, "r");
	if (fi == NULL) {
		printf("Khong the mo file!\n");
		exit(1);
	}
	fscanf(fi, "%d\n", &n);
	initRoomList(room);
	for (int i = 0; i < n; i++)
	{
		classroom x;
		read1RoomOnFile(fi, x);

		roomNode* p = createRoomNode(x);
		insertTail(room, p);
	}
	fclose(fi);
	printf("Doc file %s thanh cong vui long nhan 2 de in\n", fileRoom);
}
void read1RoomOnFile(FILE* fi, classroom& x) {
	fscanf(fi, "%[^|]|%[^|]|%d|%ld |%d%d%d|%d%d%d|%d%d%d\n", &x.maLop
		, &x.tenLop
		, &x.lichHoc
		, &x.hocPhi
		, &x.startDay.year, &x.startDay.month, &x.startDay.day
		, &x.endDay.year, &x.endDay.month, &x.endDay.day
		, &x.realEndDay.year, &x.realEndDay.month, &x.realEndDay.day
		);
	
}
//========================================================================
//thêm
int insertTail(roomList &room, roomNode* p) {
	if (!p)	//p==NULL
		return 0;
	if (isEmpty(room))
		insertHead(room, p);
	else {
		room.tailNode->next = p;
		room.tailNode = p;
	}
	return 1;
}
int insertHead(roomList &room, roomNode* p) {
	if (p == NULL)
		return 0;
	if (isEmpty(room))
		room.headNode = room.tailNode = p;
	else {
		p->next = room.headNode;
		room.headNode = p;
	}
	return 1;
}
//========================================================================
//kiểm tra rổng
int isEmpty(roomList room) {
	return room.headNode == NULL;
}
//in thông tin node
void showRoomNode(roomNode* p) {
	printInfoClass(p->value);
}
//========================================================================
//khởi tạo dslk
void initRoomList(roomList &room) {
	room.headNode = room.tailNode = NULL;
}
//kiểm tra KHoá lịch học
const char* keyLichHoc(classroom room) {
	if(room.lichHoc == 1)
		return "Sang";
	else if(room.lichHoc == 2)
		return "Chieu";
	return "Toi";
}