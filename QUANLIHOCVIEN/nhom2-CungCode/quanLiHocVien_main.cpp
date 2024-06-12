#include "prototype-HocVien.h"
void process();
void printMenu();
bool isListLoaded = false;
bool checkListLoaded();
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
        printf("Choose 0..10: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                readListStudent("hocVien.txt", sl);
                readListRoom("lopHoc.txt", room);
                isListLoaded = true;
                break;
            case 2:
                if (checkListLoaded()) {
                    showSList(sl);
                    showRoomList(room);
                }
                break;
            case 3:
                if (checkListLoaded()) {
                    input1Info(room, x, sl);
					p = createSNode(x);
                    insertTail(sl, p);
					if(p!=NULL)  
						printf("Them thanh cong!\n");
					else
						printf("Them ko thanh cong!\n");
                }
                break;
            case 4:
                if (checkListLoaded()) {
                    searchStudent(sl);
                }
                break;
			case 5:
				if(checkListLoaded()) {
					inThongTinHocVienTheoTenLop(sl, room);
				}
				break;
			case 6:
				 if (checkListLoaded()) {
					inHocVienDiemCaoNhat(sl);
                }
				break;
			case 7:
				if (checkListLoaded()) {
				printStudentHaveMaxFee(sl, room);
				}
			case 8:
				if (checkListLoaded()) {
				sapXepTheoMaLopVaDiem(sl);
				}
				break;
			case 9:
				if (checkListLoaded()) {
				inHocVienChuaDat(sl);
				}
				break;
			case 10:
				if (checkListLoaded()) {
				saveDSHocBong_ToTextFile(sl, "dshocbong.txt");
				}
            case 0:
                break;
            default:
                printf("Vui long nhap tu 0..10\n");
                break;
        }
    } while (choice != 0);
    printf("Bye! Have a nice day\n");
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
    printf("| 5.In thong tin lop hoc(cac hoc vien trong moi lop)            |\n");
    printf("| 6.Tim hoc vien co diem cao nhat                               |\n");
    printf("| 7.Tim hoc vien hoc o lop co hoc phi cao nhat                  |\n");
    printf("| 8.Sap xep hoc vien theo ma lop, hoc vien cung lop thi sap xep |\n");
    printf("|   Diem giam dan                                               |\n");
    printf("| 9.Thong tin hoc vien co diem chua dat (<5), sap xep giam dan  |\n");
    printf("|   theo ten                                                    |\n");
    printf("| 10.In danh sach sinh vien dat HOC BONG (Diem >=8)             |\n");
    printf("=================================================================\n");
}
//===========================================================================
//PHỤ LỤC
//Kiểm tra danh sách đã đc upload hay chưa, chưa thì không cho dùng tính năng
bool checkListLoaded() {
    if (!isListLoaded) {
        printf("Danh sach chua duoc tai. Vui long tai danh sach truoc.\n");
        return false;
    }
    return true;
}