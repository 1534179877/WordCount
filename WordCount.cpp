#include <stdio.h>
#include <string.h>

int *TXTCount(char *filename, char *w);

int main(){
    char filename[30];
	char w[5];
	
    printf("Input file name &&input count way:(input -c 字符数 or  -w 单词数)\n ");
    scanf("%s %s",&w,filename);
	
	TXTCount(filename, w);
    return 0;
}



int *TXTCount(char *filename, char *w ){
	FILE  *f;//文件指针
	char buffer[1003];
	int bufferL;
	int i;
	char c;
	int blank = 0;
	int charnum = 0;
	int wordnum = 0;//每一行的字符数，单词数
	int CharNum = 0;
	int WordNum = 0;//总的字符数，单词数

	if((f=fopen(filename,"rb"))==NULL){
		perror(filename);//读取路径下的文本文件  输出错误
		return NULL;
	}
	while(fgets(buffer,1003,f)!=NULL){
		bufferL = strlen(buffer);//遍历缓冲区
	for(i=0; i<bufferL; i++){//遇到空格
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
	!blank&&wordnum++;//最后一个字符不是空格
	blank=1;
		
	CharNum +=charnum;
	WordNum +=wordnum;

	charnum = 0;
    wordnum = 0;

	}

	if(strcmp(w,"-c")==0){
		printf("字符数：%d\n",CharNum);
	}
	else {
		printf("单词数：%d\n",WordNum);
	}

	return 0;
}
