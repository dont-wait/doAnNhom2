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
//int main() {
//	//tao mot stack s
//    stack st;
//    //nhap n phan tu can them vao stac
//    int n;
//	int x;
//    printf("Nhap n: ");
//    scanf("%d",&n);
//    
//	//khoi tao stack s
//    init(st);
//    //goi ham nhap n phan tu vao stack
//    
//	input(st,n);
//    //goi ham xuat cac phan tu o tron stack
//    printf("Stack vua nhap la: \n");
//    output(st);
//    
//	//lay phan tu top cua stack ra nhung khong xoa
//    printf("Top cua stack voi ham top %d\n", getTop(st));
//    
//	//lay phan tu top cua stack ra va xoa
//	pop(st, x);
//    printf("Stack sau khi pop la\n");
//    output(st);
//
//	getch();
//}
//void output(stack st) {
//	if(isEmpty(st)) {
//		printf("Stack Rong\n");
//		return;
//	}
//	//duyet tu phan tu top ve phan tu cuoi stack
//    for(int i = st.top; i > -1; i--){
//        //hien thi ra ket qua
//        printf("     | %d |\n",st.a[i]);
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
//int isFull(stack st) {return st.top == MAX_ARRAY - 1;	}// 0..99 -> 100 
//int isEmpty(stack st) {return st.top == -1;}
//void init(stack &st) {st.top = -1;}