#include<cstdio>
using namespace std;
int main(){
int now,now1,now2,ans=0;
scanf("%d%d%d",&now2,&now1,&now);
while(now!=0){
if(now1>now&&now1>now2){
ans++;
}now2=now1;
now1=now;
scanf("%d",&now);}
printf("%d",ans);