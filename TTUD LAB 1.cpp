
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int time_to_seconds(const string &time)
{
    int h, m, s;
    sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
} // hàm chuyển đổi thời gian thành giây
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int total = 0;
    string line;

    unordered_map<string, int> countphone1, counttime; // sử dụng cấu trúc dữ liệu dạng <key, value> để lưu trữ data dạng <phone, count>

    bool yes = true; // biến trạng thái của "định dạng phone có hợp lệ hay không"

    // xử lý data ngay khi đọc
    while (getline(cin, line) && line != "#")
    {
        total++;
        size_t pos = line.find(' ');
        size_t pos1 = line.find(' ', pos + 1);
        size_t pos2 = line.find(' ', pos1 + 1);
        size_t pos3 = line.find(' ', pos2 + 1);
        size_t pos4 = line.find(' ', pos3 + 1);
        // xác định vị trí tất cả dấu ' '

        string phone1 = line.substr(pos + 1, pos1 - pos - 1);
        string start_time = line.substr(pos3 + 1, pos4 - pos3 - 1);
        string end_time = line.substr(pos4 + 1);
        // tách từng thông tin (là các chuỗi giữa 2 dấu cách ' ')

        countphone1[phone1]++;                                                        // tính số lượng phone1
        counttime[phone1] += time_to_seconds(end_time) - time_to_seconds(start_time); // tính tổng time phone1

        if (((pos1 - pos - 1) != 10) || (pos2 - pos1 - 1 != 10)) // check phone1 và phone2 có hợp lệ (đúng định dạng 10 số) hay không?
            yes = false;
    }

    // chỉ in ra output vì đã xử lý trước đó:
    while (getline(cin, line) && line != "#")
    {
        size_t pos = line.find(' ');
        string cmd = line.substr(0, pos);
        if (cmd == "?number_total_calls")
        {
            cout << total << endl;
        }
        else if (cmd == "?number_calls_from")
        {
            string target_phone = line.substr(pos + 1);
            // cout << target_phone << endl;
            cout << countphone1[target_phone] << endl;
        }
        else if (cmd == "?check_phone_number")
        {
            if (yes)
            {
                cout << "1" << endl;
            }
            else
                cout << "0" << endl;
        }
        else if (cmd == "?count_time_calls_from")
        {
            string target_phone = line.substr(pos + 1);
            cout << counttime[target_phone] << endl;
        }
    }
    return 0;
}
