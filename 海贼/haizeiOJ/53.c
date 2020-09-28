/*************************************************************************
	> File Name: 53.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年03月29日 星期日 21时11分57秒
 ************************************************************************/
#include<stdio.h>
#include<math.h>
int is_prime[2000000] = {1,1,0};
int prime[2000000]={0};
long long f[2000000];
void init() {
  for(int i = 2;i < 2000000;++i){
    if(!is_prime[i]){
      prime[++prime[0]] = i;  
      f[i] = i + 1;
    }
    for (int j = 1; j < prime[0];++j) {
      if(i * prime[j] > 2000000)
      break;
      is_prime[prime[j] * i] = 1;
      if (i % prime[j] == 0){
        int a = i,cnt = 0;
        while(a % prime[j]== 0){
          a /= prime[j];
          ++cnt;
        } 
        f[prime[j] * i] = f[i] * ( 1 -  pow(prime[j],cnt + 2))/(1 -  pow(prime[j],cnt + 1));
        break;
      }
      else
      {
        f[prime[j] * i] = f[i] * f[prime[j]];
      }
      
    }
  }
}
int main(){
  init();
  long long ans = 0 ;
  for(int a = 1; a < 1000001 ; ++a ){
  //  long long ans = 0 ;
    if(f[a] > ans){ 
      ans  = f[a];
      }      
  }
  printf("%lld\n",ans);
//  printf("%d"， f[25]);
  return 0;
}
