#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;



int main()
{char s[300], *p, aux[300], sufix[300], prefix[300], aux1[300];
cin.getline(s, 300);
int i, j, k, suf, pref;
suf=0; pref=0;
int ok;
aux[0]=0;
strcat(aux, s);
//cout<<aux;
strrev(aux);
if(strcmp(aux, s)==0) cout<<s<<' '<<s;
else{
for(i=1; i<strlen(s); i++)
{aux[0]=0;
strncat(aux, s, i);

ok=1;
/*for(j=0, k=strlen(aux)-1; j<k && ok; j++, k--)
    if(aux[i]!=aux[j]) ok=0;*/
strcpy(aux1, aux);
strrev(aux);
if(strcmp(aux, aux1)==0){
    if(strlen(aux)>pref) {
            strcpy(prefix, aux); pref=strlen(aux);}
}
strcpy(aux, s+i);

ok=1;
/*for(j=0, k=strlen(aux)-1; j<k && ok; j++, k--)
    if(aux[i]!=aux[j]) ok=0;*/
        strcpy(aux1, aux);
    strrev(aux);
if(strcmp(aux1, aux)==0){
    if(strlen(aux)>suf) {strcpy(sufix, aux); suf=strlen(aux);}

}
}

cout<<prefix<<' '<<sufix;

}

    return 0;
}
