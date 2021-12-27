#include <iostream>
#include <windows.h>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <vector>

using namespace std;

struct ksiazkaAdresowa
{
    int ID;
    string imie, nazwisko, nrTelefonu, email, adres;
};

vector <ksiazkaAdresowa> kontakty;

void zapisDoPlikuTekstowego( ksiazkaAdresowa adresat,int iloscKontaktow )
{
    fstream plik;
    plik.open("KsiazkaAdresowaKS.txt", ios::out | ios::app);
    plik<<adresat.ID<< "|";                                                           //ZAPIS
    plik<<adresat.imie<< "|";
    plik<<adresat.nazwisko<< "|";
    plik<<adresat.nrTelefonu<< "|";
    plik<<adresat.email<< "|";
    plik<<adresat.adres<< "|" << endl;
    plik.close();
}

int odczytZPlikuDoProgramu( int iloscKontaktow )                                        //ODCZYT
{
    fstream plik;
    string linia;
    ksiazkaAdresowa adresat;

    if(plik.good() == true)
    {
        plik.open("KsiazkaAdresowaKS.txt", ios::in);
        while(getline(plik,linia))
        {
            string imie = "", nazwisko = "", nrTelefonu = "", email = "", adres = "", ID = "";
            int pozycjaLitery = 0;

            while( linia[ pozycjaLitery ] != '|')
            {
                ID = ID + linia[ pozycjaLitery ];
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                imie = imie +  linia[ pozycjaLitery ];
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                nazwisko = nazwisko +  linia[ pozycjaLitery ];
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                nrTelefonu = nrTelefonu +  linia[ pozycjaLitery ];
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                email = email +  linia[ pozycjaLitery ];
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                adres = adres +  linia[ pozycjaLitery ];
                pozycjaLitery++;
            }
            adresat.ID = atoi(ID.c_str());
            adresat.imie = imie;
            adresat.nazwisko = nazwisko;
            adresat.nrTelefonu = nrTelefonu;
            adresat.email = email;
            adresat.adres = adres;
            kontakty.push_back( adresat );
            iloscKontaktow++;
        }
        plik.close();
        return iloscKontaktow;
    }
}

void zastapDaneWPlikuTekstowym()                                                          //ZASTAP ZAPIS
{
    ksiazkaAdresowa adresat;
    fstream plik2;
    plik2.open("KsiazkaAdresowaPrzechowanieDanych.txt", ios::out);

    for( int i = 0; i < kontakty.size(); i++ )
    {
        adresat = kontakty[i];
        plik2<<adresat.ID<< "|";
        plik2<<adresat.imie<< "|";
        plik2<<adresat.nazwisko<< "|";
        plik2<<adresat.nrTelefonu<< "|";
        plik2<<adresat.email<< "|";
        plik2<<adresat.adres<< "|" << endl;
    }

    plik2.close();
    remove("KsiazkaAdresowaKS.txt");
    rename("KsiazkaAdresowaPrzechowanieDanych.txt", "KsiazkaAdresowaKS.txt");
}

int dodajOsobe( int iloscKontaktow )
{
    ksiazkaAdresowa adresat;
    string imie, nazwisko, nrTelefonu, email, adres;
    int dlugoscWektora = kontakty.size();

    system("cls");
    cout << "Podaj imie dodawanej osoby: ";
    cin >> imie;
    cout << "Podaj nazwisko dodawanej osoby: ";
    cin >> nazwisko;
    cout << "Podaj numer telefonu dodawanej osoby: ";
    cin.sync();
    getline(cin, nrTelefonu);

    for(int i=0; i<iloscKontaktow; i++)
    {
        if(kontakty[i].nrTelefonu == nrTelefonu )
        {
            cout << "Podany numer jest juz przypisany do innego kontaktu, prosze wprowadzic poprawny numer telefonu: ";
            cin.sync();
            getline(cin, nrTelefonu);
            i = -1;
        }
    }
    cout << "Podaj adres e-mail dodawanej osoby: ";
    cin >> email;

    for(int i=0; i<iloscKontaktow; i++)
    {
        if( kontakty[i].email == email )
        {
            cout << "Podany email jest juz przypisany do innego adresata, prosze wprowadzic poprawny adres email: ";
            cin >> email;
            i = -1;
        }
    }
    cout << "Podaj adres osoby dodawanej: ";
    cin.sync();
    getline(cin, adres);

    adresat.imie = imie;
    adresat.nazwisko = nazwisko;
    adresat.nrTelefonu = nrTelefonu;
    adresat.email = email;
    adresat.adres = adres;

    if( iloscKontaktow == 0 )
    {
        adresat.ID = 1;
    }
    else if ( iloscKontaktow > 0 )
    {
        adresat.ID = kontakty[ dlugoscWektora - 1 ].ID + 1;
    }

    kontakty.push_back( adresat );

    cout << endl;
    cout << "Pomyslnie dodano osobe do ksiazki adresowej!" << endl;
    Sleep(2500);

    zapisDoPlikuTekstowego( adresat, iloscKontaktow);

    return iloscKontaktow+1;
}

void wyszukajPoImieniu( int iloscKontaktow )
{
    string imie;
    int numerPozycji = 0;

    system("cls");
    cout << "Wprowadz wyszukiwane imie: ";
    cin >> imie;
    cout << endl;

    for (int i = 0; i < iloscKontaktow; i++)
    {
        if(kontakty[i].imie == imie)
        {
            cout << numerPozycji+1 << ". " << endl;
            cout << "Numer ID: " << kontakty[i].ID << endl;
            cout << "Imie: " << kontakty[i].imie <<endl;
            cout << "Nazwisko: " << kontakty[i].nazwisko << endl;
            cout <<"Numer telefonu: " << kontakty[i].nrTelefonu << endl;
            cout << "Adres e-mail: " << kontakty[i].email << endl;
            cout << "Adres zamieszkania: " << kontakty[i].adres << endl;
            cout << endl;
            numerPozycji++;
        }
    }

    if(numerPozycji == 0)
    {
        cout << "Brak kontaktow o podanym imieniu" << endl;
    }
    cout <<"Aby przejsc dalej wcisnij dowolny klawisz" << endl;
    getchar();
    getchar();
}

void wyszukajPoNazwisku( int iloscKontaktow )
{
    string nazwisko;
    int numerPozycji = 0;

    system("cls");
    cout << "Wprowadz wyszukiwane nazwisko: ";
    cin >> nazwisko;
    cout << endl;

    for (int i = 0; i < iloscKontaktow; i++)
    {
        if(kontakty[i].nazwisko == nazwisko)
        {
            cout << numerPozycji+1 << ". " << endl;
            cout << "Numer ID: " << kontakty[i].ID << endl;
            cout << "Imie: " << kontakty[i].imie <<endl;
            cout << "Nazwisko: " << kontakty[i].nazwisko << endl;
            cout <<"Numer telefonu: " << kontakty[i].nrTelefonu << endl;
            cout << "Adres e-mail: " << kontakty[i].email << endl;
            cout << "Adres zamieszkania: " << kontakty[i].adres << endl;
            cout << endl;
            numerPozycji++;
        }
    }

    if(numerPozycji == 0)
    {
        cout << "Brak kontaktow o podanym nazwisku" << endl;
    }
    cout <<"Aby przejsc dalej wcisnij dowolny klawisz" << endl;
    getchar();
    getchar();
}

void wyswietlWszystkichAdresatow( int iloscKontaktow )
{
    int numerPozycji = 0;
    system("cls");

    for(int i = 0; i < iloscKontaktow; i++)
    {
        cout << numerPozycji+1 << ". " << endl;
        cout << "Numer ID: " << kontakty[i].ID << endl;
        cout << "Imie: " << kontakty[i].imie <<endl;
        cout << "Nazwisko: " << kontakty[i].nazwisko << endl;
        cout <<"Numer telefonu: " << kontakty[i].nrTelefonu << endl;
        cout << "Adres e-mail: " << kontakty[i].email << endl;
        cout << "Adres zamieszkania: " << kontakty[i].adres << endl;
        cout << endl;
        numerPozycji++;
    }

    if(numerPozycji == 0)
    {
        cout << "Brak zapisanych kontaktow w Twojej ksiazce adresowej" << endl;
        cout << endl;
    }
    cout << "Aby przejsc dalej kliknij dowolny klawisz" << endl;
    getchar();
    getchar();
}

void edytujAdresata()
{
    int ID = 0;
    int iloscWystapien = 0;
    int numerPozycjiWWektorze = 0;
    string imie, nazwisko, email, nrTelefonu, adres;
    system("cls");
    cout << "Podaj ID adresata ktorego chcesz edytowac" << endl;
    cout << "ID: ";
    cin >> ID;

    for( int i = 0; i < kontakty.size(); i++)
    {
        if( kontakty[i].ID == ID )
        {
            iloscWystapien++;
            break;
        }
        if( iloscWystapien == 0 ) numerPozycjiWWektorze++;
        else if ( iloscWystapien > 0 ) break;
    }

    if ( iloscWystapien < 1 )
    {
        cout << endl;
        cout << "Nie znaleziono kontaktu o podanym numerze ID";
        Sleep(2500);
    }


    else if ( iloscWystapien >= 1 )
    {

        char wybor;
        while( wybor != '6' )
        {
            system("cls");
            cout << "Wybierz informacje adresata ktora chcesz edytowac: " << endl;
            cout << "1 - imie" << endl;
            cout << "2 - nazwisko" << endl;
            cout << "3 - numer telefonu" << endl;
            cout << "4 - email" << endl;
            cout << "5 - adres" << endl;
            cout << "6 - powrot do menu" << endl;
            cout << "Twoj wybor: ";
            cin >> wybor;
            cout << endl;

            switch( wybor )
            {
                system("cls");

            case '1':
                cout << "Wprowadz nowe imie: ";
                cin >> imie;
                kontakty[ numerPozycjiWWektorze ].imie = imie;
                zastapDaneWPlikuTekstowym();
                break;

            case '2':
                cout << "Wprowadz nowe nazwisko: ";
                cin >> nazwisko;
                kontakty[ numerPozycjiWWektorze ].nazwisko = nazwisko;
                zastapDaneWPlikuTekstowym();
                break;

            case '3':
                cout << "Wprowadz nowy numer telefonu: ";
                cin.sync();
                getline(cin, nrTelefonu);
                kontakty[ numerPozycjiWWektorze ].nrTelefonu = nrTelefonu;
                zastapDaneWPlikuTekstowym();
                break;

            case '4':
                cout << "Podaj nowy adres e-mail: ";
                cin >> email;
                kontakty[ numerPozycjiWWektorze ].email = email;
                zastapDaneWPlikuTekstowym();
                break;

            case '5':
                cout << "Podaj nowy adres: ";
                cin.sync();
                getline(cin, adres);
                kontakty[ numerPozycjiWWektorze ].adres = adres;
                zastapDaneWPlikuTekstowym();
                break;
            }
        }
    }
}

int usunAdresata ( int iloscKontaktow )
{
    int ID = 0;
    int iloscWystapien = 0;
    int numerPozycjiWWektorze = 0;
    char wybor;
    int zmiennaSprawdzajaca = 0;

    system("cls");
    cout << "Podaj ID adresata ktorego chcesz usunac" << endl;
    cout << "ID: ";
    cin >> ID;

    for( int i = 0; i < kontakty.size(); i++)
    {
        if( kontakty[i].ID == ID )
        {
            iloscWystapien++;
            break;
        }
        if( iloscWystapien == 0 ) numerPozycjiWWektorze++;
        else if ( iloscWystapien > 0 ) break;
    }

    if ( iloscWystapien < 1 )
    {
        cout << endl;
        cout << "Nie znaleziono kontaktu o podanym numerze ID";
        Sleep(2500);
    }


    else if ( iloscWystapien >= 1 )
    {
        system("cls");
        cout << "Czy na pewno chesz usunac adresata: " << kontakty[numerPozycjiWWektorze].imie << " " << kontakty[numerPozycjiWWektorze].nazwisko << " z ksiazki adresowej ?" << endl;
        cout << endl;
        cout << "t/n     (tak/nie)" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        if( wybor == 't' )
        {
            kontakty.erase(kontakty.begin() + numerPozycjiWWektorze);
            zastapDaneWPlikuTekstowym();
            zmiennaSprawdzajaca++;
        }
        else if( wybor == 'n' )
        {
            return 0;
        }
    }

    iloscKontaktow = iloscKontaktow - zmiennaSprawdzajaca;
    return iloscKontaktow;
}

int main()
{
    int iloscKontaktow = 0;
    char wybor;
    iloscKontaktow = odczytZPlikuDoProgramu( iloscKontaktow );

    while(1)
    {
        system("cls");
        cout << "KSIAZKA ADRESOWA" << endl;
        cout << "1.Dodaj adresata" << endl;
        cout << "2.Wyszukaj po imieniu" << endl;
        cout << "3.Wyszukaj po nazwisku" << endl;
        cout << "4.Wyswietl wszystkich adresatow" << endl;
        cout << "5.Usun adresata" << endl;
        cout << "6.Edytuj adresata" << endl;
        cout << "9.Zakoncz program" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        if(wybor == '1')
        {
            iloscKontaktow = dodajOsobe( iloscKontaktow );
        }
        else if (wybor == '2')
        {
            wyszukajPoImieniu( iloscKontaktow );
        }
        else if (wybor == '3')
        {
            wyszukajPoNazwisku( iloscKontaktow );
        }
        else if (wybor == '4')
        {
            wyswietlWszystkichAdresatow( iloscKontaktow );
        }
        else if (wybor == '5')
        {
            iloscKontaktow = usunAdresata( iloscKontaktow );
        }
        else if (wybor == '6')
        {
            edytujAdresata();
        }
        else if (wybor == '9')
        {
            return 0;
        }
    }

    return 0;
}
