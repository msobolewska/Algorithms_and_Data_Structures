#include <stdio.h>
#include <iostream>

int Solve_Puzzle(char Table[10][10], int i_1, int j_1, char Words[10][10], int Length[10], int IsInserted[10]);
int InsertWord(char Table[10][10], char Words[10][10], int Length[10], int IsInserted[10], int i, int j, int k, int vertical);
int AllInserted(int Length[10], int IsInserted[10]);

int main(){
    FILE * file;
    file=fopen("Crossword_Puzzle.txt","r");
    if(!file){
        return 0;
    }

    char Table[10][10];
    char Words[10][10];
    int Length[10];
    int IsInserted[10];

    for(int i = 0;i<10;i++){
        for(int j = 0; j < 9; j++){
            fscanf(file, "%c", &Table[i][j]);
        }
        fscanf(file, "%c ", &Table[i][9]);
    }

    for(int i = 0;i<10;i++){
        for(int j = 0; j < 10; j++){
            printf("%c", Table[i][j]);
        }
        printf("\n");
    }

    int temp1;
    std::string help;

    std::cin>>help;

    unsigned int k = 0;

    for(int i = 0;i<10 && k<help.length();i++){
        IsInserted[i] = 0;
        temp1 = 0;
        char temp_c;
        for(int j = -1; temp1 != 1 && j < 10 && k<help.length()+1; j++, k++){
            if(j != -1){
                Words[i][j] = temp_c;
                printf("%c", Words[i][j]);
            }
            temp_c = help[k];
            temp1 = (int)(temp_c == ';');
            Length[i] = j+1;
            }
        printf("%d\n", Length[i]);
        temp1 = 0;
    }

    if(!Solve_Puzzle(Table, 0, 0, Words, Length, IsInserted)){
        return 0;
    }

    for(int i = 0;i<10;i++){
        for(int j = 0; j < 10; j++){
            printf("%c", Table[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int Solve_Puzzle(char Table[10][10], int i_1, int j_1, char Words[10][10], int Length[10], int IsInserted[10]){
    for(int i = i_1; i < 10; i++){
        for(int j = j_1; j < 10; j++){
            //printf("%c\n", Table[i][j]);
            if(Table[i][j] == '-'){
                for(int k = 0; k<10; k++){
                    if(Length[k] != 0){
                        int PreviousTable[10][10];
                        for(int i_2 = 0; i_2 < 10; i_2++){
                            for(int j_2 = 0; j_2 < 10; j_2++){
                                PreviousTable[i_2][j_2] = Table[i_2][j_2];
                            }
                        }
                        if(InsertWord(Table, Words, Length, IsInserted, i, j, k, 0)){
                            if(AllInserted(Length, IsInserted)){
                                return 1;
                            }
                        else if(!Solve_Puzzle(Table, i, j, Words, Length, IsInserted)){
                            for(int i_2 = 0; i_2 < 10; i_2++){
                                for(int j_2 = 0; j_2 < 10; j_2++){
                                    Table[i_2][j_2] = PreviousTable[i_2][j_2];
                                }
                            }
                            IsInserted[k] = 0;
                        }
                        else{
                            return 1;
                        }
                    }
                    if(InsertWord(Table, Words, Length, IsInserted, i, j, k, 1)){
                        if(AllInserted(Length, IsInserted)){
                                return 1;
                        }
                        else if(!Solve_Puzzle(Table, i, j, Words, Length, IsInserted)){
                            for(int i_2 = 0; i_2 < 10; i_2++){
                                for(int j_2 = 0; j_2 < 10; j_2++){
                                    Table[i_2][j_2] = PreviousTable[i_2][j_2];
                                }
                            }
                            IsInserted[k] = 0;
                        }
                        else{
                            return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int InsertWord(char Table[10][10], char Words[10][10], int Length[10], int IsInserted[10], int i_1, int j_1, int k, int vertical){
    if(!IsInserted[k]){
        int i=i_1;
        int j=j_1;
        int length = Length[k];
        int end = 0;
        int count=0;
        int starting_position;
        if(vertical == 1){
            starting_position=i;
            while(starting_position-1>=0 && Table[starting_position-1][j] != '+'){
                starting_position--;
            }

            i = starting_position;
            while(i<10 && !end){
                if(Table[i][j] == '-' || Table[i][j] == Words[k][i-starting_position]){
                    count++;
                }
                else{
                    end = 1;
                }
                i++;
            }
            if(count == length){
                for(i=starting_position; i< starting_position+length; i++){
                    Table[i][j] = Words[k][i-starting_position];
                }
                IsInserted[k] = 1;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            starting_position=j;
            while(starting_position-1>=0 && Table[i][starting_position-1] != '+'){
                starting_position--;
            }

            j=starting_position;
            while(j<10 && !end){
                if(Table[i][j] == '-' || Table[i][j] == Words[k][j-starting_position]){
                    count++;
                }
                else{
                end = 1;
                }
                j++;
            }
            if(count == length){
                for(j=starting_position; j< starting_position+length; j++){
                    Table[i][j] = Words[k][j-starting_position];
                }
                IsInserted[k] = 1;
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    else{
        return 0;
    }
}

int AllInserted(int Length[10], int IsInserted[10]){
    int temp = 1;
    int i = 0;
    while(temp && i<10){
        if(IsInserted[i] == 0 && Length[i] != 0){
                temp = 0;
        }
        //printf("%d %d\n", IsInserted[i], Length[i]);
        i++;
    }
    return temp;
}
