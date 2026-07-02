#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void xuatMang(const vector<int>& a)
{
    for (int x : a)
        cout << setw(4) << x;

    cout << endl;
}

void vunDong(vector<int>& a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    cout << "\nvundong nut i = " << i << endl;

    if (left < n)
        cout << "Con trai  a[" << left << "] = "
             << a[left] << endl;

    if (right < n)
        cout << "Con phai  a[" << right << "] = "
             << a[right] << endl;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        cout << "Doi "
             << a[i]
             << " va "
             << a[largest]
             << endl;

        swap(a[i], a[largest]);

        cout << "Trang thai hien tai:\n";
        xuatMang(a);

        vunDong(a, n, largest);
    }
    else
    {
        cout << "Khong can doi\n";

        cout << "Trang thai hien tai:\n";
        xuayMang(a);
    }
}

void sapXepVunDong(vector<int>& a)
{
    int n = a.size();

    cout << "\n========================\n";
    cout << "      VUN DONG\n";
    cout << "========================\n";

    // Build Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        cout << "\n--- vundong tai i = "
             << i
             << " ---\n";

        vunDong(a, n, i);

        cout << "Sau vundong i = "
             << i
             << ":\n";

        printArray(a);
    }

    cout << "\n========================\n";
    cout << "      SAP XEP\n";
    cout << "========================\n";

    // Heap Sort
    for (int i = n - 1; i > 0; i--)
    {
        cout << "\nDua max "
             << a[0]
             << " xuong cuoi\n";

        swap(a[0], a[i]);

        cout << "Sau khi doi:\n";
        xuatMang(a);

        cout << "\nVun lai heap:\n";

        vunDong(a, i, 0);

        cout << "Mang sau khi vun lai:\n";
        xuatMang(a);
    }
}

int main()
{
    int n;

    cout << "Nhap so phan tu: ";
    cin >> n;

    vector<int> a(n);

    cout << "Nhap day so:\n";

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nMang ban dau:\n";
    xuatMang(a);

    sapXepVunDong(a);

    cout << "\n========================\n";
    cout << "Mang sau khi sap xep:\n";
    xuatMang(a);

    return 0;
}
