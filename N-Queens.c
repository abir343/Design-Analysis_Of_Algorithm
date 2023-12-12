#include<stdio.h>
#include<math.h>

int board[20],count;

void Print(int n) {
    int i,j;
    printf("\n\nSolution %d : \n\n",++count);

    for(i=1;i<=n;++i)
        printf("\t%d",i);
    for(i=1;i<=n;++i) {
        printf("\n\n%d",i);
        for(j=1;j<=n;++j) { //for nxn board
            if(board[i]==j)
                printf("\tQ"); //queen at i,j position
            else
                printf("\t-"); //empty slot
        }
    }
}

int IsPlacable(int row,int column) {
    int i;
    for(i=1;i<=row-1;++i) {
        //checking column and digonal conflicts
        if(board[i]==column)
            return 0;
        else
            if(abs(board[i]-column)==abs(i-row))
                return 0;
    }
    return 1; //no conflicts
}

void Queen(int row,int n) {
    int column;
    for(column=1;column<=n;++column) {
        if(IsPlacable(row,column)) {
            board[row]=column; //no conflicts so place queen
            if(row==n) //dead end
                Print(n); //printing the board configuration
            else //try queen with next position
                Queen(row+1,n);
        }
    }
}

int main() {
    int n,i,j;
    void Queen(int row,int n);
    printf("\nEnter number of Queens : ");
    scanf("%d",&n);
    Queen(1,n);
    return 0;
}

