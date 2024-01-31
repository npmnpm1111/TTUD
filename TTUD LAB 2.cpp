#include <iostream>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
// lưu bước di chuyển (lên, xuống, trái phải) để phục vụ cho vòng lặp

int n, m, r, c, bit;
bool marked[1000][1000] = {false}; // mảng đánh dấu
queue<pair<int, int>> q;           // hàng đợi để lưu trữ tọa độ {x,y}
int dist[1000][1000];              // mảng chứa giá trị của tọa độ điểm (0 hoặc 1)

int main()
{
    cin >> n >> m >> r >> c;

    int A[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> A[i][j];
            dist[i][j] = -1;
        }
    } // đọc input

    // bắt đầu BFS
    q.push({r, c});
    dist[r][c] = 1;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && A[nx][ny] == 0 && dist[nx][ny] == -1) // điều kiện biên
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    // tìm số bước nhỏ nhất
    int minDist = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i][1] != -1)
            minDist = min(minDist, dist[i][1]);
        if (dist[i][m] != -1)
            minDist = min(minDist, dist[i][m]);
    }

    for (int j = 1; j <= m; j++)
    {
        if (dist[1][j] != -1)
            minDist = min(minDist, dist[1][j]);
        if (dist[n][j] != -1)
            minDist = min(minDist, dist[n][j]);
    }

    if (minDist == INT_MAX)
    {
        cout << "-1";
    }
    else
    {
        cout << minDist;
    }

    return 0;
}
Sửa code trên hoàn chỉnh để làm bài toán sau:
Một lưới ô vuông nxm,đánh tọa độ từ 1 đến n (hàng ngang), và 1 đến m (dọc).
 Bắt đầu từ ô (1,1) (góc trái trên cùng), ta cần phải đi đến ô (n,m). 
 Mỗi ô có tọa độ (i,j) có một chi phí a_ij. Nếu a_ij = 0 tức là có quái vật, không được đi qua. Nếu a_ij khác 0 thì có thể đi qua nhưng phải trả chi phí là a_ij.
 Ta chỉ có thể đi xuống dưới, sang phải, đường chéo. nghĩa là từ (i,j) chỉ có thể đi sang (i+1,j), (i,j+1), (i+1,j+1) miễn là tọa độ các ô vẫn nằm trong lưới ô vuông. 
 Tìm đường đi có chi phí tối thiểu

 Định dạng input:
 Dòng 1: chứa 2 số n, m là số hàng và cột của lưới.
 Mỗi dòng thứ i trong n dòng tiếp chứa m số nguyên a_ij, j = 1,2,...,m (|a_ij|<=10^9) cách nhau bởi dấu cách thể hiện tính chất của các ô trong dòng i của lưới.
 Dữ liệu input đảm bảo a11 và anm luôn khác 0

 Định dạng output:
 Một ghi nguyên duy nhất là chi phí tối tiểu để đến được điểm anm. Nếu không thể đi, ghi -1.

 Ví dụ
 Input:
 5 6
  1 2 0 5 1 3
  5 -9 2 0 1 3
  1 4 1 5 7 4
  -60 1 0 0 0 0
  6 7 0 5 4 3 

  Output:
  -1
