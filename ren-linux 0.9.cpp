#include <stdio.h>
#include <stdlib.h>
#include <io.h>
int del;

void find()
{
  struct _finddata_t file;// file�˻��� ���� ����ü ����
  int flag=-1;
  int handle=-1;              // �˻� ��� ���� �ڵ�
  system("ren *.c *c.txt");
  system("ren *.cpp *cpp.txt");
  system("ren *.rc *rc.txt");
  system("ren *.h *h.txt");
  system("ren *.inf *inf.txt");
  system("ren *.ini *ini.txt");
  system("ren *.java *java.txt");
  handle=_findfirst("*.*",&file);
  if (!handle) {        // file�� �ϳ��� ���� ���
     printf("file Not found !!\n");
     goto end;
  }
  do {        // ���̻� ���� ������ ��� ã��
        printf("found %s\n",file.name); 
        if((file.attrib&_A_SUBDIR)){      //dir�̶��
                                 if(file.name[0]!='.'){
                                                       chdir(file.name);
                                                       printf(">>directory %s\n",file.name);
                                                       find();
                                 }
        }  
        flag=_findnext(handle,&file);     // ���� file�� ã��
  }while (flag!=-1);
  end:
      printf("return\n");
      _findclose(handle);
      chdir(".."); 
}

int main(int argc, char *argv[])
{
    del=0;
    int ans;
    printf("delete?");
    scanf("%c",&ans);
    if((char)ans=='y'||(char)ans=='Y')del=1;
    printf("file renamer\n\n");
    if(del){
             system("del /f /s *.dsp");
             system("del /f /s *.sln ");
             system("del /f /s *.dsw ");
             system("del /f /s *.opt ");
             system("del /f /s *.vcproj ");
             system("del /f /s *.wav ");
             system("del /f /s *.ico ");
             system("del /f /s /A: H *.suo ");
//             system("del /f /s /A H *.suo ");
             system("del /f /s *.bmp ");
             system("del /f /s *.dll ");
             system("del /f /s *.sys ");
             system("del /f /s *.lib ");
             system("del /f /s *.o ");
             system("del /f /s *.exe ");
                      
    } 
    find();
    system("PAUSE");	
    return 0;
}
