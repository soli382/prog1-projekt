#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* version = 
    "alap v0.1.0";

const char* alap_help =
    "\n"
    "Usage: alap <template_id> [option]\n\n"
    "Available options:\n"
    "  -h, --help       show this help\n"
    "  -v, --version    version info\n"
    "  --stdout         don't create source file, print result to stdout\n\n"
    "Available templates:\n"
    "  * c        - C source code [main.c]\n"
    "  * py       - Python 3 source code [main.py]\n"
    "  * java     - Java source code [Main.java]\n"
    "  * sh       - Bash source code [main.sh]";

const char* c_program =
    "#include <stdio.h>\n"
    "\n"
    "int main()\n"
    "{\n"
    "   printf(\"Hello World!\\n\");\n"
    "\n"   
    "   return 0;\n"
    "}";

const char* python_program =
    "#!/usr/bin/env python3"
    "\n"
    "\n"
    "\n"
    "def main():\n"
    "   print(\"Hello World!\")\n"
    "\n"
    "#####################################\n"
    "\n"
    "if __name__ == \"__main__\":\n"
    "   main()";

const char* java_program =
    "class Alap {\n"
    "   public static void main(String[] args) {\n"
    "   Alap alap = new Alap();\n"
    "   alap.start();\n"
    "}\n"
    "\n"
    "int make_double(int n) {\n"
    "   return 2 * n;\n"
    "}\n"
    "\n"
    "void start() {\n"
    "   System.out.println(\"hello\");\n"
    "   int x = make_double(10);\n"
    "   System.out.println(x);\n"
    "   }\n"
    "}";

const char* bash_program =
    "#!/bin/bash\n"
    "\n"
    "echo \"Hello World!\"";

int main(int argc, char* argv[])
{
    //alap
    if(argc == 1 || (argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")))) 
    {
        puts(version);
        puts(alap_help);
    }
    else if (argc == 2 && (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version"))) 
    {
        puts(version);
    }

    //error if too much arguments
    if(argc >= 4)
    {
        printf("Too much arguments in alap!\n");
    }
    
    
    //c program
    if(argc == 3 && !strcmp(argv[1], "c") && !strcmp(argv[2], "--stdout"))
    {
        puts(c_program);
    }
    else if(argc == 2 && !strcmp(argv[1], "c"))
    {
        FILE *fp = fopen("main.c","r");
        if(fp != NULL)
        {
            fclose(fp);
            printf("Error!: the file 'main.c' already exists\n");
        }
        else {
            fp = fopen("main.c", "w");
            fputs(c_program,fp);
            fclose(fp);
            printf("# 'main.c' was created\n");
        }
    }

    //python program
    if(argc == 3 && !strcmp(argv[1], "py") && !strcmp(argv[2], "--stdout"))
    {
        puts(python_program);
    }
    else if(argc == 2 && !strcmp(argv[1], "py"))
    {
        FILE *fp = fopen("main.py","r");
        if(fp != NULL)
        {
            fclose(fp);
            printf("Error!: the file 'main.py' already exists\n");
        }
        else {
            fp = fopen("main.py", "w");
            fputs(python_program,fp);
            fclose(fp);
            printf("# 'main.py' was created\n");
        }
    }

    //java program
    if(argc == 3 && !strcmp(argv[1], "java") && !strcmp(argv[2], "--stdout"))
    {
        puts(java_program);
    }
    else if(argc == 2 && !strcmp(argv[1], "java"))
    {
        FILE *fp = fopen("Main.java","r");
        if(fp != NULL)
        {
            fclose(fp);
            printf("Error!: the file 'Main.java' already exists\n");
        }
        else {
            fp = fopen("Main.java", "w");
            fputs(java_program,fp);
            fclose(fp);
            printf("# 'Main.java' was created\n");
        }
    }

    //bash program
    if(argc == 3 && !strcmp(argv[1], "sh") && !strcmp(argv[2], "--stdout"))
    {
        puts(bash_program);
    }
    else if(argc == 2 && !strcmp(argv[1], "sh"))
    {
        FILE *fp = fopen("main.sh","r");
        if(fp != NULL)
        {
            fclose(fp);
            printf("Error!: the file 'main.sh' already exists\n");
        }
        else {
            fp = fopen("main.sh", "w");
            fputs(bash_program,fp);
            fclose(fp);
            printf("# 'main.sh' was created\n");
        }
    }

    return 0;
}