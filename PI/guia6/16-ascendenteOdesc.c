#define FILS 3
#define COLS 4
int ascendenteODescendente(const int (m[])[COLS]){
    int asc = 1, desc=-1;
    int previo = m[0][0];

    for(int i=0; i<FILS && (asc==1 || desc==-1); i++){
        for(int j = 0; j<COLS; j++){
            if (m[i][j]<previo){
                asc = 0;
            } else if (m[i][j]>previo){
                desc = 0;
            }
            previo = m[i][j];
        }
    }
    if(asc==1) {return asc;}
    else return desc;
}