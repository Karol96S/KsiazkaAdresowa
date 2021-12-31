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

struct uzytkownik
{
    int idUzytkownika;
    string nazwa, haslo;
};

vector <ksiazkaAdresowa> kontakty;
vector <uzytkownik> uzytkownicy;

void zapisDoPlikuTekstowego( ksiazkaAdresowa adresat, int numerPozycjiUzytkownika )
{
    fstream plik;
    plik.open("Adresaci.txt", ios::out | ios::app);
    plik<<adresat.ID<< "|";
    plik<<uzytkownicy[numerPozycjiUzytkownika].idUzytkownika<< "|";                                                           //ZAPIS
    plik<<adresat.imie<< "|";
    plik<<adresat.nazwisko<< "|";
    plik<<adresat.nrTelefonu<< "|";
    plik<<adresat.email<< "|";
    plik<<adresat.adres<< "|" << endl;
    plik.close();
}

int odczytZPlikuDoProgramu( int iloscKontaktow, int numerPozycjiUzytkownika )                                        //ODCZYT
{
    fstream plik;
    string linia;
    ksiazkaAdresowa adresat;

    if(plik.good() == true)
    {
        plik.open("Adresaci.txt", ios::in);
        while(getline(plik,linia))
        {
            string imie = "", nazwisko = "", nrTelefonu = "", email = "", adres = "", ID = "", idUzytkownika = "";
            int idUzytkownikaZamienioneNaInt = 0;
            int pozycjaLitery = 0;

            while( linia[ pozycjaLitery ] != '|')
            {
                ID = ID + linia[ pozycjaLitery ];
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                idUzytkownika = idUzytkownika + linia[ pozycjaLitery ];
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

            idUzytkownikaZamienioneNaInt = atoi(idUzytkownika.c_str());
            adresat.ID = atoi(ID.c_str());
            adresat.imie = imie;
            adresat.nazwisko = nazwisko;
            adresat.nrTelefonu = nrTelefonu;
            adresat.email = email;
            adresat.adres = adres;

            if( idUzytkownikaZamienioneNaInt == uzytkownicy[numerPozycjiUzytkownika].idUzytkownika )
            {
            kontakty.push_back( adresat );
            iloscKontaktow++;
            }
        }
        plik.close();
        return iloscKontaktow;
    }
}

void zastapDaneWPlikuTekstowym( int numerPozycjiUzytkownika, int idKontaktu )                                                          //ZASTAP ZAPIS
{
    int sprawdzIdUzytkownika = 0;
    int sprawdzIdKontaktu = 0;
    int sprawdzPozycjeKontaktow = 0;
    ksiazkaAdresowa adresat;
    fstream plik;
    fstream plik2;
    string linia;

    if(plik.good() == true)
    {
        plik.open("Adresaci.txt", ios::in);
        plik2.open("AdresaciPrzechowanieDanych.txt", ios::out);
        while(getline(plik,linia))
        {
          string imie = "", nazwisko = "", nrTelefonu = "", email = "", adres = "", ID = "", sprawdzIdUzytkownika = "";
          int sprawdzIdUzytkownikaZamienioneNaInt = 0;
          int pozycjaLitery = 0;

            while( linia[ pozycjaLitery ] != '|')
            {
                ID = ID + linia[ pozycjaLitery ];
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                sprawdzIdUzytkownika = sprawdzIdUzytkownika + linia[ pozycjaLitery ];
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

            sprawdzIdUzytkownikaZamienioneNaInt = atoi(sprawdzIdUzytkownika.c_str());
            sprawdzIdKontaktu = atoi(ID.c_str());
            adresat.ID = atoi(ID.c_str());
            adresat.imie = imie;
            adresat.nazwisko = nazwisko;
            adresat.nrTelefonu = nrTelefonu;
            adresat.email = email;
            adresat.adres = adres;

            if( sprawdzIdUzytkownikaZamienioneNaInt == uzytkownicy[numerPozycjiUzytkownika].idUzytkownika && sprawdzIdKontaktu != idKontaktu )
            {
                plik2<<kontakty[sprawdzPozycjeKontaktow].ID<< "|";
                plik2<<uzytkownicy[numerPozycjiUzytkownika].idUzytkownika<< "|";
                plik2<<kontakty[sprawdzPozycjeKontaktow].imie<< "|";
                plik2<<kontakty[sprawdzPozycjeKontaktow].nazwisko<< "|";
                plik2<<kontakty[sprawdzPozycjeKontaktow].nrTelefonu<< "|";
                plik2<<kontakty[sprawdzPozycjeKontaktow].email<< "|";
                plik2<<kontakty[sprawdzPozycjeKontaktow].adres<< "|" << endl;
                sprawdzPozycjeKontaktow++;
            }

            else if ( sprawdzIdUzytkownikaZamienioneNaInt != uzytkownicy[numerPozycjiUzytkownika].idUzytkownika && sprawdzIdKontaktu != idKontaktu )
            {
                plik2<<adresat.ID<< "|";
                plik2<<sprawdzIdUzytkownika<< "|";
                plik2<<adresat.imie<< "|";
                plik2<<adresat.nazwisko<< "|";
                plik2<<adresat.nrTelefonu<< "|";
                plik2<<adresat.email<< "|";
                plik2<<adresat.adres<< "|" << endl;
            }
        }
    }


    plik2.close();
    plik.close();
    remove("Adresaci.txt");
    rename("AdresaciPrzechowanieDanych.txt", "Adresaci.txt");
}

int dodajOsobe( int iloscKontaktow, int numerPozycjiUzytkownika )
{
    ksiazkaAdresowa adresat;
    ksiazkaAdresowa adresat2;
    string imie, nazwisko, nrTelefonu, email, adres;
    int dlugoscWektora = kontakty.size();
    int poprzednieId = 0;
    //int sprawdzamIdUzytkownika = 0;

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
    //                                                                                                       Dziwne rozwiazanie, zamien w funkcje
    fstream plik;
    string linia;

    if(plik.good() == true)
    {
        plik.open("Adresaci.txt", ios::in);
        while(getline(plik,linia))
        {
            string imie = "", nazwisko = "", nrTelefonu = "", email = "", adres = "", ID = "", idUzytkownika = "";
            int idUzytkownikaZamienioneNaInt = 0;
            int pozycjaLitery = 0;

            while( linia[ pozycjaLitery ] != '|')
            {
                ID = ID + linia[ pozycjaLitery ];
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                idUzytkownika = idUzytkownika + linia[ pozycjaLitery ];
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                pozycjaLitery++;
            }

            //sprawdzamIdUzytkownika = atoi(idUzytkownika.c_str());
            adresat2.ID = atoi(ID.c_str());
            poprzednieId = atoi(ID.c_str());

        }
        plik.close();

if( poprzednieId > 0 )
        {
            adresat.ID = adresat2.ID + 1;
        }
    //
else
{
    if( iloscKontaktow == 0 )
    {
        adresat.ID = 1;
    }
    else if ( iloscKontaktow > 0 )
    {
        adresat.ID = kontakty[ dlugoscWektora - 1 ].ID + 1;
    }
}
    kontakty.push_back( adresat );

    cout << endl;
    cout << "Pomyslnie dodano osobe do ksiazki adresowej!" << endl;
    Sleep(2500);

    zapisDoPlikuTekstowego( adresat, numerPozycjiUzytkownika );

    return iloscKontaktow+1;
}
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

    for(int i = 0; i < kontakty.size(); i++)
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

void edytujAdresata( int numerPozycjiUzytkownika )
{
    int ID = 0;
    int iloscWystapien = 0;
    int numerPozycjiWWektorze = 0;
    int idKontaktu = 0; //blank
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
                zastapDaneWPlikuTekstowym( numerPozycjiUzytkownika, idKontaktu );
                break;

            case '2':
                cout << "Wprowadz nowe nazwisko: ";
                cin >> nazwisko;
                kontakty[ numerPozycjiWWektorze ].nazwisko = nazwisko;
                zastapDaneWPlikuTekstowym( numerPozycjiUzytkownika, idKontaktu );
                break;

            case '3':
                cout << "Wprowadz nowy numer telefonu: ";
                cin.sync();
                getline(cin, nrTelefonu);
                kontakty[ numerPozycjiWWektorze ].nrTelefonu = nrTelefonu;
                zastapDaneWPlikuTekstowym( numerPozycjiUzytkownika, idKontaktu );
                break;

            case '4':
                cout << "Podaj nowy adres e-mail: ";
                cin >> email;
                kontakty[ numerPozycjiWWektorze ].email = email;
                zastapDaneWPlikuTekstowym( numerPozycjiUzytkownika, idKontaktu );
                break;

            case '5':
                cout << "Podaj nowy adres: ";
                cin.sync();
                getline(cin, adres);
                kontakty[ numerPozycjiWWektorze ].adres = adres;
                zastapDaneWPlikuTekstowym( numerPozycjiUzytkownika, idKontaktu );
                break;
            }
        }
    }
}

int usunAdresata ( int iloscKontaktow, int numerPozycjiUzytkownika )
{
    int ID = 0;
    int iloscWystapien = 0;
    int numerPozycjiWWektorze = 0;
    int idKontaktu = 0;
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
            idKontaktu = ID;
            kontakty.erase(kontakty.begin() + numerPozycjiWWektorze);
            zastapDaneWPlikuTekstowym( numerPozycjiUzytkownika, idKontaktu );
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

void zapiszUzytkownika( uzytkownik nowyUzytkownik )
{
    fstream plik;
    plik.open("Uzytkownicy.txt", ios::out | ios::app);
    plik<<nowyUzytkownik.idUzytkownika<< "|";                                                           //ZAPIS
    plik<<nowyUzytkownik.nazwa<< "|";
    plik<<nowyUzytkownik.haslo<< "|" << endl;
    plik.close();
}

void nadpiszUzytkownikow()
{
    fstream plik;
    plik.open("Uzytkownicy.txt", ios::out);

    for(int i = 0; i < uzytkownicy.size(); i++)
    {
    plik<<uzytkownicy[i].idUzytkownika<< "|";
    plik<<uzytkownicy[i].nazwa<< "|";
    plik<<uzytkownicy[i].haslo<< "|" << endl;
    }
    plik.close();
}

void odczytUzytkownikow()
{
    fstream plik;
    string linia;
    uzytkownik uzytkownikDoWczytania;

    if(plik.good() == true)
    {
        plik.open("Uzytkownicy.txt", ios::in);
        while(getline(plik,linia))
        {
            string nazwa = "", haslo = "", idUzytkownika = "";
            int pozycjaLitery = 0;

            while( linia[ pozycjaLitery ] != '|')
            {
                idUzytkownika = idUzytkownika + linia[ pozycjaLitery ];
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                nazwa = nazwa + linia[ pozycjaLitery ];
                pozycjaLitery++;
            }
            pozycjaLitery++;

            while( linia[ pozycjaLitery ] != '|')
            {
                haslo = haslo + linia[ pozycjaLitery ];
                pozycjaLitery++;
            }

            uzytkownikDoWczytania.idUzytkownika = atoi(idUzytkownika.c_str());
            uzytkownikDoWczytania.nazwa = nazwa;
            uzytkownikDoWczytania.haslo = haslo;
            uzytkownicy.push_back( uzytkownikDoWczytania );
        }
        plik.close();
    }
}

int rejestracja()
{
    string nazwa, haslo;
    uzytkownik nowyUzytkownik;
    int iloscUzytkownikow = uzytkownicy.size();
    int id = 0;
    int sprawdzamCzyNazwaJestZajeta = 0;
    while ( id == 0 )
    {
        while ( sprawdzamCzyNazwaJestZajeta == 0 )
        {
            system("cls");
            cout << "Prosze podac nazwe uzytkownika: ";
            cin >> nazwa;
            sprawdzamCzyNazwaJestZajeta = 1;

            if( iloscUzytkownikow > 0 )
            {
                for (int i = 0; i < iloscUzytkownikow; i++)
                {
                    if( uzytkownicy[i].nazwa == nazwa )
                    {
                        cout << endl;
                        cout << "Podana nazwa jest juz zajeta!" << endl;
                        sprawdzamCzyNazwaJestZajeta = 0;
                        system("pause");
                        break;
                    }
                }
            }

        }

            system("cls");
            cout << "Prosze podac haslo: ";
            cin >> haslo;

        nowyUzytkownik.nazwa = nazwa;
        nowyUzytkownik.haslo = haslo;
        if ( uzytkownicy.size() == 0 )
        {
            nowyUzytkownik.idUzytkownika = 1;
        }
        else if( uzytkownicy.size() > 0 )
        {
            nowyUzytkownik.idUzytkownika = uzytkownicy[ iloscUzytkownikow - 1 ].idUzytkownika + 1;
        }

        id = nowyUzytkownik.idUzytkownika;
    }

    if( id!= 0) zapiszUzytkownika ( nowyUzytkownik );
    uzytkownicy.push_back( nowyUzytkownik );

    return id;

    system ("cls");
    cout << "Pomyslnie zarejestrowano nowego uzytkownika!" << endl;
    cout << endl;
    system("pause");
}

int logowanie()
{
    string nazwa, haslo;
    int id = 0;
    int sprawdzamCzyNazwaIstnieje = 0;
    int sprawdzamCzyHasloIstnieje = 0;
    int numerUzytkownika = 0;

    while ( id == 0 )
    {
        while ( sprawdzamCzyNazwaIstnieje == 0 )
        {
            system("cls");
            cout << "Aby wrocic wpisz '0'"<< endl;
            cout << endl;
            cout << "Podaj login(nazwe): ";
            cin >> nazwa;

            if ( nazwa == "0")
            {
                return 0;
            }

            else
            {
                if( uzytkownicy.size() > 0)
                {
                    for (int i = 0; i < uzytkownicy.size(); i++)
                    {
                        if( uzytkownicy[i].nazwa == nazwa)
                        {
                            sprawdzamCzyNazwaIstnieje = 1;
                            break;
                        }
                    }
                    if( sprawdzamCzyNazwaIstnieje == 0 )
                    {
                        cout << endl;
                        cout << "Podano bledna nazwe uzytkownika!" << endl;
                        system("pause");
                    }

                }

                else
                {
                    cout << "Ta baza danych nie ma jeszcze zapisanych uzytkownikow!" << endl;
                    system("pause");
                    return 0;
                }

            }
        }


        while ( sprawdzamCzyHasloIstnieje == 0 )
        {
            system ("cls");
            cout << "Aby wrocic wpisz '0'"<< endl;
            cout << endl;
            cout << "Podaj haslo: ";
            cin >> haslo;

            if ( haslo == "0")
            {
                return 0;
            }

            else
            {
                for (int i = 0; i < uzytkownicy.size(); i++)
                {
                    if( uzytkownicy[i].haslo == haslo && uzytkownicy[i].nazwa == nazwa )
                    {
                        sprawdzamCzyHasloIstnieje = 1;
                        numerUzytkownika = i;
                        system("cls");
                        cout << "Zalogowano poprawnie! Witaj." << endl;
                        cout << endl;
                        system("pause");
                    }
                }

                if( sprawdzamCzyHasloIstnieje == 0 )
                {
                    cout << endl;
                    cout << "Podano bledne haslo!" << endl;
                    system("pause");
                }
                id = uzytkownicy[ numerUzytkownika ].idUzytkownika;
            }
        }
    }
    return id;
}


int ekranLogowania()
{
    int idUzytkownika = -1;
    char wybor;
    while (1)
    {
        system("cls");
        cout << "1. Logowanie" << endl;
        cout << "2. Rejestracja" << endl;
        cout << "3. Zamknij program" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        if(wybor == '1')
        {
            idUzytkownika = logowanie();
            break;
        }
        else if (wybor == '2')
        {
            idUzytkownika = rejestracja();
        }
        else if (wybor == '3')
        {
            break;
        }
        else
        {
            cout << endl;
            cout << "Niewlasciwy klawisz, prosze wybrac opcje z zakresu 1 do 3" << endl;
            system("pause");
        }

    }
    return idUzytkownika;
}

string sprawdzamNazweUzytkownika( int idUzytkownika )
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if( uzytkownicy[i].idUzytkownika == idUzytkownika )
        {
            return uzytkownicy[i].nazwa;
            break;
        }
    }
}

int sprawdzNumerPozycjiUzytkownika( int idUzytkownika )
{
    for(int i = 0; i < uzytkownicy.size(); i++)
    {
        if( uzytkownicy[i].idUzytkownika == idUzytkownika )
        {
            return i;
            break;
        }
    }
}

void zmienHaslo( int idUzytkownika )
{
    int ktoryUzytkownik = 0;
    int sprawdzamHaslo = 1;
    string noweHaslo;

    while( sprawdzamHaslo == 1 )
    {
    for(int i = 0; i < uzytkownicy.size(); i++)
    {
        if( uzytkownicy[i].idUzytkownika == idUzytkownika)
        {
            ktoryUzytkownik = i;
        }
    }

    system("cls");
    cout << "Aby cofnac wcisnij '0'" << endl;
    cout << endl;
    cout << "Prosze podac nowe haslo: ";
    cin >> noweHaslo;

    if( noweHaslo == "0" )
    {
        break;
    }

    sprawdzamHaslo = 0;

    for(int i = 0; i < uzytkownicy.size(); i++)
    {
        if( uzytkownicy[i].haslo == noweHaslo )
        {
            system("cls");
            cout << "Podano bledne haslo!" << endl;
            system("pause");
            sprawdzamHaslo = 1;
            break;
        }
    }

    if ( sprawdzamHaslo == 0 )
    {
        uzytkownicy[ktoryUzytkownik].haslo = noweHaslo;
        system("cls");
        cout << "Haslo zostalo poprawnie zmienione!" << endl;
        nadpiszUzytkownikow ();
        system("pause");
    }

    }

}

int main()
{
    int iloscKontaktow = 0;
    char wybor;
    odczytUzytkownikow();
    int idUzytkownika = 0;
    int numerPozycjiUzytkownika = 0;
    string nazwa;

    while (idUzytkownika == 0 )
    {
        idUzytkownika = ekranLogowania();
        if( idUzytkownika == -1 )
        {
            return 0;
            return 0;
        }
        numerPozycjiUzytkownika = sprawdzNumerPozycjiUzytkownika( idUzytkownika );
        iloscKontaktow = odczytZPlikuDoProgramu( iloscKontaktow, numerPozycjiUzytkownika );
    }

    while( idUzytkownika != 0 )
    {
        nazwa = sprawdzamNazweUzytkownika( idUzytkownika );

        system("cls");
        cout << "KSIAZKA ADRESOWA" << "                  Zalogowano jako: " << nazwa << endl;
        cout << "1.Dodaj adresata" << endl;
        cout << "2.Wyszukaj po imieniu" << endl;
        cout << "3.Wyszukaj po nazwisku" << endl;
        cout << "4.Wyswietl wszystkich adresatow" << endl;
        cout << "5.Usun adresata" << endl;
        cout << "6.Edytuj adresata" << endl;
        cout << "7.Zmien Haslo" << endl;
        cout << "8.Wyloguj sie" << endl;
        cout << "9.Zakoncz program" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        if(wybor == '1')
        {
            iloscKontaktow = dodajOsobe( iloscKontaktow, numerPozycjiUzytkownika );
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
            iloscKontaktow = usunAdresata( iloscKontaktow, numerPozycjiUzytkownika );                        //dziala wszystko poza usuwaniem
        }
        else if (wybor == '6')
        {
            edytujAdresata( numerPozycjiUzytkownika );
        }
        else if (wybor == '7')
        {
            zmienHaslo( idUzytkownika );
        }
        else if (wybor == '8')
        {
            idUzytkownika = ekranLogowania();
            if( idUzytkownika == -1 )
            {
                break;
            }
            else
            {
            kontakty.clear();
            numerPozycjiUzytkownika = sprawdzNumerPozycjiUzytkownika( idUzytkownika );
            iloscKontaktow = odczytZPlikuDoProgramu( iloscKontaktow, numerPozycjiUzytkownika );
            }
        }
        else if (wybor == '9')
        {
            return 0;
        }
    }

    return 0;
}
