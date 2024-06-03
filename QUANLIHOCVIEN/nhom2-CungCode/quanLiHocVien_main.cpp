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
    bool isLoaded = false;  // Biến cờ để kiểm tra xem danh sách đã được tải lên hay chưa

    do {
        printMenu();
        printf("Choose 0..10: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            readListStudent("hocVien.txt", sl);
            readListRoom("lopHoc.txt", room);
            isLoaded = true;  // Đặt cờ là true khi danh sách đã được tải
            break;
        case 2:
            if (isLoaded) {
                showSList(sl);
                showRoomList(room);
            } 
			else 
                printf("Danh sach chua duoc tai. Vui long tai danh sach truoc.\n");
            break;
        case 3:
            if (isLoaded) {
                input1Info(room, x, sl);
                p = createSNode(x);
                insertTail(sl, p);
            } 
			else 
                printf("Danh sach chua duoc tai. Vui long tai danh sach truoc.\n");
            break;
        case 4:
            if (isLoaded) {
                searchStudent(sl);
            }
			else 
                printf("Danh sach chua duoc tai. Vui long tai danh sach truoc.\n");
            break;
        // Các case khác cũng thêm kiểm tra isLoaded tương tự như trên
        case 5:
            if (isLoaded) {
                
            } 
			else 
                printf("Danh sach chua duoc tai. Vui long tai danh sach truoc.\n");
            break;
        case 6:
            if (isLoaded) {
               
            } 
			else 
                printf("Danh sach chua duoc tai. Vui long tai danh sach truoc.\n");
            
            break;
        case 7:
            if (isLoaded) {
                
            } 
			else 
                printf("Danh sach chua duoc tai. Vui long tai danh sach truoc.\n");
            break;
        case 8:
            if (isLoaded) {
                // Thực hiện các chức năng liên quan đến case 8
            } else 
                printf("Danh sach chua duoc tai. Vui long tai danh sach truoc.\n");
            break;
        case 9:
            if (isLoaded) {
                // Thực hiện các chức năng liên quan đến case 9
            } 
			else
                printf("Danh sach chua duoc tai. Vui long tai danh sach truoc.\n");
            break;
        case 10:
            if (isLoaded) {
                // Thực hiện các chức năng liên quan đến case 10
            } 
			else
                printf("Danh sach chua duoc tai. Vui long tai danh sach truoc.\n");
            break;
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

//============================================================================
//PHỤ LỤC
//TH: Người dùng chưa load danh sách lên thì khôngn đc sử dụnngn các tính năng
