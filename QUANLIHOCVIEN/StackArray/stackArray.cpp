//#include <stdio.h>
//#include <conio.h>
//#define MAX_ARRAY 100
//struct stack {
//	int top;
//	int a[MAX_ARRAY];
//};
//void init(stack &st);
//int isEmpty(stack st);
//int isFull(stack st);
//int push(stack &st, int x);
//int pop(stack &st, int &x);
//int getTop(stack &st);
//void input(stack &st, int n);
//void output(stack st);
//void printMenu();
//int search(stack s, int target);	//trả về vị trí tìm thấy 
//stack sortStackAndReturnNew(stack &s) {
//    stack sortedStack;
//    init(sortedStack);
//
//    // Sao chép các phần tử từ stack ban đầu vào mảng tạm thời để sắp xếp
//    int temp[MAX_ARRAY];
//    for (int i = 0; i <= s.top; i++) 
//        temp[i] = s.a[i];
//    
//
//    // Sắp xếp mảng tạm thời
//    for (int i = 0; i <= s.top; i++) 
//        for (int j = i + 1; j <= s.top; j++) 
//            if (temp[i] > temp[j]) {
//                int t = temp[i];
//                temp[i] = temp[j];
//                temp[j] = t;
//            }
//    // Đẩy các phần tử đã sắp xếp vào stack mới
//    for (int i = s.top; i >= 0; i--) 
//        push(sortedStack, temp[i]);
//    return sortedStack;
//}
//int main() {
//	//tao mot stack s
//    stack st;
//    //nhap n phan tu can them vao stac
//    int n;
//	int x;
//	int choice;
//	int target, result;
//	do{
//		printMenu();
//		printf("Nhap lua chon: ");
//		scanf("%d", &choice);
//		switch (choice)
//		{
//		case 1:
//			//khoi tao stack s
//			init(st);
//			printf("Kkhoi tao stack mang thanh cong!");
//			break;
//		case 2:
//			printf("Nhap n: ");
//			scanf("%d",&n);
//			input(st,n);
//			break;
//		case 3:
//			//lay phan tu top cua stack ra va xoa
//			pop(st, x);
//			printf("Stack sau khi pop la\n");
//			output(st);
//			break;
//		case 4:
//			printf("Stack vua nhap la: \n");
//			output(st);
//			break;
//		case 5:
//			printf("Nhap vao gia tri muon tim: ");
//			scanf("%d", &target);
//			result = search(st, target);
//			if(result == -1)
//				printf("Ko ton tai %d trong Stack!\n", target);
//			else	
//				printf("Gia tri %d nam tai vi tri %d trong stack\n", target, result); 
//			break;
//		case 6:
//			st = sortStackAndReturnNew(st);
//			printf("sap xep thanh cong\n");
//			break;
//		case 0:
//			printf("Have a gud time <3\n");
//			break;
//			
//		default:
//			printf("Vui long nhap tu 0.6");
//		break;
//		}
//
//	}while(choice != 0);
//	getch();
//}
//void printMenu() {
//	printf("\n=================================\n");
//	printf("1.Khoi tao stack dac            =\n");
//	printf("2.Them phan tu                  =\n");
//	printf("3.Xoa 1 phan tu                 =\n");
//	printf("4.Duyet Stack                   =\n");
//	printf("5.Tim kiem phan tu              =\n");
//	printf("6.Sap xep cac phan tu           =\n");
//	printf("=================================\n");
//}
////void sortStack(stack &s) {
////    if (isEmpty(s)) {
////        return;
////    }
////	//sắp xếp tăng dần
////    for (int i = 0; i < s.top; i++) 
////        for (int j = i + 1; j < s.top - 1; j++) 
////            if (s.a[i] > s.a[j]) {
////               int tmp = s.a[i];
////			   s.a[i] = s.a[j];
////			   s.a[j] = tmp;
////            }
////}
//int search(stack s, int target) {
//    for (int i = 0; i <= s.top; i++)
//        if (s.a[i] == target) 
//            return i;
//    return -1;	//ko tồn tại trong mảng
//}
//void output(stack st) {
//	if(isEmpty(st)) {
//		printf("Stack Rong\n");
//		return;
//	}
//	//duyet tu phan tu top ve phan tu cuoi stack
//    for(int i = st.top; i > -1; i--){
//        //hien thi ra ket qua
//		printf("     | %5d |\n", st.a[i]);
//    }
//}
//void input(stack &st, int n) {
//	    //duyet tu 0 den n
//    for(int i = 0; i< n; i++){
//        //thuc hien nhap gia tri vao bien x
//        int x;
//        printf("Nhap gia tri node thu %d: ",i);
//        scanf("%d",&x);
//        //thuc hien push vao stack
//        push(st,x);
//    }
//	printf("Them thanh cong!\n");
//}
//int getTop(stack &st) {
//	int x;
//    // stack khac rong
//    if(!isEmpty(st)){
//        //thuc hien gan phan tu cuoi bang x
//        x = st.a[st.top];
//        //tra ve x duoc gan bang phan tu cuoi cung cua mang
//        return x;
//	}
//    return NULL;
//}
//int pop(stack &st, int &x) {
//     // neu stack khac rong
//    if(!isEmpty(st)){
//        //thuc hien gan phan tu cuoi cua stack bang x
//        x = st.a[st.top];
//        //giam so luong phan tu mang di 1 don vi
//        st.top--;
//		return 1;
//    }
//	return 0; //xoa thanh cong
//}
//int push(stack &st, int x) {
//    if(!isFull(st)){ 
//        st.top++;
//        st.a[st.top] = x;
//		return 1;
//	}
//	return 0; // fail 
//}
//int isFull(stack st) {return st.top == MAX_ARRAY - 1;	}// 0..99 . 100 
//int isEmpty(stack st) {return st.top == -1;}
//void init(stack &st) {st.top = -1;}