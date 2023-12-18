/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "score.h"
#include <string>
#include <iostream>
#include <fstream>

void score::add_plyr(string inito, string initt, int scr) {
    int o = hash_inits(inito);
    int t = hash_inits(initt);
    
    board[o].push_back(make_plyr(initt,scr));
    board[t].push_back(make_plyr(inito,scr));
}

score::score() {
    ifstream inpoot;
    string nameo, namet;
    int score;
    
    inpoot.open("scores.txt");
    while(!inpoot.eof()) {
        inpoot >> nameo >> score >> namet;
        add_plyr(nameo,namet,score);
    }
}

int score::max_scor() {
    int max = 0;
    for(int i = 0; i < 15; i++) {
        for (top_plyr ite : board[i]) {
            for(int j = 0; j < i; j++) {
                if (ite.score > max) max = ite.score;
                else max = max;
            }
        }
    }
    return max;
}

// Print adjacency list representation of graph
void score::printGraph()
{
    string v;
    int w;
    for (int u = 0; u < 15; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = board[u].begin(); it!=board[u].end(); it++)
        {
            v = it->initials;
            w = it->score;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}