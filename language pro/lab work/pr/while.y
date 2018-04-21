%{
	#include<bits/stdc++.h>
	using namespace std;
	
	void yyerror(char *str)
	{
		cout<<"\nError : \n"<<str<<endl;
	}
	int yylex();
	
	string myitoa(int n)
	{
		string str = "";
		while(n > 0)
		{
			int r = n%10;
			str += (char) r+'0';
			
			n /= 10;
		}
		
		int len = str.length();
		for(int i=0;i<len/2;i++)
			swap(str[i], str[len-i-1]);
		
		return str;
	}
	
	struct CodeHolder
	{
		string place;
		string code;
		string begin;
		string after;
		string type;
		string temp;
		map<string, string> *labelMap;
	}table[10005];
	
	
	int tableIndex = 0;
	int getFreeTableIndex()
	{
		table[tableIndex].place = "";
		table[tableIndex].code = "";
		table[tableIndex].begin = "";
		table[tableIndex].after = "";
		table[tableIndex].type = "";
		table[tableIndex].labelMap = NULL;
		return tableIndex++;
	}
	int labelIndex = 1;
	string newLabel()
	{
		string str = "L";
		str = str + myitoa(labelIndex++);
		return str;
	}
	int freeVarIndex = 1;
	string newTemp()
	{
		string str = "t";
		str = str + myitoa(freeVarIndex++);
		return str;
	}
	
	int mainTableIndex = -1;
	
	map<string, string> varType;
	bool isDeclared(string var)
	{
		if(varType.find(var)==varType.end())
			return false;
		return true;
	}
	int getVarSize(string str)
	{
		if(str[0]=='i' | str[0]=='u')
			return 32;
		if(str[0]=='b')
			return 8;
		return 0;
	}
	
	string getCombinedType(string ta, string tb)
	{
		if(ta=="int" || tb=="int")
			return "int";
		
		if(ta=="uint" || tb=="uint")
			return "uint";
		
		return "bool";
	}
	
	stack<string> blockExit;
	
	string curDataType;
%}

%union{	int lnum; char *lstr; }
%token<lstr> ID NUM
%token<lstr> DATA_TYPE IF_KEY ELSE_KEY SWITCH_KEY CASE_KEY DEFAULT_KEY BREAK_KEY WHILE_KEY
%type<lnum> exp
%type<lnum> program 
%type<lnum> stmt declare_stmt assign_stmt opt_assign if_stmt switch_stmt while_stmt
%type<lnum> switch_body case_body break_stmt
%left<lnum> LOROP LANDOP
%left<lnum> BOROP BANDOP BXOROP
%left<lnum> EQOP NEQOP LTOP LTEQOP GTOP GTEQOP ADDEQ SUBEQ MULEQ DIVEQ
%left<lnum> '+' '-'
%left<lnum> '*' '/'
%right<lnum> EXPOP
%left<lnum> LNOTOP BNOTOP
%nonassoc IFX
%nonassoc ELSE_KEY

%token<lnum> SPACE

%%
//Program
program:
	program stmt				{
									$$ = getFreeTableIndex();
									table[$$].code = table[$1].code + table[$2].code;
									mainTableIndex = $$;
								}
	|							{
									$$ = getFreeTableIndex();
									table[$$].code = "";
									mainTableIndex = $$;
								}
	;
//Statement (All types)
stmt:
	declare_stmt				{
									$$ = getFreeTableIndex();
									table[$$] = table[$1];
									mainTableIndex = $$;
								}
	|assign_stmt				{
									$$ = getFreeTableIndex();
									table[$$] = table[$1];
									mainTableIndex = $$;
								}
	|if_stmt					{
									$$ = getFreeTableIndex();
									table[$$] = table[$1];
									mainTableIndex = $$;
								}
	|switch_stmt				{
									$$ = getFreeTableIndex();
									table[$$] = table[$1];
									mainTableIndex = $$;
								}
	| '{' program '}'			{
									$$ =getFreeTableIndex();
									table[$$] = table[$2];
									mainTableIndex = $$;
								}
	| while_stmt				{
									$$ = getFreeTableIndex();
									table[$$] = table[$1];
									mainTableIndex = $$;
								}
	| break_stmt				{
									$$ = getFreeTableIndex();
									table[$$] = table[$1];
									mainTableIndex = $$;
								}
	| ';'						{
									$$ = getFreeTableIndex();
									table[$$].code = "";
									mainTableIndex = $$;
								}
	;
//While Construct
while_stmt:
	WHILE_KEY {blockExit.push(newLabel());} 	'(' exp ')' stmt	{
																		$$ = getFreeTableIndex();
																		string startLabel = newLabel();
																		string falseLabel = blockExit.top();
																		table[$$].code = startLabel + ":\n";
																		table[$$].code += table[$4].code;
																		string boolCode;
																		if(table[$4].type=="bool")
																			boolCode = "if FALSE " + table[$4].place + ", goto " + falseLabel + "\n";
																		else
																			boolCode = "if " + table[$4].place + " == 0, goto " + falseLabel + "\n";
																		table[$$].code += boolCode;
																		table[$$].code += table[$6].code;
																		table[$$].code += "goto " + startLabel + "\n";
																		table[$$].code += falseLabel + ":\n";
																		table[$$].after = falseLabel;
																		blockExit.pop();
																		mainTableIndex = $$;
																	}
//Switch construct
switch_stmt:
	SWITCH_KEY {blockExit.push(newLabel());} '(' exp ')' '{' switch_body '}'	{
																					$$ = getFreeTableIndex();
																					table[$$].code = table[$4].code;
																					string startLabel = newLabel();
																					string outLabel = blockExit.top();
																					table[$$].code += table[$7].temp;
																					table[$$].code += "goto " + startLabel + "\n";
																					table[$$].code += table[$7].code;
																					table[$$].code += "goto " + outLabel + "\n";
																					table[$$].code += startLabel + ":\n";
																					map<string, string> *temp = table[$7].labelMap;
																					for(map<string, string>::iterator iter = temp->begin();iter!=temp->end();iter++)
																					{
																						if((iter->first) == "default")
																							continue;
																						string expvar = table[$4].place;
																						table[$$].code += "if " + iter->first + " == " + expvar + ", goto " + iter->second + "\n";
																					}
																					if((*temp)["default"].length()!=0)
																						table[$$].code += "goto " + (*temp)["default"] + "\n";
																					table[$$].code += outLabel + ":\n";
																					blockExit.pop();
																					mainTableIndex = $$;
																				}
	;
switch_body:
	switch_body CASE_KEY exp ':' case_body		{
													$$ = getFreeTableIndex();
													table[$$].temp = table[$1].temp + table[$3].code;
													string startLabel = newLabel();
													map<string, string> *temp = table[$1].labelMap;
													table[$$].labelMap = temp;
													(*temp)[table[$3].place] = startLabel;
													table[$$].code = table[$1].code;
													table[$$].code += startLabel + ":\n";
													table[$$].code += table[$5].code;
													mainTableIndex = $$;
												}
	|switch_body DEFAULT_KEY ':' case_body		{
													$$ = getFreeTableIndex();
													table[$$].temp = table[$1].temp;
													string startLabel = newLabel();
													map<string, string> *temp = table[$1].labelMap;
													table[$$].labelMap = temp;
													if((*temp).find("default")!=(*temp).end())
													{
														cout<<"\nMore than 1 default statements in a switch body\n";
														exit(1);
													}
													(*temp)["default"] = startLabel;
													table[$$].code = table[$1].code;
													table[$$].code += startLabel + ":\n";
													table[$$].code += table[$4].code;
													mainTableIndex = $$;
												}
	|											{
													$$ =getFreeTableIndex();
													map<string, string> *temp = new map<string, string>;
													table[$$].labelMap = temp;
													table[$$].code = "";
													table[$$].temp = "";
													mainTableIndex = $$;
												}
	;
case_body:
	case_body stmt								{
													$$ = getFreeTableIndex();
													table[$$].code = table[$1].code + table[$2].code;
													mainTableIndex = $$;
												}
	|											{
													$$ = getFreeTableIndex();
													table[$$].code = "";
													mainTableIndex = $$;
												}
	;
break_stmt:
	BREAK_KEY ';'								{
													$$ = getFreeTableIndex();
													if(blockExit.empty())
													{
														cout<<"\nBreak statement written outside a valid block\n";
															exit(1);
													}
													table[$$].code = "goto " + blockExit.top() + "\n";
													mainTableIndex = $$;
												}
//If else Construct
if_stmt:
	IF_KEY '(' exp ')' stmt %prec IFX			{
												$$ = getFreeTableIndex();
												string falseLabel;
												if(table[$5].after.length()==0)
													falseLabel = newLabel();
												else
													falseLabel = table[$5].after;
												table[$$].code = table[$3].code;
												string boolCode;
												if(table[$3].type=="bool")
													boolCode = "if FALSE " + table[$3].place + ", goto " + falseLabel + "\n";
												else
													boolCode = "if " + table[$3].place + " == 0, goto " + falseLabel + "\n";
												table[$$].code += boolCode + table[$5].code;
												if(table[$5].after.length()==0)
													table[$$].code += falseLabel + ":\n";
												table[$5].after = falseLabel;
												table[$$].after = falseLabel;
												mainTableIndex = $$;
											}
	|IF_KEY '(' exp ')' stmt ELSE_KEY stmt		{
												$$ = getFreeTableIndex();
												string falseLabel, outLabel;
												falseLabel = newLabel();
												if(table[$7].after.length()==0)
													outLabel = newLabel();
												else
													outLabel = table[$7].after;
												table[$$].code = table[$3].code;
												string boolCode;
												if(table[$3].type=="bool")
													boolCode = "if FALSE " + table[$3].place + ", goto " + falseLabel + "\n";
												else
													boolCode = "if " + table[$3].place + " == 0, goto " + falseLabel + "\n";
												table[$$].code += boolCode + table[$5].code;
												table[$$].code += "goto " + outLabel + "\n";
												table[$$].code += falseLabel + ":\n";
												table[$$].code += table[$7].code;
												if(table[$7].after.length()==0)
													table[$$].code += outLabel + ":\n";
												table[$7].after = outLabel;
												table[$$].after = outLabel;
												mainTableIndex = $$;
											}
//Declare statement
declare_stmt:
	DATA_TYPE ID opt_assign ';'	{
									$$ = getFreeTableIndex();
									if(isDeclared(string($2)))
									{
										cout<<"\nVariable "<<$2<<" declared more than once\n";
										exit(1);
									}
									varType[string($2)] = string($1);
									table[$$].code = "assign " + string($2) + ", " + myitoa(getVarSize(string($1))) + "\n";
									string tempCode = string($2) + " = " + table[$3].place + "\n";
									table[$$].code += table[$3].code + tempCode;
									
									string reqType = getCombinedType(varType[string($2)], table[$3].type);
									if(reqType!=varType[string($2)])
									{
										cout<<"\nVariable "<<$2<<"'s type doesn't match with expression type:\n";
										cout<<"Required : "<<varType[string($2)];
										cout<<"\nFound : "<<reqType<<endl;
										exit(1);
									}
									mainTableIndex = $$;
								}
	;
//Optional Assignment Associated with declaration
opt_assign:
	'=' exp						{
									$$ = getFreeTableIndex();
									table[$$] = table[$2];
									mainTableIndex = $$;
								}
	|							{
									$$ = getFreeTableIndex();
									table[$$].place = "0";
									table[$$].type = "bool";
									mainTableIndex = $$;
								}
	;
//Assignment statement
assign_stmt:
	ID '=' exp ';'				{
									if(!isDeclared(string($1)))
									{
										cout<<"\nVariable "<<$1<<" not declared before use\n";
										exit(1);
									}
									$$ = getFreeTableIndex();
									cout<<"\nCurrent ID = "<<$1<<endl;
									string tempCode = string($1) + " = " + table[$3].place + "\n";
									table[$$].code = table[$3].code + tempCode;
									string reqType = getCombinedType(varType[string($1)], table[$3].type);
									if(reqType!=varType[string($1)])
									{
										cout<<"\nVariable "<<$1<<"'s type doesn't match with expression type:\n";
										cout<<"Required : "<<varType[string($1)];
										cout<<"\nFound : "<<reqType<<endl;
										exit(1);
									}
									mainTableIndex = $$;
								}
	|ID ADDEQ exp ';'			{
									if(!isDeclared(string($1)))
									{
										cout<<"\nVariable "<<$1<<" not declared before use\n";
										exit(1);
									}
									$$ = getFreeTableIndex();
									cout<<"\nCurrent ID = "<<$1<<endl;
									string tempCode = string($1) + " = " + string($1) + " + " + table[$3].place + "\n";
									table[$$].code = table[$3].code + tempCode;
									string reqType = getCombinedType(varType[string($1)], table[$3].type);
									if(reqType!=varType[string($1)])
									{
										cout<<"\nVariable "<<$1<<"'s type doesn't match with expression type:\n";
										cout<<"Required : "<<varType[string($1)];
										cout<<"\nFound : "<<reqType<<endl;
										exit(1);
									}
									mainTableIndex = $$;
								}
	|ID SUBEQ exp ';'			{
									if(!isDeclared(string($1)))
									{
										cout<<"\nVariable "<<$1<<" not declared before use\n";
										exit(1);
									}
									$$ = getFreeTableIndex();
									cout<<"\nCurrent ID = "<<$1<<endl;
									string tempCode = string($1) + " = " + string($1) + " - " + table[$3].place + "\n";
									table[$$].code = table[$3].code + tempCode;
									string reqType = getCombinedType(varType[string($1)], table[$3].type);
									if(reqType!=varType[string($1)])
									{
										cout<<"\nVariable "<<$1<<"'s type doesn't match with expression type:\n";
										cout<<"Required : "<<varType[string($1)];
										cout<<"\nFound : "<<reqType<<endl;
										exit(1);
									}
									mainTableIndex = $$;
								}
	|ID MULEQ exp ';'			{
									if(!isDeclared(string($1)))
									{
										cout<<"\nVariable "<<$1<<" not declared before use\n";
										exit(1);
									}
									$$ = getFreeTableIndex();
									cout<<"\nCurrent ID = "<<$1<<endl;
									string tempCode = string($1) + " = " + string($1) + " * " + table[$3].place + "\n";
									table[$$].code = table[$3].code + tempCode;
									string reqType = getCombinedType(varType[string($1)], table[$3].type);
									if(reqType!=varType[string($1)])
									{
										cout<<"\nVariable "<<$1<<"'s type doesn't match with expression type:\n";
										cout<<"Required : "<<varType[string($1)];
										cout<<"\nFound : "<<reqType<<endl;
										exit(1);
									}
									mainTableIndex = $$;
								}
	|ID DIVEQ exp ';'			{
									if(!isDeclared(string($1)))
									{
										cout<<"\nVariable "<<$1<<" not declared before use\n";
										exit(1);
									}
									$$ = getFreeTableIndex();
									cout<<"\nCurrent ID = "<<$1<<endl;
									string tempCode = string($1) + " = " + string($1) + " / " + table[$3].place + "\n";
									table[$$].code = table[$3].code + tempCode;
									string reqType = getCombinedType(varType[string($1)], table[$3].type);
									if(reqType!=varType[string($1)])
									{
										cout<<"\nVariable "<<$1<<"'s type doesn't match with expression type:\n";
										cout<<"Required : "<<varType[string($1)];
										cout<<"\nFound : "<<reqType<<endl;
										exit(1);
									}
									mainTableIndex = $$;
								}
	;
//Expression
exp:
	  exp LOROP exp				{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " || " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = "bool";
	  								mainTableIndex = $$;
	  							}
	| exp LANDOP exp			{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " && " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = "bool";
	  								mainTableIndex = $$;
	  							}
	
	| exp BOROP exp				{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " | " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = "bool";
	  								mainTableIndex = $$;
	  							}
	| exp BANDOP exp			{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " & " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = "bool";
	  								mainTableIndex = $$;
	  							}
	| exp BXOROP exp			{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " ^ " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = "bool";
	  								mainTableIndex = $$;
	  							}
	
	| exp EQOP exp				{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " == " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = "bool";
	  								mainTableIndex = $$;
	  							}
	| exp NEQOP exp				{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " != " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = "bool";
	  								mainTableIndex = $$;
	  							}
	| exp LTOP exp				{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " < " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = "bool";
	  								mainTableIndex = $$;
	  							}
	| exp LTEQOP exp			{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " <= " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = "bool";
	  								mainTableIndex = $$;
	  							}
	| exp GTOP exp				{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " > " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = "bool";
	  								mainTableIndex = $$;
	  							}
	| exp GTEQOP exp			{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " >= " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = "bool";
	  								mainTableIndex = $$;
	  							}
	
	| exp '+' exp				{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " + " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = getCombinedType(table[$1].type, table[$3].type);
	  								mainTableIndex = $$;
	  							}
	| exp '-' exp				{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " - " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = getCombinedType(table[$1].type, table[$3].type);
	  								mainTableIndex = $$;
	  							}
	| exp '*' exp				{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " * " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = getCombinedType(table[$1].type, table[$3].type);
	  								mainTableIndex = $$;
	  							}
	| exp '/' exp				{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " / " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = getCombinedType(table[$1].type, table[$3].type);
	  								mainTableIndex = $$;
	  							}
	
	| exp EXPOP exp				{
	  								$$ = getFreeTableIndex();
	  								table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = " + table[$1].place + " @ " + table[$3].place + "\n";
	  								table[$$].code = table[$1].code + table[$3].code + tempCode;
	  								table[$$].type = table[$1].type;
	  								mainTableIndex = $$;
	  							}
	
	| LNOTOP exp				{
	  								$$ = getFreeTableIndex();
									table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = NOT " + table[$2].place + "\n";
	  								table[$$].code = table[$2].code + tempCode;
	  								table[$$].type = table[$2].type;
	  								mainTableIndex = $$;
								}
	| BNOTOP exp				{
	  								$$ = getFreeTableIndex();
									table[$$].place = newTemp();
	  								string tempCode = table[$$].place + " = NOT " + table[$2].place + "\n";
	  								table[$$].code = table[$2].code + tempCode;
	  								table[$$].type = table[$2].type;
	  								mainTableIndex = $$;
								}
	
	| '(' exp ')'				{
	  								$$ = getFreeTableIndex();
									table[$$] = table[$2];
									mainTableIndex = $$;
								}
	| ID						{
	  								if(!isDeclared(string($1)))
	  								{
	  									cout<<"\nVariable "<<$1<<" not declared before use\n";
	  									exit(1);
	  								}
	  								$$ = getFreeTableIndex();
									table[$$].place = string($1);
									table[$$].type = varType[string($1)];
									mainTableIndex = $$;
								}
	| NUM						{
									int numval = atoi($1);
									$$ = getFreeTableIndex();
									table[$$].place = newTemp();
									table[$$].code = table[$$].place + " = " + string($1) + "\n";
									
									if(numval==0 || numval==1)
										table[$$].type = "bool";
									else
										table[$$].type = "uint";
									mainTableIndex = $$;
								}
	;
	
%%

int main()
{
	yyparse();
	
	cout<<"\n\nGenerated 3-address code : \n\n";
	cout<<table[mainTableIndex].code<<endl;
	
	return 0;
}
