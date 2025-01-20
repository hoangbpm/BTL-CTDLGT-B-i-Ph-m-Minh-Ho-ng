
#include <iostream>
#include <cstring> // Để sử dụng memset

using namespace std;

// Lớp đồ thị
class DoThi
{
public:
    // Ma trận kề biểu diễn đồ thị
    int danhSachKe[100][100];
    // Số đỉnh trong đồ thị
    int soDinh;

    // Hàm khởi tạo đồ thị
    DoThi(int n)
    {
        soDinh = n;
        // Khởi tạo ma trận kề với giá trị 0
        memset(danhSachKe, 0, sizeof(danhSachKe));
    }

    // Thêm cạnh vào đồ thị
    void themCanh(int u, int v)
    {
        danhSachKe[u][v] = 1;
    }
};

// Hàm kiểm tra đường đi từ đỉnh `batDau` đến `ketThuc`
bool coDuongDi(DoThi &doThi, int batDau, int ketThuc)
{
    // Mảng đánh dấu các đỉnh đã thăm
    bool daTham[100];
    memset(daTham, false, sizeof(daTham));

    // Ngăn xếp để thực hiện duyệt DFS
    int nganXep[100], top = -1;

    // Đưa đỉnh bắt đầu vào ngăn xếp
    nganXep[++top] = batDau;

    // Duyệt DFS
    while (top >= 0)
    {
        // Lấy đỉnh hiện tại từ ngăn xếp
        int dinhHienTai = nganXep[top--];

        // Nếu đỉnh hiện tại là đích, trả về true
        if (dinhHienTai == ketThuc)
            return true;

        // Đánh dấu đỉnh hiện tại đã thăm
        daTham[dinhHienTai] = true;

        // Duyệt qua tất cả các đỉnh kề
        for (int dinhKe = 0; dinhKe < doThi.soDinh; ++dinhKe)
        {
            if (doThi.danhSachKe[dinhHienTai][dinhKe] == 1 && !daTham[dinhKe])
            {
                // Thêm đỉnh kề vào ngăn xếp
                nganXep[++top] = dinhKe;
            }
        }
    }

    // Không tìm thấy đường đi
    return false;
}

// Hàm kiểm tra 2 test case
int main()
{
    // Đồ thị với 6 đỉnh
    DoThi doThi(6);

    // Thêm các cạnh vào đồ thị
    doThi.themCanh(0, 1);
    doThi.themCanh(1, 2);
    doThi.themCanh(2, 3);
    doThi.themCanh(3, 5);
    doThi.themCanh(4, 1);

    // Test case 1
    int batDau1 = 4, ketThuc1 = 5;
    if (coDuongDi(doThi, batDau1, ketThuc1))
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    // Test case 2
    int batDau2 = 5, ketThuc2 = 1;
    if (coDuongDi(doThi, batDau2, ketThuc2))
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    return 0;
}
