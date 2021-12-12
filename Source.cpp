#include <iostream>
#include <fstream>
using namespace std;

/*void input_array(int* mas, int n, ifstream& in) {
    for (int i = 0; i < n; i++)
    {
        in >> mas[i];
    }
}
bool check(int* mas, int n) {
    int d = mas[1] - mas[0];
    bool k = true;
    for (int i = 1; i < n - 1; i++) {
        if (mas[i + 1] - mas[i] != d) {
            k = false;
            break;
        }
    }
    return k;
}

int main()
{
    setlocale(LC_ALL, "russian");
    ifstream fin;
    string input_file_name;
    cout << "Введите имя входного файла\n";
    //string input_file_name = "1.txt";
    cin >> input_file_name;
    fin.open(input_file_name);
    ofstream fout("2.txt");
    if (fin) {
        int n;
        std::cout << "Ведите колво элементов";
        std::cin >> n;
        int* mas = new int[n];
        
        //ввод массива
        input_array(mas, n, fin);
        //проверка массива
       
        if (check(mas,n)) fout << "YES\n";
        else fout << "NO\n";
    }

    else {
        cout << "error open input file\n";
        return 1;
    }




}*/
void input_matrix(int** mas, int n, ifstream& in) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            in >> mas[i][j];
        }
    }
}
int min_row(int** mas, int n, int row_number) {
    int min = mas[row_number][0];
    int pos = 0;
    for (int j = 0; j < n; j++) {
        if (mas[row_number][j] < min) {
            min = mas[row_number][j];
            pos = j;
        }
    }
    return pos;
}
int max_col(int** mas, int n, int col_number) {
    int max = mas[0][col_number];
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i][col_number] > max) {
            max = mas[i][col_number];
            pos = i;
        }
    }
    return pos;
}


int main()
{
    setlocale(LC_ALL, "russian");
    ifstream fin;
    //string input_file_name;
    //cout << "Введите имя входного файла\n";
    string input_file_name = "1.txt";
    //cin >> input_file_name;
    fin.open(input_file_name);
    ofstream fout("2.txt");
    if (fin) {
        int n;
        std::cout << "Ведите размер квадратной матрицы n";
        std::cin >> n;
        int** mas = new int* [n];
        for (int i = 0; i < n; i++) {
            mas[i] = new int[n];
        }

        //ввод массива
        input_matrix(mas, n, fin);
        //поиск узловой точки
        bool s = false;
        for (int k = 0; k < n; k++) {
            int x = min_row(mas, n, k);
            int y = max_col(mas, n, min_row(mas, n, k));
            if (k == y) {
                fout << "Седловая точка [" << y << "]" << "[" << x << "]"  << endl;
                s = true;
            }
        }
        if (!s) fout << "Седловых точек нет" << endl;

    }

    else {
        cout << "error open input file\n";
        return 1;
    }
}