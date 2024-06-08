

#include "prototype-HocVien.h"
//xuất thông tin học viên đạt học bổng vào file
void saveDSHocBong(FILE *fo, student &x) {
    fprintf(fo, "%s|%s|%s|%d|%d|%d|%s|%.2f\n", 
            x.maHocVien, 
            x.hoLot, 
            x.ten, 
            x.birthday.year, 
            x.birthday.month, 
            x.birthday.day, 
            x.lopHoc.maLop, 
            x.diem);
}
void saveDSHocBong_ToTextFile(studentList &listStudent, char DSHocBong[]) {
	FILE *fo = fopen(DSHocBong, "w");
	if (fo == NULL)
	{
		printf("Loi mo file: %s", DSHocBong);
		return;
	}
	if (isEmpty(listStudent) == 1)
	{
		printf("Danh sach rong!. Khong the luu FILE \n");
		return;
	}
	studentNode *p = listStudent.headNode;
	while (p != NULL)
	{
		if (p->value.diem >= 8.0)
			saveDSHocBong(fo, p->value);

		p = p->next;
	}
	printf("LUU FILE THANH CONG. \n");
	fclose(fo);
}
//tim kiem
void searchStudent(studentList sl) {
	fflush(stdin);
	int choice;
	do {
		printf("1.Tim hoc vien theo ten lop\n");
		printf("2.Tim hoc vien theo ma hoc vien\n");
		printf("3.Tim hoc vien theo nam sinh\n");
		printf("0.Thoat\n");
		printf("Chon 1..3: ");
		scanf("%d", &choice); 
		fflush(stdin);
	switch (choice)
	{
	case 1:  {
		char tenLop[30];
		printf("Nhap ten lop: ");
		gets_s(tenLop);
		//LAMBDA EXPRESSION
		//TÌm kiếm theo Tên lớp
		auto searchByTenLop = [] (studentList sl, const char* nameRoom) -> void {
			studentNode* currNode = sl.headNode;
			bool found = false;
			while(currNode != NULL) {
				if(stricmp(currNode->value.lopHoc.maLop, keyTenMon(nameRoom)) == 0) {
					found = true;	//cờ đã lên, ít nhất tìm đc 1 học viên học trong lớp 
					showSNode(currNode);				 
				} 
				currNode = currNode->next;
			}
			if(!found) printf("Khong ton tai sinh vien nao hoc lop: %s\n", nameRoom); //lớp không có ai học
			
		};
		printf("DANH SACH SINH VIEN HOC LOP: %s\n", strupr(tenLop));
		searchByTenLop(sl, tenLop);
		break;
	}
	case 2: {
		char hocVienCoMaHocVien[16];
		printf("Nhap ma hoc vien: ");
		gets_s(hocVienCoMaHocVien);
		//TÌm kiếm theo Mã học viên
		//nếu có thì chắc chắn chỉ tồn tại 1 sv, vì mã số của mỗi người là duy nhất
		auto searchByMaHocVien = [] (studentList sl, char maHocVien[]) -> void {
			bool found = false;
			studentNode* currNode = sl.headNode;
			while (currNode != NULL) {
				if (stricmp(currNode->value.maHocVien, maHocVien) == 0) {
					found = true;		
					showSNode(currNode);
				}
				currNode = currNode->next;	
			}
			if(!found) printf("Khong tim thay sinh vien co ma: %s\n", maHocVien);
		};	
		printf("Thong tin sinh vien co Ma hoc vien: %s\n", strupr(hocVienCoMaHocVien));
		searchByMaHocVien(sl, hocVienCoMaHocVien);
		break;
	}
	case 3: {
		int year;
		printf("Nhap nam sinh: ");
		scanf("%d", &year);
		//TÌm kiếm theo Năm sinh
		auto searchByYOB = [](studentList sl, int year) -> void {
			bool found = false;
			studentNode* currNode = sl.headNode;
			while (currNode != NULL) {
				if (currNode->value.birthday.year == year) {
					found = true;
					showSNode(currNode);		
				}
				currNode = currNode->next;
			}
			if(!found) printf("Khong co sinh vien nao sinh nam: %d\n", year);
		};		
		printf("DANH SACH SINH VIEN SINH NAM: %d\n", year);
		searchByYOB(sl, year);
		break;
	}
	case 0:
		break;
	default: printf("Vui long chon 0..3!!!\n");
	}
}while(choice != 0);
}
//=================================================
//Xử lí file
void readListStudent(char fileName[], studentList& sl) {
	int n;
	FILE* fi = fopen(fileName, "r");
	if (fi == NULL) {
		printf("Khong the mo file!\n");
		exit(1);
	}
	fscanf(fi, "%d\n", &n);
	initSList(sl);
	for (int i = 0; i < n; i++)
	{
		student x;
		read1InfoOnFile(fi, x);

		studentNode* p = createSNode(x);
		insertTail(sl, p);
	}
	fclose(fi);
	printf("Doc file %s thanh cong vui long nhan 2 de in\n", fileName);
}

void read1InfoOnFile(FILE* fi, student& x) {
	fscanf(fi, "%[^|]|%[^|]|%[^|]|%d%d%d|%[^|]|%f\n", &x.maHocVien, &x.hoLot, &x.ten, &x.birthday.year, &x.birthday.month, &x.birthday.day, &x.lopHoc.maLop, &x.diem);
}
//==============================
void input1Info(roomList room, student& x, studentList list) {
	fflush(stdin);
	do {
		printf("Nhap ma hoc vien: ");
		gets_s(x.maHocVien);
		if(!isValidMHV(x, list))
			printf("Da ton tai Ma hoc vien nay!\n");
	}while(!isValidMHV(x, list));
	
	fflush(stdin);
	printf("Nhap Ho lot : ");
	gets_s(x.hoLot);
	
	fflush(stdin);
	printf("Nhap Ten: ");
	gets_s(x.ten);
	fflush(stdin);
	do {
		printf("Nhap ngay thang nam sinh (yyyy/mm/dd): ");
		scanf("%d%d%d", &x.birthday.year, &x.birthday.month, &x.birthday.day);
		if (!is_valid_date(x.birthday))
			printf("SAI DINH DANG! Moi ban nhap lai\n");
	} while (!is_valid_date(x.birthday));	//còn nhập sai thì nhập lại đi :)
	
	do {
		fflush(stdin);
		printf("Nhap Ma lop: ");
		gets_s(x.lopHoc.maLop);
		if (!isValidNumberclass(x, room)) //false
			printf("Ma lop hoc khong ton tai! Vui long nhap lai\n");
	} while (!isValidNumberclass(x, room)); //false
	
	fflush(stdin);
	printf("Nhap Diem: ");
	scanf("%f", &x.diem);
}
//==============================
//Xoá studentNode 3 cách
int deleteAfter(studentList& sl, studentNode* q, student& x) {
	if (!q || !q->next)
		return 0;
	studentNode* p = q->next;
	q->next = p->next;
	if (sl.tailNode == p)
		sl.tailNode = q;
	x = p->value;
	delete p;
	return 1;
}
int deleteHead(studentList &sl, student &x) {
	if (isEmpty(sl))
		return 0;
	studentNode* p = sl.headNode;
	sl.headNode = sl.headNode->next;
	x = p->value;
	delete p;		
	return 1;
}
int deleteTail(studentList& sl, student& x) {
	if (isEmpty(sl))
		return 0;
	studentNode* target = sl.tailNode;	//vị trí cần xoá, đích đến.
	studentNode* currNode = sl.headNode;
	if (currNode == target)
		sl.headNode = sl.tailNode = NULL;
	else {
		while (currNode->next != target)
			currNode = currNode->next;
		sl.tailNode = currNode;
		sl.tailNode->next = NULL;
	}
		
	x = target->value;
	delete target;
	return 1;
}
//=========================================
//thêm studentNode 3 cách
int insertAfter(studentList& sl, studentNode* q, studentNode* p) {
	if (!p || !q)
		return 0;
	p->next = q->next;
	q->next = p;
	if (sl.tailNode = q)
		sl.tailNode = p;
	return 1;
}

int insertTail(studentList& sl, studentNode* p) {
	if (!p)	//p==NULL
		return 0;
	if (isEmpty(sl))
		insertHead(sl, p);
	else {
		sl.tailNode->next = p;
		sl.tailNode = p;
	}
	return 1;
}

int insertHead(studentList &sl, studentNode* p) {
	if (p == NULL)
		return 0;
	if (isEmpty(sl))
		sl.headNode = sl.tailNode = p;
	else {
		p->next = sl.headNode;
		sl.headNode = p;
	}
	return 1;
}
//========================================================================
//xuất thông tin node
void showSList(studentList sl) {
	if (isEmpty(sl)) {
		printf("Linked studentList is Empty\n");
		return;
	}
	printf("Noi dung danh sach lien ket:\n");
	printf("|%-s|%-14s|%-21s|%16s| %s|%-11s|%s|\n", "STT", "Ma hoc vien", "Ho lot", "Ten", "yyyy/mm/dd", "Ma lop hoc", "Diem");
	printf("---------------------------------------------------------------------------------------\n");
	studentNode* p = sl.headNode;
	int i = 0;
	while (p != NULL) {
		printf("  %02d", i+1);
		showSNode(p);
		i++;
		p = p->next;
	}
	printf("====================================================================================\n");
}

void showSNode(studentNode* p) {
	printInfo(p->value);
}
void printInfo(student x) {
	printf("|%-14s|%-21s|%16s| %d/%02d/%02d|%-11s|%4.2f|\n", x.maHocVien
		, x.hoLot
		, x.ten
		, x.birthday.year
		, x.birthday.month
		, x.birthday.day
		, x.lopHoc.maLop
		, x.diem
		);
}
int isEmpty(studentList sl) {
	return sl.headNode == NULL;
}
//init
roomNode* createRoomNode(classroom x) {
	roomNode* p = new roomNode;
	if (p == NULL)
		printf("Khong du bo nho cap phat\n");
	p->value = x;
	p->next = NULL;
	return p;
}
studentNode* createSNode(student x) {
	studentNode* p = new studentNode;
	if (p == NULL)
		printf("Khong du bo nho cap phat\n");
	p->value = x;
	p->next = NULL;
	return p;
}

void initSList(studentList &sl) {
	sl.headNode = sl.tailNode = NULL;
}
//PHỤ LỤC===================================================================
//Kiểm tra
bool is_valid_date(Date date) {
	// Kiểm tra xem day, month, year có phải là số nguyên
	if (date.day < 1 || date.month < 1 || date.year < 1) 
		return false;
	// Kiểm tra xem year có phải là năm nhuận
	bool is_leap_year = (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0));

	// Số ngày trong mỗi tháng
	int days_in_month[] = { 31, 28 + is_leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// Kiểm tra xem month có hợp lệ không
	if (date.month < 1 || date.month > 12) {
		return false;
	}

	// Kiểm tra xem day có hợp lệ không
	if (date.day < 1 || date.day > days_in_month[date.month - 1]) {
		return false;
	}
	return true;
}
//Kiểm tra lớp học đó có mở, có tồn tại
bool isValidNumberclass(student newStudent, roomList room) {
	roomNode* currNode = room.headNode;
	while (currNode != NULL) {
		if (stricmp(newStudent.lopHoc.maLop, currNode->value.maLop) == 0)
			return true;	//thấy rồi, mừng quá, môn này có mở lớp !
		currNode = currNode->next;
	}
	return false; // Ko có lớp đó để học
}
//không được tồn tại học sinh trùng mã học viên
bool isValidMHV(student newStudent, studentList list) {
	studentNode* currNode = list.headNode;
	while (currNode != NULL) {
		if (stricmp(newStudent.maHocVien, currNode->value.maHocVien) == 0)
			return false; //tìm thấy sinh viên trùng -> NHẬP LẠI
		currNode = currNode->next;
	}
	return true;	//OKIE
}
