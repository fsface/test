#include <stdio.h>

void openFile(){
    FILE *file = fopen("./test.txt", "r+");
    FILE *file1 = NULL;
    if(NULL == file){
        file1 = fopen("./test.txt", "w+");
    }
    else{
        fputs("hello file", file);
        fclose(file);
    }
    if(NULL != file1){
        printf("start writing:\n");
        fputs("writing", file1);
        fclose(file1);
    }
}

void testFputc(){
    FILE *file = fopen("./test.txt", "r+");
    if(NULL == file){
        file = fopen("./test.txt", "w+");
    }
    fputc('d', file);
    fclose(file);
}

void testFgetc(){
    FILE *file = fopen("./test.txt", "r+");
    if(NULL == file){
        file = fopen("./test.txt", "w+");
    }
    char word = fgetc(file);
    printf("the first word is %c \n", word);
    fclose(file);
}

void testReadWrite(){
    FILE *file = fopen("./test.txt", "r+");
    if(NULL == file){
        file = fopen("./test.txt", "w+");
    }
    char writeStr[] = "ming tian ni hao";
    for(int count = 0; writeStr[count] != '\0'; count++){
        fputc(writeStr[count], file);
    }
    fclose(file);

}

void testFgets(){
    FILE *file = fopen("./test.txt", "r+");
    if(NULL == file){
        file = fopen("./test.txt", "w+");
    }
    int const str_len = 200;
    char str[str_len] = {0};
    while(1){
        char *string = fgets(str, sizeof(str), file);
        if(NULL == string){
            break;
        }
        printf("%s\n", string);
    }
}

int main(){
//    openFile();
//    testFputc();
//    testFgetc();
//    testReadWrite();
    testFgets();
    return 0;
}