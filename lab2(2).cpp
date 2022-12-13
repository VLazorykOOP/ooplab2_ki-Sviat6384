#include <fstream>
#include <iostream>
using namespace std;
int main(){
  char s[32][5],ch;
  char so[32][5];
  unsigned short sh_dat[128],sd2[128],r,w;
  char st[5];
  ifstream ifs("in.dat");
if (!ifs) {
cout << "File in.dat not open" << endl; return -1;
}
ofstream ofs("out.dat");
ofstream ofsb("outb.dat", ios::out | ios::binary);
unsigned short i, j, l, b, k, t;
for (i = 0;i < 32;i++)
{
ifs.get(s[i], 5, '\0'); ifs.get(ch);
}

j = 0;
for (i = 0;i < 32; i++)
    for (l = 0;l < 4; l++)
{
r = i; // 0000 0000 0000 0___ <- i
w = l << 2;
r |= w; // 0000 0000 00__ _000 <- l
b = 0; t = 1;
if (b) r |= w; // 0000 0000 0_000 0000 <- b
w = s[i][l];
w <<= 7;
r |= w;
if (r & 0x4000) r |= 0x8000;
sh_dat[j] = r; 
j++;
ofs << hex<<r<<' ';
cout << hex << r << endl;

}
ofsb.write((char*)sh_dat, 128 * sizeof(unsigned short));
ofsb.close();
ifs.close();
//for (i = 0;i < 64;i++) sh_dat[i] = 0;  
ifs.open("outb.dat", ios::in | ios::binary);
ifs.read((char*)sd2, 128 * sizeof(unsigned short));
short indi, indj;
for (i = 0;i < 128;i++){
  r = sd2[i];
  indj = r & 0x0038;
  indj >>= 5; 
  indi = r&0x0007; 
  w = r&0x7f80; 
  w >>= 7;
  ch = w;
  so[indi][indj]=ch;
  }
  for (i = 0;i < 32; i++) {
for (l = 0;l < 4; l++)
cout << so[i][l];
cout << endl;
    }
  return 0 ;
  }
