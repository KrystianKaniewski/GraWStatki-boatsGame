
class wykluczenia {
public:
    bool czy_wstaw_stat(std::string s[32][32], int statek, std::string ori, int poz[2]) {
        if (ori == "v") {
            switch (statek) {
                case 2:
                    if (poz[1] >= 29)
                        return false;
                    if(     s[poz[1]-1][poz[0]-2] != "*"    || s[poz[1]-2][poz[0]] != "*"   || s[poz[1]-2][poz[0]+1] != "*" ||
                            s[poz[1]-1][poz[0]-1] != "*"    || s[poz[1]-1][poz[0]] != "*"   || s[poz[1]-1][poz[0]+1] != "*" ||
                            s[poz[1]][poz[0]-1] != "*"      || s[poz[1]][poz[0]] != "*"     || s[poz[1]][poz[0]+1] != "*"   ||
                            s[poz[1]+1][poz[0]-1] != "*"    || s[poz[1]+1][poz[0]] != "*"   || s[poz[1]+1][poz[0]+1] != "*" ||
                            s[poz[1]+2][poz[0]-1] != "*"    || s[poz[1]+2][poz[0]] != "*"   || s[poz[1]+2][poz[0]+1] != "*" )
                        return false;
                    break;
                case 3:
                    if (poz[1] >= 28)
                        return false;
                    if(     s[poz[1]-1][poz[0]-2] != "*"    || s[poz[1]-2][poz[0]] != "*"   || s[poz[1]-2][poz[0]+1] != "*" ||
                            s[poz[1]-1][poz[0]-1] != "*"    || s[poz[1]-1][poz[0]] != "*"   || s[poz[1]-1][poz[0]+1] != "*" ||
                            s[poz[1]][poz[0]-1] != "*"      || s[poz[1]][poz[0]] != "*"     || s[poz[1]][poz[0]+1] != "*"   ||
                            s[poz[1]+1][poz[0]-1] != "*"    || s[poz[1]+1][poz[0]] != "*"   || s[poz[1]+1][poz[0]+1] != "*" ||
                            s[poz[1]+2][poz[0]-1] != "*"    || s[poz[1]+2][poz[0]] != "*"   || s[poz[1]+2][poz[0]+1] != "*" ||
                            s[poz[1]+3][poz[0]-1] != "*"    || s[poz[1]+3][poz[0]] != "*"   || s[poz[1]+3][poz[0]+1] != "*" )
                        return false;
                    break;
                case 4:
                    if (poz[1] >= 27)
                        return false;
                    if(     s[poz[1]-1][poz[0]-2] != "*"    || s[poz[1]-2][poz[0]] != "*"   || s[poz[1]-2][poz[0]+1] != "*" ||
                            s[poz[1]-1][poz[0]-1] != "*"    || s[poz[1]-1][poz[0]] != "*"   || s[poz[1]-1][poz[0]+1] != "*" ||
                            s[poz[1]][poz[0]-1] != "*"      || s[poz[1]][poz[0]] != "*"     || s[poz[1]][poz[0]+1] != "*"   ||
                            s[poz[1]+1][poz[0]-1] != "*"    || s[poz[1]+1][poz[0]] != "*"   || s[poz[1]+1][poz[0]+1] != "*" ||
                            s[poz[1]+2][poz[0]-1] != "*"    || s[poz[1]+2][poz[0]] != "*"   || s[poz[1]+2][poz[0]+1] != "*" ||
                            s[poz[1]+3][poz[0]-1] != "*"    || s[poz[1]+3][poz[0]] != "*"   || s[poz[1]+3][poz[0]+1] != "*" ||
                            s[poz[1]+4][poz[0]-1] != "*"    || s[poz[1]+4][poz[0]] != "*"   || s[poz[1]+4][poz[0]+1] != "*" )
                        return false;
                    break;
                case 5:
                    if (poz[1] >= 26)
                        return false;
                    if (    s[poz[1]-1][poz[0]-2] != "*"    || s[poz[1]-2][poz[0]] != "*"   || s[poz[1]-2][poz[0]+1] != "*" ||
                            s[poz[1]-1][poz[0]-1] != "*"    || s[poz[1]-1][poz[0]] != "*"   || s[poz[1]-1][poz[0]+1] != "*" ||
                            s[poz[1]][poz[0]-1] != "*"      || s[poz[1]][poz[0]] != "*"     || s[poz[1]][poz[0]+1] != "*"   ||
                            s[poz[1]+1][poz[0]-1] != "*"    || s[poz[1]+1][poz[0]] != "*"   || s[poz[1]+1][poz[0]+1] != "*" ||
                            s[poz[1]+2][poz[0]-1] != "*"    || s[poz[1]+2][poz[0]] != "*"   || s[poz[1]+2][poz[0]+1] != "*" ||
                            s[poz[1]+3][poz[0]-1] != "*"    || s[poz[1]+3][poz[0]] != "*"   || s[poz[1]+3][poz[0]+1] != "*" ||
                            s[poz[1]+4][poz[0]-1] != "*"    || s[poz[1]+4][poz[0]] != "*"   || s[poz[1]+4][poz[0]+1] != "*" ||
                            s[poz[1]+5][poz[0]-1] != "*"    || s[poz[1]+5][poz[0]] != "*"   || s[poz[1]+5][poz[0]+1] != "*" )
                        return false;
                    break;
            }
        }
        if (ori == "h") {
            switch (statek) {
                case 2:
                    if (poz[0] >= 29)
                        return false;
                    if (    s[poz[1]-1][poz[0]-1] != "*"    || s[poz[1]-1][poz[0]] != "*"   || s[poz[1]-1][poz[0]+1] != "*"     || s[poz[1]-1][poz[0]+2] != "*"     || s[poz[1]-1][poz[0]+3] != "*" ||
                            s[poz[1]][poz[0]-1] != "*"      || s[poz[1]][poz[0]] != "*"     || s[poz[1]][poz[0]+1] != "*"       || s[poz[1]][poz[0]+2] != "*"       || s[poz[1]][poz[0]+3] != "*"   ||
                            s[poz[1]+1][poz[0]-1] != "*"    || s[poz[1]+1][poz[0]] != "*"   || s[poz[1]+1][poz[0]+1] != "*"     || s[poz[1]+1][poz[0]+2] != "*"     || s[poz[1]+1][poz[0]+3] != "*" )
                        return false;
                    break;
                case 3:
                    if (poz[0] >= 28)
                        return false;
                    if (    s[poz[1]-1][poz[0]-1] != "*"    || s[poz[1]-1][poz[0]] != "*"   || s[poz[1]-1][poz[0]+1] != "*"     || s[poz[1]-1][poz[0]+2] != "*"     || s[poz[1]-1][poz[0]+3] != "*"     || s[poz[1]-1][poz[0]+4] != "*"     ||
                            s[poz[1]][poz[0]-1] != "*"      || s[poz[1]][poz[0]] != "*"     || s[poz[1]][poz[0]+1] != "*"       || s[poz[1]][poz[0]+2] != "*"       || s[poz[1]][poz[0]+3] != "*"       || s[poz[1]][poz[0]+4] != "*"       ||
                            s[poz[1]+1][poz[0]-1] != "*"    || s[poz[1]+1][poz[0]] != "*"   || s[poz[1]+1][poz[0]+1] != "*"     || s[poz[1]+1][poz[0]+2] != "*"     || s[poz[1]+1][poz[0]+3] != "*"     || s[poz[1]+1][poz[0]+4] != "*")
                        return false;
                    break;
                case 4:
                    if (poz[0] >= 27)
                        return false;
                    if (    s[poz[1]-1][poz[0]-1] != "*"    || s[poz[1]-1][poz[0]] != "*"   || s[poz[1]-1][poz[0]+1] != "*"     || s[poz[1]-1][poz[0]+2] != "*"     || s[poz[1]-1][poz[0]+3] != "*"     || s[poz[1]-1][poz[0]+4] != "*"     || s[poz[1]-1][poz[0]+5] != "*" ||
                            s[poz[1]][poz[0]-1] != "*"      || s[poz[1]][poz[0]] != "*"     || s[poz[1]][poz[0]+1] != "*"       || s[poz[1]][poz[0]+2] != "*"       || s[poz[1]][poz[0]+3] != "*"       || s[poz[1]][poz[0]+4] != "*"       || s[poz[1]][poz[0]+5] != "*"   ||
                            s[poz[1]+1][poz[0]-1] != "*"    || s[poz[1]+1][poz[0]] != "*"   || s[poz[1]+1][poz[0]+1] != "*"     || s[poz[1]+1][poz[0]+2] != "*"     || s[poz[1]+1][poz[0]+3] != "*"     || s[poz[1]+1][poz[0]+4] != "*"     || s[poz[1]+1][poz[0]+5] != "*" )
                        return false;
                    break;
                case 5:
                    if (poz[0] >= 26)
                        return false;
                    if (    s[poz[1]-1][poz[0]-1] != "*"    || s[poz[1]-1][poz[0]] != "*"   || s[poz[1]-1][poz[0]+1] != "*"     || s[poz[1]-1][poz[0]+2] != "*"     || s[poz[1]-1][poz[0]+3] != "*"     || s[poz[1]-1][poz[0]+4] != "*"     || s[poz[1]-1][poz[0]+5] != "*" || s[poz[1]-1][poz[0]+6] != "*" ||
                            s[poz[1]][poz[0]-1] != "*"      || s[poz[1]][poz[0]] != "*"     || s[poz[1]][poz[0]+1] != "*"       || s[poz[1]][poz[0]+2] != "*"       || s[poz[1]][poz[0]+3] != "*"       || s[poz[1]][poz[0]+4] != "*"       || s[poz[1]][poz[0]+5] != "*"   || s[poz[1]][poz[0]+6] != "*"   ||
                            s[poz[1]+1][poz[0]-1] != "*"    || s[poz[1]+1][poz[0]] != "*"   || s[poz[1]+1][poz[0]+1] != "*"     || s[poz[1]+1][poz[0]+2] != "*"     || s[poz[1]+1][poz[0]+3] != "*"     || s[poz[1]+1][poz[0]+4] != "*"     || s[poz[1]+1][poz[0]+5] != "*" || s[poz[1]+1][poz[0]+6] != "*")
                        return false;
                    break;
            }
        }
        return true;
    }
    bool czy_shot(std::string s[32][32], int poz[2]){
        if(s[poz[1]][poz[0]] == "o" || s[poz[1]][poz[0]] == "x")
            return false;
        return true;
    }
    bool czy_shot_a(std::string s[32][32], int poz[2]){
        if(s[poz[1]][poz[0]] == "o" || (poz[0]+poz[1])%2 == 0)
            return false;
        if( s[poz[1]-1][poz[0]-1] == "x"    || s[poz[1]-1][poz[0]] == "x"     || s[poz[1]-1][poz[0]+1] == "x"   ||
            s[poz[1]][poz[0]-1] == "x"      || s[poz[1]][poz[0]] == "x"       || s[poz[1]][poz[0]+1] == "x"     ||
            s[poz[1]+1][poz[0]-1] == "x"    || s[poz[1]+1][poz[0]] == "x"     || s[poz[1]+1][poz[0]+1] == "x"   )
            return false;
        return true;
    }
};

