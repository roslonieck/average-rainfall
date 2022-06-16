#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std; 

const int miesiace = 12;
const int czas = 5;

double wylosuj(double tab[czas][miesiace]){
    for (int i = 0; i < czas; i++)
    {
        for (int j = 0; j < miesiace; j++)
        {
            tab[i][j] = (double)-rand()/(RAND_MAX/(0.0-10.0));
        }   
    }
    return tab[czas][miesiace];
}

void narysujTablice(double tab[czas][miesiace]){
    cout << "lata";
    for (int i = 0; i < miesiace; i++)
    {
        cout << setw(5) << i + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < czas; i++)
    {
        cout << i + 2016 << " ";
        for (int j = 0; j < miesiace; j++)
        {
            cout << setw(5) << setprecision(3) << tab[i][j] << " ";
        }
        cout << endl;
    }
}

void wyznaczStatystyki(double tab[czas][miesiace]){
    for (int i = 0; i < czas; i++)
    {   
        double roczneOpady = 0;
        for (int j = 0; j < miesiace; j++)
        {
            roczneOpady = roczneOpady + tab[i][j];
        }
        cout << "Roczna ilosc opadow w " << 2016 + i << " wynosi " << roczneOpady << endl;
        cout << "Srednia ilosc opadow w " << 2016 + i << " wynosi " << roczneOpady/miesiace << endl;
        cout << endl; 
    }    
}

void wyliczMiesiace(double tab[czas][miesiace]){
    for (int i = 0; i < miesiace; i++)
    {   
        double miesieczna = 0;
        for (int j = 0; j < czas; j++)
        {
            miesieczna = miesieczna + tab[j][i];
        }
        cout << "Laczna ilosc opadow w miesiacu " << i + 1 << " wynosi " << miesieczna << endl;
        cout << "Srednia ilosc opadow w miesiacu " << i + 1 << " wynosi " << miesieczna/czas << endl;
        cout << endl; 
    }
}

void znajdzNajwieksze(double tab[czas][miesiace]){
    double najwieksze = 0;
    int kiedy;
    int rok;
    for (int i = 0; i < czas; i++)
    {
        for (int j = 0; j < miesiace; j++)
        {
            if (tab[i][j] > najwieksze)
            {
                najwieksze = tab[i][j];
                kiedy = j;
                rok = i;
            }
        }
    }
    cout << "Najwieksze opady wynosily: " << najwieksze << " i byly w " << kiedy + 1 << " " << rok + 2016 << endl;  
}
    

int main(){

    srand(time(NULL));
    double tabWarszawa[czas][miesiace];
    double tabSztokholm[czas][miesiace];
    wylosuj(tabWarszawa);
    cout << "Dane statystyczne dla Warszawy: " << endl;
    narysujTablice(tabWarszawa);
    wyznaczStatystyki(tabWarszawa);
    wyliczMiesiace(tabWarszawa);
    znajdzNajwieksze(tabWarszawa);
    cout << endl;
    wylosuj(tabSztokholm);
    cout << "\nDane statystyczne dla Sztokholmu: " << endl;
    narysujTablice(tabSztokholm);
    wyznaczStatystyki(tabSztokholm);
    wyliczMiesiace(tabSztokholm);
    znajdzNajwieksze(tabSztokholm);
    return 0;
}
