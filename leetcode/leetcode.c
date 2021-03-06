int longestArithSeqLength(int* A, int ASize){
    if (!A) return 0;
    int min=A[0], max=A[0];
    for (int i=0; i<ASize; i++){
        if (A[i]<min) min=A[i];
        if (A[i]>max) max=A[i];
    }
    int tmp=max-min;
    
    int map[ASize][2*tmp+1];
    memset(map, 0, sizeof(map[0][0]) * ASize * (2*tmp+1));

    int res=0;
    
    for (int i=0; i<ASize; i++){
        for (int j=0; j<i; j++){
            int diff=A[i]-A[j]+tmp;
            map[i][diff]=map[j][diff]+1;
            if (map[i][diff]>res)
                res=map[i][diff];
        }
    }
    return res+1;
}
