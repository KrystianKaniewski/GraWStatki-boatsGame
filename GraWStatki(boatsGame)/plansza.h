#include <cstdlib>
#include <string>
#include "wykluczenia.h"

class plansza :public wykluczenia{
public:
    void wypisywanie_planszy(std::string x[32][32]) {
        std::cout << "      ";
        for (int i = 0; i < 30; i++) {
            if (i >= 8)
                std::cout << i + 1 << "|";
            else
                std::cout << i + 1 << "| ";
        }
        std::cout << "\n\n";
        for (int i = 0; i < 30; i++) {
            if (i >= 9)
                std::cout << i + 1 << "  |";
            else
                std::cout << i + 1 << "   |";
            for (int j = 0; j < 30; j++) {
                std::cout << " " << x[i+1][j+1] << "|";
            }
            std::cout << std::endl;
        }
    }
    bool wypelnianie(){
        std::string opcja;
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "czy chcesz wypenic tablice automatycznie [t/n]: \n";
        std::cin>>opcja;
        std::cout<<"";
        if (opcja != "t" || opcja != "n"){
            while (opcja != "t" || opcja != "n") {
                if(opcja == "t" || opcja == "n")
                    break;
                std::cout << "prosze podac odpowiedni parametr: ";
                std::cin >> opcja;
            }
        }
        std::cout << "--------------------------------------------------------------------------------\n";
        if(opcja == "n")
            return false;
        return true;
    }
    void manual_fill(std::string s[32][32], int l_statki[4]) {
        std::string orientacja;
        int statek, pozycja[2];
        std::cout << "\n--------------------------------------------------------------------------------\n";
        std::cout << "dostepne statki:\n"
                  << l_statki[0] << " dwumasztowcow\n"
                  << l_statki[1] << " trzymasztowcow\n"
                  << l_statki[2] << " czteromasztowcow\n"
                  << l_statki[3] << " pieciomasztowcow\n";
        std::cout << " wybierz statek (2,3,4,5):";
        std::cin >> statek;
        if (l_statki[statek - 2] == 0)
            while (l_statki[statek - 2] == 0) {
                std::cout << "brak Ci statkow tego typu, podaj inny: ";
                std::cin >> statek;
            }
        l_statki[statek - 2]--;
        std::cout << "orientacja (poziomo - h, pionowo - v):";
        std::cin >> orientacja;
        std::cout<<"";
        if (orientacja != "h" || orientacja != "v"){
            while (orientacja != "h" || orientacja != "v") {
                if(orientacja == "h" || orientacja == "v")
                    break;
                std::cout << "prosze podac odpowiedni parametr: ";
                std::cin >> orientacja;
            }
        }
        std::cout << "pozycja:\n pion: ";
        std::cin >> pozycja[0];
        std::cout << "poziom: ";
        std::cin >> pozycja[1];
        if(!czy_wstaw_stat(s, statek, orientacja, pozycja)){
            std::cout<<"statek sie nie miesci, podaj inne parametry: \n";
            while(!czy_wstaw_stat(s, statek, orientacja, pozycja)){
                std::cout << "orientacja (poziomo - h, pionowo - v):";
                std::cin >> orientacja;
                std::cout<<"";
                if (orientacja != "h" || orientacja != "v"){
                    while (orientacja != "h" || orientacja != "v") {
                        if(orientacja == "h" || orientacja == "v")
                            break;
                        std::cout << "prosze podac odpowiedni parametr: ";
                        std::cin >> orientacja;
                    }
                }
                std::cout << "pozycja:\n pion: ";
                std::cin >> pozycja[0];
                std::cout << "poziom: ";
                std::cin >> pozycja[1];
                if(!czy_wstaw_stat(s, statek, orientacja, pozycja))
                    std::cout<<"statek sie nie miesci, podaj inne parametry: \n";
            }
        }
        wstaw_statek(s, statek, orientacja, pozycja);
        std::cout << "--------------------------------------------------------------------------------\n";

    }

    void wstaw_statek(std::string s[32][32], int statek, std::string ori, int poz[2]) {
        if (ori == "v") {
            switch (statek) {
                case 2:
                    s[poz[1]][poz[0]] = '2';
                    s[poz[1]+1][poz[0]] = '2';
                    break;
                case 3:
                    s[poz[1]][poz[0]] = '3';
                    s[poz[1]+1][poz[0]] = '3';
                    s[poz[1] + 2][poz[0]] = '3';
                    break;
                case 4:
                    s[poz[1]][poz[0]] = '4';
                    s[poz[1]+1][poz[0]] = '4';
                    s[poz[1] + 2][poz[0]] = '4';
                    s[poz[1] + 3][poz[0]] = '4';
                    break;
                case 5:
                    s[poz[1]][poz[0]] = '5';
                    s[poz[1]+1][poz[0]] = '5';
                    s[poz[1] + 2][poz[0]] = '5';
                    s[poz[1] + 3][poz[0]] = '5';
                    s[poz[1] + 4][poz[0]] = '5';
                    break;
            }
        }
        if (ori == "h") {
            switch (statek) {
                case 2:
                    s[poz[1]][poz[0]] = '2';
                    s[poz[1]][poz[0]+1] = '2';
                    break;
                case 3:
                    s[poz[1]][poz[0]] = '3';
                    s[poz[1]][poz[0]+1] = '3';
                    s[poz[1]][poz[0] + 2] = '3';
                    break;
                case 4:
                    s[poz[1]][poz[0]] = '4';
                    s[poz[1]][poz[0]+1] = '4';
                    s[poz[1]][poz[0] + 2] = '4';
                    s[poz[1]][poz[0] + 3] = '4';
                    break;
                case 5:
                    s[poz[1]][poz[0]] = '5';
                    s[poz[1]][poz[0]+1] = '5';
                    s[poz[1]][poz[0] + 2] = '5';
                    s[poz[1]][poz[0] + 3] = '5';
                    s[poz[1]][poz[0] + 4] = '5';
                    break;
            }
        }
    }
    bool strzelanie(){
        std::string opcja;
        std::cout << "--------------------------------------------------------------------------------\n";
        std::cout << "czy chcesz aby gracz byl automatem [t/n]: \n";
        std::cin>>opcja;
        std::cout<<"";
        if (opcja != "t" || opcja != "n"){
            while (opcja != "t" || opcja != "n") {
                if(opcja == "t" || opcja == "n")
                    break;
                std::cout << "prosze podac odpowiedni parametr: ";
                std::cin >> opcja;
            }
        }
        std::cout << "--------------------------------------------------------------------------------\n";
        if(opcja == "n")
            return false;
        return true;
    }
    void manual_shot(std::string s[32][32], std::string sg[32][32], int *l_s){
        int pozycja[2];
        std::cout << "\n--------------------------------------------------------------------------------\n";
        std::cout<<"podaj koordynaty do ostrzalu:\n";
        std::cout << "pozycja:\n pion: ";
        std::cin >> pozycja[0];
        std::cout << "poziom: ";
        std::cin >> pozycja[1];
        if(!czy_shot(sg, pozycja)){
            std::cout<<"ta pozycja zostala juz ostrzelana, podaj inna:\n";
            while(!czy_shot(sg, pozycja)){
                std::cout << "pozycja:\n pion: ";
                std::cin >> pozycja[0];
                std::cout << "poziom: ";
                std::cin >> pozycja[1];
                if(!czy_shot(sg, pozycja))
                    std::cout<<"ta pozycja zostala juz ostrzelana, podaj inna:\n";
            }
        }
        shot(s, sg, pozycja, l_s);
        std::cout << "\n--------------------------------------------------------------------------------\n";
    }
    void shot(std::string s[32][32], std::string sg[32][32], int poz[2], int *l_s){
        std::string a = s[poz[1]][poz[0]];
        if(s[poz[1]][poz[0]] == "*")
            sg[poz[1]][poz[0]] = "o";
        switch(a[0]){
            case '2':
                (*l_s)--;
                sg[poz[1]][poz[0]] = "x";
                if(s[poz[1]-1][poz[0]] == a)
                    sg[poz[1]-1][poz[0]] = "x";
                if(s[poz[1]+1][poz[0]] == a)
                    sg[poz[1]+1][poz[0]] = "x";
                if(s[poz[1]][poz[0]-1] == a)
                    sg[poz[1]][poz[0]-1] = "x";
                if(s[poz[1]+1][poz[0]+1] == a)
                    sg[poz[1]+1][poz[0]+1] = "x";
                break;
            case '3':
                (*l_s)--;
                sg[poz[1]][poz[0]] = "x";
                if(s[poz[1]-1][poz[0]] == a){
                    sg[poz[1]-1][poz[0]] = "x";
                    if(s[poz[1]-2][poz[0]] == a)
                        sg[poz[1]-2][poz[0]] = "x";
                }
                if(s[poz[1]+1][poz[0]] == a){
                    sg[poz[1]+1][poz[0]] = "x";
                    if(s[poz[1]+2][poz[0]] == a)
                        sg[poz[1]+2][poz[0]] = "x";
                }
                if(s[poz[1]][poz[0]-1] == a){
                    sg[poz[1]][poz[0]-1] = "x";
                    if(s[poz[1]][poz[0]-2] == a)
                        sg[poz[1]][poz[0]-2] = "x";
                }
                if(s[poz[1]][poz[0]+1] == a){
                    sg[poz[1]][poz[0]+1] = "x";
                    if(s[poz[1]][poz[0]+2] == a)
                        sg[poz[1]][poz[0]+2] = "x";
                }
                break;
            case '4':
                (*l_s)--;
                sg[poz[1]][poz[0]] = "x";
                if(s[poz[1]-1][poz[0]] == a){
                    sg[poz[1]-1][poz[0]] = "x";
                    if(s[poz[1]-2][poz[0]] == a){
                        sg[poz[1]-2][poz[0]] = "x";
                        if(s[poz[1]-3][poz[0]] == a){
                            sg[poz[1]-3][poz[0]] = "x";
                        }
                    }
                }
                if(s[poz[1]+1][poz[0]] == a){
                    sg[poz[1]+1][poz[0]] = "x";
                    if(s[poz[1]+2][poz[0]] == a){
                        sg[poz[1]+2][poz[0]] = "x";
                        if(s[poz[1]+3][poz[0]] == a){
                            sg[poz[1]+3][poz[0]] = "x";
                        }
                    }
                }
                if(s[poz[1]][poz[0]-1] == a){
                    sg[poz[1]][poz[0]-1] = "x";
                    if(s[poz[1]][poz[0]-2] == a){
                        sg[poz[1]][poz[0]-2] = "x";
                        if(s[poz[1]][poz[0]-3] == a){
                            sg[poz[1]][poz[0]-3] = "x";
                        }
                    }
                }
                if(s[poz[1]][poz[0]+1] == a){
                    sg[poz[1]][poz[0]+1] = "x";
                    if(s[poz[1]][poz[0]+2] == a){
                        sg[poz[1]][poz[0]+2] = "x";
                        if(s[poz[1]][poz[0]+3] == a){
                            sg[poz[1]][poz[0]+3] = "x";
                        }
                    }
                }
                break;
            case '5':
                (*l_s)--;
                sg[poz[1]][poz[0]] = "x";
                if(s[poz[1]-1][poz[0]] == a){
                    sg[poz[1]-1][poz[0]] = "x";
                    if(s[poz[1]-2][poz[0]] == a){
                        sg[poz[1]-2][poz[0]] = "x";
                        if(s[poz[1]-3][poz[0]] == a){
                            sg[poz[1]-3][poz[0]] = "x";
                            if(s[poz[1]-4][poz[0]] == a){
                                sg[poz[1]-4][poz[0]] = "x";
                            }
                        }
                    }
                }
                if(s[poz[1]+1][poz[0]] == a){
                    sg[poz[1]+1][poz[0]] = "x";
                    if(s[poz[1]+2][poz[0]] == a){
                        sg[poz[1]+2][poz[0]] = "x";
                        if(s[poz[1]+3][poz[0]] == a){
                            sg[poz[1]+3][poz[0]] = "x";
                            if(s[poz[1]+4][poz[0]] == a){
                                sg[poz[1]+4][poz[0]] = "x";
                            }
                        }
                    }
                }
                if(s[poz[1]][poz[0]-1] == a){
                    sg[poz[1]][poz[0]-1] = "x";
                    if(s[poz[1]][poz[0]-2] == a){
                        sg[poz[1]][poz[0]-2] = "x";
                        if(s[poz[1]][poz[0]-3] == a){
                            sg[poz[1]][poz[0]-3] = "x";
                            if(s[poz[1]][poz[0]-4] == a){
                                sg[poz[1]][poz[0]-4] = "x";
                            }
                        }
                    }
                }
                if(s[poz[1]][poz[0]+1] == a){
                    sg[poz[1]][poz[0]+1] = "x";
                    if(s[poz[1]][poz[0]+2] == a){
                        sg[poz[1]][poz[0]+2] = "x";
                        if(s[poz[1]][poz[0]+3] == a){
                            sg[poz[1]][poz[0]+3] = "x";
                            if(s[poz[1]][poz[0]+4] == a){
                                sg[poz[1]][poz[0]+4] = "x";
                            }
                        }
                    }
                }
                break;
        }
    }
};
