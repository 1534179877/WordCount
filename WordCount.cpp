#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[] ){
	FILE  *f;//�ļ�ָ��
	char buffer[1003];
	int bufferL;
	int i;
	char c;
	int blank = 0;
	int charnum = 0;
	int wordnum = 0;//ÿһ�е��ַ�����������
	int CharNum = 0;
	int WordNum = 0;//�ܵ��ַ�����������

	if((f=fopen(argv[2],"rb"))==NULL){
		perror(argv[2]);//��ȡ·���µ��ı��ļ�  �������
		return NULL;
	}
	while(fgets(buffer,1003,f)!=NULL){
		bufferL = strlen(buffer);//����������
	for(i=0; i<bufferL; i++){//�����ո�
		c=buffer[i];
		if(c==' '||c=='\t'){
			!blank&&wordnum++;
			blank = 1;
			charnum++;
		}
		else{
			charnum++;
			blank=0;
		}
	}
	!blank&&wordnum++;//���һ���ַ����ǿո�
	blank=1;
		
	CharNum +=charnum;
	WordNum +=wordnum;

	charnum = 0;
    wordnum = 0;

	}

	if(strcmp(argv[1],"-c")==0){
		printf("�ַ�����%d\n",CharNum);
	}
	else {
		printf("��������%d\n",WordNum);
	}

	return 0;
}
