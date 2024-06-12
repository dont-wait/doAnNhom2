#ifndef _quanLiHocVien_h
#define _quanLiHocVien_h
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#pragma warning (disable : 4996)
#include "prototype-LopHoc.h"
#include <iostream>
#include <iomanip>
using namespace std;

//PHẦN 1: Phước
//1. Xây dựng danh sách liên kết đơn phù hợp để tổ chức lưu trữ lớp học và học viên tại trung tâm.
struct student {
	char maHocVien[16];
	char hoLot[21];
	char ten[16];
	Date birthday;
	classroom lopHoc; // bao gồm mã lớp ở trong, giúp dễ truy xuất dữ liệu hơn
	float diem;
};
struct studentNode {
	student value;
	studentNode* next;
};

struct studentList {
	studentNode* headNode;
	studentNode* tailNode;
};
//===============================================
//khởi tạo
void initSList(studentList &sl);
studentNode* createSNode(student x);
roomNode* createRoomNode(classroom x);
//===============================================
//kiểm tra
int isEmpty(studentList sl);
bool is_valid_date(Date date);
bool isValidNumberclass(student newStudent, roomList room);
bool isValidMHV(student newStudent, studentList list);
//===============================================
//hiển thị
void showSNode(studentNode* p);
void showSList(studentList sl);
void printInfo(student x); //show thông tin sinh viên
//===============================================
//thêm
int insertHead(studentList &sl, studentNode* p);
int insertTail(studentList& sl, studentNode* p);
int insertAfter(studentList& sl, studentNode* q, studentNode* p);
//===============================================
//xoá
int deleteHead(studentList &sl, student &x);
int deleteTail(studentList& sl, student& x);
int deleteAfter(studentList& sl, studentNode* q, student& x);
//===============================================
//nhập dữ liệu bằng tay
void input1Info(roomList room, student& x, studentList list);
//===============================================
//Xu li file
void readListStudent(char fileName[], studentList& sl);
void read1InfoOnFile(FILE* fi, student& x);
void writeInfOnFile(char fileName[], student x);//write FILE	đưa dữ liệu từ RAM vào FILE.txt lun
void getAnwser(studentList &sl, student x);
//tim kiem
void searchStudent(studentList sl);
//in thông tin học viên học lớp có tiền học lớn nhất //2 200 0000
void printStudentHaveMaxFee(studentList listStudent, roomList listRoom);
//in thông tin học viên đạt học bổng (điểm >= 8) vào file
void saveDSHocBong_ToTextFile(studentList &listStudent, char DSHocBong[]);
void saveDSHocBong(FILE *fo, student &x);
//tìm học sinh có điểm cao nhất
float timDiemCaoNhat(studentList list);
void inHocVienDiemCaoNhat(studentList list);
//sắp xếp theo tên
void inHocVienChuaDat(studentList list);
void sapXepHocVien(studentList &list);	//theo alphabet
//in thông tin theo tên lớp
void inThongTinHocVienTheoTenLop(studentList list, roomList rooms);
//sắp xếp danh sách học viên
void sapXepTheoMaLopVaDiem(studentList &list);
void sapXepTheoMaLop(studentList &list);
void swap(studentNode* &a, studentNode* &b);
#endif _quanLiHocVien_h