#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
const int MAXC = 10, MAXR = 10;
void bai1bnhapmang(int a[10][10], int n, int m);
void bai1cxuatmang(int a[10][10], int n, int m);
//xuat mang nhap mang
void bai1a () {
	//a[hang][cot]
	int a[MAXR][MAXC], n, m;
	cout << " nhap mang 2 chieu: ";
	cin >> n >> m;
	bai1bnhapmang(a, n, m);
	bai1cxuatmang(a, n, m);
}
void bai1bnhapmang(int a[10][10], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
}
void bai1cxuatmang(int a[10][10], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}
}
//nhap mang va xuat mang bang vong lap while
void bai2() {
	int a[MAXR][MAXC], n, m, i=0;
	cout << "nhap mang 2 chieu: ";
	cin >> n >> m;
	while (i < n) {
		int j = 0;
		while (j < m) {
			cin >> a[i][j];
			j++;
		}
		i++;
	}
	int k=0;
	while (k < n) {
		int l = 0;
		while (l < m) {
			cout << a[k][l]<<" ";
			l++;
		}
		cout << endl;
		k++;
	}
}
void bai3() {
	int a[10][15], n, m;
	// nhap so luong hang va cot gioi han 10 hang va 15 cot
	do {
		cout << " nhap mang 2 chieu";
		cin >> n >> m;
	} while (n > 10 && m > 15);
	// nhap gia tri cho mang
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	//tinh tong cua mang
	int tong = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tong = tong + a[i][j];
		}
	}
	cout << "tong tat ca gia tri la: " << tong << endl;
	//tim ra so lon nhat va nho nhat cua mang
	int max=a[0][0], min=a[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
					if (a[i][j] > max) {
						max = a[i][j];
					}
					if (a[i][j] < min) {
						min = a[i][j];
					}
		}
	}
	cout << "gia tri lon nhat va gia tri nho nhat lan luot la: " << max << " " << min << endl;
	// in ra vi tri so lom nhat va nho nhat
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == max) {
				cout << "so lon nhat o hang " << i << " cot " << j << endl;
			}
			if (a[i][j] == min) {
				cout << "so nho nhat o hang " << i << " cot " << j << endl;
			}
		}
	}

}
void bai4(){
	int array[5][6];
	int hang, cot, sum=0;
	// nhap so luong hang va cot co gioi han
	do{
		cout<<"moi nhap so hang va cot: ";
		cin>>hang>>cot;
		if(hang >5 || cot>6){
			cout<<"nhap sai moi nhap lai"<<endl;;
		}
	} while(hang >5 || cot>6);
	//nhap gia tri mang 
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			cin>>array[i][j];
		}
	}
	int choice;
	//tinh tong hang hoac cot cua mang 
	do{
		cout<<"lua chon tinh hang hoac cot (1: Cot 2: Hang)";
		cin>>choice;
		if(choice<1 || choice >2){
			cout<<"khong hop le moi nhap lai"<<endl;
		}
	}while(choice <1 || choice > 2);
	int indexCot, indexHang;
	if(choice ==1){
		do{
			cout<<"moi nhap so cot can tinh tong: ";
			cin>>indexCot;
			if(indexCot<=0 || indexCot>cot){
				cout<<"khong hop le moi nhap le"<<endl;
			}
		}while(indexCot<=0 || indexCot>cot);
		for(int i=0;i<hang;i++){
			sum=sum + array[i][indexCot-1];
		}
		cout<<"tong cot "<<indexCot<<" la "<<sum;
	}
	else{
		do{
			cout<<"moi nhap so hang can tinh tong: ";
			cin>>indexHang;
			if(indexHang <=0 || indexHang >hang	){
				cout<<"khong hop le moi nhap lai"<<endl;
			}
		}while(indexHang <=0 || indexHang >hang);
		for(int i=0;i<cot;i++){
			sum=sum+ array[cot-1][i];
		}
		cout<<"tong hang "<<indexHang<<" la "<<sum;
	}
	//tim so X trong 1 mang
	int x, count=0;
	cout<<"nhap so x can tim: ";
	cin>>x;
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			if(count==0 && array[i][j]==x){
				count++;
				cout<<"so X co ton tai"<<endl;;
				cout<<"so X ton tai o hang "<<i<<" cot "<<j<<endl;
			}
			else if(array[i][j]==x){
				count++;
				cout<<"so X ton tai o hang "<<i<<" cot "<<j<<endl;
			}
		}
	}
	cout<<"tong cong so X xuat hien "<<count<<" lan";
}
// tinh duong cheo chinh va cheo phu trong 1 mang hinh vuong
void bai5(){
	int n, cheochinh=0, cheophu=0;
	int array[100][100];
	cout<<"moi nhap so luong mang hinh vuong n: ";
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>array[i][j];
		}
	}
	//duong cheo chinh
	int cot=0, hang=0;
	for(int i=0;i<n;i++){
		cheochinh=cheochinh+array[hang][cot];
		hang++;
		cot++;
	}
	cout<<"duong cheo chinh bang: "<<cheochinh<<endl;
	int cotphu=n-1, hangphu=0;
	for(int i=0;i<n;i++){
		cheophu=cheophu+array[hangphu][cotphu];
		hangphu++;
		cotphu--;
	}
	cout<<"duong cheo phu bang: "<<cheophu;
}
//bai 6
// tich va tong 2 ma tran giong nhau ve cot va hang
void bai6a(){
	int matrix1[100][100], matrix2[100][100], sumMatrix[100][100], multipliMatrix[100][100];
	int rows, cols;
	cout<<"moi nhap so hang: ";
	cin>>rows;
	cout<<"moi nhap so cot: ";
	cin>>cols;
	if(rows != cols){
		cout<<"khong the tinh duoc";
		return;
	}

	//nhap du lieu matrix1
	cout<<"nhap phan tu matrix thu nhat"<<endl;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>matrix1[i][j];
		}
	}
	//nhap du lieu matrix2
	cout<<"nhap phan tu matrix thu 2"<<endl;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>matrix2[i][j];
		}
	}
	
	//tong va in ra tong 2 ma tran;
	cout<<"tong 2 ma tran la: "<<endl;
	for(int i=0;i<rows;i++){
		cout<<"\t";
		for(int j=0;j<cols;j++){
			sumMatrix[i][j]=matrix1[i][j] + matrix2[i][j];
			cout<<sumMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
	// tich 2 ma tran
	if(rows != cols){
		cout<<"khong the tinh duoc tich 2 ma tran";
	}
	else{
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				for(int k=0;k<cols;k++){
					multipliMatrix[i][j]+= matrix1[i][k]*matrix2[k][j];
				}
			}
		}
	}
	// in ra tich 2 ma tran
	cout<<"tich cua 2 ma tran: "<<endl;
	for(int i=0;i<rows;i++){
		cout<<"\t";
		for(int j=0;j<cols;j++){
			cout<<multipliMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
// tinh tong va tich 2 ma tran co kich thuoc khac nhau
void bai6b(){
	int matrix1[100][100], matrix2[100][100], sumMatrix[100][100], multipliMatrix[100][100];
	int r1, c1, r2, c2;
	cout<<"moi nhap so hang va so cot ma tran 1: ";
	cin>>r1>>c1;
	cout<<"moi nhap so hang va so cot ma tran 2: ";
	cin>>r2>>c2;
	// check xem co tinh tich 2 ma tran duoc khong
	if(c1 != r2){
		cout<<"khong the tich 2 ma tran";
		return;
	}
	cout<<"moi nhap phan tu ma tran 1: ";
	for(int i=0;i<r1;i++){
		for(int j=0;j<c1;j++){
			cin>>matrix1[i][j];
		}
	}
	cout<<"moi nhap phan tu ma tran 2: ";
	for(int i=0;i<r2;i++){
		for(int j=0;j<c2;j++){
			cin>>matrix2[i][j];
		}
	}
	// tinh tong va in ra tong 2 tran
	cout<<"tinh tong 2 ma tran: "<<endl;
	if(c1 >= c2 && r1 >=r2){
		for(int i=0;i<r1;i++){
			cout<<"\t";
			for(int j=0;j<c1;j++){
				sumMatrix[i][j]=matrix1[i][j]+matrix2[i][j];
				cout<<sumMatrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else if(r1>=r2 && c2>=c1){
		for(int i=0;i<r1;i++){
			cout<<"\t";
			for(int j=0;j<c2;j++){
				sumMatrix[i][j]=matrix1[i][j]+matrix2[i][j];
				cout<<sumMatrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else if(r2 >=r1 && c2 >=c1){
		for(int i=0;i<r2;i++){
			cout<<"\t";
			for(int j=0;j<c2;j++){
				sumMatrix[i][j]=matrix1[i][j]+matrix2[i][j];
				cout<<sumMatrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else if(r2 >= r1 && c1>=c2){
		for(int i=0;i<r2;i++){
			cout<<"\t";
			for(int j=0;j<c1;j++){
				sumMatrix[i][j]=matrix1[i][j]+matrix2[i][j];
				cout<<sumMatrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	// tinh tich 2 ma tran
	cout<<"tich 2 ma tran: "<<endl;
	for(int i=0;i<r1;i++){
			for(int j=0;j<c2;j++){
				for(int k=0;k<r2;k++){
					multipliMatrix[i][j]+= matrix1[i][k]*matrix2[k][j];
				}
			}
	}
	// in ra tich ma tran
	for(int i=0;i<r1;i++){
		cout<<"\t";
		for(int j=0;j<c2;j++){
			cout<<multipliMatrix[i][j]<<" ";
		}
		cout<<endl;
	}

}
//bai 7
//ham tao 1 mang co cac gia tri ngau nhien 
void taomang(int array[100][100], int rows, int cols){
	//ham srand nhan so dau vao time(0) cho ham rand() de tao 1 so ngau nhien
	//ham time(0) lay thoi gian tinh theo so giay ke tu bat dau thoi dai unix den hien tai
	//vi time(0) la kieu so long nen static_cast<int> ep kieu ve thanh kieu int
	srand(static_cast<int>(time(0)));
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			// % la chia lay du khi chia nhu vay se khong co so nao vuot qua so du la 10
			array[i][j]= rand() % 10;
		}
	}
}
//tao gia tri mang 1 cach ngau nhien bang vong lap while
void taomang1(int array[100][100], int rows, int cols){
	// time(NULL) = time(0) deu la lay thoi gian hien tai lam dau vao
	srand(static_cast<int>(time(NULL)));
	int i=0;
	while (i<rows)
	{
		int j=0;
		while (j<cols)
		{
			array[i][j]= rand() % 10;
			j++;
		}
		i++;
	}
	
}
//nhap gia tri mang
void inputArray(int array[100][100], int rows, int cols){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>array[i][j];
		}
	}
}
//in ra gia tri mang da duoc nhap
void printArray(int array[100][100], int rows, int cols){
	//kiem tra mang co hop le hay khong
	if(rows <= 0 || cols <= 0){
		return;
	}
	for(int i=0;i<rows;i++){
		cout<<"\t";
		for(int j=0;j<cols;j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}
double averageArray(int array[100][100], int rows, int cols){
	//kiem tra mang co hop le hay khong
	if(rows <= 0 || cols <= 0){
		return 0;
	}
	int sum=0;
	//tinh tong cua mang
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			sum+=array[i][j];
		}
	}
	//tinh trung binh cong
	double average = sum/(rows*cols);
	return average;
}
bool findX(int array[100][100], int rows, int cols, int X){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(array[i][j]==X){
				cout<<X<<" co ton tai"<<endl;
				return true;
			}
		}
	}
	cout<<X<<" khong ton tai"<<endl;
	return false;
}
// hoan doi 2 gia tri X va Y duoc nhap tu user
void hoandoi1(int array[100][100], int rows, int cols){
	int X, Y;
	cout<<"moi nhap so X ban muon tim: ";
	cin>>X;
	cout<<"moi nhap so Y ban muon tim: ";
	cin>> Y;
	if(findX(array, rows, cols, X) && findX(array, rows, cols, Y)){
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(array[i][j]==X){
					array[i][j]=Y;
				}
				else if(array[i][j]==Y){
					array[i][j]=X;
				}
			}
		}
		cout<<"hoan doi thanh cong"<<endl;
	}
	else{
		cout<<"so X hoac Y khong ton tai"<<endl;
	}
}
// hoan doi 2 gia tri X va Y duoc random
void hoandoi2(int array[100][100], int rows, int cols){
	int X, Y;
	srand(static_cast<int>(time(0)));
	X= rand()%10;
	Y= rand()%10;
	cout<<"so X la: "<<X<<endl;
	cout<<"so Y la: "<<Y<<endl;
	if(findX(array, rows, cols, X) && findX(array, rows, cols, Y)){
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(array[i][j]==X){
					array[i][j]=Y;
				}
				else if(array[i][j]==Y){
					array[i][j]=X;
				}
			}
		}
		cout<<"hoan doi thanh cong";
	}
	else{
		cout<<"so X hoac Y khong ton tai";
	}
}
void sumRow(int array[100][100], int rows, int cols){
	int col, sum=0;
	cout<<"moi nhap so cot ban muon tinh tong: ";
	cin>>col;
	//so sanh cot muon tinh co hop le khong
	if(col>=cols){
		cout<<"khong hop le";
		return;
	}
	//tinh tong cot user chon
	else{
		for(int i=0;i<rows;i++){
			sum+=array[i][col];
		}
		cout<<"tong cot "<<col<<" la: "<<sum<<endl;
	}
}
void bai7(){
	int array[100][100];
	int rows, cols;
	cout<<"nhap so hang va so cot: ";
	cin>>rows>>cols;
	// tao mang gia tri ngau nhien
	taomang(array, rows, cols);
	//in ra mang
	printArray(array, rows, cols);
	//tinh trung binh cong
	averageArray(array, rows, cols);
	//kiem tra so 3 co ton tai khong
	if(findX(array, rows, cols, 3)){
		cout<<"so 3 co ton tai"<<endl;;
	}
	else{
		cout<<"so 3 khong ton tai"<<endl;
	}
	//xac nhan va hoan doi 2 gia tri X va Y
	hoandoi1(array, rows, cols);
	//in ra mang sau khi da hoan doi
	printArray(array, rows, cols);
	sumRow(array,rows, cols);

}
//bai 8
//random gia tri mang 
//initializeArray
// bien seed se lam tang gia tri moi khi ham srand duoc su dung giup moi lan tao mang se khac nhau
long seed=time(0);
void randomArray(int array[100][100], int n){
	srand(static_cast<int>(seed++));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			array[i][j]= rand() % 10;
		}
	}
}
//in ra mang da tao
void printarray(int array[100][100], int n){
	for(int i=0;i<n;i++){
		cout<<"\t";
		for(int j=0;j<n;j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}
void sumandmultiplyArray(int array1[100][100],int array2[100][100], int n){
	int sum[100][100], multiplie[100][100];
	//tinh va in ra tong 2 ma tran
	cout<<"tong 2 mang la: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"\t";
		for(int j=0;j<n;j++){
			sum[i][j]=array1[i][j]+array2[i][j];
			cout<<sum[i][j]<<" ";
		}
		cout<<endl;
	}
	//tinh tich 2 ma tran
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				multiplie[i][j]+=array1[i][k]*array2[k][j];
			}
		}
	}
	cout<<"tich 2 ma tran la: "<<endl;
	//in ra tich 2 ma tran
	for(int i=0;i<n;i++){
		cout<<"\t";
		for(int j=0;j<n;j++){
			cout<<multiplie[i][j]<<" ";
		}
		cout<<endl;
	}
}
void bai8(){
	int array[100][100], array1[100][100], array2[100][100];
	int n;
	cout<<"moi nhap kich thuoc mang hinh vuong n: ";
	cin>>n;
	randomArray(array, n);
	printarray(array, n);
	//in ra 2 ma tran
	randomArray(array1, n);
	cout<<"ma tran thu 1 la: "<<endl;
	printarray(array1, n);
	randomArray(array2, n);
	cout<<"ma tran thu 2 la: "<<endl;
	printarray(array2, n);
	//tinh tong va tich 2 ma tran
	sumandmultiplyArray(array1,array2,n);
}
//nhap mang kieu zigzag
void bai9a(){
	int n, array[100][100], value=1;
	cout<<"moi nhap do dai hinh vuong: ";
	cin>>n;
	for(int i=0;i<n;i++){
		//neu cot chan thi danh gia tri tu tren xuong
		if(i %2 ==0){
			for(int j=0;j<n;j++){
				array[j][i]=value;
				value++;
			}
		}
		// neu cot le thi danh gia tri tu duoi len
		else{
			for(int j=n-1;j>=0;j--){
				array[j][i]=value;
				value++;
			}
		}
	}
	printArray(array,n,n);
}
//dung tham chieu truc tiep toi gia tri
void swarps(int &a,int &b){
	int tp;
	tp=a;
	a=b;
	b=tp;
}
//tao ma tran zigzag cach 2
void bai9b(){
	int value =1, n, array[100][100];
	//tao mang ban dau
	cout<<"moi nhap so n: ";
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			array[i][j]=value++;
		}
	}
	//in ra man hinh matrix truoc khi chinh sua
	cout<<"matrix before edit into zigzag: "<<endl;;
	for(int i=0;i<n;i++){
		cout<<"\t";
		for(int j=0;j<n;j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Matrix after edit into zigzag: "<<endl;
	//sap xep theo tu tren xuong duoi
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(i !=j){
				//doi cho theo duong cheo
				swarps(array[i][j],array[j][i]);
			}
		}
	}
	//doi cac cot chan theo tu duoi len tren
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if(j %2 !=0 && i<n/2){
				//doi cho trong cung 1 cot: so dau va so cuoi
				swarps(array[i][j], array[n-1-i][j]);
			}
		}
	}
	printArray(array,n,n);
}
//nhpa mang theo vong xoay
void bai10(){
	int array[100][100], n, value=1;
	cout<<"moi ban nhap so n cho do dai hinh vuong: ";
	cin>>n;
	int left=0, right=n-1, top=0, bot=n-1;
	while(value<=n*n){
		for(int i=left;i<=right;i++){
			array[top][i]=value;
			value++;
		}	
		top++;
		for(int i=top;i<=bot;i++){
			array[i][right]=value;
			value++;
		}
		right--;
		for(int i=right;i>=left;i--){
			array[bot][i]=value;
			value++;
		}
		bot--;
		for(int i=bot;i>=top;i--){
			array[i][left]=value;
			value++;
		}
		left++;
	}
	printArray(array, n, n);
}
//danh sach cho ngoi may bay
//tao danh sach ban dau
void taosodo(string array[20][20]){
	//dung de gan cho mang o hang cot
	char a='A';
	//dung de danh dau so cua hang b: cho 9 hang dau; c: cho tu hang 10 ve sau
	int  b= 1, c=0;
	for(int i=0;i<14;i++){
		for(int j=0;j<7;j++){
			array[0][0]=' ';
			if(i==0 && j!=0){
				array[i][j]=a++;
			}
			else if(j==0 && i !=0){
				if(i>0 && i<=9){
					//ep kieu int ve kieu string
					array[i][j]=to_string(b++);
				}
				else if(i>0){
					array[i][j]=to_string(c++);
				}
			}
			else{
				array[i][j]='*';
			}
		}
	}
}
void xuatsodo(string array[20][20], int n){
	switch (n)
	{
		//xuat toan bo danh sach
	case 0:{
			for(int i=0;i<14;i++){
				if( i==0){
					cout<<"      ";
				}
				else if( i!=0 && i<=9){
					cout<<"Hang "<<" ";
				}
				else{
				cout<<"Hang "<<1;
				}
				for(int j=0;j<7;j++){
				cout<<array[i][j]<<" ";
				}
				cout<<endl;
				}
		break;
	}
	//xuat danh sach cho hang thuong gia
	case 1:{
		for(int i=0;i<3;i++){
			if(i==0){
				cout<<"      ";
			}
			else{
				cout<<"Hang "<<" ";
			}
			for(int j=0;j<7;j++){
				cout<<array[i][j]<<" ";
			}
			cout<<endl;
		}
		break;
	}
	//xuat danh sach cho hang pho thong
	case 2:{
		string a[7];
		char chu='A';
		for(int i=0;i<7;i++){
			if(i==0){
				a[i]=' ';
			}
			else{
				a[i]=chu++;
			}
		}
		cout<<"      ";
		for(int i=0;i<7;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		for(int i=3;i<=7;i++){
			cout<<"Hang "<<" ";
			for(int j=0;j<7;j++){
				cout<<array[i][j]<<" ";
			}
			cout<<endl;
		}
		break;
	}
	//xuat danh sach cho hang tiet kiem
	case 3:{
		string a[7];
		char chu='A';
		for(int i=0;i<7;i++){
			if(i==0){
				a[i]=' ';
			}
			else{
				a[i]=chu++;
			}
		}
		cout<<"      ";
		for(int i=0;i<7;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		for(int i=8;i<14;i++){
			if(i<=9){
				cout<<"Hang "<<" ";
			}
			else{
				cout<<"Hang "<<1;
			}
			for(int j=0;j<7;j++){
				cout<<array[i][j]<<" ";
			}
			cout<<endl;
		}
		break;
	}
	}
}
void danhdau(string array[20][20], int a, int b){
	if(array[a][b] =="*"){
		array[a][b]="X";
	}
	else{
		cout<<"khong hop le hoac da co nguoi dat";
	}
}
void bai11(){
	string array[20][20];
	taosodo(array);
	int ve;
	//kiem tra xem khach hang co muon dat ve tiep khong
	while(true){
		do{
		cout << "Chon loai ve ban muon: \n";
		cout << "0.Xem tat ca cac ghe\n";
		cout << "1.Thuong gia\n";
		cout << "2.Pho thong\n";
		cout << "3.Tiet kiem\n";
		cout << "Chon loai ve ban muon: \n";
		//chon loai ve muon dat
		cin>>ve;
		if(ve>3){
			cout<<"khong hop le moi nhap lai";
		}
		}while(ve>3);
		cout << "X:Cho da dat truoc\n";
		cout << "*:Cho con trong\n";
		//xuat ra danh sach ghe theo loai ve khach hang chon
		xuatsodo(array, ve);
		cout<<"moi nhap vi tri ban muon mua (cot va hang): ";
		char cot;
		int hang;
		cin>>cot>>hang;
		//danh dau ghe ngoi
		//o day con vai truong hop ngoai le chua duoc code
		if(cot>='a' && cot<='z'){
			//ep kieu du lieu char thanh int
			danhdau(array,hang,int(cot)-96);
		}
		else {
			danhdau(array, hang, int(cot)-64);
		}
		//xuat ra danh sach sau ghi da danh dau
		xuatsodo(array,ve);
		cout<<endl;
		cout<<"Nhan 1 de chon ghe tiep hoac nhan 0 de thoat: ";
		int d;
		cin>>d;
		//kiem tra xem khach hang muon dat tiep khong
		if(d==0){
			cout<<"Cam on quy khanh da ung ho :)))";
			break;
		}

	}
}
int main (){
	bai11();
	system("pause");
	return 0;
}