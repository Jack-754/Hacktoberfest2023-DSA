
#include <stdio.h>
#include <string.h>
#define maxlen 10000

//The dp array. The dp array size can be changed on requirement by changing the macro maxlen
int dp[maxlen][maxlen];

//A function to compare two integers and return the maximum value
int max(int m, int n){
    if(m>n)return m;
    else return n;
}

//A function which fills the dp array 
int solve(char s1[], char s2[]){
    int i, j;
    int n=strlen(s1), m=strlen(s2);
    for(i=0; i<=n; i++){
        for(j=0; j<=m; j++){
            if(i==0||j==0)dp[i][j]=0;
            else dp[i][j]=-1;
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

//A function which will use the calculated dp array to find the actual longest common subsequence
void realsolver(char s1[], char s2[], char soln[]){
    int i, j, n=strlen(s1), m=strlen(s2), idx=0;
    i=n;
    j=m;
    while(i>0&&j>0){
        if(s1[i-1]==s2[j-1]){
            soln[idx]=s1[i-1];
            idx++;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]==dp[i][j])i--;
            else j--;
        }
    }
}

int main(){
    char s1[maxlen], s2[maxlen];
    printf("Enter the first string: ");
    scanf(" %s", s1);
    printf("Enter the second string: ");
    scanf(" %s", s2);
    int len=solve(s1, s2);
    char sol[len];
    realsolver(s1, s2, sol);
    printf("\nThe longest common subsequence is : ");
    for(int i=len-1; i>=0; i--)printf("%c", sol[i]);
    printf("\n");

    return 0;
}