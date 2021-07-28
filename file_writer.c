#include <stdio.h>

#include "file_writer.h"

FILE *fp;

void make_csv_file(){
    fp = fopen("..\\output\\out.csv","a+");
    fprintf(fp,"type, no_of_threads, member_operations, insert_operations, delete_operations, time_interval\n");
    fclose(fp);
}

void write_on_csv(char type[], int no_of_threads, int member_operations,
                  int insert_operations, int delete_operations, unsigned long time_interval){
    fp = fopen("..\\output\\out.csv","a+");
    fprintf(fp,"%s, %d, %d, %d, %d, %lu\n",type, no_of_threads, member_operations, insert_operations, delete_operations, time_interval);
    fclose(fp);
}