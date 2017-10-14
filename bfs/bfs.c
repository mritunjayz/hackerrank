#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define max 1001
int stack[max];
int pushin=0,popout=0;
 void push(int data){
     stack[pushin]=data;
     pushin++;
 }
int pop(){
    int re;
    if(popout>=pushin)return -100;
   re=stack[popout];
    popout++;
    return re;
}

int main() {
    int q; 
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        int n; 
        int m; 
        scanf("%i %i", &n, &m);
        int edl[m],edr[m];
        for(int a1 = 0; a1 < m; a1++){
            int u; 
            int v; 
            scanf("%i %i", &u, &v);
            edl[a1]=u;
            edr[a1]=v;
        }
        int s; 
        scanf("%i", &s);
        
        int r=n+1;
        int a[r];
        for(int i=0;i<r;i++)a[i]=0;
        
        
        for(int i=0;i<m;i++){
            if(edl[i]==s){
                push(edr[i]);
                a[edr[i]]=6;
            }
            if(edr[i]==s){
                push(edl[i]);
                a[edl[i]]=6;
            }
            
        }
        while(1){
            int get=pop();
            if(get==-100)break;
            for(int i=0;i<m;i++){
            if(edl[i]==get){
                if(a[edr[i]]==0){
                push(edr[i]);
                a[edr[i]]=a[get]+6;
                }
            }
            if(edr[i]==get){
                if(a[edl[i]]==0){
                push(edl[i]);
                a[edl[i]]=a[get]+6;
            }}}
        }
        for(int i=1;i<r;i++){if(i!=s){if(a[i]==0)printf("-1 ");else printf("%d ",a[i]);}}
        printf("\n");
    }
    return 0;
}
