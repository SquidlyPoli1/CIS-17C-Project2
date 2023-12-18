/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   score.h
 * Author: SquidlyPoli1
 *
 * Created on December 15, 2023, 3:51 PM
 */

#ifndef SCORE_H
#define SCORE_H

#include <list>
#include <string>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

struct top_plyr {
    string initials;
    int score;
};

class score {
    private:
        int hash_inits(string topt) {
            int ret = 0,rettou = 0;
            for (int i = 0; i < 3; i++) {
                if (toupper(topt[i]) == 'A' || toupper(topt[i]) == 'B' || toupper(topt[i]) == 'C')
                    rettou = 2;
            	else if (toupper(topt[i]) == 'D' || toupper(topt[i]) == 'E' || toupper(topt[i]) == 'F')
                    rettou = 3;
            	else if (toupper(topt[i]) == 'G' || toupper(topt[i]) == 'H' || toupper(topt[i]) == 'I')
                    rettou = 4;
            	else if (toupper(topt[i]) == 'J' || toupper(topt[i]) == 'K' || toupper(topt[i]) == 'L')
                    rettou = 5;
        	else if (toupper(topt[i]) == 'M' || toupper(topt[i]) == 'N' || toupper(topt[i]) == 'O')
                    rettou = 6;
        	else if (toupper(topt[i]) == 'P' || toupper(topt[i]) == 'Q' || toupper(topt[i]) == 'R' || toupper(topt[i]) == 'S')
                    rettou = 7;
        	else if (toupper(topt[i]) == 'T' || toupper(topt[i]) == 'U' || toupper(topt[i]) == 'V')
                    rettou = 8;
        	else if (toupper(topt[i]) == 'W' || toupper(topt[i]) == 'X' || toupper(topt[i]) == 'Y' || toupper(topt[i]) == 'Z')
                    rettou = 9;
        	else rettou = 0;
                ret += rettou * pow(10,2-i);
            }
            return ret % 15;
        }
        top_plyr make_plyr(string init,int scr) {
            top_plyr ply;
            ply.initials = init;
            ply.score = scr;
            return ply;
        }
    public:
        list<top_plyr> board [15];
        void add_plyr(string,string,int);
        void disp_board();
        void printGraph();
        void save_board();
        int max_scor();
        score();
};

#endif /* SCORE_H */

