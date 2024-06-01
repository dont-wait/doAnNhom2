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
//tim kiem
void searchStudent(studentList sl);

#endif _quanLiHocVien_h