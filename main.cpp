#include<iostream>

using namespace std;

const int maxSize = 10;

int table[maxSize][maxSize] = {0};
int temp[maxSize];

void merge(int size);

void createTable(int size) {
    if (size == 1) {
        table[1][1] = 1;
        return;
    }
    if (size % 2 == 1) {
        createTable(size + 1);
        return;
    }
    createTable(size / 2);
    merge(size);
}

void merge(int size) {
    if ((size /2) == 1 || (size/2) % 2 == 0) {
        int mid = size / 2;
        for (int i = 1; i <= mid; i++)
            for (int j = 1; j <= mid; j++) {
                table[i][j+mid] = table[i][j] + mid;
                table[i+mid][j] = table[i][j+mid];
                table[i+mid][j+mid] = table[i][j];
            }
    } else {
        int mid = size / 2;

        for (int i = 1; i <= mid; i++) {
            temp[mid + i] = temp[i] = mid + i;
        }

        for (int i = 1; i <= mid; i++) {
            //left bottom
            for (int j = 1; j <= mid+1; j++) {
                if (table[i][j] > mid) {
                    table[i][j] = temp[i];
                    table[mid+i][j] = (temp[i] + mid) % size;
                } else {
                     table[mid+i][j] = table[i][j] + mid;
                };
            }
            //right top/bottom
            for (int j = 2; j <= mid; j++) {
                table[i][mid+j] = temp[i+j-1];
                table[temp[i+j-1]][mid+j] = i;
            }
        }

    }
}

void print(int size) {
    for (int i = 1; i<= size; i++) {
        for (int j = 1; j <= size; j++)
            cout << table[i][j] << " ";
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    createTable(n);
    if (n % 2 == 1) n = n+1;
    print(n);
    return 0;
}