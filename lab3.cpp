#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<math.h>
using namespace std;
void bai1(){
    int x,y;
    //khai bao con tro p tro den bien x
    int *p =&x;
    *p=80;
    cout<<"Dia chi cua bien x: "<<&x<<endl;
    cout<<"Dia chi cua con luu trong con tro p: "<<p<<endl;
    cout<<"Gia tri ma con tro p tro den: "<<*p<<endl;
    cout<<"Gia tri bei x: "<<x<<endl;
    if (x == *p)
    {
        cout << "gia tri con tro = gia tri x" << endl;
    }
}
void bai2(){
    int arr[30];
    //nhap mang voi gia tri ngau nhien
    for(int i=0;i<30;i++){
        arr[i]= rand() % 10;
    }
    //xuat mang
    for(int i=0;i<30;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int *ptr=arr;
    //xuat mang theo ki phap do doi
    for(int i=0;i<30;i++){
        cout<<*(ptr+i)<<" ";
    }
    cout<<endl;
    //xuat mang theo ki phap chi so 
    for(int i=0;i<30;i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}
void bai3(){
    int x,y;
    cin>>x>>y;
    int *ptr = &x;
    int *ptr_01= &y;
    while (*ptr_01!=0)
    {
        int r = *ptr % *ptr_01;
        *ptr=*ptr_01;
        *ptr_01=r;
    }
    cout<<"uoc chung lon nhat cua 2 so x va y la: "<<*ptr<<endl;
}
void bai4(){
    int arr[30], a=rand() %31;
    int *ptr=arr;
    for(int i=0;i< a;i++){
        arr[i]=rand() % 10;
    }
    int *max;
    max=arr;
    cout<<"Cac phan tu le la: "<<endl;
    //ky phap do doi
    for(int i=0;i<a;i++){
        if(*(ptr+i)%2!=0){
            cout<<*(ptr+i)<<" ";
        }
        if(*max<*(ptr+i)){
            max=ptr+i;
        }
    }
    //xac nhan lai dia chi da dung chua
    cout<<endl<<"Dia chi cua phan tu co gia tri lon nhat la: "<<max<<endl;
    int max_1=arr[0], *max_2;
    cout<<"Phan tu lon nhat la: ";
    for(int i=0;i<a;i++){
        if(max_1<arr[i]){
            max_1=arr[i];
            max_2=&arr[i];
        }
    }
    cout<<max_2<<endl;
}
//cach cua kha
bool odd(int n){
    //neu true se tra ra gia tri ben trai dau phay va nguoc lai
    return n%2 !=0 ? true : false;
}
void task4(){
    int arr[30];
    int *ptr=arr;
    for(int i=0;i< 30;i++){
        arr[i]=rand() % 10;
    }
    for(int i=0;i< 30;i++){
        cout<<*(ptr+i)<<" ";
    }
    cout<<endl;
    for(int i=0; i<30;i++){
        //ky phap do doi 
        if(odd(*(ptr+i))){
            cout<<*(ptr+i)<<" ";
        }
    }
    cout<<endl;
    int right =29;
    int left =0;
    while(right>left){
        if(*(ptr+right)<*(ptr+left)){
            right--;
        }
        else{
            left++;
        }
    }
    cout<<"Max is: "<<*(ptr+left)<<" "<<left<<endl;
    cout<<"Max is: "<<*(ptr+right)<<" "<<right<<endl;
}
void bai5(){
    int n;
    cout<<"Moi nhap so gia tri fib ma ban muon tinh: ";
    cin>>n;
    if(n<=1){
        cout<<"n phai lon hon 1"<<endl;
        return ;
    }
    //cap phat dong
    int *arr=new int [n];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<n;++i){
        arr[i]=arr[i-1]+arr[i-2];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //giai phong vung nho
    delete[] arr;
    //huy cap phat dong dua con tro ve con tro rong
    arr=nullptr;
}
//khong dung cap phat dong
void task5(){
    int n;
    cout<<"Moi nhap so gia tri fib ma ban muon tinh: ";
    cin>>n;
    if(n<=1){
        cout<<"n phai lon hon 1"<<endl;
        return ;
    }
    int arr[100];
    int *ptr=arr;
    ptr[0]=0;
    ptr[1]=1;
    for(int i=2;i<n;i++){
        ptr[i]=ptr[i-1]+ptr[i-2];
    }
    for(int i=0;i<n;i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}
void swap(int *p1, int *p2){
    int p=*p1;
    *p1=*p2;
    *p2=p;
}
void bai6(){
    int n;
    cout<<"Moi nhap so luong phan tu: ";
    cin>>n;
    if(n<=0){
        cout<<"So luong phan tu khong hop le";
        return;
    }
    int *arr= new int [n];
    srand(static_cast<int>(time(0)));
    for(int i=0;i<n;i++){
        arr[i]=rand() % 10;
    }
    cout<<"Mang truoc khi doi chieu: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int right=n-1;
    int left =0;
    while (right>left)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    cout<<"Mang sau khi dao nguoc: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //giai phong vung nho cua mang
    delete[] arr;
    //huy cap phat dong dua con tro ve con tro rong
    arr=nullptr;
}
//lam trong 1 ham
void task6(){
    int n;
    cout<<"Moi nhap so luong phan tu: ";
    cin>>n;
    if(n<=0){
        cout<<"So luong phan tu khong hop le";
        return;
    }
    int *arr= new int [n];
    srand(static_cast<int>(time(0)));
    for(int i=0;i<n;i++){
        arr[i]=rand() % 10;
    }
    cout<<"Mang truoc khi doi chieu: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int *start=arr;
    //o day truyen dia chi chu khong phai gia tri va cung co the ghi la *end=arr+n-1
    int *end= &arr[n-1];
    while(end>start){
        int temp =*start;
        *start=*end;
        *end=temp;
    }
    cout<<"Mang sau khi dao nguoc: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //giai phong vung nho cua mang 
    delete[] arr;
    //huy cap phat dong dua con tro ve con tro rong
    arr=nullptr;
}
//khi khong co ham con tro 
void bai7(){
    int n;
    cout<<"Nhap so luong phan tu: ";
    cin>>n;
    if(n<=0){
        cout<<"So luong phan tu khong hop le";
        return;
    }
    int *arr= new int [n];
    srand(static_cast<int>(time(0)));
    for(int i=0;i<n;i++){
        arr[i]=rand() % 10;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int target;
    cout<<endl<<"Moi nhap so ban muon tim: ";
    cin>>target;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"Dia chi cua so ban muon tim: "<<arr+i<<endl;
            cout<<"Vi tri cua so ban muon tim trong mang la: "<<i<<endl;
            return;
        }
    }
    cout<<"Khong ton tai";
    //giai phong vung nho cua mang
    delete[] arr;
}
//no se tra ve dia chi
//cach 1: tim voi mang 
int *findElement(int arr[], int n, int target){
    for(int i=0;i<n;i++){
        if(target == arr[i]){
            return &arr[i];
        }
    }
    return NULL;
}
//tim voi con tro mang
int *timphantu(int *arr, int n, int target ){
    for(int *ptr=arr;ptr<arr+n;ptr++){
        if(*ptr == target){
            return ptr;
        }
    }
    return NULL;
}
//cach 3 khong dung cap phat dong
void bai7cach3(){
    cout<<"Day la cach 3"<<endl;
    int n;
    cout<<"Nhap so luong phan tu: ";
    cin>>n;
    if(n<=0){
        cout<<"So luong phan tu khong hop le";
        return;
    }
    int arr[100];
    srand(static_cast<int>(time(0)));
    for(int i=0;i<n;i++){
        arr[i]=rand() % 10;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int target;
    cout<<endl<<"Moi nhap so ban muon tim: ";
    cin>>target;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"Dia chi de xac nhan la: "<<&arr[i]<<endl;
            break;
        }
    }
    cout<<"Dia chi o cach 1: "<<findElement(arr,n,target)<<endl;
    cout<<"Dia chi o cach 2: "<<timphantu(arr,n,target)<<endl;
}
void task7(){
    int n;
    cout<<"Nhap so luong phan tu: ";
    cin>>n;
    if(n<=0){
        cout<<"So luong phan tu khong hop le";
        return;
    }
    int *arr= new int [n];
    srand(static_cast<int>(time(0)));
    for(int i=0;i<n;i++){
        arr[i]=rand() % 10;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int target;
    cout<<endl<<"Moi nhap so ban muon tim: ";
    cin>>target;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"Dia chi de xac nhan la: "<<&arr[i]<<endl;
            break;
        }
    }
    cout<<"Dia chi o cach 1: "<<findElement(arr,n,target)<<endl;
    cout<<"Dia chi o cach 2: "<<timphantu(arr,n,target)<<endl;
    //giai phong vung nho cua mang 
    delete[] arr;
    //huy cap phat dong dua con tro ve con tro rong
    arr=nullptr;
}
void bai8(){
    cout<<"Nhap vao chieu ca cua tam giac Pascal: ";
    int h;
    cin>>h;
    //khai bao con tro cap 2 
    //con tro tro den 1 mang 1 chieu, int *[h]: chua cac con tro tro den mang 1 chieu khac
    int **pascal=new  int *[h];
    for(int i=0;i<h;i++){
        pascal[i]=new int [i+1];
    }
    //ghi gia tri len tam giac pascal
    for(int i=0;i<h;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i){
                pascal[i][j]=1;
            }
            else{
                pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<=i;j++){
            cout<<pascal[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < h; i++) {
        //giai phong vung nho cua moi hang
        delete[] pascal[i];
    }
    //giai phong vung nho cua hang
    delete[] pascal;
    //huy cap phat dong dua con tro ve con tro rong
    pascal=nullptr;
}
bool isPrime(int n){
    if(n<2){
        return false;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int sumPrime(int **arr,int cot, int hang){
    int sum =0;
    for(int i=0;i<hang;i++){
        for(int j=0;j<cot;j++){
            if(isPrime(arr[i][j])){
                sum+=arr[i][j];
            }
        }
    }
    return sum;
}
void bai9(){
    int cot, hang;
    cout<<"Moi ban nhap hang va cot: ";
    cin>>hang >>cot;
    int **arr=new int *[hang];
    for(int i=0;i<hang;i++){
        arr[i]=new int[cot];
    }
    srand(static_cast<int>(time(0)));
    for(int i=0;i<hang;i++){
        for(int j=0;j<cot;j++){
            arr[i][j]= rand() % 10; 
        }
    }
    for(int i=0;i<hang;i++){
        for(int j=0;j<cot;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Cac so nguyen to: ";
    for(int i=0;i<hang;i++){
        for(int j=0;j<cot;j++){
            if(isPrime(arr[i][j])){
                cout<<arr[i][j]<<" ";
            }
        }
    }
    cout<<endl;
    cout<<"Tong mang la: "<<sumPrime(arr,cot,hang)<<endl;
    for(int i=0;i<hang;i++){
        delete[] arr[i];
    }
    //huy cap phat dong dua con tro ve con tro rong
    delete[]arr;
    arr=nullptr;
} 
//bai 10: 
void inputMatrix(int **matrix, int rows, int cols){
    srand(static_cast<int>(time(0)));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            matrix[i][j]=rand() % 10;
        }
    }
}
void printMatrix(int **matrix, int rows, int cols){
    for(int i=0;i<rows;i++){
        cout<<"\t";
        for(int j=0;j<cols;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void SumMatrix(int **matrix1, int **matrix2, int **sumMatrix, int rows, int col){
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            sumMatrix[i][j]= matrix1[i][j]+ matrix2[i][j];
        }
    }
}
void multiplieMatrix(int **matrix1, int **matrix2, int **multiplie, int rows1, int col1, int rows2, int col2){
    for(int i=0;i<rows1;i++){
        for(int j=0;j<col2;j++){
            for(int k=0;k<rows2;k++){
                multiplie[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
}
void bai10() {
    int rows1, col1, rows2,col2;
    cout<<"Moi nhap so luong hang va cot cua matrix1: ";
    cin>>rows1 >>col1;
    cout<<"Moi nhap so luong hang va cot cua matrix2: ";
    cin>>rows2>>col2;
    int **matrix1= new int *[rows1];
    int **matrix2=new int *[rows2];
    for(int i =0;i<rows1;i++){
        matrix1[i]=new int [col1];
    }
    for(int i=0;i<rows2;i++){
        matrix2[i] = new int [col2];
    }
    inputMatrix(matrix1, rows1, col1);
    inputMatrix(matrix2, rows2, col2);
    cout<<"Matrix 1 co gia tri la: "<<endl;
    printMatrix(matrix1, rows1, col1);
    cout<<"Matrix 2 co gia tri la: "<<endl;
    printMatrix(matrix2, rows2, col2);
    if (col1 != rows2) {
        cout << "Khong the tinh tich 2 ma tran." << endl;
    }
    else{
        int **multiplie = new int *[rows1];
        for(int i=0;i<rows1;i++){
            multiplie[i] = new int [col2];
        }
        multiplieMatrix(matrix1,matrix2,multiplie,rows1,col1,rows2,col2);
        cout<<"Tich 2 ma tran la: "<<endl;
        printMatrix(multiplie, rows1, col2);
    }
    if(rows1 != rows2 || col1 != col2){
        cout<<"Khong the tinh tong 2 ma tran";
    }
    else{
        int **sumMatrix=new int *[rows1];
        for(int i=0;i<rows1;i++){
            sumMatrix[i] = new int [col1];
        }
        SumMatrix(matrix1, matrix2,sumMatrix, rows1, col1);
        cout<<"Tong 2 ma tran la: "<<endl;
        printMatrix(sumMatrix, rows1, col1);
    }
}
int main(){
    bai1();
    bai2();
    // bai3();
    bai4();
    task4();
    // bai5();
    // task5();
    // bai6();
    // task6();
    // bai7();
    // bai7cach3();
    // bai8();
    // bai9();
    bai10();
    return 0;
}