#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <time.h>
#include "automaty.h"
//w przypadku wyboru automatow program daje od 1,5 do 5 sekund odczekania na przyjrzenie sie wynikowm operacji
int main() {
    srand(time(NULL));
    std::string planG1[32][32], planG1g[32][32], planG2[32][32], planG2g[32][32], gracz = "gracz 1";
    automaty p;
    int l_statkiG1[4] = { 8, 7, 6, 6},
        l_statkiG2[4] = { 8, 7, 6, 6},
        l_sG1 = l_statkiG1[0]+l_statkiG1[1]+l_statkiG1[2]+l_statkiG1[3],
        l_sG2 = l_statkiG2[0]+l_statkiG2[1]+l_statkiG2[2]+l_statkiG2[3];
    bool wyp1, wyp2;
    //wypelanianie tablic gry w statki znakami '*'
    for (int i = 0; i < 32; i++)
        for (int j = 0; j < 32; j++) {
            planG1[i][j] = '*';
            planG2[i][j] = '*';
            planG1g[i][j] = '*';
            planG2g[i][j] = '*';
        }
    // wypelnianie statkami tablicy gracza 1
    gracz[6] = '1';
    std::cout << "--------------------------------------------------------------------------------\n"<< gracz << std::endl;
    wyp1 = p.wypelnianie();
    if(wyp1){
        p.auto_wyp(planG1, l_statkiG1);
        p.wypisywanie_planszy(planG1);
        Sleep(5000);
    }else{
        gracz[6] = '1';
        std::cout<<"wprowadzanie danych dla "<<gracz<<std::endl;
        while (true) {
            switch (gracz[6]) {
                case '1':
                    p.wypisywanie_planszy(planG1);
                    break;
                default:
                    std::cout << "blad gry";
                    break;
            }
            switch (gracz[6]) {
                case '1':
                    p.manual_fill(planG1, l_statkiG1);
                    p.wypisywanie_planszy(planG1);
                    break;
                default:
                    std::cout << "blad gry";
                    break;
            }
            if (l_statkiG1[0] == 0 && l_statkiG1[1] == 0 && l_statkiG1[2] == 0 && l_statkiG1[3] == 0)
                break;
        }
    }
    system("cls");
    // wypelnianie statkami tablicy gracza 2
    gracz[6] = '2';
    std::cout << "--------------------------------------------------------------------------------\n"<< gracz << std::endl;
    wyp2 = p.wypelnianie();
    if(wyp2){
        p.auto_wyp(planG2, l_statkiG2);
        p.wypisywanie_planszy(planG2);
        Sleep(5000);
    }else{
        gracz[6] = '2';
        std::cout<<"wprowadzanie danych dla "<<gracz<<std::endl;
        while (true) {
            switch (gracz[6]) {
                case '2':
                    p.wypisywanie_planszy(planG2);
                    break;
                default:
                    std::cout << "blad gry";
                    break;
            }
            switch (gracz[6]) {
                case '2':
                    p.manual_fill(planG2, l_statkiG2);
                    p.wypisywanie_planszy(planG2);
                    break;
                default:
                    std::cout << "blad gry";
                    break;
            }
            if (l_statkiG2[0] == 0 && l_statkiG2[1] == 0 && l_statkiG2[2] == 0 && l_statkiG2[3] == 0)
                break;
        }
    }
    system("cls");
    // strzelanie
    gracz[6] = '1';
    std::cout << "--------------------------------------------------------------------------------\n"<< gracz << std::endl;
    wyp1 = p.strzelanie();
    std::cout << "--------------------------------------------------------------------------------\n";
    system("cls");
    gracz[6] = '2';
    std::cout << "--------------------------------------------------------------------------------\n"<< gracz << std::endl;
    wyp2 = p.strzelanie();
    std::cout << "--------------------------------------------------------------------------------\n";
    system("cls");
    if(wyp1 && wyp2){
        while(true){
            gracz[6] = '1';
            std::cout<<gracz<<std::endl;
            p.auto_shot(planG2,planG2g,&l_sG2);
            p.wypisywanie_planszy(planG2g);
            std::cout<<"\nzostalo "<<l_sG2<<" statkow przeciwnika\n";
            Sleep(1500);
            if(l_sG2 == 0){
                std::cout<<"wygral gracz 1!";
                break;
            }
            system("cls");
            gracz[6] = '2';
            std::cout<<gracz<<std::endl;
            p.auto_shot(planG1,planG1g,&l_sG1);
            p.wypisywanie_planszy(planG1g);
            std::cout<<"\nzostalo "<<l_sG1<<" statkow przeciwnika\n";
            Sleep(1500);
            if(l_sG1 == 0){
                std::cout<<"wygral gracz 2!";
                break;
            }
            system("cls");
        }
    }
    else if(!wyp1 && !wyp2){
        while(true){
            gracz[6] = '1';
            std::cout<<gracz<<std::endl;
            p.wypisywanie_planszy(planG2g);
            std::cout<<"\nzostalo "<<l_sG2<<" statkow przeciwnika\n";
            p.manual_shot(planG2,planG2g,&l_sG2);
            if(l_sG2 == 0){
                std::cout<<"wygral gracz 1!";
                break;
            }
            system("cls");
            gracz[6] = '2';
            std::cout<<gracz<<std::endl;
            p.wypisywanie_planszy(planG1g);
            std::cout<<"\nzostalo "<<l_sG1<<" statkow przeciwnika\n";
            p.manual_shot(planG1,planG1g,&l_sG1);
            if(l_statkiG2[0] == 7 && l_statkiG2[1] == 6 && l_statkiG2[2] == 5 && l_statkiG2[3] == 4){
                std::cout<<"wygral gracz 2!\n";
                break;
            }
            system("cls");
        }
    }
    else if(wyp1 && !wyp2){
        while(true){
            gracz[6] = '1';
            std::cout<<gracz<<std::endl;
            p.auto_shot(planG1,planG2g,&l_sG2);
            p.wypisywanie_planszy(planG2g);
            std::cout<<"\nzostalo "<<l_sG2<<" statkow przeciwnika\n";
            Sleep(1500);
            if(l_sG2 == 0){
                std::cout<<"wygral gracz 1!\n";
                break;
            }
            system("cls");
            gracz[6] = '2';
            std::cout<<gracz<<std::endl;
            p.wypisywanie_planszy(planG1g);
            std::cout<<"\nzostalo "<<l_sG1<<" statkow przeciwnika\n";
            p.manual_shot(planG1,planG1g,&l_sG1);
            if(l_sG1 == 0){
                std::cout<<"wygral gracz 2!\n";
                break;
            }
            system("cls");
        }
    }
    else if(!wyp1 && wyp2){
        while(true){
            gracz[6] = '1';
            std::cout<<gracz<<std::endl;
            p.wypisywanie_planszy(planG2g);
            std::cout<<"\nzostalo "<<l_sG2<<" statkow przeciwnika\n";
            p.manual_shot(planG2,planG2g,&l_sG2);
            if(l_sG2 == 0){
                std::cout<<"wygral gracz 1!\n";
                break;
            }
            system("cls");
            gracz[6] = '2';
            std::cout<<gracz<<std::endl;
            p.auto_shot(planG1,planG1g,&l_sG1);
            p.wypisywanie_planszy(planG1g);
            std::cout<<"\nzostalo "<<l_sG1<<" statkow przeciwnika\n";
            Sleep(1500);
            if(l_sG1 == 0){
                std::cout<<"wygral gracz 2!\n";
                break;
            }
            system("cls");
        }
    }
    else{
        std::cout<<"cos poszlo nie tak";
    }
    return 0;
}
