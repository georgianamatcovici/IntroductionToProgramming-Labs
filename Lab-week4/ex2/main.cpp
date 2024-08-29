#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
ifstream fin("f.in.ads");

char s[300];


int main()
{int i;
char *p;
int ok=1;
while(fin.getline(s, 256))
{
p=strchr(s, '<');
while(p!=NULL && ok)
{if(p[1]=='b' || p[1]=='i' || p[1]=='u' || p[1]=='/' && p[2]=='>')
{i=3;
while(p[i]!='/') i++;
i+=2;
strcpy(p, p+i+1);
p=strchr(p, '<');
}

else p=strchr(p+1, '<');
}

cout<<s<<endl;
}





    return 0;
}
