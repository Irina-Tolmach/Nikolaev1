#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

long long int cnt_sum_s = 0, cnt_mult_s = 0;

void setMatr(int m, int n1, int** a, int n2, int p, int **b) // заполнение матриц случайными числами
{
    srand(time(NULL));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n1; j++)
            a[i][j] = 9 - rand() % 19 ;

    for (int i = 0; i < n2; i++)
        for (int j = 0; j < p; j++)
            b[i][j] = 9 - rand() % 19;
    return;
}

int k_search(int k, int m, int n, int p)
{
    n = max(m, max(n, p));
    if (n % 2 == 1)
        n++;
    bool flag = true;
    for (int i = n; 1; i+=2)
    {
        int j = i;
        while (j > k && j%2==0)
            j /= 2;
        if (j <= k)
            return i;
    }
}

void peredel(int** a1, int** b1, int** a, int** b, int m, int n, int p, int r)
{
 
    for(int i=0; i< r; i++)
        for (int j = 0; j < r; j++)
        {
            if (i < m && j < n)
                a1[i][j] = a[i][j];
            else
                a1[i][j] = 0;
        }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
        {
            if (i < n && j < p)
                b1[i][j] = b[i][j];
            else
                b1[i][j] = 0;
        }
    return;
}

void Mult_Matr(int** a, int** b, int** c, int r)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            for (int k = 0; k < r; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
                cnt_mult_s++;
                if (k > 0)
                    cnt_sum_s++;
            }
    return;
}

void Sum_matr(int** a, int** b, int **c, int r)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++) 
        {
           c[i][j] = a[i][j] + b[i][j];
           cnt_sum_s++;
        }
    return;
}


void Mult_on_Minus(int** a, int r)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            a[i][j] = -a[i][j];
    return;
}

int** Shtrassen(int** a, int** b, int k, int r)
{

    if (r > k)
    {
        int r1 = r / 2;
        int** m1, ** m2, ** m3, ** m4, ** m5, ** m6, ** m7;
        int** vs, ** vs1;
        int** c11, ** c12, ** c21, ** c22;
        c11 = new int* [r1];
        c12 = new int* [r1];
        c21 = new int* [r1];
        c22 = new int* [r1];

        vs = new int* [r1];
        vs1 = new int* [r1]; 

            m1 = new int* [r1];
        m2 = new int* [r1];
        m3 = new int* [r1];
        m4 = new int* [r1];
        m5 = new int* [r1];
        m6 = new int* [r1];
        m7 = new int* [r1];
        for (int i = 0; i < r1; i++)
        {
            m1[i] = new int[r1];
            m2[i] = new int[r1];
            m3[i] = new int[r1];
            m4[i] = new int[r1];
            m5[i] = new int[r1];
            m6[i] = new int[r1];
            m7[i] = new int[r1];

            vs[i] = new int[r1];
            vs1[i] = new int[r1];

            c11[i] = new int[r1];
            c12[i] = new int[r1];
            c21[i] = new int[r1];
            c22[i] = new int[r1];
            for (int j = 0; j < r1; j++)
            {
                m1[i][j] = 0;
                m2[i][j] = 0;
                m3[i][j] = 0;
                m4[i][j] = 0;
                m5[i][j] =0;
                m6[i][j] = 0;
                m7[i][j] =0;

                vs[i][j] = 0;
                vs1[i][j] = 0;

                c11[i][j] = 0;
                c12[i][j] = 0;
                c21[i][j] = 0;
                c22[i][j] = 0;
            }
        }
        
            int** v8, ** v1, ** v2, ** v3, ** v4, ** v5, ** v6, ** v7;
            int** vv, ** vv1;
            v8 = new int* [r1];
            v1 = new int* [r1];
            v2 = new int* [r1];
            v3 = new int* [r1];
            v4 = new int* [r1];
            v5 = new int* [r1];
            v6 = new int* [r1];
            v7 = new int* [r1];

            vv = new int* [r1];
            vv1 = new int* [r1];

            for (int i = 0; i < r1; i++)
            {
                v8[i] = new int[r1];
                v1[i] = new int[r1];
                v2[i] = new int[r1];
                v3[i] = new int[r1];
                v4[i] = new int[r1];
                v5[i] = new int[r1];
                v6[i] = new int[r1];
                v7[i] = new int[r1];

                vv[i] = new int[r1];
                vv1[i] = new int[r1];
            }
            for (int i = 0; i < r1; i++)             // a[1][1]
                for (int j = 0; j < r1; j++)
                {
                    v1[i][j] = a[i][j];
                    v5[i][j] = b[i][j];
                }
            for (int i = r1; i < r; i++)          // a[2][1]
                for (int j = 0; j < r1 ; j++)
                {
                    v2[i - r1][j] = a[i][j];
                    v6[i - r1][j] = b[i][j];
                }
            for (int i = 0; i < r1 ; i++)           // a[1][2]
                for (int j = r1; j < r; j++)
                {
                    v3[i][j - r1] = a[i][j];
                    v7[i][j - r1] = b[i][j];
                }
            for (int i = r1; i < r; i++)              // a[2][2]
                for (int j = r1; j < r; j++)
                {
                    v4[i - r1][j - r1] = a[i][j];
                    v8[i - r1][j - r1] = b[i][j];
                }
      
            Sum_matr(v1, v4, vv, r1); //m1+
            Sum_matr(v5, v8, vv1, r1); //m1+
            m1 = Shtrassen(vv, vv1, k, r1);  //m1
        
            Sum_matr(v2, v4, vv, r1); // m2+
            m2 =Shtrassen(vv, v5, k, r1); //m2
       
            Mult_on_Minus(v8, r1);
            Sum_matr(v7, v8, vv, r1);  //m3-
            m3 = Shtrassen(v1, vv, k, r1); //m3
            Mult_on_Minus(v8, r1);
        
            Mult_on_Minus(v5, r1);
            Sum_matr(v6, v5, vv, r1);  //m4-
            m4 = Shtrassen(v4, vv, k, r1); //m4
            Mult_on_Minus(v5, r1);
   
            Sum_matr(v1, v3, vv, r1);  //m5+
            m5 = Shtrassen(vv, v8, k, r1); //m5

            Mult_on_Minus(v1, r1);
            Sum_matr(v2, v1, vv, r1); // m6-
            Sum_matr(v5, v7, vv1, r1); // m6+
            m6 = Shtrassen(vv, vv1, k, r1); // m6
            Mult_on_Minus(v1, r1);
     
            Mult_on_Minus(v4, r1);
            Sum_matr(v3, v4, vv, r1); //m7-
            Sum_matr(v6, v8, vv1, r1); //m7+
            m7 = Shtrassen(vv, vv1, k, r1); //m7
            Mult_on_Minus(v4, r1);;
            


        Sum_matr(m1, m4, vs, r1);
        Mult_on_Minus(m5, r1);
        Sum_matr(m5, m7, vs1, r1);
        Sum_matr(vs, vs1, c11, r1);
        Mult_on_Minus(m5, r1);

        Sum_matr(m3, m5, c12, r1);

        Sum_matr(m2, m4, c21, r1);

        Mult_on_Minus(m2, r1);
        Sum_matr(m1, m2, vs, r1);
        Sum_matr(m3, m6, vs1, r1);
        Sum_matr(vs, vs1, c22, r1);
        Mult_on_Minus(m2, r1);

        int** c1;
        c1 = new int* [r];
        for (int i = 0; i < r; i++)
            c1[i] = new int[r];
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < r1; j++)
                c1[i][j] = c11[i][j];
        for (int i = r1; i < r; i++)
            for (int j = 0; j < r1; j++)
                c1[i][j] = c21[i - r1][j];
        for (int i = 0; i < r1; i++)
            for (int j = r1; j < r ; j++)
                c1[i][j] = c12[i][j - r1];
        for (int i = r1; i <  r; i++)
            for (int j = r1; j <  r; j++)
                c1[i][j] = c22[i - r1][j - r1];
        
       
        return c1;
    }
    else
    {

        int** a1, ** b1, ** c1;
        a1 = new int* [r];
        b1 = new int* [r];
        c1 = new int* [r];
        for (int i = 0; i < r; i++)
        {
            a1[i] = new int[r];
            b1[i] = new int[r];
            c1[i] = new int[r];
        }
        for(int i = 0; i < r; i++)
            for (int j = 0; j  < r; j++)
            {
                a1[i][j] = a[i][j];
                b1[i][j] = b[i][j];
                c1[i][j] = 0;
            }
       Mult_Matr(a1, b1, c1, r);
       return c1;
    }

}





int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    setlocale(LC_ALL, "Russian");
    int prov, m, n1, n2, p, k, ** a, ** b, ** c;
    cout << "Введите размер матрицы А (m*n) \n";
    {
        prov = scanf_s("%d %d", &m, &n1);
        if (prov == -1 || m <= 0 || n1 <= 0)
        {
            cout << "Введены некорректные данные(не числа или неположиетльные числа)";
            return 0;
        }
    }
    cout << "Введите размер матрицы В n*p\n";
    {
        prov = scanf_s("%d %d", &n2, &p);
        if (prov == -1 || n2 <= 0 || p <= 0)
        {
            cout << "Введены некорректные данные(не числа или неположиетльные числа)";
            return 0;
        }
    }
    if (n1 != n2)
    {
        cout << "Введены некорректные данные (нельзя по определению перемножить матрицы данного размера)";
        return 0;
    }
    cout << "Введите параметр k\n";
    {
        prov = scanf_s("%d", &k);
        if (p == -1 || k <= 0)
        {
            cout << "Введено некорректное значение параметра k";
            return 0;
        }
    }
    int n = n1;
    a = new int* [m];
    b = new int* [n];
    c = new int* [m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        c[i] = new int[p];
    }
    for (int i = 0; i < n; i++)
        b[i] = new int[p];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            c[i][j] = 0;

    int*** cnt; //cnt[i][j].first - счетчик сложения для получения значения ячейки cnt[i][j].second - умножения
    cnt = new int** [m];
    int cnt_mult = 0;
    int cnt_sum = 0;
    for (int i = 0; i < m; i++)
    {
        cnt[i] = new int* [p];
        for (int j = 0; j < p; j++)
        {
            cnt[i][j] = new int[2];
            cnt[i][j][0] = -1;
            cnt[i][j][1] = 0;
        }
    }
    setMatr(m, n, a, n, p, b);
    if (n < 30 && m < 30 && p < 30)
    {
        cout << "\nМатрица А :";
        for (int i = 0; i < m; i++)       // вывод матриц
        {
            cout << endl;
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
        }
        cout << "\n\nМатрица В :";
        for (int i = 0; i < n; i++)
        {
            cout << endl;
            for (int j = 0; j < p; j++)
                cout << b[i][j] << " ";
        }
    }
    else
        cout << "Матрицы слишком велики для комфортного вывода на экран" << endl;


    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n1; k++) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
                cnt[i][j][0]++; // количество операций сложения для получения каждой ячейки матрицы
                cnt[i][j][1]++; // количество операций умножения для получения каждой ячейки матрицы

            }
            cnt_sum += cnt[i][j][0];
            cnt_mult += cnt[i][j][1];
        }

    if (m >= 30 || p >= 30)
        cout << "Матрица С очень велика для комфортного вывода на экран" << endl;
    else
    {
        cout << "\n\nПроизведение матриц по определению :";
        for (int i = 0; i < m; i++)
        {
            cout << endl;
            for (int j = 0; j < p; j++)
                cout << c[i][j] << " ";
        }
    }
    cout << "\nЧисло элементарных операций умножения: " << cnt_mult << endl;
    cout << "\nЧисло элементарных операций сложения: " << cnt_sum << endl;

    int r = k_search(k, m, n, p); // достаиваем до размера r
    //cout << r << endl;
    int** a1, ** b1;
    a1 = new int* [r];
    b1 = new int* [r];
    for (int i = 0; i < r; i++)
    {
        a1[i] = new int[r];
        b1[i] = new int[r];
    }

    peredel(a1, b1, a, b, m, n, p, r); // дозаполняем матрицы нулями до размера r*r

    if (r <= k)
        cout << "Алгоритм Штрассена не отличается от перемножения матриц по определению, т.к. k не меньше размера достроенной матрицы";
        int** c1;
        c1 = Shtrassen(a1, b1, k, r);
        if (m <= 30 && p <= 30) {
            cout << endl << "Произведение матриц по алгоритму Штрассена: " << endl;
            for (int i = 0; i < m; i++)
            {
                cout << endl;
                for (int j = 0; j < p; j++)
                    cout << c1[i][j] << " ";
            }
        }
        else
            cout << "Матрица С очень велика для комфортного вывода на экран" << endl;
        cout << "\nЧисло элементарных операций умножения: " << cnt_mult_s << endl;
        cout << "\nЧисло элементарных операций сложения: " << cnt_sum_s << endl;
}

