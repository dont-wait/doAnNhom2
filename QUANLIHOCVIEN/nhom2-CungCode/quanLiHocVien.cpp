

#include "prototype-HocVien.h"
//tim kiem
void searchStudent(studentList sl) {
	fflush(stdin);
	int choice;
	studentNode* p;
	roomList room;
	printf("1.Tim hoc vien theo ten lop\n");
	printf("2.Tim hoc vien theo ma hoc vien\n");
	printf("3.Tim hoc vien theo nam sinh\n");
	printf("Chon 1..3: ");
	scanf("%d", &choice); 
	fflush(stdin);
	switch (choice)
	{
	case 1: 
		char tenLop[30];
		printf("Nhap ten lop: ");
		gets_s(tenLop);
		roomNode* roomNodeExist =  findNodeExistTenLopForTrue(room, tenLop);	
		auto searchByTenLop = [] (studentList sl, char nameRoom[]) -> studentNode*{
			studentNode* currNode = sl.headNode;
			
			return NULL;
		};
		break;
	case 2:
		char hocVienCoMaHocVien[16];
		printf("Nhap ma hoc vien: ");
		gets_s(hocVienCoMaHocVien);
		
		auto searchByMaHocVien = [] (studentList sl, char nameClass[]) -> studentNode*{
			studentNode* currNode = sl.headNode;
			while (currNode != NULL) {
				if (stricmp(currNode->value.maHocVien, nameClass) == 0)
					return currNode;
				currNode = currNode->next;
			}
			return NULL;
		};
		
		p = searchByMaHocVien(sl, hocVienCoMaHocVien);
		if (p == NULL)
			printf("Khong ton tai hoc vien co ten lop %s\n", hocVienCoMaHocVien);
		else {
			p = createSNode(p->value);
			showSNode(p);
		}
		break;
	case 3:
		int year;
		printf("Nhap nam sinh: ");
		scanf("%d", &year);
		
		auto searchByYOB = [](studentList sl, int year) -> studentNode* {
			studentNode* currNode = sl.headNode;
			while (currNode != NULL) {
				if (currNode->value.birthday.year == year)
					return currNode;
			currNode = currNode->next;
			}
			return NULL;
		};
		
		p = searchByYOB(sl, year);
		if (p == NULL)
			printf("Khong ton tai hoc vien sinh nam %d\n", year);
		else {
			p = createSNode(p->value);
			showSNode(p);
		}
		break;
	default:
		break;
	}
	
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
bool isValidNumberclass(student newStudent, roomList room) {
	roomNode* currNode = room.headNode;
	while (currNode != NULL) {
		if (stricmp(newStudent.lopHoc.maLop, currNode->value.maLop) == 0)
			return true;
		currNode = currNode->next;
	}
	return false;
}

void input1Info(roomList room, student& x) {
	fflush(stdin);
	printf("Nhap ma hoc vien: ");
	gets_s(x.maHocVien);
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
		if (isValidNumberclass(x, room) == false)
			printf("Ma lop hoc khong ton tai! Vui long nhap lai\n");
	} while (isValidNumberclass(x, room) != true);
	
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


