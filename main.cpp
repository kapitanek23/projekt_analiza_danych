#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

// Funkcja do zapisywania czasu operacji i rozmiaru tablicy do pliku txt
void zapiszDoPliku(int liczbaWierszy, int liczbaKolumn, int czasOperacji)
{
    ofstream plik("wyniki_operacji.txt", ios::app); // Utwórz lub otwórz plik do zapisu (tryb append)
    if (plik.is_open())
    {
        plik << liczbaWierszy <<"x"<< liczbaKolumn << "," << czasOperacji << endl;
        plik.close();
    }
    else
    {
        cout << "Błąd podczas otwierania pliku!" << endl;
    }
}

int main() {
    // Wprowadzanie liczby wierszy i kolumn
    int liczbaWierszy, liczbaKolumn;
    cout << "Podaj liczbe wierszy: ";
    cin >> liczbaWierszy;
    cout << "Podaj liczbe kolumn: ";
    cin >> liczbaKolumn;

    // Tworzenie dwuwymiarowej tablicy dynamicznej
    int** tablica2D = new int*[liczbaWierszy];
    for (int i = 0; i < liczbaWierszy; i++) {
        tablica2D[i] = new int[liczbaKolumn];
    }

    // Wybór opcji wypełnienia tablicy
    cout << "Wybierz opcje wypelnienia tablicy:" << endl;
    cout << "1. Wprowadzanie reczne" << endl;
    cout << "2. Wypelnij losowo z zakresu 0-9" << endl;
    int opcja;
    cin >> opcja;

    if (opcja == 1) {
        // Wprowadzanie zawartości tablicy
        cout << "Wprowadz zawartosc tablicy:" << endl;
        for (int wiersz = 0; wiersz < liczbaWierszy; wiersz++) {
            for (int kolumna = 0; kolumna < liczbaKolumn; kolumna++) {
                cout << "Wprowadz element w wierszu " << wiersz + 1 << " i kolumnie " << kolumna + 1 << ": ";
                cin >> tablica2D[wiersz][kolumna];
            }
        }
    } else if (opcja == 2) {
        // Wprowadzanie losowych wartosci tablicy
        srand(time(NULL));
        for (int wiersz = 0; wiersz < liczbaWierszy; wiersz++) {
            for (int kolumna = 0; kolumna < liczbaKolumn; kolumna++) {
                tablica2D[wiersz][kolumna] = rand() % 10;
                //cout<< tablica2D[wiersz][kolumna]<<" "<<endl;
            }
        }
    } else {
        cout << "Nieprawidlowa opcja. Program zostanie zakonczony." << endl;
        return 1;
    }

    // Rozpocznij pomiar czasu
    auto start = high_resolution_clock::now();

      // Inicjalizacja tablicy do przechowywania wyst�pie� element�w
    int wystapienia[100] = {0};  // Przyjmujemy, �e elementy s� liczbami ca�kowitymi od 1 do 100

    // Przeszukiwanie pierwszego wiersza i inicjalizacja wyst�pie�
    for (int kolumna = 0; kolumna < liczbaKolumn; kolumna++) {
        int element = tablica2D[0][kolumna];
        wystapienia[element]++;
    }

    // Przeszukiwanie pozosta�ych wierszy
    for (int wiersz = 0; wiersz < liczbaWierszy; wiersz++) {
        for (int kolumna = 0; kolumna < liczbaKolumn; kolumna++) {
            int element = tablica2D[wiersz][kolumna];
            if (wystapienia[element] == wiersz) {
                wystapienia[element]++;
            }
        }
    }
    // Zakończ pomiar czasu
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    // Wy�wietlamy wsp�lne elementy
    cout << "Wspolne elementy we wszystkich wierszach:";
    for (int element = 1; element <= 100; element++) {
        if (wystapienia[element] == liczbaWierszy) {
            cout << " " << element;
        }
    }
    cout << endl;
     cout << "Czas operacji: " << duration.count() << " ms" << endl;
    // Zapisz do pliku
    zapiszDoPliku(liczbaWierszy, liczbaKolumn , duration.count());
    return 0;
}
