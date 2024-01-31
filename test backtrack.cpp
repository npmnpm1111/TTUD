#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n;
int x[maxn];

void print_sol(int A[maxn])
{
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
bool isUsed(int val, int k)
{
    for (int i = 1; i < k; i++)
    {
        if (x[i] == val)
            return true;
    }
    return false;
}

void Try(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (!isUsed(i, k))
        {
            x[k] = i;
            if (k == n)
                print_sol(x);
            else
                Try(k + 1);
        }
    }
}

int main()
{
    x[0] = 0;
    cin >> n;
    Try(1);
    return 0;
}

Một đội K xe giống nhau có khả năng vận chuyển Q cần được lên lịch để giao các gói hàng từ kho trung tâm ở vị trí 0 cho n khách hàng 1, 2, ..., n ở vị trí 1, 2, ..., n. Mỗi khách yêu cầu d[i] gói. 
Khoảng cách từ vị trí i đến j là c[i,j], 0<=i, j<=n. Do một số ràng buộc về nghiệp vụ, có một danh sách F gồm các cặp khách hàng ở vị trí (i,j) không thể được phục vụ bởi
cùng một xe tải trên cùng một hành trình. Giải pháp là một tập các tuyến đường : mỗi xe tải được phân cho một tuyến đường, bắt đầu từ kho, đến thăm một số khách hàng để giao các gói hàng
và quay lại kho. Mỗi xe chỉ thực hiện một hành trình duy nhất như vậy. Giải pháp giao hàng phải thỏa mãn:
Mỗi khách được thăm và giao bởi đúng 1 tuyến đường của 1 xe nào đó
Tổng số kiện hàng khách yêu cầu của mỗi xe không vượt quá khả năng vận chuyển Q của xe.
Nếu (i,j) thuộc F thì khách ở vị trí i và j phải được các xe tải khác nhau ghé thăm và giao hàng. 
Lưu ý:
có thể xảy ra trường hợp xe không ghe thăm khách nào (tuyến rỗng)
thứ tự của khách trong 1 tuyến rất quan trọng, ví dụ: các tuyến 0->1->2->3->0 và 0->3->2->1->0 là khác nhau

Input: 
dòng 1: n, K, Q(2<n<12, 1<K<K, 1<Q<50)
Dòng 2: d[1], ..., d[n] (1<d[i]<10)
Dòng i+3 (i=0, ...n): dòng thứ i của ma trận khoảng cách c(1<c[i,j]<30)
Dòng n +4: chứa số nguyên M là số cặp của danh sách F (0<=M<=n(n-1)/2)
Dòng m + n + 4 (m=1, ... M) chứa 2 số nguyên dương i và j (i,j) là cặp thứ m của danh sách F.

Kết quả: tổng quảng đường di chuyển tối thiểu hoặc -1 nếu bài toán ko có lời giải

Ví dụ:
Input:
3 2 7
3 2 3 
0 2 3 1
4 0 1 3
2 3 0 4
3 2 4 0
1 
1 2

Output:
13