#include "prototype-HocVien.h"		//	2in1 
									//	đã khai báo thư viện prototype-LopHoc.h bên trong thư viện này nên không cần khai báo lại
//PHẦN 5 Thuỷ
//7. Tìm thông tin các học viên học ở lớp học có học phí cao nhất.
void printStudentHaveMaxFee(studentList listStudent, roomList listRoom) {
	roomNode* maxFee = getMaxFee(listRoom);		//node này chỉ chứa mã lớp chứa số tiền học lớn nhất
	studentNode* curr = listStudent.headNode;	//mike chỉ cần so sánh xem có trùng mã lớp không, trùng thì in hoi, vì đã thoả đk ròi
	printf("DANH SACH HOC VIEN HOC LOP CO HOC PHI LON NHAT: %d\n", maxFee->value.hocPhi);
	while(curr != NULL) {
		if(strcmpi(curr->value.lopHoc.maLop, maxFee->value.maLop) == 0)
			printInfo(curr->value);
		curr = curr->next;
	}
} 
//hàm trả về địa chỉ lớp học có học phí lớn nhất, việc còn lại của mike là so sánh mã lớp 2 bên nx là okie
roomNode* getMaxFee(roomList list) {
    roomNode* curr = list.headNode;
    roomNode* maxFee = curr;
    while (curr != NULL) {
        if (maxFee->value.hocPhi < curr->value.hocPhi) 
            maxFee = curr;    
        curr = curr->next;
    }
    return maxFee; 
}
//======================================================================== PHẦN 5: Thuỷ

//========================================================================
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
//thêm node
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
//PHỤ LỤC=================================================================
//Chuyển đổi key sang lịch học
const char* keyLichHoc(classroom room) {
	if(room.lichHoc == 1)
		return "Sang";
	else if(room.lichHoc == 2)
		return "Chieu";
	return "Toi";
}
//Đổi từ tên lớp sang mã lớp
const char* keyTenMon(const char* nameRoom) { //ép chó thành mèo
	//người dùng nhập vào tên môn, mike chuyển tên môn trong lớp học thành mã lớp học 
	//vd: Basic English -> LH005
	//dựa vào mã lớp học ta bắt đầu tìm kiếm trên ds sinh viên
	//bởi vì đặc tính của sinh viên chỉ Mã lớp chứ k có Tên Môn
    if(strcmpi(nameRoom, "Basic English") == 0)
        return "LH001";
    else if(strcmpi(nameRoom, "Python Programming") == 0)
        return "LH002";
    else if(strcmpi(nameRoom, "Digital Marketing") == 0)
        return "LH003";
    else if(strcmpi(nameRoom, "Basic Accounting") == 0)
        return "LH004";
    else if(strcmpi(nameRoom, "Basic Photoshop") == 0)
        return "LH005";
    else if(strcmpi(nameRoom, "Basic Japanese") == 0)
        return "LH006";
    else if(strcmpi(nameRoom, "Interview Skills") == 0)
        return "LH007";
    else if(strcmpi(nameRoom, "Graphic Design") == 0)
        return "LH008";
    else if(strcmpi(nameRoom, "Project Management") == 0)
        return "LH009";
    else if(strcmpi(nameRoom, "Self-learning Guitar") == 0)
        return "LH010";
    else if(strcmpi(nameRoom, "Online Marketing") == 0)
        return "LH011";
    else if(strcmpi(nameRoom, "Basic Chinese") == 0)
        return "LH012";
    else if(strcmpi(nameRoom, "Tour Guiding") == 0)
        return "LH013";
    else if(strcmpi(nameRoom, "CV Writing Skills") == 0)
        return "LH014";
    else if(strcmpi(nameRoom, "Piano Basics") == 0)
        return "LH015";
    else if(strcmpi(nameRoom, "Basic French") == 0)
        return "LH016";
    else if(strcmpi(nameRoom, "Beauty Tips") == 0)
        return "LH017";
    else if(strcmpi(nameRoom, "Presentation Skills") == 0)
        return "LH018";
    else if(strcmpi(nameRoom, "Java Programming") == 0)
        return "LH019";
    else if(strcmpi(nameRoom, "Baking Basics") == 0)
        return "LH020";
    else
        return "Unknown";
}