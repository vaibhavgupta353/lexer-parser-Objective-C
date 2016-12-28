#include <stdio.h>
#include<string.h>
void LIST1();
void IF();
void Stmts();
void Stmt();
void R();
void IF1();
void E();
void WHILE();
void ass();
void LIST();
void T();
void F();
void T1();
void A();
void F1();
void D();
void A1();
void X();
void B();
void C();
void B1();
void K();
void N();
void C1();
void M();
void G();
void D1();
void DEC();
void DEC1();
void LIST2();
void LIST3();
char st[1000];
FILE *f1;
int getNextToken()
{
	//printf("%s",st);
	int i;
	for(i=0;i<1000;i++)
		st[i]='\0';
	//printf("%s",st);
	if(fscanf(f1,"%s",st)==EOF)
		return 0;

}

int S()
{	

	//printf("hello");
	if(strcmp("int",st)==0)
	{
		getNextToken();
		getNextToken();		
	}

	else
	{
		printf("expected int, found %s\n",st);
			getNextToken();
			getNextToken();
	}

	if(strcmp("main",st)==0)
	{
		getNextToken();
		getNextToken();
		
	}

	else
	{
		printf("expected main, found %s\n",st);
			getNextToken();
			getNextToken();
	}

	if(strcmp("BRAC_OP",st)==0)
	{
		getNextToken();
		getNextToken();
	}

	else
	{
		printf("expected BRAC_OP, found %s\n",st);
			getNextToken();
			getNextToken();
	}

	

	if(strcmp("BRAC_CL",st)==0)
	{
		getNextToken();
		getNextToken();
	}

	else
	{
		printf("expected BRAC_CL, found %s\n",st);
			getNextToken();
			getNextToken();
	}

	if(strcmp("CURLBRAC_OP",st)==0)
	{
		getNextToken();
		getNextToken();
	}

	else
	{
		printf("expected CURLBRAC_OP, found %s\n",st);
			getNextToken();
			getNextToken();
	}
	//printf("Stmts->Stmt R|re\n");
	Stmts();

	if(strcmp("return",st)==0)
	{
		getNextToken();
		getNextToken();
	
		if(strcmp("INT_LITERAL",st)==0)
		{
			getNextToken();
			getNextToken();
		}
		if(strcmp("SEMICOL",st)==0)
		{
			getNextToken();
			getNextToken();	
		}
		else
		{
			printf("expected SEMICOL, found %s\n",st);
			//getNextToken();
			//getNextToken();
		}

	}

	if(strcmp("CURLBRAC_CL",st)==0)
	{
		getNextToken();
		getNextToken();
	}

	else
	{
		printf("expected CURLBRAC_CL, found %s\n",st);
			getNextToken();
			getNextToken();
	}

    if(st[0]!='\0')
    {
    	printf("extra tokens after closing main\n");
    	return 0;
    }
	printf("PARSING COMPLETE, WE ARE DONE HERE\n");
    
	return 0;
	
}

void Stmts()
{ //printf("hii\n");
		printf("Stmts->Stmt R\n");
		Stmt();
		printf("R\n");
	    	R();
	
}

void R()
{
	if(strcmp("if",st)==0 || strcmp("while",st)==0 || strcmp("ID",st)==0 || strcmp("int",st)==0 || strcmp("float",st)==0 || strcmp("char",st)==0 || strcmp("double",st)==0)
	{
		printf("R->Stmts\n");
		Stmts();
	}
	else
	{
		printf("R->null\n");
		return ;
	}
	// check for null  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}

void Stmt()
{
	if(strcmp("if",st)==0)
	{
		printf("Stmt->IF\n");
		IF();
	}
	else if(strcmp("while",st)==0)
		{
			printf("Stmt->WHILE\n");
			WHILE();
		}
	else if(strcmp("ID",st)==0)
		{
			printf("Stmt->ass\n");
			ass();
		}
	else if(strcmp("int",st)==0 || strcmp("float",st)==0 || strcmp("char",st)==0 || strcmp("double",st)==0 || strcmp("long",st)==0)
      {
      	printf("Stmt->DEC\n");
      	DEC();
      } 
    else if(strcmp(st,"NSString")==0)
    	{
    		printf("Stmt->DEC1\n");
    		DEC1();
    	}
   else
   	{
   		printf("expected if, while, ID, int or float, found %s\n",st);
		getNextToken();
		getNextToken();
   	}
}
void IF()
{
	if(strcmp("if",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected if, found %s\n",st);
		getNextToken();
		getNextToken();
	}

	if(strcmp("BRAC_OP",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected BRAC_OP, found %s\n",st);
		getNextToken();
		getNextToken();
	}
	printf("IF->if(E\n");
	E();
	if(strcmp("BRAC_CL",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected BRAC_CL, found %s\n",st);
		getNextToken();
		getNextToken();
	}
	if(strcmp("CURLBRAC_OP",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected CURLBRAC_OP, found %s\n",st);
		getNextToken();
		getNextToken();
	}
	printf("IF->if(E){Stmts\n");
	Stmts();
	if(strcmp("CURLBRAC_CL",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected CURLBRAC_CL, found %s\n",st);
		getNextToken();
		getNextToken();
	}
	//printf("IF1\n");
	printf("if(E){Stmts}IF1\n");
	IF1();
}
void IF1()
{
	if(strcmp("else",st)==0)
	{
		getNextToken();
		getNextToken();
	    if(strcmp("CURLBRAC_OP",st)==0)
		{
			getNextToken();
			getNextToken();
		}
		else
		{
			printf("expected CURLBRAC_OP, found %s\n",st);
			getNextToken();
			getNextToken();
		}
		printf("else{Stmts\n");
		Stmts();
		if(strcmp("CURLBRAC_CL",st)==0)
		{
			getNextToken();
			getNextToken();
		}
		else
		{
			printf("expected CURLBRAC_CLOSE, found %s\n",st);
			getNextToken();
			getNextToken();
		}
	}
	else
	{
		printf("IF1->null\n");
		return;
	}
	
}
void WHILE()
{
	if(strcmp("while",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected while, found %s\n",st);
		getNextToken();
		getNextToken();
	}
	if(strcmp("BRAC_OP",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected BRAC_OP, found %s\n",st);
		getNextToken();
		getNextToken();
	}
	printf("WHILE->while(E\n");
	E();

	if(strcmp("BRAC_CL",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected BRAC_CL, found %s\n",st);
		getNextToken();
		getNextToken();
	}
	if(strcmp("CURLBRAC_OP",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected CURLBRAC_OP, found %s\n",st);
		getNextToken();
		getNextToken();
	}
	printf("WHILE->while(E){Stmts\n");
	Stmts();
	if(strcmp("CURLBRAC_CL",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected CURLBRAC_CL, found %s\n",st);
		getNextToken();
		getNextToken();
	}
}

void DEC1()
{
	if(strcmp("NSString",st)==0)
	{
		getNextToken();
		getNextToken();
		printf("DEC1->TYPE LIST2\n");
		LIST2();
		if(strcmp(st,"SEMICOL")==0)
		{
			getNextToken();
			getNextToken();
		}
		else
		{
			printf("expected SEMICOL, found %s\n",st);
			//getNextToken();
			//getNextToken();
		}
	}
	else
	{
		printf("expected NSString, found %s\n",st);
		getNextToken();
		getNextToken();
	}
}

void LIST2()
{
	if(strcmp("#",st)==0)
	{
      getNextToken();
      getNextToken();
      if(strcmp(st,"ID")==0)
      {
      	getNextToken();
      	getNextToken();
      	printf("LIST2->#ID LIST3\n");
      	LIST3();
      }
      else
      {
      	printf("expected ID, found %s\n",st);
		getNextToken();
		getNextToken();
      }
	}
	else
	{
		printf("expected #, found %s\n",st);
		getNextToken();
		getNextToken();
	}
}

void LIST3()
{
	if(strcmp("COMMA",st)==0)
	{
		getNextToken();
		getNextToken();
		printf("LIST2\n");
		printf("LIST3->,LIST2\n");
		LIST2();
	}
	else
	{
		printf("LIST3->null\n");
		return;
	}
}

void ass()
{
	if(strcmp("ID",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected ID, found %s\n",st);
		getNextToken();
		getNextToken();
	}
	if(strcmp("EQ",st)==0)
	{
		getNextToken();
		getNextToken();				//SEGMENTATION FAULT after this
	}
	else
	{
		printf("expected EQ, found %s\n",st);
		getNextToken();
		getNextToken();
	}
	printf("ass->id=E\n");
	E();
	if(strcmp("SEMICOL",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected SEMICOL, found %s\n",st);
		//getNextToken();
		//getNextToken();
	}

}

void DEC()
{
	if(strcmp("int",st)==0 || strcmp("float",st)==0 || strcmp("char",st)==0 || strcmp("double",st)==0 || strcmp("long",st)==0)
	{
		getNextToken();
		getNextToken();
		printf("DEC->TYPE LIST\n");
		LIST();
		if(strcmp(st,"SEMICOL")==0)
		{
			getNextToken();
			getNextToken();
		}
		else
		{
			printf("expected SEMICOL, found %s\n",st);
			//getNextToken();
			//getNextToken();
		}
	}
	else
	{
		printf("expected int,float, char, double or long, found %s\n",st);
		getNextToken();
		getNextToken();
	}
}

void LIST()
{
	if(strcmp("ID",st)==0)
	{
		getNextToken();
		getNextToken();
	}
	else
	{
		printf("expected ID, found %s\n",st);
		getNextToken();
		getNextToken();
	}
	printf("LIST->ID LIST1\n");
	LIST1();	
}
void LIST1()
{
	if(strcmp("COMMA",st)==0)
	{
		getNextToken();
		getNextToken();
		printf("LIST1->,LIST\n");
		LIST();
	}
	else
	{
		printf("LIST1->null\n");
		return;
	}
}

void E()
{
	/*if(strcmp("ID",st)==0)
	{
		getNextToken();
		getNextToken();
	    if(strcmp("EQ",st)==0)
	    {
	     getNextToken();
		 getNextToken();
		 E();
	    }
	    else
	    {
	    	printf("E error\n");
	    }	
	}*/
		printf("E->T\n");
		T();
	
}

void T()
{
	printf("T->FT1\n");
   F();
   printf("T->FT1\n");
   T1();
}

void T1()
{
   if(strcmp("OR",st)==0)
   { 
   	 getNextToken();
   	 getNextToken();
     printf("T1->||FT1\n");
     F();
     printf("T1->||FT1\n");
     T1();
   }
   else{
   	printf("T1->null\n");
   	return ;
   }
   	
}

void F()
{
	printf("F->AF1\n");
	A();
	printf("F->AF1\n");
	F1();
}

void F1()
{
   if(strcmp("AND",st)==0)
   { 
   	 getNextToken();
   	 getNextToken();
     printf("F1->&& A F1\n");
     A();
     printf("F1->&& A F1\n");
     F1();
   }
   else
   {
   	printf("F->null\n");
   	return  ;	
	}
}

void A()
{
	printf("A->BA1\n");
	B();
	printf("A->BA1\n");
	A1();
}

void A1()
{
  if(strcmp("EQQ",st)==0 || strcmp(st,"NQ")==0)
   { 
   	printf("A1->XA1\n");
     X();
     printf("A1->XA1\n");
     A1();

   }
   else{
   	printf("A->null\n");
   	return ;
   }
}

void X()
{
   if(strcmp("EQQ",st)==0 || strcmp(st,"NQ")==0)
   { 
   	 getNextToken();
   	 getNextToken();
   	 printf("X->==B|X->!=B\n");
     B();
   }
   else
   {
   	 printf("expected EQQ or NQ, found %s\n",st);
   	 getNextToken();
   	 getNextToken();
   }
}

void B()
{
	printf("B->CB1\n");
	C();
	printf("B->CB1\n");
	B1();
}

void B1()
{
  if(strcmp("LE",st)==0 || strcmp(st,"LEE")==0 || strcmp(st,"GR")==0 || strcmp(st,"GRE")==0)
   { 
   	printf("B1->KB1\n");
   	 K();
   	 printf("B1->KB1\n");
   	 B1();
   }
   else
   {
   	printf("B1->null\n");
   	return ;
}
}

void K()
{
	if(strcmp("LE",st)==0 || strcmp(st,"LEE")==0 || strcmp(st,"GR")==0 || strcmp(st,"GRE")==0)
   { 
   	 getNextToken();
   	 getNextToken();
   	 printf("K-> <C| <=C | >C | >=C\n");
   	 C();
   }
   else
   {
   	 printf("expected LE, LEE, GR or GRE, found %s\n",st);
   	 getNextToken();
   	 getNextToken();
   }
}

void C()
{
	printf("C->DC1\n");
	D();
	printf("C->DC1\n");
	C1();
}

void C1()
{
	if(strcmp("PLUS",st)==0 || strcmp(st,"MINUS")==0)
   { 
   	 printf("C1->NC1\n");
   	 N();
   	 printf("C1->NC1\n");
   	 C1();
   }
   else{
	printf("C1->null\n");   
   	return;
}
}

void N()
{
   if(strcmp("PLUS",st)==0 || strcmp(st,"MINUS")==0)
   { 
   	 getNextToken();
   	 getNextToken();
   	 printf("N-> +D | -D\n");
   	 D();
   }
   else
   {
   	 printf("expected PLUS or MINUS, found %s\n",st);
   	 getNextToken();
   	 getNextToken();
   }	
}

void D()
{
	printf("D->GD1\n");

	G();
	printf("D->GD1\n");
	D1();
}

void D1()
{
	if(strcmp("MUL",st)==0 || strcmp("DIV",st)==0 || strcmp("MOD",st)==0)	//ERROR in comparing
   { 
   	 printf("D1->MD1\n");
   	 M();
   	 printf("D1->MD1\n");
   	 D1();
   }
   else{
   	printf("D1->null\n");
   	return ;
}
}

void M()
{
   if(strcmp("MUL",st)==0 || strcmp(st,"DIV")==0 || strcmp(st,"MOD")==0)			//ERROR in comparing
   { 
   	 getNextToken();
   	 getNextToken();
   	 printf("M->*G|/G|%%G\n");
   	 G();
   }
   else
   {
   	 printf("expected MUL, DIV or MOD, found %s\n",st);
   	 getNextToken();
   	 getNextToken();
   }	
}

void G()			//INT_LITERAL not handled
{
	if(strcmp("ID",st)==0)
   { 
   	printf("G->id\n");
     getNextToken(); //not sure maybe wrong 
     getNextToken();
   }
   else if(strcmp("NOT",st)==0)
   {
   	getNextToken();
   	getNextToken();
   	printf("G->not G\n");
   	G();
   }	
   else if(strcmp("INT_LITERAL",st)==0)
   {
   	getNextToken();
   	getNextToken();
   	printf("G->INT_LITERAL\n");
   }
   else if(strcmp("@",st)==0)
   {
   	getNextToken();
   	getNextToken();
   	printf("G->@STRING\n");
   	if(strcmp(st,"STRING")==0)
   	{
   		getNextToken();
   		getNextToken();
   	}
   	else
   		printf("string expected, found %s\n",st);
  }
  else if(strcmp("FLOAT_LITERAL",st)==0)
  {
   	getNextToken();
   	getNextToken();
  }	
  else
  {
   	printf("while declaration expected ID or INT_LITERAL FLOAT_LITERAL or @ or NOT, found %s\n",st);
   	getNextToken();
   	getNextToken();
  }
   	
}



int main()
{
	f1=fopen("output.txt","r");
	
	getNextToken();
	//printf("%s",st);
	printf("S->int main(){Stmts}\n");
	S();
}
