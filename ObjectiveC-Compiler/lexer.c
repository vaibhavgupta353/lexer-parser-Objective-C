#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

#define D *ch>='0' && *ch<='9'
#define L *ch>='a' && *ch<='z'|| *ch>='A' && *ch<='Z'

// file pointers
FILE* in_file;
FILE* out_file;

char input[200];
char* ch;
char* start = NULL;
char* current = NULL;
int j=0;
int state = 0;
int single_token_flag = 0;
int keyword_token_flag = 0;
int id_int_float_flag = 0;

char *keyword[100]={"printf","main","NSString","if","else","while","return","for","break","goto","switch","int","float","char","case","continue","long long","double","long","unsigned int","unsigned","long long int","long int"};
void init_file(){
	
	in_file = fopen("input.c","r");
	out_file = fopen("output.txt","w");
	
	if (in_file == NULL || out_file == NULL) {
		printf("file initialization error\n");
	}
}


int get_next_state(char* ch, int state)
{
	int next_state = 0;
	//printf("hi%s\n",ch);
	while(*ch!='\0' && *ch!='\n')
	{
				char buffer[100];
				int i=0,k=0;
				char *temp=ch;
				int flag=0,flag1=0;
				for(k=0;k<100;k++)
					buffer[k]='\0';
				//printf("%d\n",next_state);
	switch (next_state)
	{
		case 0: if (*ch == '=') {
					next_state =1;
				}
				else if (*ch == '!') {
					next_state =3;
				}
				else if (*ch == '>') {
					next_state =5;
				}
				else if (*ch == '<') {
					next_state =7;
				}
				else if (*ch == '|') {
					next_state = 14;
				}
				else if (*ch == '&') {
					next_state = 16;
				}
				else if (*ch == '+') {
					next_state = 9;
					
				}
				else if (*ch == '-') {
					next_state = 10;
				}
				else if (*ch == '*') {
					next_state = 11;
				}
				else if (*ch == '/') {
					next_state = 12;
				}
				else if (*ch == '%') {
					next_state = 13;
				}
				else if (*ch == ',') {
					next_state = 23;
				}
				else if (*ch == '(') {
					next_state = 24;
				}
				else if (*ch == ')') {
					next_state = 25;
				}
				else if (*ch == '[') {
					next_state = 26;
				}
				else if (*ch == ']') {
					next_state = 27;
				}
				else if (*ch == '{') {
					next_state = 29;
				}
				else if (*ch == '}') {
					next_state = 28;
				}
				else if (*ch == ';') {
					next_state = 30;
				}
				else if (L) {
					flag1=1;
					next_state = 22;
				}
				else if(*ch=='\"')
				{
					next_state=31;
				}
                else if(*ch=='@')
                {
                	next_state=60;
                }
                else if(*ch=='#')
                {
                	next_state=61;
                }
				else if(D)
				{
					next_state=34;
				}

				else if(*ch=='.'){
					next_state=35;
				}
				break;

		case 1: if (*ch == '=') {
					next_state=2;
				}
				else {
					flag1=1;
					fprintf(out_file,"%s %d\n", "EQ", next_state);
					next_state =0;
				}
				break;
		case 2: fprintf(out_file,"%s %d\n", "EQQ", next_state);
				next_state =0;
				flag1=1;
				break;
		case 3: if (*ch == '=') {
					next_state=4;
				}
				else {
					flag1=1;
					fprintf(out_file,"%s %d\n", "NOT", next_state);
					next_state =0;
				}
				break;
		case 4: fprintf(out_file,"%s %d\n", "NQ", next_state);
				next_state =0;
				flag1=1;
				break;
		case 5: if (*ch == '=') {
					next_state=6;
				}
				else {
					flag1=1;
					fprintf(out_file,"%s %d\n", "GR", next_state);
					next_state =0;
				}
				break;
		case 6: fprintf(out_file,"%s %d\n", "GRE", next_state);
				next_state =0;
				flag1=1;
				break;
		case 7: if (*ch == '=') {
					next_state=8;
				}
				else {
					flag1=1;
					fprintf(out_file,"%s %d\n", "LE", next_state);
					next_state =0;
				}
				break;
		case 8: fprintf(out_file,"%s %d\n", "LEE", next_state);
				next_state =0;
				flag1=1;
				break;
		case 9: fprintf(out_file,"%s %d\n", "PLUS", next_state);
				next_state =0;
				flag1=1;
				break;
		case 10: fprintf(out_file,"%s %d\n", "MINUS", next_state);
				next_state =0;
				flag1=1;
				break;
		case 11: fprintf(out_file,"%s %d\n", "MUL", next_state);
				next_state =0;
				flag1=1;
				break;
		case 12: if (*ch ==  '*') {
					next_state = 18;
				}
				else if (*ch == '/' ) {
					next_state = 20;
				}
				else {
					fprintf(out_file,"%s %d\n", "DIV", next_state);
					flag1=1;
					next_state =0;
				}
				break;
		case 13: fprintf(out_file,"%s %d\n", "MOD", next_state);
				next_state =0;
				flag1=1;
				break;
		case 14:if (*ch ==  '|') {
					next_state = 15;
				}
				else {
					next_state =0;
				}
				break;
		case 16:if (*ch ==  '&') {
					next_state = 17;
				}
				else {
					next_state =0;
				}
				break;
		case 15:fprintf(out_file, "%s %d\n", "OR", next_state);
				next_state =0;
				flag1=1;
				break;
		case 17:fprintf(out_file, "%s %d\n", "AND", next_state);
				next_state =0;
				flag1=1;
				break;
		case 18:if (*ch != '*') {
					next_state = 18;
				}
				else {
					next_state = 19;
				}
				break;
		case 19:next_state = 0;
				break;
		case 20:if (*ch != '\n') {
					next_state = 20;
				}
				else {
					next_state =21;
				}
				break;
		case 21:next_state=0;
				break;
		case 22:
				i=0;	
				while(*ch!=' ' && *ch!='\n'&& *ch!='\0'&&*ch!='\t')
				{
					//printf("%c\nhi",*ch );
					buffer[i]=*ch;
					i++;
					
					ch++;
				
					if((!(L) && !(D) && *ch!='_'))
						{	flag1=1;
							//printf("45%s\n",buffer );
						break;
					}
				}
				
				for(i=0;i<20;i++)
				{
					if(strcmp(buffer,keyword[i])==0)
					{
						fprintf(out_file,"%s %d\n", buffer, next_state);
						flag=1;
						next_state=0;
					}

				}

				if(flag==0)
				{
					//printf("vahscv");
					ch=temp;
					printf("%c\n",*ch);
					next_state=33;
				}
				break;
		case 23:fprintf(out_file,"%s %d\n", "COMMA", next_state);
				next_state=0;
				flag1=1;
				break;

		case 24:fprintf(out_file,"%s %d\n", "BRAC_OP", next_state);
				next_state=0;
				flag1=1;
				break;		
		case 25:fprintf(out_file,"%s %d\n", "BRAC_CL", next_state);
				next_state=0;
				flag1=1;
				break;

		case 26:fprintf(out_file,"%s %d\n", "SQBRAC_OP", next_state);
				next_state=0;
				flag1=1;
				break;
		
		case 27:fprintf(out_file,"%s %d\n", "SQBRAC_CL", next_state);
				next_state=0;
				flag1=1;
				break;

		case 28:fprintf(out_file,"%s %d\n", "CURLBRAC_CL", next_state);
				next_state=0;
				flag1=1;
				break;		

		case 29:fprintf(out_file,"%s %d\n", "CURLBRAC_OP", next_state);
				next_state=0;
				flag1=1;
				break;						

		case 30:fprintf(out_file,"%s %d\n", "SEMICOL", next_state);
				next_state=0;
				flag1=1;
				break;
				
		case 31:
				if(*ch!='\"')
					next_state=31;
				else
					next_state=32;
				break;
		case 32:fprintf(out_file,"%s %d\n", "STRING", next_state);
				next_state=0;
				flag1=1;
				break;

		case 33:if(L)
				next_state=39;

				else if(D)
				{
					next_state=40;
				}		

				else if(*ch=='_')
					next_state=41;

				else {
					fprintf(out_file,"%s %d\n", "ID", next_state);
					next_state=0;
					flag1=1;
				}
					break;
		case 39:if(L)
				next_state=39;

				else if(D)
				{
					next_state=40;
				}		

				else if(*ch=='_')
					next_state=41;

				else {
					fprintf(out_file,"%s %d\n", "ID", next_state);
					next_state=0;
					flag1=1;
				}
					break;
				
		case 40:if(L)
				next_state=39;

				else if(D)
				{
					next_state=40;
				}		

				else if(*ch=='_')
					next_state=41;

				else {
					fprintf(out_file,"%s %d\n", "ID", next_state);
					next_state=0;
					flag1=1;
				}
					break;
					
		case 41:if(L)
				next_state=39;

				else if(D)
				{
					next_state=40;
				}		

				else if(*ch=='_')
					next_state=41;

				else{ 
					fprintf(out_file,"%s %d\n", "ID", next_state);
					next_state=0;
					flag1=1;
				}
					break;
					
		case 34:if(D)
			next_state=34;

			else if(*ch=='.')
				next_state=35;

			else
			{
					fprintf(out_file,"%s %d\n", "INT_LITERAL", next_state);
					next_state=0;
					flag1=1;
			}

			break;
		case 35:if(D)
			next_state=36;
			break;

		case 36:if(D)
			next_state=36;

			else{
				fprintf(out_file,"%s %d\n", "FLOAT_LITERAL", next_state);
					next_state=0;
					flag1=1;
			}
			break;
        case 60:fprintf(out_file,"%s %d\n", "@", next_state);
				next_state=0;
				flag1=1;
				break;
		case 61:fprintf(out_file,"%s %d\n", "#", next_state);
				next_state=0;
				flag1=1;
				break;
																	


	}
	printf("state=%d\n",next_state);
	if(!flag1)
	ch++;
	printf("%c This is c\n",*ch );
}

}


int main()
{
	init_file();
   	char readinp[100];
	while(fgets(readinp,100,in_file)!=NULL)
	{
		//printf("%s\n",readinp);
		int st=get_next_state(readinp,0);
		//printf("%s\n",readinp);
	}



	return 0;
}
