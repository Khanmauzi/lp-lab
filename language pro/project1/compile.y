
%{
#include<bits/stdc++.h>
using namespace std;
int vc=0;				//variable count
int lc=0;				//label count

bool compati(string s1,string s2)		// to check the data type of variable.
{
	if((s1=="BOOL"&&(s2=="UINT"||s2=="INT")) || (s2=="BOOL"&&(s1=="UINT"||s1=="INT"))) return false;
	return true;
}
map<string,string >maintable;				//to store variable and its type

bool conditionformaintable(string index, string value)
{
	if(maintable[index]==value) return true;  // Check  for datatype
	return false;

}
struct TS
{
	string place;
	string code;					//store the 3-address code 
	string initial;				        
	string after;					
}table[10000];

void yyerror(const char *str){
	cout<<"\nError : \n"<<str<<endl;
}

int yylex();

int initiali=0;			//intitial index

string nts()			//getting new temporary variable
{
	string temp="t"+to_string(vc);
	vc++;
	return temp;
}


string getLabel()		//getting label
{
	string temp="L"+to_string(lc);
	lc++;
	return temp;
}

int getEmptyRow()					//return the index at which code will be inserted
{
	table[initiali].place="";
	table[initiali].code="";
	table[initiali].initial="";
	table[initiali].after="";
	return initiali++;
}

int maini=-1;				//main index
int lastTableIndex=-1;			//last table index
int nested=0;				//to check nested loop

void checkcompati(string s, string d)			// to check the compatibility 
{
	if(!compati(maintable[s],maintable[d]))
	{
		cout<<"Type Incompatible \n";
		exit(0);
	}
}

void updatemainindex()
{
	maini++;
}
%}
%union
{
int number;
char* str;
}
%token<str> NUM ID
%token EOL
%token INT UINT BOOL 
%token<str> TR FL 
%token IF WHILE
%token SWITCH
%token Case
%nonassoc IFX
%nonassoc ELSE 
%type<number> SStatement
%type<number> caseSwitch
%type<number> singleCase
%type<number> expression
%type<number> AssignmentStatement 
%type<number> DeclareStatement
%type<number> StartSymbol statements IfStatement WhileStatement 

%token PLEQ SBEQ MLEQ DVEQ
%left GREQ  
%left LSEQ
%left GRTH 
%left LSTH
%left EQEQ
%left NOTEQ
%left LOR
%left LNOT
%left LAND
%left '|' 
%left '^'
%left '&'
%left '~'
%left '='
%left '+' '-'
%left '*' '/'
%left '%'
%%
StartSymbol:					{
								$$=getEmptyRow();		
							}
 |StartSymbol statements        {
 								$$=getEmptyRow();
 								if(lastTableIndex!=-1)
 								table[$$].code=table[lastTableIndex].code+table[$2].code;
 								else
 								table[$$].code=table[$2].code;
 								maini = $$;
 								lastTableIndex=$$;
 							}
 ;
statements:					
DeclareStatement 				{
								$$ = $1;
							}
|AssignmentStatement 	                        {$$ = $1; 
			    }
							
|IfStatement					{$$ = $1;
                            }
                            
|WhileStatement					{$$ = $1;
                            }
|SStatement				{$$ = $1;
			    }
|'{' StartSymbol '}'			{
								$$=$2;
								maini=$$;							
							}			
;
SStatement: SWITCH '(' expression ')'  singleCase 	 {
	
								      if(!conditionformaintable(table[$3].place,"BOOL"))	{
							cout<<"not compatibe"<<endl;									
									exit(0);
								}
								$$=getEmptyRow();
									table[$$].after=getLabel();
									string gen="";
									gen="if "+table[$3].place+"=="+'0'+" goto "+table[$$].after+'\n';
									table[$$].code=table[$3].code+gen+table[$5].code+'\n'+table[$$].after;
									maini=$$;
								}
;
caseSwitch: singleCase		{
							$$=getEmptyRow();
							table[$$].code=table[$1].code;
							maini=$$;
							}
;
singleCase: Case expression ':' statements 	{
								    if(!conditionformaintable(table[$2].place,"BOOL"))	{
							cout<<"not compatibe"<<endl;									
									exit(0);
								}
									$$=getEmptyRow();
									table[$$].after=getLabel();
									string gen="";
									gen="if "+table[$2].place+"=="+'0'+" goto "+table[$$].after+'\n';
									table[$$].code=table[$2].code+gen+table[$4].code+'\n'+table[$$].after;
									maini=$$;		
  								 }
;

IfStatement: IF '(' expression ')'  statements %prec IFX {
								    if(!conditionformaintable(table[$3].place,"BOOL"))	{
							cout<<"not compatibe"<<endl;									
									exit(0);
								}
									$$=getEmptyRow();
									table[$$].after=getLabel();
									string gen="";
									gen="if "+table[$3].place+"=="+'0'+" goto "+table[$$].after+'\n';
									table[$$].code=table[$3].code+gen+table[$5].code+'\n'+table[$$].after;
									maini=$$;		
  								 }
  | IF '(' expression ')' statements ELSE statements {
  									if(!conditionformaintable(table[$3].place,"BOOL"))	exit(0);
									$$=getEmptyRow();
									table[$$].after=getLabel();
									string gen="";
									gen="if "+table[$3].place+"=="+'0'+" goto "+table[$$].after+'\n';
									table[$$].code=table[$3].code+gen+table[$5].code+'\n'+table[$$].after;
									maini=$$;
  								}
;
WhileStatement:
WHILE '(' expression ')' statements {
									if(!conditionformaintable(table[$3].place,"BOOL"))	exit(0);
									$$=getEmptyRow();
									table[$$].initial=getLabel();
									table[$$].after=getLabel();
									string gen="";
									gen=table[$$].initial+":\n"+"if "+table[$3].place+"=="+'0'+" goto "+table[$$].after+'\n';
									table[$$].code=table[$3].code+gen+table[$5].code+'\n'+"goto " +table[$$].initial+"\n"+table[$$].after+":";
									maini=$$;
							}
;
DeclareStatement:
INT ID ';'          {
							if(maintable.find(string($2))!=maintable.end()){cout<<"redeclaration of "<<$2<<endl; exit(0);}
							maintable[string($2)] = "INT";
							$$ =getEmptyRow();
							table[$$].code ="Declaring "+string($2)+"\n";
							maini=$$;
     		            }
|INT ID '=' expression ';' {
    						if(maintable.find(string($2))!=maintable.end()) {cout<<"redeclaration of "<<$2<<endl; exit(0);}
    						maintable[string($2)] = "INT";
    						$$ =getEmptyRow();
							string mycode  = string($2)+ '=' + table[$4].place + '\n';
							table[$$].code=table[$4].code+"\n"+mycode;
							maini=$$;
    				    }    				   
    |UINT ID ';'        {
    						if(maintable.find(string($2))!=maintable.end()) exit(0);
	 						maintable[string($2)] = "UINT";
	 						$$ =getEmptyRow();
							table[$$].code ="Declaring "+string($2)+"\n";
							maini=$$;
     		            }   		           
    |UINT ID '=' expression ';'{
    						if(maintable.find(string($2))!=maintable.end()) exit(0);
							        					maintable[string($2)] = "UINT";
    						$$ =getEmptyRow();
							string mycode  = string($2)+ '=' + table[$4].place + '\n';
							table[$$].code=table[$4].code+"\n"+mycode;
							maini=$$;
    				    }    				    
    |BOOL ID  ';'       {
                            if(maintable.find(string($2))!=maintable.end()) exit(0);
	 						maintable[string($2)] = "BOOL";
	 						$$ =getEmptyRow();
							table[$$].code ="Declaring "+string($2)+"\n";
							maini=$$;
   						}
   	 |BOOL ID '=' TR ';' {
                            if(maintable.find(string($2))!=maintable.end()) { exit(0);}
							
	 						maintable[string($2)] = "BOOL";
	 						$$ =getEmptyRow();
							string mycode  = "Declared and Initialised  "+string($2)+ '=' + "true" + '\n';
							table[$$].code =mycode;
							maini=$$;
   						   }					   
   	|BOOL ID '=' FL ';' {
                            if(maintable.find(string($2))!=maintable.end()) exit(0);
							
	 						maintable[string($2)] = "BOOL";
	 						$$ =getEmptyRow();
							string mycode  = "Declared and Initialised"+ string($2)+ '=' + "false" + '\n';
							table[$$].code =mycode;
							maini=$$;
   						   }	 
;       
AssignmentStatement:
	ID '=' expression ';' {
					if(maintable.find(string($1))==maintable.end()){cout<<$1<<" is not declared"<<endl; exit(0);}
					checkcompati(table[$3].place,table[$3].place);
					$$ =getEmptyRow();
					string mycode  = string($1)+ '=' + table[$3].place + '\n';
					table[$$].code=table[$3].code+mycode;
					maini=$$;
					}
	|ID PLEQ expression ';'{
					$$ =getEmptyRow();
					table[$$].place =nts();
					checkcompati(table[$3].place,table[$3].place);
					maintable[table[$$].place] ="INT";
					table[$$].code = table[$3].code +table[$$].place + '=' +string($1)+ '+' + table[$3].place+"\n" + string($1) + '=' + table[$$].place;
					maini=$$;
			      }  
	| ID SBEQ expression ';'{
					$$ =getEmptyRow();
					table[$$].place =nts();
					checkcompati(table[$3].place,table[$3].place);
					maintable[table[$$].place] ="INT";
					table[$$].code = table[$3].code +table[$$].place + '=' +string($1)+ '-' + table[$3].place+"\n" + string($1) + '=' + table[$$].place;
					maini=$$;
			      }	      
	| ID MLEQ expression ';'{
					$$ =getEmptyRow();
					table[$$].place =nts();
					checkcompati(table[$3].place,table[$3].place);
					maintable[table[$$].place] ="INT";
					table[$$].code = table[$3].code +table[$$].place + '=' +string($1)+ '*' + table[$3].place+"\n" + string($1) + '=' + table[$$].place;
					maini=$$;
			      }
	| ID DVEQ expression';'{
					$$ =getEmptyRow();
					table[$$].place =nts();
					checkcompati(table[$3].place,table[$3].place);
					maintable[table[$$].place] ="INT";
					table[$$].code = table[$3].code +table[$$].place + '=' +string($1)+ '/' + table[$3].place+"\n" + string($1) + '=' + table[$$].place;
					maini=$$;
			      }	
;
expression:  
	expression '|' expression {
					$$ =getEmptyRow();
					table[$$].place =nts();
					checkcompati(table[$3].place,table[$3].place);
					if(conditionformaintable(table[$1].place,"BOOL") || conditionformaintable(table[$3].place, "BOOL"))exit(0);
					
					if(maintable[table[$3].place] =="INT"||maintable[table[$1].place] =="INT")
					maintable[table[$$].place] ="INT";
					else
					maintable[table[$$].place] ="UINT";
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + '|' + table[$3].place+"\n";
					maini=$$;
			     }
	|expression '&' expression {
					$$ =getEmptyRow();
					table[$$].place =nts();
					checkcompati(table[$3].place,table[$3].place);
					if(conditionformaintable(table[$1].place,"BOOL") || conditionformaintable(table[$3].place, "BOOL"))exit(0);
					if(maintable[table[$3].place] =="INT"||maintable[table[$1].place] =="INT")
					maintable[table[$$].place] ="INT";
					else
					maintable[table[$$].place] ="UINT";
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + '&' + table[$3].place+"\n";
					maini=$$;
			      }
    | expression '^' expression {
					$$ =getEmptyRow();
					table[$$].place =nts();
					checkcompati(table[$3].place,table[$3].place);
					if(conditionformaintable(table[$1].place,"BOOL") || conditionformaintable(table[$3].place, "BOOL"))exit(0);
					if(maintable[table[$3].place] =="INT"||maintable[table[$1].place] =="INT")
					maintable[table[$$].place] ="INT";
					else
					maintable[table[$$].place] ="UINT";
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + '^' + table[$3].place+"\n";
					maini=$$;
				  }
	| '~' expression 	  {
	  				$$ =getEmptyRow();
					table[$$].place =nts();
					if(maintable[table[$2].place]=="BOOL") exit(0);
					if(maintable[table[$2].place]=="INT")
					{
						maintable[table[$$].place] ="INT";
					}
					else
					{
						maintable[table[$$].place] ="UINT";
					}
					string mygen = '~' + table[$2].place+"\n";
					table[$$].code = table[$2].code+table[$$].place + '=' + mygen;
					maini=$$;
				  }	      
	|expression '+' expression {
					$$ =getEmptyRow();
					table[$$].place =nts();
					checkcompati(table[$3].place,table[$3].place);
					if(conditionformaintable(table[$1].place,"BOOL") || conditionformaintable(table[$3].place, "BOOL"))exit(0);
					if(maintable[table[$3].place] =="INT"||maintable[table[$1].place] =="INT")
					maintable[table[$$].place] ="INT";
					else
					maintable[table[$$].place] ="UINT";
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + '+' + table[$3].place+"\n";
					maini=$$;
			      }
	| expression '-' expression {
					$$ =getEmptyRow();
					table[$$].place =nts();
					if(!compati(maintable[table[$3].place],maintable[table[$3].place])) exit(0);
					if(maintable[table[$3].place] =="INT"||maintable[table[$1].place] =="INT")
					maintable[table[$$].place] ="INT";
					else
					maintable[table[$$].place] ="UINT";
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + '-' + table[$3].place+"\n";
					maini=$$;
			      }
	| expression '*' expression {
					$$ =getEmptyRow();
					table[$$].place =nts();
					checkcompati(table[$3].place,table[$3].place);
					if(conditionformaintable(table[$1].place,"BOOL") || conditionformaintable(table[$3].place, "BOOL"))exit(0);
					if(maintable[table[$3].place] =="INT"||maintable[table[$1].place] =="INT")
					maintable[table[$$].place] ="INT";
					else
					maintable[table[$$].place] ="UINT";
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + '*' + table[$3].place+"\n";
					maini=$$;
			      }
	| expression '/' expression {
					$$ =getEmptyRow();
					table[$$].place =nts();
					checkcompati(table[$3].place,table[$3].place);
					if(conditionformaintable(table[$1].place,"BOOL") || conditionformaintable(table[$3].place, "BOOL"))exit(0);
					if(maintable[table[$3].place] =="INT"||maintable[table[$1].place] =="INT")
					maintable[table[$$].place] ="INT";
					else
					maintable[table[$$].place] ="UINT";
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + '/' + table[$3].place+"\n";
					maini=$$;
			      }
	| expression '%' expression {
					$$ =getEmptyRow();
					table[$$].place =nts();
					checkcompati(table[$3].place,table[$3].place);
					if(conditionformaintable(table[$1].place,"BOOL") || conditionformaintable(table[$3].place, "BOOL"))exit(0);
					if(maintable[table[$3].place] =="INT"||maintable[table[$1].place] =="INT")
					maintable[table[$$].place] ="INT";
					else
					maintable[table[$$].place] ="UINT";
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + '%' + table[$3].place+"\n";
					maini=$$;
			      }  
	| expression LOR expression {
					$$ =getEmptyRow();
					table[$$].place =nts(); 
					if(maintable[table[$1].place] !="BOOL"||maintable[table[$3].place] !="BOOL") exit(0);
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + "||" + table[$3].place+"\n";
					maintable[table[$$].place] ="BOOL";
					maini=$$;
			      }
	| expression LAND expression{
					$$ =getEmptyRow();
					table[$$].place =nts();
					if(maintable[table[$1].place] !="BOOL"||maintable[table[$3].place] !="BOOL") exit(0);
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + "&&" + table[$3].place+"\n";
					maintable[table[$$].place] ="BOOL";
					maini=$$;
			      }     
	 | expression GREQ expression{
					$$ =getEmptyRow();
					table[$$].place =nts();
					if(maintable[table[$1].place] =="BOOL"||maintable[table[$3].place] =="BOOL") exit(0);
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + ">=" + table[$3].place+"\n";
					maintable[table[$$].place] ="BOOL";
					maini=$$;
			      } 
	| expression LSEQ expression{
					$$ =getEmptyRow();
					table[$$].place =nts();
					if(maintable[table[$1].place] =="BOOL"||maintable[table[$3].place] =="BOOL") exit(0);
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + "<=" + table[$3].place+"\n";
					maintable[table[$$].place] ="BOOL";
					maini=$$;
			      } 
	| expression GRTH expression{
					$$ =getEmptyRow();
					table[$$].place =nts();
					if(maintable[table[$1].place] =="BOOL"||maintable[table[$3].place] =="BOOL") exit(0);
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + ">" + table[$3].place+"\n";
					maintable[table[$$].place] ="BOOL";
					maini=$$;
			      } 
	| expression LSTH expression{
					$$ =getEmptyRow();
					table[$$].place =nts();
					if(maintable[table[$1].place] =="BOOL"||maintable[table[$3].place] =="BOOL") exit(0);
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + "<" + table[$3].place+"\n";
					maintable[table[$$].place] ="BOOL";
					maini=$$;
			      } 
	
	| expression EQEQ expression{
					$$ =getEmptyRow();
					table[$$].place =nts();
					if(maintable[table[$1].place] =="BOOL"||maintable[table[$3].place] =="BOOL") exit(0);
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + "==" + table[$3].place+"\n";
					maintable[table[$$].place] ="BOOL";
					maini=$$;
			      } 
	| expression NOTEQ expression{
					$$ =getEmptyRow();
					table[$$].place =nts();
					if(maintable[table[$1].place] =="BOOL"||maintable[table[$3].place] =="BOOL") exit(0);
					table[$$].code = table[$1].code+table[$3].code +table[$$].place + '=' +table[$1].place + "!=" + table[$3].place+"\n";
					maintable[table[$$].place] ="BOOL";
					maini=$$;
			      } 	      
	| LNOT expression	 {
					$$ =getEmptyRow();
					table[$$].place =nts();
					if(maintable[table[$2].place] !="BOOL") exit(0);
					table[$$].code = table[$2].code +table[$$].place + '=' + "!" + table[$2].place +"\n";
					maintable[table[$$].place] ="BOOL";
					maini=$$;
			      }        
	| '(' expression ')' {
					$$ = getEmptyRow();
					table[$$] = table[$2];
					maini = $$;
				  }
	| ID		  {
	                if(maintable.find(string($1))==maintable.end()) exit(0);
	    			$$ =getEmptyRow();
					table[$$].place =string($1);
					maini=$$;
				  } 		  
	| TR		  {
	    			$$ = getEmptyRow();
					table[$$].place = nts();
					maintable[table[$$].place]="BOOL";
					table[$$].code = table[$$].place + " = " + "true" + "\n";
					maini = $$;
				  } 
	| FL		  {
	    			$$ = getEmptyRow();
					table[$$].place = nts();
					maintable[table[$$].place]="BOOL";
					table[$$].code = table[$$].place + " = " + "false" + "\n";
					maini = $$;
				  } 
	|NUM		  {
						$$ = getEmptyRow();
						table[$$].place = nts();
						maintable[table[$$].place]="INT";
						table[$$].code = table[$$].place + " = " + string($1) + "\n";
						maini = $$;
				  }
	;
%%
int main()
{
	yyparse();
	cout<<table[lastTableIndex].code<<endl;
	return 0;
}
