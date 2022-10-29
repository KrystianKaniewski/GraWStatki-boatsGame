#include <cstdlib>
#include <string>
#include <time.h>
#include "plansza.h"
class automaty: public plansza {
public:
    void auto_wyp(std::string s[32][32], int l_statki[4]){
        int poz[2], ori;
        for(int i = 0; i < l_statki[3];i++){
            ori = rand()%100;
            if(ori%2 == 1){
                poz[0] = rand()%30+1;
                poz[1] = rand()%26+1;
                if(!czy_wstaw_stat(s, 5, "v", poz)){
                    while(!czy_wstaw_stat(s, 5, "v", poz)){
                        poz[0] = (rand()%30)+1;
                        poz[1] = (rand()%26)+1;
                    }
                }
                wstaw_statek(s, 5, "v", poz);
            }
            else{
                poz[0] = rand()%26+1;
                poz[1] = rand()%30+1;
                if(!czy_wstaw_stat(s, 5, "h", poz)){
                    while(!czy_wstaw_stat(s, 5, "h", poz)){
                        poz[0] = (rand()%30)+1;
                        poz[1] = (rand()%26)+1;
                    }
                }
                wstaw_statek(s, 5, "h", poz);
            }
        }
        for(int i = 0; i < l_statki[2];i++){
            ori = rand()%100;
            if(ori%2 == 1){
                poz[0] = rand()%30+1;
                poz[1] = rand()%27+1;
                if(!czy_wstaw_stat(s, 4, "v", poz)){
                    while(!czy_wstaw_stat(s, 4, "v", poz)){
                        poz[0] = (rand()%30)+1;
                        poz[1] = (rand()%27)+1;
                    }
                }
                wstaw_statek(s, 4, "v", poz);
            }
            else{
                poz[0] = rand()%27+1;
                poz[1] = rand()%30+1;
                if(!czy_wstaw_stat(s, 4, "h", poz)){
                    while(!czy_wstaw_stat(s, 4, "h", poz)){
                        poz[0] = (rand()%30)+1;
                        poz[1] = (rand()%27)+1;
                    }
                }
                wstaw_statek(s, 4, "h", poz);
            }
        }
        for(int i = 0; i < l_statki[1];i++){
            ori = rand()%100;
            if(ori%2 == 1){
                poz[0] = rand()%30+1;
                poz[1] = rand()%28+1;
                if(!czy_wstaw_stat(s, 3, "v", poz)){
                    while(!czy_wstaw_stat(s, 3, "v", poz)){
                        poz[0] = (rand()%30)+1;
                        poz[1] = (rand()%28)+1;
                    }
                }
                wstaw_statek(s, 3, "v", poz);
            }
            else{
                poz[0] = rand()%28+1;
                poz[1] = rand()%30+1;
                if(!czy_wstaw_stat(s, 3, "h", poz)){
                    while(!czy_wstaw_stat(s, 3, "h", poz)){
                        poz[0] = (rand()%30)+1;
                        poz[1] = (rand()%28)+1;
                    }
                }
                wstaw_statek(s, 3, "h", poz);
            }
        }
        for(int i = 0; i < l_statki[0];i++){
            ori = rand()%100;
            if(ori%2 == 1){
                poz[0] = rand()%30+1;
                poz[1] = rand()%29+1;
                if(!czy_wstaw_stat(s, 2, "v", poz)){
                    while(!czy_wstaw_stat(s, 2, "v", poz)){
                        poz[0] = (rand()%30)+1;
                        poz[1] = (rand()%29)+1;
                    }
                }
                wstaw_statek(s, 2, "v", poz);
            }
            else{
                poz[0] = rand()%29+1;
                poz[1] = rand()%30+1;
                if(!czy_wstaw_stat(s, 2, "h", poz)){
                    while(!czy_wstaw_stat(s, 2, "h", poz)){
                        poz[0] = (rand()%30)+1;
                        poz[1] = (rand()%29)+1;
                    }
                }
                wstaw_statek(s, 2, "h", poz);
            }
        }
    }
    void auto_shot(std::string s[32][32], std::string sg[32][32], int *l_s){
        int pozycja[2];
        pozycja[0]= (rand()%30)+1;
        pozycja[1]= (rand()%30)+1;
        if(!czy_shot_a(sg, pozycja)){
            while(!czy_shot_a(sg, pozycja)){
                pozycja[0]= (rand()%30)+1;
                pozycja[1]= (rand()%30)+1;
            }
        }
        shot(s, sg,pozycja, l_s);
    }
};

