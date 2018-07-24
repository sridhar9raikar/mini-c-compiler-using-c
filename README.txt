******************************************************************      
                   Implementing Mini C-Compiler    
******************************************************************

Team Member:
   1. S Rajesh               -  01FB15ECS249
   2. Sanjay Rajendra Awate  -  01FB15ECS265
   3. Shankar Kanamadi       -	01FB16ECS722  
   4.Sandeep Kumar           -  01FB15ECS903

******************************************************************



 
 Description -
 
	Implementation of  mini C-Complier using lex and yacc to accept simple 
  expressions, if-else statement, while statement and other basic
  statements and also generate 3-address code as the output for the input code.
	
    

 Different files in the directory
	
   compiler.l  - It is lex (token generator) file to generate tokens from the source program
       
   compiler.y  - It is yacc (parser) file to validate  the syntax of the source program

   codegen.h   - It is c header file, it contains  functions  to genarate the 3-address code   
		
   symbol.h    - It contains functions  to generate the symbol table 

      


Execution phases        

- Give the input file as a c program file.
        
- It removes all single line and/or multiline comments.
        
- Generate tokens using lex tool.
        
- Validate the syntax as per grammar using yacc tool.
        
- While parsing the input , it generates symbol table
        
- If parsing is successful it generates the three-address code otherwise
 display's the appropriate error message.  
 
 

 Steps to Compile and Run program        

  step 1. Execute yacc file with following command it generates y.tab.c & y.tab.h
      
	yacc -d compiler.l
	
        
  step 2. Execute lex file it generates yy.lex.c
         
	lex compiler.l
	
        
  step 3. Compile y.tab.c using C-compiler (gcc) it generates owncc objective file  

         
	gcc -o owncc y.tab.c -ll

        
  step 4. Run the owncc file with input file as the input        
                   
	./owncc < input.c




