/*
 AdjacencyList.hpp
 Graphs
 
 Copyright � 2018  Dominik Witczak & Krzysztof Sychla
 
 This program is free software : you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <iostream>
#include <list>
#include <stack>


class AdjacencyList {
    friend class GraphMatrix;
private:
    std::list<int> *lists;
    int size;
    
    std::stack<int> temp_euler;
    std::list<int> sol_euler;
    
    int *visited;
    int *predecessors;
    int *sorted;
    
protected:
public:
    AdjacencyList(int **tab, int _size, int which);
    void initialize(int ** tab, int _size, int which);
    AdjacencyList(int tab[6][6], int _size, int which);
    AdjacencyList(int *tab, int size_of_tab, int _size);
    ~AdjacencyList();
    
    bool check(int i);
    
    void DFS(int i, int &idx);
    void sortDFS();
    void sortBFS();
    
    void print_list();
    
    std::list<int>::iterator firstOnTheList(int whichList);
    std::list<int>::iterator lastOnTheList(int whichList);
    std::list<int>::iterator nextOnTheList(int whichList);
    
    bool connected(int a, int b);
    int getv(std::list<int>::iterator p) { return *&*p; }
    
    void Hamilton(int i,bool boo);
    void Euler(int v);
    
    int type;
    enum {
        NEXT,
        PREV,
        NOINCIDENCY
    };
};
