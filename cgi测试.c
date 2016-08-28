#include <stdio.h>  
#include <stdlib.h> //必要的头文件  
int main(void){  
        int len;  
        char *lenstr,poststr[20];  
        char m[10],n[10];  
        printf("Content-Type:text/html/n/n");  
        printf("<HTML>/n");  
        printf("<HEAD>/n<TITLE >post Method</TITLE>/n</HEAD>/n");  
        printf("<BODY>/n");  
        printf("<div style="/" mce_style="/""font-size:12px/">/n");  
        lenstr=getenv("CONTENT_LENGTH");//CONTENT_LENGTH这 是 使 用 者 输 入 资 料 的 长 度 。  
        if(lenstr == NULL)  
                printf("<DIV STYLE="/" mce_STYLE="/""COLOR:RED/">Error parameters should be entered!</DIV>/n");  
        else{  
                len=atoi(lenstr);  
                fgets(poststr,len+1,stdin);//这里是吧从HTML传输过来的内容读取出来放到poststr中；  
                if(sscanf(poststr,"m=%[^&]&n=%s",m,n)!=2){//有关sscanf()会在下面说明  
                        printf("<DIV STYLE="/" mce_STYLE="/""COLOR:RED/">Error: Parameters are not right!</DIV>/n");  
                }  
                else{  
                       printf("<DIV STYLE="/" mce_STYLE="/""COLOR:GREEN; font-size:15px;font-weight:bold/">m * n = %d</DIV>/n",atoi(m)*atoi(n));  
                }  
        }  
        printf("<HR COLOR=/"blue/" align=/"left/" width=/"100/">");  
        printf("<input type=/"button/" value=/"Back CGI/" onclick=/"<a href="http://lib.csdn.net/base/javascript" class='replace_word' title="JavaScript知识库" target='_blank' style='color:#df3434; font-weight:bold;'>JavaScript</a>:window.location='../cgi.html'/">");//这里是返回的位置  
        printf("</div>/n");  
        printf("</BODY>/n");  
        printf("</HTML>/n");  
        fflush(stdout);  
        return 0;  
}   
  