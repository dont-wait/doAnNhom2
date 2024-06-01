#include "prototype-HocVien.h"
void process();
void printMenu();

int main() {
	process();
	getch();
	return 0;
}
void process() {
	student x;
	studentList sl;
	roomList room;
	studentNode* p;
	int choice;

	do {
		printMenu();
		printf("Choose 0..9: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			readListStudent("hocVien.txt", sl);
			readListRoom("lopHoc.txt", room);	
			break;
		case 2:
			showSList(sl);
			showRoomList(room);
			break;
		case 3:
			input1Info(room, x, sl);
			p = createSNode(x);
			insertTail(sl, p);
			break;
		case 4:
			searchStudent(sl);
			break;
		default:
			printf("Vui long nhap tu 0..9\n");
			break;
		}
	} while (choice != 0);
}

void printMenu() {
	printf("=================================================================\n");
printf("|                                                               |\n");
printf("|            Chao mung ban den voi chuong trinh                 |\n");
printf("|                 QUAN LI HOC VIEN                              |\n");
printf("|                                                               |\n");
printf("|---------------------------------------------------------------|\n");
printf("| 1.Doc thong tin lop hoc va hoc vien tu FILE                   |\n");
printf("| 2.Xuat thong tin cac lop hoc va sinh vien hien tai            |\n");
printf("| 3.Them 1 hoc vien vao danh sach - bang ban phim               |\n");
printf("| 4.Tim kiem hoc vien                                           |\n");
printf("| 5.In thong tin lop hoc                                        |\n");
printf("| 6.Tim hoc vien co diem cao nhat                               |\n");
printf("| 7.Tim hoc vien hoc o lop co hoc phi cao nhat                  |\n");
printf("| 8.Sap xep hoc vien theo ma lop, hoc vien cung lop thi sap xep |\n");
printf("|   Diem giam dan                                               |\n");
printf("| 9.Thong tin hoc vien co diem chua dat (<5), sap xep giam dan  |\n");
printf("|   theo ten                                                    |\n");
printf("| 10.In danh sach sinh vien dat HOC BONG (Diem >=8)             |\n");
printf("=================================================================\n");


}