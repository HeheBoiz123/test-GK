#include<iostream>
using namespace std;
//bai 1a: 1+2+3+..+n
int SumNumber(int n){
    if(n ==1){
        return 1;
    }
    return n+SumNumber(n-1);
}
//bai 1b: 1^2 +2^2+3^2+..n^2
int SquareNumber(int n){
    if(n==1){
        return 1;
    }
    return n*n + SquareNumber(n-1);
}
//bai1c: 1+1/3+1/3+1/5+..+1/n
double tinhDayHarmonic(int n){
    if(n<1){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n %2==0){
        return tinhDayHarmonic(n-1);
    }
    else{
        return (1.0/n) +tinhDayHarmonic(n-2);
    }
}
//bai 1d: tinh tong giai thua
//tinh giai thua cua tung so
int factorial(int n){
    if(n<0){
        //tra ve tru 1 de bieu thi loi 
        return -1;
    }
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}
//tinh tong giai thua 
int Sumfactorial(int n){
    if(n==0 || n<1){
        return 0;
    }
    return factorial(n)+ Sumfactorial(n-1);
}
//bai 2:
int Factorial(int n){
    if(n<0){
        //tra ra -1 de biet bi loi
        return -1;
    }
    if(n==0){
        return 1;
    }
    return n*Factorial(n -1);
}
//bai 3:
int fibonacci(int n){
    if(n ==1 || n==0){
        return n;
    }
    return fibonacci(n-1)+ fibonacci(n-2);
}
//bai 4:
int pow(int a, int b){
    if(b==0){
        return 1;
    }
    if(a<0 || b<0){
        return -1;
    }
    return a*pow(a,b-1);
}  
//bai 5:
int countNumber(int n){
    if(n==0){
        return 0;
    }
    return 1 + countNumber(n/10);
}
//bai 6:     
int reversenumber(int n, int a){
    //a la bien luu tru so dao nguoc va lan dau co gia tri la: 0
    if(n==0){
        return a;
    }
    if(n<0){
        return -1;
    }
    return reversenumber(n/10, a=a*10+n%10);
}
//bai 7: tinh chan/le cua 1 den n
int sum_Odd_even(int n){
    if(n<=0){
        return 0;
    }
    return n+sum_Odd_even(n-2);
}
//bai 8: chuyen he thap phan sang nhi phan 
//cach 1: chi co the duoc voi so le
int binary_Ten(int n, int a){
    if(n==0){
        return reversenumber(a,0);
    }
    return binary_Ten(n/2,a=a*10+n%2);
}
//cach 2
int Decimal(int n) {
  if (n == 0) {
    return 0;
  } else {
    return (n % 2) + 10 * Decimal(n / 2);
  }
}
//cach 3: cua kha bang cach xem so do la chan hay le (chan: 0, le: 1)
int binary_Khacach1(int n,int array[], int &k){
    if(n==0){
        return 0;
    }
    int m=n;
    n=n/2;
    if(m==n*2){
        array[k]=0;
    }
    else{
        array[k]=1;
    }
    k++;
    return binary_Khacach1(n,array,k);
}
//cach 4: cung la cach cua Kha ma khong co bien m
int binary_Khacach2(int n,int array[], int &k){
    if(n==0){
        return 0;
    }
    if(n%2==0){
        array[k]=0;
    }
    else{
        array[k]=1;
    }
    k++;
    n=n/2;
    return binary_Khacach2(n,array,k);
}
//bai 9: chuyen he nhi phan sang he thap phan
//cach 1: cua Kha dung mang
int binaryToDecimal(int array[], int k){
    if(k==-1){
        return 0;
    }
    int m = pow(2*array[k],k);
    k--;
    return m+ binaryToDecimal(array,k);
}
// cach 2: khong dung mang
int binary_Decimal(int n, int k){
    if(n==0){
        return 0;
    }
    // su dung k++ no se tra ve so hien tai roi moi +1 co nghia o day no se chi mai dua vao 0 ma thoi
    //++k: se +1 truoc khi dua tham so vao
    return (n%10*pow(2,k)) + binary_Decimal(n/10,++k);
}
//bai 10: tim ucln 
//cach 1: bang thuat giai Euclid
int Greatest_Common_Divisor(int a, int b){
    if(b==0){
        return a;
    }
    else{
        int d=a%b;
        return Greatest_Common_Divisor(b,d);
    }
}
// cach 2: khong dung thuat giai
//c==(a < b) ? a:b
int gcd(int a, int b, int c){
    if(a %c==0 && b % c==0){
        return c;
    }
    else{
        return gcd(a,b,c-1);
    }
}
//bai 11:
int SumArray(int array[], int n){
    if(n ==0){
        return 0;
    }
    return array[n-1]+SumArray(array, n-1);
}
//bai 12:
//cach 1:
int minArray(int arr[], int n, int m){
    if(n==0){
        return m;
    }
    if(m>arr[n-1]){
        m=arr[n-1];
    }
    return minArray(arr,n-1,m);
}
//cach 2:
int minValue(int arr[], int n) {
    //1 o day la 1 phan tu trong mang   
    if (n == 1){
        return arr[0];
    }
    else {
        int min = minValue(arr, n - 1);
        if (arr[n - 1] < min){
            return arr[n - 1];
        }
        else{
            return min;
        }
    }
}
//bai 13:
int tohop(int n, int k){
    return factorial(n) /(factorial(k)*factorial(n-k));   
}
//in ra hang cua tam giac 
void pascal_row(int n, int index){
    if(index>n){
        return;
    }
    cout<<tohop(n, index)<<" ";
    pascal_row(n, index +1);
}
void pascal_draw(int n, int index){
    if(index==n){
        return;
    }
    pascal_row(index,0);
    cout<<endl;
    return pascal_draw(n, index+1);
}
//de quy ho tuong:
bool isOdd(int n);
bool isEven(int n){
    if(n==0){
        return true;
    }
    else{
        return isOdd(n-1);
    }
}
bool isOdd(int n){
    return !isEven(n);
}
//de quy nhi phan: 
int nhiphantohop(int n, int k){
    if(n<k){
        return -1;
    }
    if(k==0 || k==n){
        return 1;
    }
    else{
        //kCn = kC(n-1)+ (k-1)C(n-1)
        return nhiphantohop(n-1,k)+nhiphantohop(n-1,k-1);
    }
}
//de quy duoi
int giaithua(int n, int result =1){
    if(n==0){
        return result;
    }
    else{
        return giaithua(n-1,n*result);
    }
}
int main() {
    //bai 1:
    //a
    cout<<"tong tu 1 den 3 la: "<<SumNumber(3)<<endl;;
    //b:
    cout<<"binh phuong tu 1 den 2 la: "<<SquareNumber(2)<<endl;
    //c: 
    cout<<"1 phan le tu 1 den 10 la: "<<tinhDayHarmonic(10)<<endl;
    //d:
    cout<<"tong gia thua tu 1 den 5 la: "<<Sumfactorial(5)<<endl;
    //bai 2:
    cout<<"giai thua cua 4 la: "<<Factorial(4)<<endl;
    //bai 3:
    cout<<"day so fibonacci cua 5 la"<<fibonacci(5)<<endl;
    //bai 4:
    cout<<"luy thu 3 cua 2 la: "<<pow(2,3)<<endl;
    //bai 5:
    cout<<"tong chu so cua 3234 la: "<<countNumber(3234)<<endl;
    //bai 6:
    cout<<"dao nguoc so cua so 123 la: "<<reversenumber(123,0)<<endl;
    //bai 7: chua ro de bai
    cout<<"tong chan hoac le cua so 7 la: "<<sum_Odd_even(7)<<endl;
    //bai 8: co 4 cach
    cout<<"chuyen he thap phan sang he nhi phan cua 13 la: "<<Decimal(13)<<endl;
    //bai 9: co 2 cach
    cout<<"chuyen tu he nhi phan sang he thap phan cua 1101: "<<binary_Decimal(1101,0)<<endl;
    //bai 10: co 2 cach
    cout<<"Uoc chung lon nhat cua 18 va 48 la: "<<Greatest_Common_Divisor(18,48)<<endl;
    //bai 11:
    int arr[] = {0, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Sum array is: "<<SumArray(arr,n)<<endl;
    //bai 12: co 2 cach
    cout<<"so nho nhat trong mang la: "<<minArray(arr,n,arr[0])<<endl;
    //bai 13;
    cout<<"tam giac pascal voi n =7"<<endl;
    pascal_draw(7,0);
    //bai ben ngoai
    //de quy ho tuong:
    cout << 6 << " la so " << (isEven(n) ? "chan" : "le") << endl;
    //de quy nhi phan:  
    cout<<"to hop 8C3: "<<nhiphantohop(8,3)<<endl;
    //de quy duoi
    cout<<"giai thua cua 5 la: "<<giaithua(5)<<endl;
    return 0;
}
